#ifndef MAINDIALOG_H
#define MAINDIALOG_H

#include "ui_MainDialog.h"
#include "MyLabel.h"
#include"trackthread.h"
class MainDialog : public QDialog, private Ui::MainDialog
{
	Q_OBJECT
private:

	QPixmap pixmap[9];
	int moveCount;
	MyLabel *p_label[9];
	MyLabel *p_labels[3][3];
	MyLabel *P_Null;
public:
	int ready;

	
	TrackThread tt;

	void gamebegin(QString imgPath);
	explicit MainDialog(QWidget *parent = 0);



	void cutImage(QPixmap image);
	void swapInformation(MyLabel *a, MyLabel *b);
	void initLabelImageInfor();

	void isComplete();
	void randPos();

	

	//void keyPressEvent(QKeyEvent *event);
	private slots:
		void on_pushButtonLoadImg_clicked();
		void on_pushButtonClear_clicked();
		void on_pushButtonExit_clicked();
		void on_pushButtonHelp_clicked();
		void closeEvent( QCloseEvent * event );

		void moveLeft();
		void moveRight();
		void moveUp();
		void moveDown();
		void setimg(QPixmap & qmg);
		void mess(QString  t,QString  s);
};

#endif // MAINDIALOG_H
