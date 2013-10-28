#ifndef MYLABLE_H
#define MYLABLE_H

#include <QLabel>

class MyLabel : public QLabel
{
	Q_OBJECT
public:
	explicit MyLabel(QWidget *parent = 0);
	void setImage(QPixmap img);
	QPixmap getPixmap();

	void setPosX(int x);
	void setPosY(int y);
	int getPosX();
	int getPosY();

	void setId(int i);
	int getId();

signals:

	public slots:
private:
	QPixmap image;   //���ص�ͼƬ
	int x;                  //x����
	int y;                  //y����
	int num;                 //���
};

//Q_DECLARE_METATYPE(MyLabel)
//qRegisterMetaType<MyLabel>( );
#endif // MYLABLE_H
