#include "maindialog.h"
#include <QtWidgets/QApplication>
#include"trackthread.h"
//#include "QTextCodec.h"


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	//QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GB2312"));
	//QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
	MainDialog w;
	//TrackThread tt(&w);
	w.show();
	//tt.start();
	return a.exec();
}
