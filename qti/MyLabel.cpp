#include "MyLabel.h"

MyLabel::MyLabel(QWidget *parent) :
QLabel(parent)
{
}

void MyLabel::setImage(QPixmap img)
{

	image = img;

	setPixmap(img);
}

QPixmap MyLabel::getPixmap()
{
	return image;
}

void MyLabel::setPosX(int x)
{
	this->x = x;
}

void MyLabel::setPosY(int y)
{
	this->y = y;
}

int MyLabel::getPosX()
{
	return x;
}

int MyLabel::getPosY()
{
	return y;
}

void MyLabel::setId(int i)
{
	num = i;
}

int MyLabel::getId()
{
	return num;
}







