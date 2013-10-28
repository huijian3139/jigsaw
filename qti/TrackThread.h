#pragma once
#ifndef TRACK_H
#define TRACK_H
//#include"maindialog.h"
#include"QThread"
//#include"qmessagebox.h"
#include "opencv2/opencv.hpp"
//#include <sstream>
//#include <iomanip>
//#include"maindialog.h"

#include "qimage.h"
#include <QLabel>
using namespace std;
using namespace cv;
class TrackThread: public QThread
{
	Q_OBJECT
public:
	int nRunFlag;
	int first;
	TrackThread();
	~TrackThread(void);
//	MainDialog *md;
protected:
	Mat gray;  //当前灰度图
	Mat gray_prev;  //之前的灰度图
	vector<Point2f> points[2];//前后两帧的特征点
	vector<Point2f> initial;//初始特征点
	vector<Point2f> features;//检测到的特征
	int max_count; //要跟踪特征的最大数目
	double qlevel; //特征检测的指标
	double minDist;//特征点之间最小容忍距离
	vector<uchar> status; //特征跟踪状态
	vector<float> err; //跟踪时的错误
	int lens;//控制域范围
	int curx,cury;//当前位置
	int edge;//追踪边界
	int ve;//每个点的漂移速度
	int dirx,diry;
	//若特征点在前后两帧移动了，则认为该点是目标点，且可被跟踪
	bool acceptTrackedPoint(int i);
	int trend(Mat&output);

public:
	int process(Mat &frame,Mat &output);
	void run();
signals:
	void moveleft();
	void moveright();
	void moveup();
	void movedown();
	void setImg(QPixmap & qmg);
	void Messquit(QString  t,QString  s);

};

#endif // TRACK_H