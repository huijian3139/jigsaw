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
	QPixmap image;   //¼ÓÔØµÄÍ¼Æ¬
	int x;                  //x×ø±ê
	int y;                  //y×ø±ê
	int num;                 //±àºÅ
};

//Q_DECLARE_METATYPE(MyLabel)
//qRegisterMetaType<MyLabel>( );
#endif // MYLABLE_H
