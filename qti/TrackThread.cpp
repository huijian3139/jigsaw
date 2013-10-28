#include "TrackThread.h"
#include "windows.h"


template<typename T>
inline QImage const reference_mat_to_qimage(cv::Mat &mat, QImage::Format format)
{
	return QImage((T*)(mat.data), mat.cols, mat.rows, mat.step, format);
}  

QImage const copy_mat_to_qimage(cv::Mat const &mat, QImage::Format format)
{
	QImage image(mat.cols, mat.rows, format);
	for (int i = 0; i != mat.rows; ++i)
	{
		memcpy(image.scanLine(i), mat.ptr(i), image.bytesPerLine() );
	}

	return image;
}  
QImage const mat_to_qimage_cpy(cv::Mat &mat, int qimage_format)
{
	if(mat.type() == CV_8UC3)
	{        
		cv::cvtColor(mat, mat, CV_BGR2RGB);

		return copy_mat_to_qimage(mat, QImage::Format_RGB888);
	}

	if(mat.type() == CV_8U)
	{
		return copy_mat_to_qimage(mat, QImage::Format_Indexed8);
	}

	if(mat.type() == CV_8UC4)
	{        
		if(qimage_format == -1)
		{
			return copy_mat_to_qimage(mat, QImage::Format_ARGB32);
		}
		else
		{
			return copy_mat_to_qimage(mat, QImage::Format(qimage_format));
		}
	}

	return QImage();
}



TrackThread::TrackThread()
{
	max_count=500;
	qlevel=0.01;
	minDist=10.;
	curx=0;cury=0;lens=300;ve=20;
	//this->md=md;
	nRunFlag=1;
	first=1;
}

TrackThread::~TrackThread(void)
{
}
int TrackThread::process(Mat &frame,Mat &output)
{
	int re=0;
	cvtColor (frame,gray,CV_BGR2GRAY);
	frame.copyTo (output);
	//特征点太少了，重新检测特征点
	//if(points[0].size ()<=10)
	{
		goodFeaturesToTrack (gray,//图片
			features,//输出特征点
			max_count,//特征点最大数目
			qlevel,//质量指标
			minDist);//最小容忍距离
		//插入检测到的特征点
		//	points[0].insert (points[0].end (),features.begin (),features.end ());
		//	initial.insert (initial.end (),features.begin (),features.end ());

		points[0]=features;
		initial=features;
	}
	//第一帧
	if(gray_prev.empty ()){
		gray.copyTo (gray_prev);
	}
	//根据前后两帧灰度图估计前一帧特征点在当前帧的位置
	//默认窗口是15*15
	calcOpticalFlowPyrLK (
		gray_prev,//前一帧灰度图
		gray,//当前帧灰度图
		points[0],//前一帧特征点位置
		points[1],//当前帧特征点位置
		status,//特征点被成功跟踪的标志
		err);//前一帧特征点点小区域和当前特征点小区域间的差，根据差的大小可删除那些运动变化剧烈的点

	int k = 0;
	//去除那些未移动的特征点
	for(int i=0;i<points[1].size();i++){
		if(acceptTrackedPoint (i))
		{
			initial[k]=initial[i];
			points[1][k++] = points[1][i];
		}
	}
	points[1].resize (k);
	initial.resize (k);
	//标记被跟踪的特征点

	for(int i=0;i<points[1].size ();i++)
	{
		//当前特征点到初始位置用直线表示
		line(output,initial[i],points[1][i],Scalar(20,150,210));
		//当前位置用圈标出
		circle(output,points[1][i],3,Scalar(120,250,10));
	}
	if(points[1].size()!=0)
		trend(output);
	//向心速度
	curx*=0.9;
	cury*=0.9;
	lens=min(output.rows,output.cols)/8;
	edge=min(output.rows,output.cols)/5;
	//控制域
	rectangle(output,
		Point(output.cols/2-lens,output.rows/2-lens),
		Point(output.cols/2+lens,output.rows/2+lens),
		Scalar(1,100,200),3);
	//追踪域
	rectangle(output,
		Point(edge,edge),
		Point(output.cols-edge,output.rows-edge),
		Scalar(10,210,1),3);
	if(first){
		if(dirx==1){
			re=4;
			line(output,
				Point(output.cols/2+lens,output.rows/2-lens),
				Point(output.cols/2+lens,output.rows/2+lens),
				Scalar(20,250,110),5);
		}
		else if(dirx==-1){
			re=3;
			line(output,
				Point(output.cols/2-lens,output.rows/2-lens),
				Point(output.cols/2-lens,output.rows/2+lens),
				Scalar(20,250,110),5);
		}
		if(diry==1){
			re=2;
			line(output,
				Point(output.cols/2-lens,output.rows/2+lens),
				Point(output.cols/2+lens,output.rows/2+lens),
				Scalar(20,250,110),5);
		}
		else if(diry==-1){
			re=1;
			line(output,
				Point(output.cols/2-lens,output.rows/2-lens),
				Point(output.cols/2+lens,output.rows/2-lens),
				Scalar(20,250,110),5);
		}
	}
	//为下一帧跟踪初始化特征点集和灰度图像
	circle(output,Point(output.cols/2+curx,output.rows/2+cury),10,Scalar(2,1,250),3);
	std::swap(points[1],points[0]);
	cv::swap(gray_prev,gray);
	return re;
}
int TrackThread::trend(Mat&output)
{
	int psize=points[1].size ();
	int x=0;
	int y=0;
	ve=0;
	//计算阈值
	for(int i=0;i<psize;i++)
	{
		ve+=abs(points[1][i].x-initial[i].x);
		ve+=abs(points[1][i].y-initial[i].y);
	}
	ve/=psize;
	int discard=0;
	//丢弃大于阈值的点
	for(int i=0;i<psize;i++)
	{
		int dx=points[1][i].x-initial[i].x;
		int dy=points[1][i].y-initial[i].y;

		if((abs(dx)+abs(dy))>ve)
			discard++;
		else
		{
			x+=dx;
			y+=dy;
		}
	}

	x/=psize-discard;
	y/=psize-discard;
	//方向特异化
	if(abs(x)>abs(y))
		x*=2;
	else
		y*=3;
	curx+=x;
	cury+=y;
	//限定范围
	if(curx>lens-10)
	{
		if(dirx!=1)
		{
			first=1;
		}
		else
		{
			first=0;
		}
		dirx=1;

		curx=lens;
	}
	else if(curx<-lens+10)
	{
		if(dirx!=-1)
		{
			first=1;
		}
		else
		{
			first=0;
		}
		dirx=-1;
		curx=-lens;
	}
	else
	{
		dirx=0;
	}
	if(cury>lens-10)
	{
		if(diry!=1)
		{
			first=1;
		}
		else
		{
			first=0;
		}
		diry=1;
		cury=lens;
	}
	else if(cury<-lens+10)
	{
		if(diry!=-1)
		{
			first=1;
		}
		else
		{
			first=0;
		}
		diry=-1;
		cury=-lens;
	}
	else
	{
		diry=0;
	}

	return 0;
}

//若特征点在前后两帧移动了，则认为该点是目标点，且可被跟踪
bool TrackThread::acceptTrackedPoint(int i)
{

	//return status[i]&&(abs(points[0][i].x-points[1][i].x)+abs(points[0][i].y-points[1][i].y) >2);
	return status[i]&&(points[1][i].x>edge)&&(points[1][i].y>edge)&&
		(points[1][i].x<gray.cols-edge)&&(points[1][i].y<gray.rows-edge)
		&&(abs(points[0][i].x-points[1][i].x)+abs(points[0][i].y-points[1][i].y) >2);
}

void TrackThread::run()
{
	VideoCapture caputure;
//	string WindowNameOutput="window";
	Mat frame;
	Mat output;
	//emit Mess(QString("test"),QString("camera open filed"));
	//return ;
	caputure.open(0);
	if(!caputure.isOpened())
	{
		emit Messquit(QString("warning"),QString("you don't have a camera, please connect one"));
		//md->mess("warning","camera open failed");
		return;
	}

//	namedWindow(WindowNameOutput);
//	cvWaitKey(1000);
	Sleep(1000);
	while(nRunFlag){
		if(!caputure.read(frame))
		{
			emit Messquit(QString("warning"),QString("please connect camera"));
			//md->mess("warning","camera read failed");
			break;
		}
		flip(frame,frame,1);
		int re=process (frame,output);

		//控制
		//if(md->ready){
			if(re==1){
				emit moveup();
			}
				//md->moveUp();
			else if(re==2){
				emit movedown();
			}
				//md->moveDown();
			else if(re==3){
				emit moveleft();
			}
				//md->moveLeft();
			else if (re==4){
				emit moveright();
			}
				//md->moveRight();
		//}
	//	imshow(WindowNameOutput,output);
	//	显示
		cvtColor(output, output, CV_BGR2RGB);
		QImage qq((unsigned char*)output.data,output.cols, output.rows,output.step,  QImage::Format_RGB888);
	//	md->setimg(QPixmap::fromImage(qq));
		emit setImg(QPixmap::fromImage(qq));
	//	if(md->exitt)
	//		break;
		Sleep(50);
//		cvWaitKey(1000);
	}
	caputure.release();
//	destroyWindow (WindowNameOutput);
}

