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
	Mat gray;  //��ǰ�Ҷ�ͼ
	Mat gray_prev;  //֮ǰ�ĻҶ�ͼ
	vector<Point2f> points[2];//ǰ����֡��������
	vector<Point2f> initial;//��ʼ������
	vector<Point2f> features;//��⵽������
	int max_count; //Ҫ���������������Ŀ
	double qlevel; //��������ָ��
	double minDist;//������֮����С���̾���
	vector<uchar> status; //��������״̬
	vector<float> err; //����ʱ�Ĵ���
	int lens;//������Χ
	int curx,cury;//��ǰλ��
	int edge;//׷�ٱ߽�
	int ve;//ÿ�����Ư���ٶ�
	int dirx,diry;
	//����������ǰ����֡�ƶ��ˣ�����Ϊ�õ���Ŀ��㣬�ҿɱ�����
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