#include "MainDialog.h"
#include <QTime>
#include <QMessageBox>
#include <QDebug>
#include <QKeyEvent>
#include <QFileDialog>
#include "windows.h"
MainDialog::MainDialog(QWidget *parent) :
QDialog(parent)
{

	//void moveLeft();
	//void moveRight();
	//void moveUp();
	//void moveDown();
	//void setimg(QPixmap & qmg);
	//void mess(QString t,QString s);
	connect(&tt,SIGNAL(moveleft()),this,SLOT(moveLeft()));
	connect(&tt,SIGNAL(moveright()),this,SLOT(moveRight()));
	connect(&tt,SIGNAL(moveup()),this,SLOT(moveUp()));
	connect(&tt,SIGNAL(movedown()),this,SLOT(moveDown()));
	connect(&tt,SIGNAL(setImg(QPixmap&)),this,SLOT(setimg(QPixmap&)),Qt::DirectConnection);
	connect(&tt,SIGNAL(Messquit(QString,QString)),this,SLOT(mess(QString,QString)),Qt::QueuedConnection);
	

	ready=0;
	setupUi(this);
	moveCount = 0;
	//////////////////////////////////////////
	P_Null = new MyLabel(this);
	P_Null->setId(9);
	//////////////////////////////////////////
	//lineEdit->setEnabled(false);
	labelnum->setText(QString::number(moveCount));
	pushButtonLoadImg->setFocusPolicy(Qt::NoFocus);
	pushButtonClear->setFocusPolicy(Qt::NoFocus);

	QString imgPath="example.jpg";

	gamebegin(imgPath);

}
void MainDialog::closeEvent( QCloseEvent * event )
{

	switch( QMessageBox::information( this, tr("Quit"),
		tr("Do you really want to quit?"),
		tr("Yes"), tr("No"),
		0, 1 ) )
	{
	case 0:
		tt.nRunFlag=0;

		tt.wait();
		//Sleep(1000);
		//QMessageBox::information(0,QString("a"),QString("a"));
		event->accept();
		break;
	case 1:
	default:
		event->ignore();
		break;
	}  
}

void MainDialog::on_pushButtonExit_clicked()
{
	close();
	//exit(0);
}
void MainDialog::on_pushButtonHelp_clicked()
{
	QMessageBox::information(this,"This game is written by Hui Jian",tr("Wave your hand in front of the camera, the jigsaw will be moved according to the direction of your hand.<br> Once you finish the jigsaw, the game terminates. <br>The less steps you use, the better skill you have!<br>Have fun!"));

}
void MainDialog::on_pushButtonLoadImg_clicked()
{//�������ͼƬ
	QString imgPath = QFileDialog::getOpenFileName(0, QString::fromUtf8("open"), ".", "Images (*.png *.xpm *.jpg)");
	gamebegin(imgPath);
}
void MainDialog::gamebegin(QString imgPath)
{
	if(imgPath.length() > 0) { 
		p_label[0] = label_0;
		p_label[1] = label_1;
		p_label[2] = label_2;
		p_label[3] = label_3;
		p_label[4] = label_4;
		p_label[5] = label_5;
		p_label[6] = label_6;
		p_label[7] = label_7;
		p_label[8] = label_8;
		labelsrc->clear();
		for(int i = 0; i < 9; ++i)
		{
			p_label[i]->clear();
			p_label[i]->setImage(QPixmap());
		}
		moveCount=0;
		labelnum->setText(QString::number(0));
		ready=0;

		QPixmap img(imgPath);
		labelsrc->setPixmap(img.scaled(labelsrc->size()));
		//pushButtonLoadImg->setEnabled(false);
		////////��ͼƬ���зָ�
		cutImage(img);
		initLabelImageInfor();
		ready=1;
		tt.start();
	}
}
void MainDialog::on_pushButtonClear_clicked()
{
	moveCount=0;
	labelnum->setText(QString::number(0));
	randPos();
}

void MainDialog::initLabelImageInfor()
{
	// label_0->setImage(pixmap[0]);

	int index = 0;
	for(int i = 0; i < 3; ++i)
	{
		for(int  j = 0; j <3; ++j)
		{//��ʼ��ͼƬ����id
			if(0 != index)
			{
				p_label[index]->setImage(pixmap[index]);
			}
			else
			{
				//
			}
			p_label[index]->setId(index);
			//��ʼ����άָ��
			p_labels[i][j] = p_label[index];
			p_labels[i][j]->setPosX(j);
			p_labels[i][j]->setPosY(i);
			++index;
		}
	}

	qDebug()<<p_label[0]->getId()<<""<<p_label[1]->getId()<<""<< p_label[2]->getId();
	qDebug()<<p_label[3]->getId()<<""<<p_label[4]->getId()<<""<<p_label[5]->getId();
	qDebug()<<p_label[6]->getId()<<""<<p_label[7]->getId()<<""<<p_label[8]->getId();

	qDebug()<<p_label[0]->getPosX()<<p_label[0]->getPosY()<<" "<<p_label[1]->getPosX()<<p_label[1]->getPosY()
		<<" "<<p_label[2]->getPosX()<<p_label[2]->getPosY();
	qDebug()<<p_label[3]->getPosX()<<p_label[3]->getPosY()<<" "<<p_label[4]->getPosX()<<p_label[4]->getPosY()
		<<" "<<p_label[5]->getPosX()<<p_label[5]->getPosY();
	qDebug()<<p_label[6]->getPosX()<<p_label[6]->getPosY()<<" "<<p_label[7]->getPosX()<<p_label[7]->getPosY()
		<<" "<<p_label[8]->getPosX()<<p_label[8]->getPosY();


	randPos();
	//label_0
}
void MainDialog::cutImage(QPixmap image)
{//��300*300��ͼƬ�ֳ�9��100*100��
	image=image.scaled(QSize(300,300));
	int index = 0;
	for(int i = 0; i < 3; ++i)
	{
		for(int j = 0; j < 3; ++j)
		{
			pixmap[index] = image.copy(100*(j), 100*(i), 100, 100);
			++index;
		}
	}
}

void MainDialog::swapInformation(MyLabel *a, MyLabel *b)
{//����ͼƬ���н���id
	//����ͼƬ
	QPixmap tempImg = b->getPixmap();
	b->setImage(a->getPixmap());
	a->setImage(tempImg);

	//������д����ID����
	int tempid = b->getId();
	b->setId(a->getId());
	a->setId(tempid);

	//���� ռλ��д
	/*
	int tempX =  b->getPosX();
	int tempY =  b->getPosY();
	b->setPosX( a->getPosX());
	b->setPosY( a->getPosY());
	a->setPosX(tempX);
	a->setPosY(tempY);
	*/
	//������άָ��ָ��
	int bx =  b->getPosX();
	int by =  b->getPosY();
	int ax =  a->getPosX();
	int ay =  a->getPosY();

	p_labels[by][bx] = b;
	p_labels[ay][ax] = a;
}

void MainDialog::moveLeft()
{//��������
	qDebug()<<"press Key_Left";

	for(int i = 0; i < 3; ++i)
	{
		for(int j = 0; j < 3; ++j)
		{
			if(p_labels[i][j]->getId() == 0)
			{
				if( j+1 < 3)
				{
					swapInformation(p_labels[i][j], p_labels[i][j+1]);
					++moveCount;
					labelnum->setText(QString::number(moveCount));
					return;
				}
			}
		}
	}

	isComplete();
}

void MainDialog::moveRight()
{//��������
	qDebug()<<"press Key_Right";

	for(int i = 0; i < 3; ++i)
	{
		for(int j = 0; j < 3; ++j)
		{
			if(p_labels[i][j]->getId() == 0)
			{
				if(j-1 >= 0)
				{
					swapInformation(p_labels[i][j], p_labels[i][j-1]);
					++moveCount;
					labelnum->setText(QString::number(moveCount));
					return;
				}
			}
		}
	}

	isComplete();
}

void MainDialog::moveUp()
{//��������
	qDebug()<<"press Key_Up"<<endl;

	for(int i = 0; i < 3; ++i)
	{
		for(int j = 0; j < 3; ++j)
		{
			if(p_labels[i][j]->getId() == 0)
			{
				if(i+1 < 3)
				{
					swapInformation(p_labels[i][j], p_labels[i+1][j]);
					++moveCount;
					labelnum->setText(QString::number(moveCount));
					return;
				}
			}
		}
	}

	isComplete();
}

void MainDialog::moveDown()
{//��������
	qDebug()<<"press Key_Down";

	for(int i = 0; i < 3; ++i)
	{
		for(int j = 0; j < 3; ++j)
		{
			if(p_labels[i][j]->getId() == 0)
			{
				if(i-1 >= 0)
				{
					swapInformation(p_labels[i][j], p_labels[i-1][j]);
					++moveCount;
					labelnum->setText(QString::number(moveCount));
					return;
				}
			}
		}
	}

	isComplete();
}
void MainDialog::setimg(QPixmap & qmg)
{
	vediolabel->setPixmap(qmg.scaled(vediolabel->size()));
}
//void MainDialog::keyPressEvent(QKeyEvent *event)
//{
//	switch (event->key())
//	{
//	case Qt::Key_Up:
//		{
//			moveUp();
//			break;
//		}
//	case Qt::Key_Down:
//		{
//			moveDown();
//			break;
//		}
//	case Qt::Key_Left:
//		{
//			moveLeft();
//			break;
//		}
//	case Qt::Key_Right:
//		{
//			moveRight();
//			break;
//		}
//	default:
//		{
//			qDebug()<<"press other Key";
//			//QLabel::keyPressEvent(event);
//			break;
//		}
//	}
//}
void MainDialog::isComplete()
{
	if(label_0->getId() == 0 && label_1->getId() == 1 && label_2->getId() == 2 && label_3->getId() == 3 && label_4->getId() == 4
		&& label_5->getId() == 5 && label_6->getId() == 6 && label_7->getId() == 7 && label_8->getId() == 8)
	{
		int result = QMessageBox::information(0, QString::fromUtf8("Result"),
			QString::fromUtf8("Congratulations! Continue? <br> click OK to continue, clock Cancel to close"),
			QMessageBox::Ok,QMessageBox::Cancel);
		if(result == QMessageBox::Ok)
		{
			labelnum->clear();
			moveCount = 0;
		}
		else if(result == QMessageBox::Cancel)
		{
			this->close();
		}
		else
		{
			qDebug()<<QString::fromUtf8("choose other button");
		}
	}
}

void MainDialog::randPos()
{
	////////////////////�����
	QTime time;
	///////////////////////////
	MyLabel *p;
	for(int i = 8; i > 0; --i)
	{
		time = QTime::currentTime();
		qsrand(time.msec());
		int num = qrand() % i;
		switch(num)
		{
		case 7:
			{//��ѡ��Ҫ������������7
				p = label_7;
				break;
			}
		case 6:
			{//��ѡ��Ҫ������������6
				p = label_6;
				break;
			}
		case 5:
			{//��ѡ��Ҫ������������5
				p = label_5;
				break;
			}
		case 4:
			{//��ѡ��Ҫ������������4
				p = label_4;
				break;
			}
		case 3:
			{//��ѡ��Ҫ������������3
				p = label_3;
				break;
			}
		case 2:
			{//��ѡ��Ҫ������������2
				p = label_2;
				break;
			}
		case 1:
			{//��ѡ��Ҫ������������1
				p = label_1;
				break;
			}
		case 0:
			{//��ѡ��Ҫ������������1
				p = label_0;
				break;
			}
		default:
			{
				qDebug()<<QString::fromUtf8("��ѡ��Ҫ��������������������!");
				break;
			}
		}

		switch(i)
		{
		case 8:
			{//8�� 0~7��һ����
				swapInformation(label_8, p);
				break;
			}
		case 7:
			{//7�� 0~6��һ����
				swapInformation(label_7, p);
				break;
			}
		case 6:
			{//6 �� 0~5��һ����
				swapInformation(label_6, p);
				break;
			}
		case 5:
			{//5��0~4 ��һ����
				swapInformation(label_5, p);
				break;
			}
		case 4:
			{//4��0~3��һ����
				swapInformation(label_4, p);
				break;
			}
		case 3:
			{//3��0~2��һ����
				swapInformation(label_3, p);
				break;
			}
		case 2:
			{//2��0~1��һ����
				swapInformation(label_2, p);
				break;
			}
		case 1:
			{//1 �� 0��
				swapInformation(label_1, p);
				break;
			}
		default:
			{
				qDebug()<<"other case !";
				break;
			}
		}
	}
	//id����
	qDebug()<<p_label[0]->getId()<<""<<p_label[1]->getId()<<""<< p_label[2]->getId();
	qDebug()<<p_label[3]->getId()<<""<<p_label[4]->getId()<<""<<p_label[5]->getId();
	qDebug()<<p_label[6]->getId()<<""<<p_label[7]->getId()<<""<<p_label[8]->getId();

	qDebug()<<p_label[0]->getPosX()<<p_label[0]->getPosY()<<" "<<p_label[1]->getPosX()<<p_label[1]->getPosY()
		<<" "<<p_label[2]->getPosX()<<p_label[2]->getPosY();
	qDebug()<<p_label[3]->getPosX()<<p_label[3]->getPosY()<<" "<<p_label[4]->getPosX()<<p_label[4]->getPosY()
		<<" "<<p_label[5]->getPosX()<<p_label[5]->getPosY();
	qDebug()<<p_label[6]->getPosX()<<p_label[6]->getPosY()<<" "<<p_label[7]->getPosX()<<p_label[7]->getPosY()
		<<" "<<p_label[8]->getPosX()<<p_label[8]->getPosY();

}

void MainDialog::mess(QString  t,QString  s)
{
	QMessageBox::information(this,t,s);
	exit(1);
}