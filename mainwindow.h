#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <cstdlib>
#include <ctime>
#include <QMessageBox>
#include <QtCore>
#include <QFileInfo>
#include <QDataStream>
#include <QTextCodec>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

struct pig{
    int species;//0为黑猪，1为小花猪，2为大花白猪
    int pigpen;//猪圈编号
    int growday=0;//饲养天数
    bool ill=0;//健康情况
    bool preill=0;
    double weight;//重量
    pig *next;
};

struct pigpen{
    int sum=0;//猪的数量
    bool blackpen=false;//是否养黑猪
    pig *start=NULL;
    pig *end=NULL;
    pig *pigpenpig[10]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
       };

class MainWindow : public QMainWindow
{
    Q_OBJECT
    pigpen pigpen[100];
    int information;
    int n0=0;
    int n1=0;
    int n2=0;
    int black=0;
    int flower=0;
    int nowpage=0;
    int pen=0;
    int money=2000000;
    int total=0;
    int illpig=0;
    int day=0;
    int id=0;
    bool timerun=false;
    QFile file;
    QFile file1;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void initial();
    void initialpigfarm();
    void initialpigpen();
    void initialpig();
    void initialshop();
    void initialinformation();
    void initialrecord();
    void addrecord(QString a);
    void addblackpig();
    void addflowerpig();
    void addpig(int n,int species);
    void movepig(int n);
    void setpage();
    void disabledfarm();
    void enabledfarm();
    void piggrow();
    void sellpig();
    void illspread();
    double generaterand(double a,double b);
private:
    Ui::MainWindow *ui;
protected:
    void timerEvent(QTimerEvent *);
private slots:
    void on_play_clicked();
    void on_close_clicked();
    void on_left_clicked();
    void on_right_clicked();
    void on_pig1_clicked();
    void on_pig2_clicked();
    void on_pig3_clicked();
    void on_pig4_clicked();
    void on_pig5_clicked();
    void on_pig6_clicked();
    void on_pig7_clicked();
    void on_pig8_clicked();
    void on_pig9_clicked();
    void on_pig10_clicked();
    void on_pen1_clicked();
    void on_pen2_clicked();
    void on_pen3_clicked();
    void on_pen4_clicked();
    void on_pen5_clicked();
    void on_pen6_clicked();
    void on_pen8_clicked();
    void on_pen7_clicked();
    void on_pen9_clicked();
    void on_pen10_clicked();
    void on_pigclose_clicked();
    void on_buy_clicked();
    void on_pay_clicked();
    void on_black_clicked();
    void on_flower_clicked();
    void on_bigflower_clicked();
    void on_record_clicked();
    void on_close1_clicked();
    void on_num_clicked();
    void on_weigh_clicked();
    void on_growtime_clicked();
    void on_timebutton_clicked();
    void on_closerecord_clicked();
    void on_killill_clicked();
    void on_exit_clicked();
    void on_Continue_clicked();
};

#endif // MAINWINDOW_H
