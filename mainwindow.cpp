#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include<qdebug.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    srand(time(NULL));
    ui->setupUi(this);
    initial();
}

MainWindow::~MainWindow()
{
    delete ui;
}
double MainWindow::generaterand(double a,double b){
double t=a+(double)(rand())/RAND_MAX*(b-a);
return t;
}
void MainWindow::initial(){
    //设置窗体大小及标题
    this->setFixedSize(1200,800);
    this->setWindowTitle("养猪模拟器");
    this->setWindowIcon(QIcon(":/new/prefix1/image/icon.jpg"));
    ui->background->setGeometry(0,0,1200,800);
    ui->background->setPixmap(QPixmap(":/new/prefix1/image/begin.jpg"));
    ui->play->setGeometry(184,600,326,97);
    ui->play->setFlat(true);
    ui->Continue->setGeometry(690,600,326,97);
    ui->Continue->setFlat(true);
    initialpigfarm();
    initialpigpen();
    initialpig();
    initialshop();
    initialinformation();
    initialrecord();
}
void MainWindow::initialpigfarm(){
    ui->pen1->setGeometry(200,250,120,120);
    ui->pen2->setGeometry(370,250,120,120);
    ui->pen3->setGeometry(540,250,120,120);
    ui->pen4->setGeometry(710,250,120,120);
    ui->pen5->setGeometry(880,250,120,120);
    ui->pen6->setGeometry(200,430,120,120);
    ui->pen7->setGeometry(370,430,120,120);
    ui->pen8->setGeometry(540,430,120,120);
    ui->pen9->setGeometry(710,430,120,120);
    ui->pen10->setGeometry(880,430,120,120);
    ui->pen1->setFlat(true);
    ui->pen2->setFlat(true);
    ui->pen3->setFlat(true);
    ui->pen4->setFlat(true);
    ui->pen5->setFlat(true);
    ui->pen6->setFlat(true);
    ui->pen7->setFlat(true);
    ui->pen8->setFlat(true);
    ui->pen9->setFlat(true);
    ui->pen10->setFlat(true);
    ui->pen1->setVisible(false);
    ui->pen2->setVisible(false);
    ui->pen3->setVisible(false);
    ui->pen4->setVisible(false);
    ui->pen5->setVisible(false);
    ui->pen6->setVisible(false);
    ui->pen7->setVisible(false);
    ui->pen8->setVisible(false);
    ui->pen9->setVisible(false);
    ui->pen10->setVisible(false);
    ui->exit->setGeometry(1050,650,100,100);
    ui->exit->setFlat(true);
    ui->exit->setVisible(false);
    ui->buy->setGeometry(50,650,100,100);
    ui->buy->setFlat(true);
    ui->buy->setVisible(false);
    ui->left->setFlat(true);
    ui->left->setGeometry(85,352,75,75);
    ui->left->setVisible(false);
    ui->right->setFlat(true);
    ui->right->setGeometry(1040,352,75,75);
    ui->right->setVisible(false);
    ui->black->setGeometry(300,650,120,40);
    ui->black->setVisible(false);
    ui->flower->setGeometry(450,650,120,40);
    ui->flower->setVisible(false);
    ui->bigflower->setGeometry(300,710,120,40);
    ui->bigflower->setVisible(false);
    ui->record->setGeometry(450,710,120,40);
    ui->record->setVisible(false);
    ui->pennum->setGeometry(540,570,120,40);
    ui->pennum->setText(QString("猪圈%1-%2").arg(nowpage*10+1).arg(nowpage*10+10));
    ui->pennum->setVisible(false);
    ui->money->setGeometry(1040,100,120,50);
    ui->money->setText(QString("金钱：%1").arg(money));
    ui->money->setVisible(false);
    ui->total->setGeometry(1040,175,120,50);
    ui->total->setText(QString("猪数：%1").arg(total));
    ui->total->setVisible(false);
    ui->illpig->setGeometry(40,50,120,50);
    ui->illpig->setText(QString("病猪数：%1").arg(illpig));
    ui->illpig->setVisible(false);
    ui->killill->setGeometry(40,150,120,50);
    ui->killill->setText(QString("隔离病猪（1000）"));
    ui->killill->setFlat(true);
    ui->killill->setVisible(false);
    ui->day->setGeometry(1040,25,120,50);
    ui->day->setText(QString("天数：%1").arg(day));
    ui->day->setVisible(false);
    ui->timebutton->setGeometry(970,25,50,50);
    ui->timebutton->setFlat(true);
    ui->timebutton->setVisible(false);
}
void MainWindow::initialpigpen(){
    ui->pigpen->setGeometry(372,79,454,653);
    ui->pigpen->setVisible(false);
    ui->pig1->setGeometry(122,114,69,69);
    ui->pig1->setFlat(true);
    ui->pig2->setGeometry(262,114,69,69);
    ui->pig2->setFlat(true);
    ui->pig3->setGeometry(122,201,69,69);
    ui->pig3->setFlat(true);
    ui->pig4->setGeometry(262,201,69,69);
    ui->pig4->setFlat(true);
    ui->pig5->setGeometry(122,288,69,69);
    ui->pig5->setFlat(true);
    ui->pig6->setGeometry(262,288,69,69);
    ui->pig6->setFlat(true);
    ui->pig7->setGeometry(122,375,69,69);
    ui->pig7->setFlat(true);
    ui->pig8->setGeometry(262,375,69,69);
    ui->pig8->setFlat(true);
    ui->pig9->setGeometry(122,462,69,69);
    ui->pig9->setFlat(true);
    ui->pig10->setGeometry(262,462,69,69);
    ui->pig10->setFlat(true);
    ui->close->setGeometry(414,0,40,40);
    ui->close->setFlat(true);
}
void MainWindow::initialpig(){
    ui->pig->setGeometry(500,250,200,300);
    ui->pig->setVisible(false);
    ui->species->setGeometry(50,20,100,30);
    ui->pigpennum->setGeometry(50,70,100,30);
    ui->growday->setGeometry(50,120,100,30);
    ui->ill->setGeometry(50,170,100,30);
    ui->weight->setGeometry(50,220,100,30);
    ui->pigclose->setGeometry(50,270,100,20);
    ui->pigclose->setFlat(true);
}
void MainWindow::initialshop(){
    ui->shop->setGeometry(400,100,400,600);
    ui->shop->setVisible(false);
    ui->blackpig->setGeometry(50,80,125,50);
    ui->flowerpig->setGeometry(50,210,125,50);
    ui->bigpig->setGeometry(50,340,125,50);
    ui->spinblack->setGeometry(225,80,125,50);
    ui->spinblack->setRange(0,1000);
    ui->spinflower->setGeometry(225,210,125,50);
    ui->spinflower->setRange(0,1000);
    ui->spinbigflower->setGeometry(225,340,125,50);
    ui->spinbigflower->setRange(0,1000);
    ui->pay->setGeometry(125,470,150,50);
    ui->pay->setFlat(true);
}
void MainWindow::initialinformation(){
    ui->information->setGeometry(0,0,1200,800);
    ui->information->setVisible(false);
    ui->num->setGeometry(240,600,320,200);
    ui->num->setFlat(true);
    ui->weigh->setGeometry(560,600,320,200);
    ui->weigh->setFlat(true);
    ui->growtime->setGeometry(880,600,320,200);
    ui->growtime->setFlat(true);
    ui->close1->setGeometry(0,600,240,200);
    ui->close1->setFlat(true);
    ui->column1->setVisible(false);
    ui->column2->setVisible(false);
    ui->column3->setVisible(false);
    ui->column4->setVisible(false);
    ui->column1->setFlat(true);
    ui->column2->setFlat(true);
    ui->column3->setFlat(true);
    ui->column4->setFlat(true);
    ui->label1->setVisible(false);
    ui->label2->setVisible(false);
    ui->label3->setVisible(false);
    ui->label4->setVisible(false);
    ui->label5->setVisible(false);
    ui->label6->setVisible(false);
    ui->label7->setVisible(false);
    ui->label8->setVisible(false);
}
void MainWindow::initialrecord(){
    ui->recordtext->setGeometry(0,0,1200,800);
    ui->recordtext->setVisible(false);
    ui->closerecord->setGeometry(0,500,450,300);
    ui->closerecord->setFlat(true);
    ui->farmrecord->setGeometry(450,0,750,800);
}
void MainWindow::disabledfarm(){
    ui->pen1->setDisabled(true);
    ui->pen2->setDisabled(true);
    ui->pen3->setDisabled(true);
    ui->pen4->setDisabled(true);
    ui->pen5->setDisabled(true);
    ui->pen6->setDisabled(true);
    ui->pen7->setDisabled(true);
    ui->pen8->setDisabled(true);
    ui->pen9->setDisabled(true);
    ui->pen10->setDisabled(true);
    ui->exit->setDisabled(true);
    ui->buy->setDisabled(true);
    ui->left->setDisabled(true);
    ui->right->setDisabled(true);
    ui->black->setDisabled(true);
    ui->flower->setDisabled(true);
    ui->bigflower->setDisabled(true);
    ui->record->setDisabled(true);
    ui->timebutton->setDisabled(true);
    if(timerun==true) killTimer(id);
}
void MainWindow::enabledfarm(){
    ui->pen1->setEnabled(true);
    ui->pen2->setEnabled(true);
    ui->pen3->setEnabled(true);
    ui->pen4->setEnabled(true);
    ui->pen5->setEnabled(true);
    ui->pen6->setEnabled(true);
    ui->pen7->setEnabled(true);
    ui->pen8->setEnabled(true);
    ui->pen9->setEnabled(true);
    ui->pen10->setEnabled(true);
    ui->exit->setEnabled(true);
    ui->buy->setEnabled(true);
    ui->left->setEnabled(true);
    ui->right->setEnabled(true);
    ui->black->setEnabled(true);
    ui->flower->setEnabled(true);
    ui->bigflower->setEnabled(true);
    ui->record->setEnabled(true);
    ui->timebutton->setEnabled(true);
    if(timerun==true) id=startTimer(1000);
}
void MainWindow::addrecord(QString a){
    QListWidgetItem *new_item;
    new_item=new QListWidgetItem(a,ui->farmrecord);
    ui->farmrecord->addItem(new_item);
}
void MainWindow::illspread(){
    if(day>=30){
        //每天有三百分之一的可能性凭空产生一只病猪
        srand(time(NULL));
        int virus=rand()%300;
        if(virus==1){
            //随机猪圈中随机猪感染病毒
            int viruspigpen;
            int viruspig;
            //随机有猪的猪圈
            while(pigpen[viruspigpen=rand()%100].sum==0){}
            //该猪圈中的随机一只猪
            while(pigpen[viruspigpen].pigpenpig[viruspig=rand()%10]==NULL){}
            pigpen[viruspigpen].pigpenpig[viruspig]->ill=true;
        }
        //预感染的猪全部发病
        for(int i=0;i<100;i++){
            for(int j=0;j<pigpen[i].sum;j++){
                if(pigpen[i].pigpenpig[j]->preill==true) pigpen[i].pigpenpig[j]->ill=true;
            }
        }
        //出现病猪后的传染
        for(int i=0;i<100;i++){
            bool illpig=0;
            for(int j=0;j<pigpen[i].sum;j++){
                if(pigpen[i].pigpenpig[j]->ill==true){
                    illpig = true;
                    break;
                }
            }
            if(illpig==false) continue;
            else{
                //本猪圈的传染
                for(int j=0;j<pigpen[i].sum;j++){
                    int virus1=rand()%2;
                    if(virus1==0){
                        pigpen[i].pigpenpig[j]->preill=true;
                    }
                }
                //周围猪圈的感染
                if(i>=1){
                    for(int j=0;j<pigpen[i-1].sum;j++){
                        int virus1=rand()%100;
                        if(virus1<15){
                            pigpen[i-1].pigpenpig[j]->preill=true;
                        }
                    }
                }
                if(i<=98){
                    for(int j=0;j<pigpen[i+1].sum;j++){
                        int virus1=rand()%100;
                        if(virus1<15){
                            pigpen[i+1].pigpenpig[j]->preill=true;
                        }
                    }
                }
            }
        }
    }
    setpage();
}
void MainWindow::sellpig(){
    if(day%90==0)
        {
            //卖猪
            float sum1=0;
            float sum2=0;
            float sum3=0;
            int sell0=0;
            int sell1=0;
            int sell2=0;
            for(int i=0;i<100;i++){
                for(int n=0;n<pigpen[i].sum;n++){
                    if(pigpen[i].pigpenpig[n]->growday>360||pigpen[i].pigpenpig[n]->weight>75.0){
                        if(pigpen[i].pigpenpig[n]==pigpen[i].start){
                            pigpen[i].start=pigpen[i].pigpenpig[n]->next;
                            pig *p1=pigpen[i].pigpenpig[n];
                            for(int k=n;k<pigpen[i].sum-1;k++){
                                pigpen[i].pigpenpig[k]=pigpen[i].pigpenpig[k+1];
                            }
                            pigpen[i].pigpenpig[pigpen[i].sum-1]=NULL;
                            pigpen[i].sum--;
                            total--;
                            if(pigpen[i].sum==0) pigpen[i].blackpen=false;
                           p1->next = NULL;
                           if(p1->species==0&&p1->ill==false){
                               sum1+=p1->weight*30.0;
                               money+=p1->weight*30.0;
                               sell0++;
                           }
                           else if(p1->species==1&&p1->ill==false){
                               sum2+=p1->weight*14.0;
                               money+=p1->weight*14.0;
                               sell1++;
                           }
                           else if(p1->species==2&&p1->ill==false){
                               sum3+=p1->weight*12.0;
                               money+=p1->weight*12.0;
                               sell2++;
                           }
                           //回收卖出的猪占用的内存空间
                           delete p1;
                           n--;
                        }
                        else if(pigpen[i].end==pigpen[i].pigpenpig[n]&&pigpen[i].start!=pigpen[i].pigpenpig[n]){
                            pigpen[i].end=pigpen[i].pigpenpig[n-1];
                            pigpen[i].end->next=NULL;
                            pig *p1=pigpen[i].pigpenpig[n];
                            pigpen[i].pigpenpig[n]=NULL;
                            pigpen[i].sum--;
                            total--;
                            if(p1->species==0&&p1->ill==false){
                                sum1+=p1->weight*30.0;
                                money+=p1->weight*30.0;
                                sell0++;
                            }
                            else if(p1->species==1&&p1->ill==false){
                                sum2+=p1->weight*14.0;
                                money+=p1->weight*14.0;
                                sell1++;
                            }
                            else if(p1->species==2&&p1->ill==false){
                                sum3+=p1->weight*12.0;
                                money+=p1->weight*12.0;
                                sell2++;
                            }
                            delete p1;
                        }
                        else{
                            pigpen[i].pigpenpig[n-1]->next=pigpen[i].pigpenpig[n]->next;
                            pig *p1=pigpen[i].pigpenpig[n];
                            for(int k=n;k<pigpen[i].sum-1;k++){
                                pigpen[i].pigpenpig[k]=pigpen[i].pigpenpig[k+1];
                            }
                            pigpen[i].pigpenpig[pigpen[i].sum-1]=NULL;
                            pigpen[i].sum--;
                            total--;
                            if(p1->species==0&&p1->ill==false)
                            {
                                sum1+=p1->weight*30.0;
                                money+=p1->weight*30.0;
                                sell0++;
                            }
                            else if(p1->species==1&&p1->ill==false)
                            {
                                sum2+=p1->weight*14.0;
                                money+=p1->weight*14.0;
                                sell1++;
                            }else if(p1->species==2&&p1->ill==false)
                            {
                                sum3+=p1->weight*12.0;
                                money+=p1->weight*12.0;
                                sell2++;
                            }
                            delete p1;
                            n--;
                        }
                    }
                }
            }
            int sum0=sum1+sum2+sum3;
            addrecord(QString("第%1天，卖出了%2只黑猪，%3只小花猪，%4只大花白猪,售得%5元。").arg(day).arg(sell0).arg(sell1).arg(sell2).arg(sum0));
            file.setFileName("C:/Users/LEGION/Desktop/Qtcode/pigfarm/buyandsell.txt");
            bool isok=file.open(QIODevice::WriteOnly|QIODevice::Append);
            if(isok){
                QTextStream stream(&file);
                QString str=QString("第%1天，卖出了%2只黑猪，%3只小花猪，%4只大花白猪,售得%5元。\n").arg(day).arg(sell0).arg(sell1).arg(sell2).arg(sum0);
                stream<<str.toUtf8();
            }
            file.close();
        }
    setpage();
}
void MainWindow::piggrow(){
    srand(time(NULL));
    for(int i=0;i<100;i++)
        for(int j=0;j<pigpen[i].sum;j++){
            pigpen[i].pigpenpig[j]->weight+=generaterand(0.0,1.2);
            pigpen[i].pigpenpig[j]->growday++;
        }
}
void MainWindow::timerEvent(QTimerEvent *){
    day++;
    setpage();
    piggrow();
    illspread();
    sellpig();
}
void MainWindow::addpig(int i,int s)
{

    //如果猪圈是空的
    if(pigpen[i].start==NULL)
    {
        pig *p1=new pig;
        pigpen[i].start=p1;
        pigpen[i].end=p1;
        p1->next=NULL;
        p1->weight=generaterand(20.0,50.0);
        p1->pigpen=i;
        p1->species=s;
        pigpen[i].pigpenpig[pigpen[i].sum]=p1;
        pigpen[i].sum++;
    }
    //如果猪圈有猪
    else
    {
        pig *p1=new pig;
        pigpen[i].end->next=p1;
        pigpen[i].end=p1;
        p1->next=NULL;
        p1->weight=generaterand(20.0,50.0);
        p1->pigpen=i;
        p1->species=s;
        pigpen[i].pigpenpig[pigpen[i].sum]=p1;
        pigpen[i].sum++;
    }
}
void MainWindow::addblackpig()
{
    black=0;
    while(n0)
    {
        //判断是否有空的黑猪圈
        bool t=false;
        for(int i=0;i<100;i++)
        {
            if(pigpen[i].blackpen==true&&pigpen[i].sum<10)
            {
                black=i;
                t=true;
                break;
            }
        }
        if(t==true)//如果有空的黑猪圈
        {
            for(int i=0;i<100;i++)
            {//找到黑猪最少的黑猪圈
                if(pigpen[i].blackpen==true&&pigpen[i].sum<pigpen[black].sum)
                {
                    black=i;
                }
            }
            addpig(black,0);
            n0--;
        }
        else//如果没有空的黑猪圈
        {
            for(int i=0;i<100;i++)
            {
                if(pigpen[i].blackpen==false)
                {
                    flower=i;
                    break;
                }
            }
            for(int i=0;i<100;i++)
            {
                if(pigpen[i].blackpen==false&&pigpen[i].sum<pigpen[flower].sum)
                {
                    flower=i;
                }
            }//如果不是空猪圈
            if(pigpen[flower].start!=NULL) movepig(flower);
            //如果是空猪圈
            pigpen[flower].blackpen=true;
            addpig(flower,0);
            n0--;
        }
        black=0;
        flower=0;
    }
}

void MainWindow::addflowerpig()
{
    flower=0;
    while(n1)
    {
        bool t=false;
        for(int i=0;i<100;i++)
        {
            if(pigpen[i].blackpen==false&&pigpen[i].sum<10)
            {
                flower=i;
                t=true;
                break;
            }
        }
        if(t==true){
            for(int i=0;i<100;i++)
            {
                if(pigpen[i].blackpen==false&&pigpen[i].sum<pigpen[flower].sum)
                {
                    flower=i;
                }
            }

            addpig(flower,1);
            n1--;
            flower=0;
        }
    }
    while(n2)
    {
        bool t=false;
        for(int i=0;i<100;i++)
        {
            if(pigpen[i].blackpen==false&&pigpen[i].sum<10)
            {
                flower=i;
                t=true;
                break;
            }
        }
        if(t==true){
            for(int i=0;i<100;i++)
            {
                 if(pigpen[i].blackpen==false&&pigpen[i].sum<pigpen[flower].sum)
                {
                    flower=i;
                }
            }
            addpig(flower,2);
            n2--;
            flower=0;
        }
    }
}
void MainWindow::movepig(int i)
{
    while(1)
    {
        int s;bool k=false;
        for(int j=0;j<100;j++)
        {
            if(j==i) continue;
            if(pigpen[j].blackpen==false&&pigpen[j].sum<10)
            {
                s=j;
                k=true;
                break;
            }
        }
        if(k==true){
            for(int j=0;j<100;j++)
            {
                if(j==i) continue;
                if(pigpen[j].blackpen==false&&pigpen[j].sum<pigpen[s].sum)
                {
                    s=j;
                }
            }
            if(pigpen[i].start==pigpen[i].end)
            {
                pig *p1=pigpen[i].start;
                pigpen[i].start=NULL;
                pigpen[i].end=NULL;
                pigpen[i].sum=0;
                for(int l=0;l<10;l++)
                {
                    pigpen[i].pigpenpig[l]=NULL;
                }
                pigpen[s].end->next=p1;
                pigpen[s].end=p1;
                p1->next=NULL;
                pigpen[s].pigpenpig[pigpen[s].sum]=p1;
                pigpen[s].sum++;
                p1->pigpen=s;
                break;
            }
            else
            {
                pig *p1=pigpen[i].start;
                pigpen[i].start=p1->next;
                p1->next=NULL;
                pigpen[i].sum--;
                pigpen[s].end->next=p1;
                pigpen[s].end=p1;
                pigpen[s].pigpenpig[pigpen[s].sum]=p1;
                pigpen[s].sum++;
                p1->pigpen=s;
            }
        }
        else{
            pigpen[i].start=NULL;
            pigpen[i].end=NULL;
            pigpen[i].sum=0;
            for(int l=0;l<10;l++)
            {
                pigpen[i].pigpenpig[l]=NULL;
            }
            break;
        }
    }
}
void MainWindow::setpage(){
    ui->pennum->setText(QString("猪圈%1-%2").arg(nowpage*10+1).arg(nowpage*10+10));
    ui->money->setText(QString("金钱：%1").arg(money));
    total=0;
    for(int i=0;i<100;i++) total+=pigpen[i].sum;
    ui->total->setText(QString("猪数：%1").arg(total));
    illpig=0;
    for(int i=0;i<100;i++)
        for(int j=0;j<pigpen[i].sum;j++)
            if(pigpen[i].pigpenpig[j]->ill==1) illpig++;
    ui->illpig->setText(QString("病猪数：%1").arg(illpig));
    ui->day->setText(QString("天数：%1").arg(day));
    if(timerun==false) ui->timebutton->setStyleSheet(tr("background-image: url(:/new/prefix1/image/starttime.jpg)"));
    else ui->timebutton->setStyleSheet(tr("background-image: url(:/new/prefix1/image/stoptime.jpg)"));
}
void MainWindow::on_play_clicked()
{
    ui->background->setPixmap(QPixmap(":/new/prefix1/image/background.jpg"));
    ui->play->setVisible(false);
    ui->Continue->setVisible(false);
    ui->pen1->setVisible(true);
    ui->pen2->setVisible(true);
    ui->pen3->setVisible(true);
    ui->pen4->setVisible(true);
    ui->pen5->setVisible(true);
    ui->pen6->setVisible(true);
    ui->pen7->setVisible(true);
    ui->pen8->setVisible(true);
    ui->pen9->setVisible(true);
    ui->pen10->setVisible(true);
    ui->left->setVisible(true);
    ui->right->setVisible(true);
    ui->buy->setVisible(true);
    ui->exit->setVisible(true);
    ui->black->setVisible(true);
    ui->flower->setVisible(true);
    ui->bigflower->setVisible(true);
    ui->record->setVisible(true);
    ui->pennum->setVisible(true);
    ui->money->setVisible(true);
    ui->total->setVisible(true);
    ui->illpig->setVisible(true);
    ui->killill->setVisible(true);
    ui->day->setVisible(true);
    ui->timebutton->setVisible(true);
    file.setFileName("C:/Users/LEGION/Desktop/Qtcode/pigfarm/buyandsell.txt");
    file.open(QFile::WriteOnly|QFile::Truncate);
    file.close();
    file1.setFileName("C:/Users/LEGION/Desktop/Qtcode/pigfarm/record.txt");
    file1.open(QFile::WriteOnly|QFile::Truncate);
    file1.close();
}

void MainWindow::on_close_clicked()
{
    ui->pigpen->setVisible(false);
    enabledfarm();
}

void MainWindow::on_left_clicked()
{
    nowpage=(nowpage+9)%10;
    setpage();
}

void MainWindow::on_right_clicked()
{
    nowpage=(nowpage+1)%10;
    setpage();
}

void MainWindow::on_pen1_clicked()
{
    ui->pigpen->setVisible(true);
    pen=0;
    disabledfarm();
    if(pigpen[nowpage*10].pigpenpig[0]!=NULL){
        if(pigpen[nowpage*10].pigpenpig[0]->species==0) ui->pig1->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10].pigpenpig[0]->species==1) ui->pig1->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10].pigpenpig[0]->species==2) ui->pig1->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig1->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10].pigpenpig[1]!=NULL){
        if(pigpen[nowpage*10].pigpenpig[1]->species==0) ui->pig2->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10].pigpenpig[1]->species==1) ui->pig2->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10].pigpenpig[1]->species==2) ui->pig2->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig2->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10].pigpenpig[2]!=NULL){
        if(pigpen[nowpage*10].pigpenpig[2]->species==0) ui->pig3->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10].pigpenpig[2]->species==1) ui->pig3->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10].pigpenpig[2]->species==2) ui->pig3->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig3->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10].pigpenpig[3]!=NULL){
        if(pigpen[nowpage*10].pigpenpig[3]->species==0) ui->pig4->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10].pigpenpig[3]->species==1) ui->pig4->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10].pigpenpig[3]->species==2) ui->pig4->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig4->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10].pigpenpig[4]!=NULL){
        if(pigpen[nowpage*10].pigpenpig[4]->species==0) ui->pig5->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10].pigpenpig[4]->species==1) ui->pig5->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10].pigpenpig[4]->species==2) ui->pig5->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig5->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10].pigpenpig[5]!=NULL){
        if(pigpen[nowpage*10].pigpenpig[5]->species==0) ui->pig6->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10].pigpenpig[5]->species==1) ui->pig6->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10].pigpenpig[5]->species==2) ui->pig6->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig6->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10].pigpenpig[6]!=NULL){
        if(pigpen[nowpage*10].pigpenpig[6]->species==0) ui->pig7->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10].pigpenpig[6]->species==1) ui->pig7->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10].pigpenpig[6]->species==2) ui->pig7->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig7->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10].pigpenpig[7]!=NULL){
        if(pigpen[nowpage*10].pigpenpig[7]->species==0) ui->pig8->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10].pigpenpig[7]->species==1) ui->pig8->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10].pigpenpig[7]->species==2) ui->pig8->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig8->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10].pigpenpig[8]!=NULL){
        if(pigpen[nowpage*10].pigpenpig[8]->species==0) ui->pig9->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10].pigpenpig[8]->species==1) ui->pig9->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10].pigpenpig[8]->species==2) ui->pig9->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig9->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10].pigpenpig[9]!=NULL){
        if(pigpen[nowpage*10].pigpenpig[9]->species==0) ui->pig10->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10].pigpenpig[9]->species==1) ui->pig10->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10].pigpenpig[9]->species==2) ui->pig10->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig10->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
}

void MainWindow::on_pen2_clicked()
{
    ui->pigpen->setVisible(true);
    pen=1;
    disabledfarm();
    if(pigpen[nowpage*10+1].pigpenpig[0]!=NULL){
        if(pigpen[nowpage*10+1].pigpenpig[0]->species==0) ui->pig1->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+1].pigpenpig[0]->species==1) ui->pig1->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+1].pigpenpig[0]->species==2) ui->pig1->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig1->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10+1].pigpenpig[1]!=NULL){
        if(pigpen[nowpage*10+1].pigpenpig[1]->species==0) ui->pig2->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+1].pigpenpig[1]->species==1) ui->pig2->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+1].pigpenpig[1]->species==2) ui->pig2->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig2->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10+1].pigpenpig[2]!=NULL){
        if(pigpen[nowpage*10+1].pigpenpig[2]->species==0) ui->pig3->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+1].pigpenpig[2]->species==1) ui->pig3->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+1].pigpenpig[2]->species==2) ui->pig3->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig3->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10+1].pigpenpig[3]!=NULL){
        if(pigpen[nowpage*10+1].pigpenpig[3]->species==0) ui->pig4->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+1].pigpenpig[3]->species==1) ui->pig4->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+1].pigpenpig[3]->species==2) ui->pig4->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig4->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10+1].pigpenpig[4]!=NULL){
        if(pigpen[nowpage*10+1].pigpenpig[4]->species==0) ui->pig5->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+1].pigpenpig[4]->species==1) ui->pig5->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+1].pigpenpig[4]->species==2) ui->pig5->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig5->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10+1].pigpenpig[5]!=NULL){
        if(pigpen[nowpage*10+1].pigpenpig[5]->species==0) ui->pig6->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+1].pigpenpig[5]->species==1) ui->pig6->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+1].pigpenpig[5]->species==2) ui->pig6->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig6->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10+1].pigpenpig[6]!=NULL){
        if(pigpen[nowpage*10+1].pigpenpig[6]->species==0) ui->pig7->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+1].pigpenpig[6]->species==1) ui->pig7->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+1].pigpenpig[6]->species==2) ui->pig7->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig7->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10+1].pigpenpig[7]!=NULL){
        if(pigpen[nowpage*10+1].pigpenpig[7]->species==0) ui->pig8->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+1].pigpenpig[7]->species==1) ui->pig8->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+1].pigpenpig[7]->species==2) ui->pig8->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig8->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10+1].pigpenpig[8]!=NULL){
        if(pigpen[nowpage*10+1].pigpenpig[8]->species==0) ui->pig9->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+1].pigpenpig[8]->species==1) ui->pig9->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+1].pigpenpig[8]->species==2) ui->pig9->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig9->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10+1].pigpenpig[9]!=NULL){
        if(pigpen[nowpage*10+1].pigpenpig[9]->species==0) ui->pig10->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+1].pigpenpig[9]->species==1) ui->pig10->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+1].pigpenpig[9]->species==2) ui->pig10->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig10->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
}

void MainWindow::on_pen3_clicked()
{
    ui->pigpen->setVisible(true);
    pen=2;
    disabledfarm();
    if(pigpen[nowpage*10+2].pigpenpig[0]!=NULL){
        if(pigpen[nowpage*10+2].pigpenpig[0]->species==0) ui->pig1->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+2].pigpenpig[0]->species==1) ui->pig1->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+2].pigpenpig[0]->species==2) ui->pig1->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig1->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10+2].pigpenpig[1]!=NULL){
        if(pigpen[nowpage*10+2].pigpenpig[1]->species==0) ui->pig2->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+2].pigpenpig[1]->species==1) ui->pig2->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+2].pigpenpig[1]->species==2) ui->pig2->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig2->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10+2].pigpenpig[2]!=NULL){
        if(pigpen[nowpage*10+2].pigpenpig[2]->species==0) ui->pig3->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+2].pigpenpig[2]->species==1) ui->pig3->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+2].pigpenpig[2]->species==2) ui->pig3->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig3->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10+2].pigpenpig[3]!=NULL){
        if(pigpen[nowpage*10+2].pigpenpig[3]->species==0) ui->pig4->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+2].pigpenpig[3]->species==1) ui->pig4->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+2].pigpenpig[3]->species==2) ui->pig4->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig4->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10+2].pigpenpig[4]!=NULL){
        if(pigpen[nowpage*10+2].pigpenpig[4]->species==0) ui->pig5->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+2].pigpenpig[4]->species==1) ui->pig5->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+2].pigpenpig[4]->species==2) ui->pig5->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig5->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10+2].pigpenpig[5]!=NULL){
        if(pigpen[nowpage*10+2].pigpenpig[5]->species==0) ui->pig6->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+2].pigpenpig[5]->species==1) ui->pig6->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+2].pigpenpig[5]->species==2) ui->pig6->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig6->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10+2].pigpenpig[6]!=NULL){
        if(pigpen[nowpage*10+2].pigpenpig[6]->species==0) ui->pig7->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+2].pigpenpig[6]->species==1) ui->pig7->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+2].pigpenpig[6]->species==2) ui->pig7->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig7->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10+2].pigpenpig[7]!=NULL){
        if(pigpen[nowpage*10+2].pigpenpig[7]->species==0) ui->pig8->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+2].pigpenpig[7]->species==1) ui->pig8->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+2].pigpenpig[7]->species==2) ui->pig8->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig8->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10+2].pigpenpig[8]!=NULL){
        if(pigpen[nowpage*10+2].pigpenpig[8]->species==0) ui->pig9->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+2].pigpenpig[8]->species==1) ui->pig9->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+2].pigpenpig[8]->species==2) ui->pig9->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig9->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10+2].pigpenpig[9]!=NULL){
        if(pigpen[nowpage*10+2].pigpenpig[9]->species==0) ui->pig10->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+2].pigpenpig[9]->species==1) ui->pig10->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+2].pigpenpig[9]->species==2) ui->pig10->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig10->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
}

void MainWindow::on_pen4_clicked()
{
    ui->pigpen->setVisible(true);
    pen=3;
    disabledfarm();
    if(pigpen[nowpage*10+3].pigpenpig[0]!=NULL){
        if(pigpen[nowpage*10+3].pigpenpig[0]->species==0) ui->pig1->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+3].pigpenpig[0]->species==1) ui->pig1->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+3].pigpenpig[0]->species==2) ui->pig1->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig1->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10+3].pigpenpig[1]!=NULL){
        if(pigpen[nowpage*10+3].pigpenpig[1]->species==0) ui->pig2->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+3].pigpenpig[1]->species==1) ui->pig2->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+3].pigpenpig[1]->species==2) ui->pig2->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig2->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10+3].pigpenpig[2]!=NULL){
        if(pigpen[nowpage*10+3].pigpenpig[2]->species==0) ui->pig3->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+3].pigpenpig[2]->species==1) ui->pig3->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+3].pigpenpig[2]->species==2) ui->pig3->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig3->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10+3].pigpenpig[3]!=NULL){
        if(pigpen[nowpage*10+3].pigpenpig[3]->species==0) ui->pig4->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+3].pigpenpig[3]->species==1) ui->pig4->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+3].pigpenpig[3]->species==2) ui->pig4->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig4->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10+3].pigpenpig[4]!=NULL){
        if(pigpen[nowpage*10+3].pigpenpig[4]->species==0) ui->pig5->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+3].pigpenpig[4]->species==1) ui->pig5->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+3].pigpenpig[4]->species==2) ui->pig5->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig5->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10+3].pigpenpig[5]!=NULL){
        if(pigpen[nowpage*10+3].pigpenpig[5]->species==0) ui->pig6->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+3].pigpenpig[5]->species==1) ui->pig6->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+3].pigpenpig[5]->species==2) ui->pig6->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig6->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10+3].pigpenpig[6]!=NULL){
        if(pigpen[nowpage*10+3].pigpenpig[6]->species==0) ui->pig7->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+3].pigpenpig[6]->species==1) ui->pig7->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+3].pigpenpig[6]->species==2) ui->pig7->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig7->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10+3].pigpenpig[7]!=NULL){
        if(pigpen[nowpage*10+3].pigpenpig[7]->species==0) ui->pig8->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+3].pigpenpig[7]->species==1) ui->pig8->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+3].pigpenpig[7]->species==2) ui->pig8->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig8->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10+3].pigpenpig[8]!=NULL){
        if(pigpen[nowpage*10+3].pigpenpig[8]->species==0) ui->pig9->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+3].pigpenpig[8]->species==1) ui->pig9->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+3].pigpenpig[8]->species==2) ui->pig9->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig9->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10+3].pigpenpig[9]!=NULL){
        if(pigpen[nowpage*10+3].pigpenpig[9]->species==0) ui->pig10->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+3].pigpenpig[9]->species==1) ui->pig10->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+3].pigpenpig[9]->species==2) ui->pig10->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig10->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
}

void MainWindow::on_pen5_clicked()
{
    ui->pigpen->setVisible(true);
    pen=4;
    disabledfarm();
    if(pigpen[nowpage*10+4].pigpenpig[0]!=NULL){
        if(pigpen[nowpage*10+4].pigpenpig[0]->species==0) ui->pig1->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+4].pigpenpig[0]->species==1) ui->pig1->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+4].pigpenpig[0]->species==2) ui->pig1->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig1->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10+4].pigpenpig[1]!=NULL){
        if(pigpen[nowpage*10+4].pigpenpig[1]->species==0) ui->pig2->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+4].pigpenpig[1]->species==1) ui->pig2->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+4].pigpenpig[1]->species==2) ui->pig2->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig2->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10+4].pigpenpig[2]!=NULL){
        if(pigpen[nowpage*10+4].pigpenpig[2]->species==0) ui->pig3->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+4].pigpenpig[2]->species==1) ui->pig3->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+4].pigpenpig[2]->species==2) ui->pig3->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig3->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10+4].pigpenpig[3]!=NULL){
        if(pigpen[nowpage*10+4].pigpenpig[3]->species==0) ui->pig4->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+4].pigpenpig[3]->species==1) ui->pig4->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+4].pigpenpig[3]->species==2) ui->pig4->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig4->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10+4].pigpenpig[4]!=NULL){
        if(pigpen[nowpage*10+4].pigpenpig[4]->species==0) ui->pig5->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+4].pigpenpig[4]->species==1) ui->pig5->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+4].pigpenpig[4]->species==2) ui->pig5->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig5->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10+4].pigpenpig[5]!=NULL){
        if(pigpen[nowpage*10+4].pigpenpig[5]->species==0) ui->pig6->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+4].pigpenpig[5]->species==1) ui->pig6->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+4].pigpenpig[5]->species==2) ui->pig6->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig6->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10+4].pigpenpig[6]!=NULL){
        if(pigpen[nowpage*10+4].pigpenpig[6]->species==0) ui->pig7->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+4].pigpenpig[6]->species==1) ui->pig7->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+4].pigpenpig[6]->species==2) ui->pig7->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig7->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10+4].pigpenpig[7]!=NULL){
        if(pigpen[nowpage*10+4].pigpenpig[7]->species==0) ui->pig8->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+4].pigpenpig[7]->species==1) ui->pig8->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+4].pigpenpig[7]->species==2) ui->pig8->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig8->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10+4].pigpenpig[8]!=NULL){
        if(pigpen[nowpage*10+4].pigpenpig[8]->species==0) ui->pig9->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+4].pigpenpig[8]->species==1) ui->pig9->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+4].pigpenpig[8]->species==2) ui->pig9->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig9->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10+4].pigpenpig[9]!=NULL){
        if(pigpen[nowpage*10+4].pigpenpig[9]->species==0) ui->pig10->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+4].pigpenpig[9]->species==1) ui->pig10->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+4].pigpenpig[9]->species==2) ui->pig10->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig10->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
}

void MainWindow::on_pen6_clicked()
{
    ui->pigpen->setVisible(true);
    pen=5;
    disabledfarm();
    if(pigpen[nowpage*10+5].pigpenpig[0]!=NULL){
        if(pigpen[nowpage*10+5].pigpenpig[0]->species==0) ui->pig1->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+5].pigpenpig[0]->species==1) ui->pig1->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+5].pigpenpig[0]->species==2) ui->pig1->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig1->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10+5].pigpenpig[1]!=NULL){
        if(pigpen[nowpage*10+5].pigpenpig[1]->species==0) ui->pig2->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+5].pigpenpig[1]->species==1) ui->pig2->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+5].pigpenpig[1]->species==2) ui->pig2->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig2->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10+5].pigpenpig[2]!=NULL){
        if(pigpen[nowpage*10+5].pigpenpig[2]->species==0) ui->pig3->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+5].pigpenpig[2]->species==1) ui->pig3->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+5].pigpenpig[2]->species==2) ui->pig3->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig3->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10+5].pigpenpig[3]!=NULL){
        if(pigpen[nowpage*10+5].pigpenpig[3]->species==0) ui->pig4->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+5].pigpenpig[3]->species==1) ui->pig4->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+5].pigpenpig[3]->species==2) ui->pig4->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig4->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10+5].pigpenpig[4]!=NULL){
        if(pigpen[nowpage*10+5].pigpenpig[4]->species==0) ui->pig5->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+5].pigpenpig[4]->species==1) ui->pig5->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+5].pigpenpig[4]->species==2) ui->pig5->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig5->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10+5].pigpenpig[5]!=NULL){
        if(pigpen[nowpage*10+5].pigpenpig[5]->species==0) ui->pig6->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+5].pigpenpig[5]->species==1) ui->pig6->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+5].pigpenpig[5]->species==2) ui->pig6->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig6->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10+5].pigpenpig[6]!=NULL){
        if(pigpen[nowpage*10+5].pigpenpig[6]->species==0) ui->pig7->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+5].pigpenpig[6]->species==1) ui->pig7->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+5].pigpenpig[6]->species==2) ui->pig7->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig7->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10+5].pigpenpig[7]!=NULL){
        if(pigpen[nowpage*10+5].pigpenpig[7]->species==0) ui->pig8->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+5].pigpenpig[7]->species==1) ui->pig8->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+5].pigpenpig[7]->species==2) ui->pig8->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig8->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10+5].pigpenpig[8]!=NULL){
        if(pigpen[nowpage*10+5].pigpenpig[8]->species==0) ui->pig9->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+5].pigpenpig[8]->species==1) ui->pig9->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+5].pigpenpig[8]->species==2) ui->pig9->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig9->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10+5].pigpenpig[9]!=NULL){
        if(pigpen[nowpage*10+5].pigpenpig[9]->species==0) ui->pig10->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+5].pigpenpig[9]->species==1) ui->pig10->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+5].pigpenpig[9]->species==2) ui->pig10->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig10->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
}
void MainWindow::on_pen7_clicked()
{
    ui->pigpen->setVisible(true);
    pen=6;
    disabledfarm();
    if(pigpen[nowpage*10+6].pigpenpig[0]!=NULL){
        if(pigpen[nowpage*10+6].pigpenpig[0]->species==0) ui->pig1->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+6].pigpenpig[0]->species==1) ui->pig1->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+6].pigpenpig[0]->species==2) ui->pig1->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig1->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10+6].pigpenpig[1]!=NULL){
        if(pigpen[nowpage*10+6].pigpenpig[1]->species==0) ui->pig2->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+6].pigpenpig[1]->species==1) ui->pig2->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+6].pigpenpig[1]->species==2) ui->pig2->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig2->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10+6].pigpenpig[2]!=NULL){
        if(pigpen[nowpage*10+6].pigpenpig[2]->species==0) ui->pig3->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+6].pigpenpig[2]->species==1) ui->pig3->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+6].pigpenpig[2]->species==2) ui->pig3->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig3->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10+6].pigpenpig[3]!=NULL){
        if(pigpen[nowpage*10+6].pigpenpig[3]->species==0) ui->pig4->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+6].pigpenpig[3]->species==1) ui->pig4->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+6].pigpenpig[3]->species==2) ui->pig4->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig4->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10+6].pigpenpig[4]!=NULL){
        if(pigpen[nowpage*10+6].pigpenpig[4]->species==0) ui->pig5->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+6].pigpenpig[4]->species==1) ui->pig5->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+6].pigpenpig[4]->species==2) ui->pig5->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig5->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10+6].pigpenpig[5]!=NULL){
        if(pigpen[nowpage*10+6].pigpenpig[5]->species==0) ui->pig6->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+6].pigpenpig[5]->species==1) ui->pig6->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+6].pigpenpig[5]->species==2) ui->pig6->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig6->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10+6].pigpenpig[6]!=NULL){
        if(pigpen[nowpage*10+6].pigpenpig[6]->species==0) ui->pig7->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+6].pigpenpig[6]->species==1) ui->pig7->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+6].pigpenpig[6]->species==2) ui->pig7->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig7->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10+6].pigpenpig[7]!=NULL){
        if(pigpen[nowpage*10+6].pigpenpig[7]->species==0) ui->pig8->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+6].pigpenpig[7]->species==1) ui->pig8->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+6].pigpenpig[7]->species==2) ui->pig8->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig8->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10+6].pigpenpig[8]!=NULL){
        if(pigpen[nowpage*10+6].pigpenpig[8]->species==0) ui->pig9->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+6].pigpenpig[8]->species==1) ui->pig9->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+6].pigpenpig[8]->species==2) ui->pig9->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig9->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10+6].pigpenpig[9]!=NULL){
        if(pigpen[nowpage*10+6].pigpenpig[9]->species==0) ui->pig10->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+6].pigpenpig[9]->species==1) ui->pig10->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+6].pigpenpig[9]->species==2) ui->pig10->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig10->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
}

void MainWindow::on_pen8_clicked()
{
    ui->pigpen->setVisible(true);
    pen=7;
    disabledfarm();
    if(pigpen[nowpage*10+7].pigpenpig[0]!=NULL){
        if(pigpen[nowpage*10+7].pigpenpig[0]->species==0) ui->pig1->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+7].pigpenpig[0]->species==1) ui->pig1->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+7].pigpenpig[0]->species==2) ui->pig1->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig1->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10+7].pigpenpig[1]!=NULL){
        if(pigpen[nowpage*10+7].pigpenpig[1]->species==0) ui->pig2->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+7].pigpenpig[1]->species==1) ui->pig2->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+7].pigpenpig[1]->species==2) ui->pig2->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig2->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10+7].pigpenpig[2]!=NULL){
        if(pigpen[nowpage*10+7].pigpenpig[2]->species==0) ui->pig3->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+7].pigpenpig[2]->species==1) ui->pig3->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+7].pigpenpig[2]->species==2) ui->pig3->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig3->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10+7].pigpenpig[3]!=NULL){
        if(pigpen[nowpage*10+7].pigpenpig[3]->species==0) ui->pig4->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+7].pigpenpig[3]->species==1) ui->pig4->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+7].pigpenpig[3]->species==2) ui->pig4->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig4->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10+7].pigpenpig[4]!=NULL){
        if(pigpen[nowpage*10+7].pigpenpig[4]->species==0) ui->pig5->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+7].pigpenpig[4]->species==1) ui->pig5->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+7].pigpenpig[4]->species==2) ui->pig5->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig5->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10+7].pigpenpig[5]!=NULL){
        if(pigpen[nowpage*10+7].pigpenpig[5]->species==0) ui->pig6->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+7].pigpenpig[5]->species==1) ui->pig6->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+7].pigpenpig[5]->species==2) ui->pig6->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig6->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10+7].pigpenpig[6]!=NULL){
        if(pigpen[nowpage*10+7].pigpenpig[6]->species==0) ui->pig7->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+7].pigpenpig[6]->species==1) ui->pig7->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+7].pigpenpig[6]->species==2) ui->pig7->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig7->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10+7].pigpenpig[7]!=NULL){
        if(pigpen[nowpage*10+7].pigpenpig[7]->species==0) ui->pig8->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+7].pigpenpig[7]->species==1) ui->pig8->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+7].pigpenpig[7]->species==2) ui->pig8->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig8->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10+7].pigpenpig[8]!=NULL){
        if(pigpen[nowpage*10+7].pigpenpig[8]->species==0) ui->pig9->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+7].pigpenpig[8]->species==1) ui->pig9->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+7].pigpenpig[8]->species==2) ui->pig9->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig9->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10+7].pigpenpig[9]!=NULL){
        if(pigpen[nowpage*10+7].pigpenpig[9]->species==0) ui->pig10->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+7].pigpenpig[9]->species==1) ui->pig10->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+7].pigpenpig[9]->species==2) ui->pig10->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig10->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
}

void MainWindow::on_pen9_clicked()
{
    ui->pigpen->setVisible(true);
    pen=8;
    disabledfarm();
    if(pigpen[nowpage*10+8].pigpenpig[0]!=NULL){
        if(pigpen[nowpage*10+8].pigpenpig[0]->species==0) ui->pig1->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+8].pigpenpig[0]->species==1) ui->pig1->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+8].pigpenpig[0]->species==2) ui->pig1->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig1->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10+8].pigpenpig[1]!=NULL){
        if(pigpen[nowpage*10+8].pigpenpig[1]->species==0) ui->pig2->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+8].pigpenpig[1]->species==1) ui->pig2->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+8].pigpenpig[1]->species==2) ui->pig2->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig2->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10+8].pigpenpig[2]!=NULL){
        if(pigpen[nowpage*10+8].pigpenpig[2]->species==0) ui->pig3->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+8].pigpenpig[2]->species==1) ui->pig3->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+8].pigpenpig[2]->species==2) ui->pig3->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig3->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10+8].pigpenpig[3]!=NULL){
        if(pigpen[nowpage*10+8].pigpenpig[3]->species==0) ui->pig4->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+8].pigpenpig[3]->species==1) ui->pig4->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+8].pigpenpig[3]->species==2) ui->pig4->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig4->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10+8].pigpenpig[4]!=NULL){
        if(pigpen[nowpage*10+8].pigpenpig[4]->species==0) ui->pig5->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+8].pigpenpig[4]->species==1) ui->pig5->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+8].pigpenpig[4]->species==2) ui->pig5->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig5->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10+8].pigpenpig[5]!=NULL){
        if(pigpen[nowpage*10+8].pigpenpig[5]->species==0) ui->pig6->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+8].pigpenpig[5]->species==1) ui->pig6->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+8].pigpenpig[5]->species==2) ui->pig6->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig6->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10+8].pigpenpig[6]!=NULL){
        if(pigpen[nowpage*10+8].pigpenpig[6]->species==0) ui->pig7->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+8].pigpenpig[6]->species==1) ui->pig7->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+8].pigpenpig[6]->species==2) ui->pig7->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig7->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10+8].pigpenpig[7]!=NULL){
        if(pigpen[nowpage*10+8].pigpenpig[7]->species==0) ui->pig8->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+8].pigpenpig[7]->species==1) ui->pig8->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+8].pigpenpig[7]->species==2) ui->pig8->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig8->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10+8].pigpenpig[8]!=NULL){
        if(pigpen[nowpage*10+8].pigpenpig[8]->species==0) ui->pig9->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+8].pigpenpig[8]->species==1) ui->pig9->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+8].pigpenpig[8]->species==2) ui->pig9->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig9->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10+8].pigpenpig[9]!=NULL){
        if(pigpen[nowpage*10+8].pigpenpig[9]->species==0) ui->pig10->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+8].pigpenpig[9]->species==1) ui->pig10->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+8].pigpenpig[9]->species==2) ui->pig10->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig10->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
}

void MainWindow::on_pen10_clicked()
{
    ui->pigpen->setVisible(true);
    pen=9;
    disabledfarm();
    if(pigpen[nowpage*10+9].pigpenpig[0]!=NULL){
        if(pigpen[nowpage*10+9].pigpenpig[0]->species==0) ui->pig1->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+9].pigpenpig[0]->species==1) ui->pig1->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+9].pigpenpig[0]->species==2) ui->pig1->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig1->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10+9].pigpenpig[1]!=NULL){
        if(pigpen[nowpage*10+9].pigpenpig[1]->species==0) ui->pig2->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+9].pigpenpig[1]->species==1) ui->pig2->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+9].pigpenpig[1]->species==2) ui->pig2->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig2->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10+9].pigpenpig[2]!=NULL){
        if(pigpen[nowpage*10+9].pigpenpig[2]->species==0) ui->pig3->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+9].pigpenpig[2]->species==1) ui->pig3->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+9].pigpenpig[2]->species==2) ui->pig3->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig3->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10+9].pigpenpig[3]!=NULL){
        if(pigpen[nowpage*10+9].pigpenpig[3]->species==0) ui->pig4->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+9].pigpenpig[3]->species==1) ui->pig4->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+9].pigpenpig[3]->species==2) ui->pig4->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig4->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10+9].pigpenpig[4]!=NULL){
        if(pigpen[nowpage*10+9].pigpenpig[4]->species==0) ui->pig5->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+9].pigpenpig[4]->species==1) ui->pig5->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+9].pigpenpig[4]->species==2) ui->pig5->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig5->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10+9].pigpenpig[5]!=NULL){
        if(pigpen[nowpage*10+9].pigpenpig[5]->species==0) ui->pig6->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+9].pigpenpig[5]->species==1) ui->pig6->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+9].pigpenpig[5]->species==2) ui->pig6->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig6->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10+9].pigpenpig[6]!=NULL){
        if(pigpen[nowpage*10+9].pigpenpig[6]->species==0) ui->pig7->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+9].pigpenpig[6]->species==1) ui->pig7->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+9].pigpenpig[6]->species==2) ui->pig7->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig7->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10+9].pigpenpig[7]!=NULL){
        if(pigpen[nowpage*10+9].pigpenpig[7]->species==0) ui->pig8->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+9].pigpenpig[7]->species==1) ui->pig8->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+9].pigpenpig[7]->species==2) ui->pig8->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig8->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10+9].pigpenpig[8]!=NULL){
        if(pigpen[nowpage*10+9].pigpenpig[8]->species==0) ui->pig9->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+9].pigpenpig[8]->species==1) ui->pig9->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+9].pigpenpig[8]->species==2) ui->pig9->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig9->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
    if(pigpen[nowpage*10+9].pigpenpig[9]!=NULL){
        if(pigpen[nowpage*10+9].pigpenpig[9]->species==0) ui->pig10->setStyleSheet(tr("background-image: url(:/new/prefix1/image/black.jpg);"));
        if(pigpen[nowpage*10+9].pigpenpig[9]->species==1) ui->pig10->setStyleSheet(tr("background-image: url(:/new/prefix1/image/flower.jpg);"));
        if(pigpen[nowpage*10+9].pigpenpig[9]->species==2) ui->pig10->setStyleSheet(tr("background-image: url(:/new/prefix1/image/bigflower.jpg);"));
    }
    else ui->pig10->setStyleSheet(tr("background-image: url(:/new/prefix1/image/blank.jpg);"));
}

void MainWindow::on_pig1_clicked()
{
    if(pigpen[nowpage*10+pen].pigpenpig[0]!=NULL){
    ui->pigpen->setVisible(false);
    ui->pig->setVisible(true);
    if(pigpen[nowpage*10+pen].pigpenpig[0]->species==0)
    ui->species->setText(QString("种类：黑猪"));
    if(pigpen[nowpage*10+pen].pigpenpig[0]->species==1)
    ui->species->setText(QString("种类：小花猪"));
    if(pigpen[nowpage*10+pen].pigpenpig[0]->species==2)
    ui->species->setText(QString("种类：大花白猪"));
    ui->pigpennum->setText(QString("猪圈编号：%1").arg(pigpen[nowpage*10+pen].pigpenpig[0]->pigpen));
    ui->growday->setText(QString("饲养天数：%1").arg(pigpen[nowpage*10+pen].pigpenpig[0]->growday));
    if(pigpen[nowpage*10+pen].pigpenpig[0]->ill) ui->ill->setText("健康情况：生病");
    else ui->ill->setText("健康情况：健康");
    ui->weight->setText(QString("重量：%1").arg(pigpen[nowpage*10+pen].pigpenpig[0]->weight));
    }
}

void MainWindow::on_pig2_clicked()
{
    if(pigpen[nowpage*10+pen].pigpenpig[1]!=NULL){
    ui->pigpen->setVisible(false);
    ui->pig->setVisible(true);
    if(pigpen[nowpage*10+pen].pigpenpig[1]->species==0)
    ui->species->setText(QString("种类：黑猪"));
    if(pigpen[nowpage*10+pen].pigpenpig[1]->species==1)
    ui->species->setText(QString("种类：小花猪"));
    if(pigpen[nowpage*10+pen].pigpenpig[1]->species==2)
    ui->species->setText(QString("种类：大花白猪"));
    ui->pigpennum->setText(QString("猪圈编号：%1").arg(pigpen[nowpage*10+pen].pigpenpig[1]->pigpen));
    ui->growday->setText(QString("饲养天数：%1").arg(pigpen[nowpage*10+pen].pigpenpig[1]->growday));
    if(pigpen[nowpage*10+pen].pigpenpig[1]->ill) ui->ill->setText("健康情况：生病");
    else ui->ill->setText("健康情况：健康");
    ui->weight->setText(QString("重量：%1").arg(pigpen[nowpage*10+pen].pigpenpig[1]->weight));
    }
}

void MainWindow::on_pig3_clicked()
{
    if(pigpen[nowpage*10+pen].pigpenpig[2]!=NULL){
    ui->pigpen->setVisible(false);
    ui->pig->setVisible(true);
    if(pigpen[nowpage*10+pen].pigpenpig[2]->species==0)
    ui->species->setText(QString("种类：黑猪"));
    if(pigpen[nowpage*10+pen].pigpenpig[2]->species==1)
    ui->species->setText(QString("种类：小花猪"));
    if(pigpen[nowpage*10+pen].pigpenpig[2]->species==2)
    ui->species->setText(QString("种类：大花白猪"));
    ui->pigpennum->setText(QString("猪圈编号：%1").arg(pigpen[nowpage*10+pen].pigpenpig[2]->pigpen));
    ui->growday->setText(QString("饲养天数：%1").arg(pigpen[nowpage*10+pen].pigpenpig[2]->growday));
    if(pigpen[nowpage*10+pen].pigpenpig[2]->ill) ui->ill->setText("健康情况：生病");
    else ui->ill->setText("健康情况：健康");
    ui->weight->setText(QString("重量：%1").arg(pigpen[nowpage*10+pen].pigpenpig[2]->weight));
    }
}

void MainWindow::on_pig4_clicked()
{
    if(pigpen[nowpage*10+pen].pigpenpig[3]!=NULL){
    ui->pigpen->setVisible(false);
    ui->pig->setVisible(true);
    if(pigpen[nowpage*10+pen].pigpenpig[3]->species==0)
    ui->species->setText(QString("种类：黑猪"));
    if(pigpen[nowpage*10+pen].pigpenpig[3]->species==1)
    ui->species->setText(QString("种类：小花猪"));
    if(pigpen[nowpage*10+pen].pigpenpig[3]->species==2)
    ui->species->setText(QString("种类：大花白猪"));
    ui->pigpennum->setText(QString("猪圈编号：%1").arg(pigpen[nowpage*10+pen].pigpenpig[3]->pigpen));
    ui->growday->setText(QString("饲养天数：%1").arg(pigpen[nowpage*10+pen].pigpenpig[3]->growday));
    if(pigpen[nowpage*10+pen].pigpenpig[3]->ill) ui->ill->setText("健康情况：生病");
    else ui->ill->setText("健康情况：健康");
    ui->weight->setText(QString("重量：%1").arg(pigpen[nowpage*10+pen].pigpenpig[3]->weight));
    }
}

void MainWindow::on_pig5_clicked()
{
    if(pigpen[nowpage*10+pen].pigpenpig[4]!=NULL){
    ui->pigpen->setVisible(false);
    ui->pig->setVisible(true);
    if(pigpen[nowpage*10+pen].pigpenpig[4]->species==0)
    ui->species->setText(QString("种类：黑猪"));
    if(pigpen[nowpage*10+pen].pigpenpig[4]->species==1)
    ui->species->setText(QString("种类：小花猪"));
    if(pigpen[nowpage*10+pen].pigpenpig[4]->species==2)
    ui->species->setText(QString("种类：大花白猪"));
    ui->pigpennum->setText(QString("猪圈编号：%1").arg(pigpen[nowpage*10+pen].pigpenpig[4]->pigpen));
    ui->growday->setText(QString("饲养天数：%1").arg(pigpen[nowpage*10+pen].pigpenpig[4]->growday));
    if(pigpen[nowpage*10+pen].pigpenpig[4]->ill) ui->ill->setText("健康情况：生病");
    else ui->ill->setText("健康情况：健康");
    ui->weight->setText(QString("重量：%1").arg(pigpen[nowpage*10+pen].pigpenpig[4]->weight));
    }
}

void MainWindow::on_pig6_clicked()
{
    if(pigpen[nowpage*10+pen].pigpenpig[5]!=NULL){
    ui->pigpen->setVisible(false);
    ui->pig->setVisible(true);
    if(pigpen[nowpage*10+pen].pigpenpig[5]->species==0)
    ui->species->setText(QString("种类：黑猪"));
    if(pigpen[nowpage*10+pen].pigpenpig[5]->species==1)
    ui->species->setText(QString("种类：小花猪"));
    if(pigpen[nowpage*10+pen].pigpenpig[5]->species==2)
    ui->species->setText(QString("种类：大花白猪"));
    ui->pigpennum->setText(QString("猪圈编号：%1").arg(pigpen[nowpage*10+pen].pigpenpig[5]->pigpen));
    ui->growday->setText(QString("饲养天数：%1").arg(pigpen[nowpage*10+pen].pigpenpig[5]->growday));
    if(pigpen[nowpage*10+pen].pigpenpig[5]->ill) ui->ill->setText("健康情况：生病");
    else ui->ill->setText("健康情况：健康");
    ui->weight->setText(QString("重量：%1").arg(pigpen[nowpage*10+pen].pigpenpig[5]->weight));
    }
}

void MainWindow::on_pig7_clicked()
{
    if(pigpen[nowpage*10+pen].pigpenpig[6]!=NULL){
    ui->pigpen->setVisible(false);
    ui->pig->setVisible(true);
    if(pigpen[nowpage*10+pen].pigpenpig[6]->species==0)
    ui->species->setText(QString("种类：黑猪"));
    if(pigpen[nowpage*10+pen].pigpenpig[6]->species==1)
    ui->species->setText(QString("种类：小花猪"));
    if(pigpen[nowpage*10+pen].pigpenpig[6]->species==2)
    ui->species->setText(QString("种类：大花白猪"));
    ui->pigpennum->setText(QString("猪圈编号：%1").arg(pigpen[nowpage*10+pen].pigpenpig[6]->pigpen));
    ui->growday->setText(QString("饲养天数：%1").arg(pigpen[nowpage*10+pen].pigpenpig[6]->growday));
    if(pigpen[nowpage*10+pen].pigpenpig[6]->ill) ui->ill->setText("健康情况：生病");
    else ui->ill->setText("健康情况：健康");
    ui->weight->setText(QString("重量：%1").arg(pigpen[nowpage*10+pen].pigpenpig[6]->weight));
    }
}

void MainWindow::on_pig8_clicked()
{
    if(pigpen[nowpage*10+pen].pigpenpig[7]!=NULL){
    ui->pigpen->setVisible(false);
    ui->pig->setVisible(true);
    if(pigpen[nowpage*10+pen].pigpenpig[7]->species==0)
    ui->species->setText(QString("种类：黑猪"));
    if(pigpen[nowpage*10+pen].pigpenpig[7]->species==1)
    ui->species->setText(QString("种类：小花猪"));
    if(pigpen[nowpage*10+pen].pigpenpig[7]->species==2)
    ui->species->setText(QString("种类：大花白猪"));
    ui->pigpennum->setText(QString("猪圈编号：%1").arg(pigpen[nowpage*10+pen].pigpenpig[7]->pigpen));
    ui->growday->setText(QString("饲养天数：%1").arg(pigpen[nowpage*10+pen].pigpenpig[7]->growday));
    if(pigpen[nowpage*10+pen].pigpenpig[7]->ill) ui->ill->setText("健康情况：生病");
    else ui->ill->setText("健康情况：健康");
    ui->weight->setText(QString("重量：%1").arg(pigpen[nowpage*10+pen].pigpenpig[7]->weight));
    }
}

void MainWindow::on_pig9_clicked()
{
    if(pigpen[nowpage*10+pen].pigpenpig[8]!=NULL){
    ui->pigpen->setVisible(false);
    ui->pig->setVisible(true);
    if(pigpen[nowpage*10+pen].pigpenpig[8]->species==0)
    ui->species->setText(QString("种类：黑猪"));
    if(pigpen[nowpage*10+pen].pigpenpig[8]->species==1)
    ui->species->setText(QString("种类：小花猪"));
    if(pigpen[nowpage*10+pen].pigpenpig[8]->species==2)
    ui->species->setText(QString("种类：大花白猪"));
    ui->pigpennum->setText(QString("猪圈编号：%1").arg(pigpen[nowpage*10+pen].pigpenpig[8]->pigpen));
    ui->growday->setText(QString("饲养天数：%1").arg(pigpen[nowpage*10+pen].pigpenpig[8]->growday));
    if(pigpen[nowpage*10+pen].pigpenpig[8]->ill) ui->ill->setText("健康情况：生病");
    else ui->ill->setText("健康情况：健康");
    ui->weight->setText(QString("重量：%1").arg(pigpen[nowpage*10+pen].pigpenpig[8]->weight));
    }
}

void MainWindow::on_pig10_clicked()
{
    if(pigpen[nowpage*10+pen].pigpenpig[9]!=NULL){
    ui->pigpen->setVisible(false);
    ui->pig->setVisible(true);
    if(pigpen[nowpage*10+pen].pigpenpig[9]->species==0)
    ui->species->setText(QString("种类：黑猪"));
    if(pigpen[nowpage*10+pen].pigpenpig[9]->species==1)
    ui->species->setText(QString("种类：小花猪"));
    if(pigpen[nowpage*10+pen].pigpenpig[9]->species==2)
    ui->species->setText(QString("种类：大花白猪"));
    ui->pigpennum->setText(QString("猪圈编号：%1").arg(pigpen[nowpage*10+pen].pigpenpig[9]->pigpen));
    ui->growday->setText(QString("饲养天数：%1").arg(pigpen[nowpage*10+pen].pigpenpig[9]->growday));
    if(pigpen[nowpage*10+pen].pigpenpig[9]->ill) ui->ill->setText("健康情况：生病");
    else ui->ill->setText("健康情况：健康");
    ui->weight->setText(QString("重量：%1").arg(pigpen[nowpage*10+pen].pigpenpig[9]->weight));
    }
}

void MainWindow::on_pigclose_clicked()
{
    ui->pig->setVisible(false);
    ui->pigpen->setVisible(true);
}

void MainWindow::on_buy_clicked()
{
    ui->shop->setVisible(true);
    disabledfarm();
}

void MainWindow::on_pay_clicked()
{
    int costblack=0,costflower=0,costbigflower=0;
    n0=ui->spinblack->value();
    n1=ui->spinflower->value();
    n2=ui->spinbigflower->value();
    costblack=n0*600;
    costflower=n1*400;
    costbigflower=n2*300;
    if((costblack+costflower+costbigflower)>money) QMessageBox::information(this,"提示",QString("<h4>金钱不足！</h4>"));
    else{
        if((n0+n1+n2)>(1000-total)) QMessageBox::information(this,"提示",QString("<h4>猪圈没有足够的空位！</h4>"));
        else{
        money-=costblack+costflower+costbigflower;
        addrecord(QString("第%1天，购买了%2只黑猪,%3只小花猪，%4只大花白猪。").arg(day).arg(n0).arg(n1).arg(n2));
        file.setFileName("C:/Users/LEGION/Desktop/Qtcode/pigfarm/buyandsell.txt");
        bool isok=file.open(QIODevice::WriteOnly|QIODevice::Append);
        if(isok){
            QTextStream stream(&file);
            QString str=QString("第%1天，购买了%2只黑猪,%3只小花猪，%4只大花白猪。\n").arg(day).arg(n0).arg(n1).arg(n2);
            stream<<str.toUtf8();
        }
        file.close();
        addflowerpig();
        addblackpig();
        ui->shop->setVisible(false);
        enabledfarm();
        setpage();
        }
    }
}

void MainWindow::on_black_clicked()
{
    ui->information->setVisible(true);
    information=0;
    ui->pen1->setVisible(false);
    ui->pen2->setVisible(false);
    ui->pen3->setVisible(false);
    ui->pen4->setVisible(false);
    ui->pen5->setVisible(false);
    ui->pen6->setVisible(false);
    ui->pen7->setVisible(false);
    ui->pen8->setVisible(false);
    ui->pen9->setVisible(false);
    ui->pen10->setVisible(false);
    ui->left->setVisible(false);
    ui->right->setVisible(false);
    ui->buy->setVisible(false);
    ui->exit->setVisible(false);
    ui->black->setVisible(false);
    ui->flower->setVisible(false);
    ui->bigflower->setVisible(false);
    ui->record->setVisible(false);
    ui->pennum->setVisible(false);
    ui->money->setVisible(false);
    ui->total->setVisible(false);
    ui->illpig->setVisible(false);
    ui->killill->setVisible(false);
    ui->day->setVisible(false);
    ui->timebutton->setVisible(false);
    disabledfarm();
}

void MainWindow::on_flower_clicked()
{
    ui->information->setVisible(true);
    information=1;
    ui->pen1->setVisible(false);
    ui->pen2->setVisible(false);
    ui->pen3->setVisible(false);
    ui->pen4->setVisible(false);
    ui->pen5->setVisible(false);
    ui->pen6->setVisible(false);
    ui->pen7->setVisible(false);
    ui->pen8->setVisible(false);
    ui->pen9->setVisible(false);
    ui->pen10->setVisible(false);
    ui->left->setVisible(false);
    ui->right->setVisible(false);
    ui->buy->setVisible(false);
    ui->exit->setVisible(false);
    ui->black->setVisible(false);
    ui->flower->setVisible(false);
    ui->bigflower->setVisible(false);
    ui->record->setVisible(false);
    ui->pennum->setVisible(false);
    ui->money->setVisible(false);
    ui->total->setVisible(false);
    ui->illpig->setVisible(false);
    ui->killill->setVisible(false);
    ui->day->setVisible(false);
    ui->timebutton->setVisible(false);
    disabledfarm();
}

void MainWindow::on_bigflower_clicked()
{
    ui->information->setVisible(true);
    information=2;
    ui->pen1->setVisible(false);
    ui->pen2->setVisible(false);
    ui->pen3->setVisible(false);
    ui->pen4->setVisible(false);
    ui->pen5->setVisible(false);
    ui->pen6->setVisible(false);
    ui->pen7->setVisible(false);
    ui->pen8->setVisible(false);
    ui->pen9->setVisible(false);
    ui->pen10->setVisible(false);
    ui->left->setVisible(false);
    ui->right->setVisible(false);
    ui->buy->setVisible(false);
    ui->exit->setVisible(false);
    ui->black->setVisible(false);
    ui->flower->setVisible(false);
    ui->bigflower->setVisible(false);
    ui->record->setVisible(false);
    ui->pennum->setVisible(false);
    ui->money->setVisible(false);
    ui->total->setVisible(false);
    ui->illpig->setVisible(false);
    ui->killill->setVisible(false);
    ui->day->setVisible(false);
    ui->timebutton->setVisible(false);
    disabledfarm();
}

void MainWindow::on_record_clicked()
{
    ui->recordtext->setVisible(true);
    disabledfarm();
    ui->pen1->setVisible(false);
    ui->pen2->setVisible(false);
    ui->pen3->setVisible(false);
    ui->pen4->setVisible(false);
    ui->pen5->setVisible(false);
    ui->pen6->setVisible(false);
    ui->pen7->setVisible(false);
    ui->pen8->setVisible(false);
    ui->pen9->setVisible(false);
    ui->pen10->setVisible(false);
    ui->left->setVisible(false);
    ui->right->setVisible(false);
    ui->buy->setVisible(false);
    ui->exit->setVisible(false);
    ui->black->setVisible(false);
    ui->flower->setVisible(false);
    ui->bigflower->setVisible(false);
    ui->record->setVisible(false);
    ui->pennum->setVisible(false);
    ui->money->setVisible(false);
    ui->total->setVisible(false);
    ui->illpig->setVisible(false);
    ui->killill->setVisible(false);
    ui->day->setVisible(false);
    ui->timebutton->setVisible(false);
}

void MainWindow::on_close1_clicked()
{
    initialinformation();
    ui->play->setVisible(false);
    ui->Continue->setVisible(false);
    ui->pen1->setVisible(true);
    ui->pen2->setVisible(true);
    ui->pen3->setVisible(true);
    ui->pen4->setVisible(true);
    ui->pen5->setVisible(true);
    ui->pen6->setVisible(true);
    ui->pen7->setVisible(true);
    ui->pen8->setVisible(true);
    ui->pen9->setVisible(true);
    ui->pen10->setVisible(true);
    ui->left->setVisible(true);
    ui->right->setVisible(true);
    ui->buy->setVisible(true);
    ui->exit->setVisible(true);
    ui->black->setVisible(true);
    ui->flower->setVisible(true);
    ui->bigflower->setVisible(true);
    ui->record->setVisible(true);
    ui->pennum->setVisible(true);
    ui->money->setVisible(true);
    ui->total->setVisible(true);
    ui->illpig->setVisible(true);
    ui->killill->setVisible(true);
    ui->day->setVisible(true);
    ui->timebutton->setVisible(true);
    enabledfarm();
}

void MainWindow::on_num_clicked()
{
    int t=0;
    if(information==0){
        ui->label5->setText("黑猪");
        for(int i=0;i<100;i++){
            if(pigpen[i].blackpen==true) t+=pigpen[i].sum;
        }
    }
    if(information==1){
        ui->label5->setText("小花猪");
        for(int i=0;i<100;i++){
            if(pigpen[i].blackpen==false) for(int j=0;j<10;j++){
                if(pigpen[i].pigpenpig[j]!=NULL&&pigpen[i].pigpenpig[j]->species==1) t++;
            }
        }
    }
    if(information==2){
        ui->label5->setText("大花白猪");
        for(int i=0;i<100;i++){
            if(pigpen[i].blackpen==false) for(int j=0;j<10;j++){
                if(pigpen[i].pigpenpig[j]!=NULL&&pigpen[i].pigpenpig[j]->species==2) t++;
            }
        }
    }
    ui->column1->setGeometry(240,250,t*2/3,100);
    ui->column1->setVisible(true);
    ui->label1->setGeometry(240+t*2/3,250,965-t*2/3,100);
    ui->label1->setVisible(true);
    ui->label1->setText(QString("%1").arg(t));
    ui->label5->setGeometry(120,250,110,100);
    ui->label5->setVisible(true);
    ui->column2->setVisible(false);
    ui->column3->setVisible(false);
    ui->column4->setVisible(false);
    ui->label2->setVisible(false);
    ui->label3->setVisible(false);
    ui->label4->setVisible(false);
    ui->label6->setVisible(false);
    ui->label7->setVisible(false);
    ui->label8->setVisible(false);
}

void MainWindow::on_weigh_clicked()
{
    int a=0,b=0,c=0;
    if(information==0){
        for(int i=0;i<100;i++){
            if(pigpen[i].blackpen==true) for(int j=0;j<10;j++){
                if(pigpen[i].pigpenpig[j]!=NULL&&pigpen[i].pigpenpig[j]->weight<50.5) a++;
                if(pigpen[i].pigpenpig[j]!=NULL&&pigpen[i].pigpenpig[j]->weight>80.5) c++;
                if(pigpen[i].pigpenpig[j]!=NULL&&pigpen[i].pigpenpig[j]->weight>=50.5&&pigpen[i].pigpenpig[j]->weight<=80.5) b++;
            }
        }
    }
    if(information==1){
        for(int i=0;i<100;i++){
            if(pigpen[i].blackpen==false) for(int j=0;j<10;j++){
                if(pigpen[i].pigpenpig[j]!=NULL&&pigpen[i].pigpenpig[j]->weight<50.5&&pigpen[i].pigpenpig[j]->species==1) a++;
                if(pigpen[i].pigpenpig[j]!=NULL&&pigpen[i].pigpenpig[j]->weight>80.5&&pigpen[i].pigpenpig[j]->species==1) c++;
                if(pigpen[i].pigpenpig[j]!=NULL&&pigpen[i].pigpenpig[j]->weight>=50.5&&pigpen[i].pigpenpig[j]->weight<=80.5&&pigpen[i].pigpenpig[j]->species==1) b++;
            }
        }
    }
    if(information==2){
        for(int i=0;i<100;i++){
            if(pigpen[i].blackpen==false) for(int j=0;j<10;j++){
                if(pigpen[i].pigpenpig[j]!=NULL&&pigpen[i].pigpenpig[j]->weight<50.5&&pigpen[i].pigpenpig[j]->species==2) a++;
                if(pigpen[i].pigpenpig[j]!=NULL&&pigpen[i].pigpenpig[j]->weight>80.5&&pigpen[i].pigpenpig[j]->species==2) c++;
                if(pigpen[i].pigpenpig[j]!=NULL&&pigpen[i].pigpenpig[j]->weight>=50.5&&pigpen[i].pigpenpig[j]->weight<=80.5&&pigpen[i].pigpenpig[j]->species==2) b++;
            }
        }
    }
    ui->column1->setGeometry(240,75,a,100);
    ui->column1->setVisible(true);
    ui->label1->setGeometry(240+a,75,965-a,100);
    ui->label1->setVisible(true);
    ui->column2->setGeometry(240,250,b,100);
    ui->column2->setVisible(true);
    ui->label2->setGeometry(240+b,250,965-b,100);
    ui->label2->setVisible(true);
    ui->column3->setGeometry(240,425,c,100);
    ui->column3->setVisible(true);
    ui->label3->setGeometry(240+c,425,965-c,100);
    ui->label3->setVisible(true);
    ui->label1->setText(QString("%1").arg(a));
    ui->label2->setText(QString("%1").arg(b));
    ui->label3->setText(QString("%1").arg(c));
    ui->label5->setGeometry(80,75,120,100);
    ui->label5->setText("[20,50.5)");
    ui->label5->setVisible(true);
    ui->label6->setGeometry(80,250,120,100);
    ui->label6->setText("[50.5,80.5]");
    ui->label6->setVisible(true);
    ui->label7->setGeometry(80,425,120,100);
    ui->label7->setText("(80.5,111]");
    ui->label7->setVisible(true);
    ui->column4->setVisible(false);
    ui->label4->setVisible(false);
    ui->label8->setVisible(false);
}

void MainWindow::on_growtime_clicked()
{
    int a=0,b=0,c=0,d=0;
    if(information==0){
        for(int i=0;i<100;i++){
            if(pigpen[i].blackpen==true) for(int j=0;j<10;j++){
                if(pigpen[i].pigpenpig[j]!=NULL&&pigpen[i].pigpenpig[j]->growday<112) a++;
                if(pigpen[i].pigpenpig[j]!=NULL&&pigpen[i].pigpenpig[j]->growday>=338) d++;
                if(pigpen[i].pigpenpig[j]!=NULL&&pigpen[i].pigpenpig[j]->growday>=112&&pigpen[i].pigpenpig[j]->growday<225) b++;
                if(pigpen[i].pigpenpig[j]!=NULL&&pigpen[i].pigpenpig[j]->growday>=225&&pigpen[i].pigpenpig[j]->growday<338) c++;
            }
        }
    }
    if(information==1){
        for(int i=0;i<100;i++){
            if(pigpen[i].blackpen==false) for(int j=0;j<10;j++){
                if(pigpen[i].pigpenpig[j]!=NULL&&pigpen[i].pigpenpig[j]->growday<112&&pigpen[i].pigpenpig[j]->species==1) a++;
                if(pigpen[i].pigpenpig[j]!=NULL&&pigpen[i].pigpenpig[j]->growday>=338&&pigpen[i].pigpenpig[j]->species==1) d++;
                if(pigpen[i].pigpenpig[j]!=NULL&&pigpen[i].pigpenpig[j]->growday>=112&&pigpen[i].pigpenpig[j]->growday<225&&pigpen[i].pigpenpig[j]->species==1) b++;
                if(pigpen[i].pigpenpig[j]!=NULL&&pigpen[i].pigpenpig[j]->growday>=225&&pigpen[i].pigpenpig[j]->growday<338&&pigpen[i].pigpenpig[j]->species==1) c++;
            }
        }
    }
    if(information==2){
        for(int i=0;i<100;i++){
            if(pigpen[i].blackpen==false) for(int j=0;j<10;j++){
                if(pigpen[i].pigpenpig[j]!=NULL&&pigpen[i].pigpenpig[j]->growday<112&&pigpen[i].pigpenpig[j]->species==2) a++;
                if(pigpen[i].pigpenpig[j]!=NULL&&pigpen[i].pigpenpig[j]->growday>=338&&pigpen[i].pigpenpig[j]->species==2) d++;
                if(pigpen[i].pigpenpig[j]!=NULL&&pigpen[i].pigpenpig[j]->growday>=112&&pigpen[i].pigpenpig[j]->growday<225&&pigpen[i].pigpenpig[j]->species==2) b++;
                if(pigpen[i].pigpenpig[j]!=NULL&&pigpen[i].pigpenpig[j]->growday>=225&&pigpen[i].pigpenpig[j]->growday<338&&pigpen[i].pigpenpig[j]->species==2) c++;
            }
        }
    }
    ui->column1->setGeometry(240,40,a,100);
    ui->column1->setVisible(true);
    ui->label1->setGeometry(240+a,40,965-a,100);
    ui->label1->setVisible(true);
    ui->column2->setGeometry(240,180,b,100);
    ui->column2->setVisible(true);
    ui->label2->setGeometry(240+b,180,965-b,100);
    ui->label2->setVisible(true);
    ui->column3->setGeometry(240,320,c,100);
    ui->column3->setVisible(true);
    ui->label3->setGeometry(240+c,320,965-c,100);
    ui->label3->setVisible(true);
    ui->column4->setGeometry(240,460,c,100);
    ui->column4->setVisible(true);
    ui->label4->setGeometry(240+c,460,965-c,100);
    ui->label4->setVisible(true);
    ui->label1->setText(QString("%1").arg(a));
    ui->label2->setText(QString("%1").arg(b));
    ui->label3->setText(QString("%1").arg(c));
    ui->label4->setText(QString("%1").arg(d));
    ui->label5->setGeometry(80,40,120,100);
    ui->label5->setText("[0,112)");
    ui->label5->setVisible(true);
    ui->label6->setGeometry(80,180,120,100);
    ui->label6->setText("[112,225)");
    ui->label6->setVisible(true);
    ui->label7->setGeometry(80,320,120,100);
    ui->label7->setText("[225,338)");
    ui->label7->setVisible(true);
    ui->label8->setGeometry(80,460,120,100);
    ui->label8->setText("[338,450)");
    ui->label8->setVisible(true);
}

void MainWindow::on_timebutton_clicked()
{
    if(timerun==false){
        ui->timebutton->setStyleSheet(tr("background-image: url(:/new/prefix1/image/stoptime.jpg)"));
        timerun=true;
        id=startTimer(1000);
    }
    else{
        ui->timebutton->setStyleSheet(tr("background-image: url(:/new/prefix1/image/starttime.jpg)"));
        timerun=false;
        killTimer(id);
    }
}

void MainWindow::on_closerecord_clicked()
{
    ui->recordtext->setVisible(false);
    ui->pen1->setVisible(true);
    ui->pen2->setVisible(true);
    ui->pen3->setVisible(true);
    ui->pen4->setVisible(true);
    ui->pen5->setVisible(true);
    ui->pen6->setVisible(true);
    ui->pen7->setVisible(true);
    ui->pen8->setVisible(true);
    ui->pen9->setVisible(true);
    ui->pen10->setVisible(true);
    ui->left->setVisible(true);
    ui->right->setVisible(true);
    ui->buy->setVisible(true);
    ui->exit->setVisible(true);
    ui->black->setVisible(true);
    ui->flower->setVisible(true);
    ui->bigflower->setVisible(true);
    ui->record->setVisible(true);
    ui->pennum->setVisible(true);
    ui->money->setVisible(true);
    ui->total->setVisible(true);
    ui->illpig->setVisible(true);
    ui->killill->setVisible(true);
    ui->day->setVisible(true);
    ui->timebutton->setVisible(true);
    enabledfarm();
}

void MainWindow::on_killill_clicked()
{
    if(money<1000) QMessageBox::information(this,"提示",QString("<h4>金钱不足！</h4>"));
    else{
        money-=1000;
        for(int i=0;i<100;i++){
            for(int n=0;n<pigpen[i].sum;n++){
                if(pigpen[i].pigpenpig[n]->ill==1){
                    if(pigpen[i].pigpenpig[n]==pigpen[i].start){
                        pigpen[i].start=pigpen[i].pigpenpig[n]->next;
                        pig *p1=pigpen[i].pigpenpig[n];
                        for(int k=n;k<pigpen[i].sum-1;k++){
                            pigpen[i].pigpenpig[k]=pigpen[i].pigpenpig[k+1];
                        }
                        pigpen[i].pigpenpig[pigpen[i].sum-1]=NULL;
                        pigpen[i].sum--;
                        total--;
                        if(pigpen[i].sum==0) pigpen[i].blackpen=false;
                       p1->next = NULL;
                       delete p1;
                       n--;
                    }
                    else if(pigpen[i].end==pigpen[i].pigpenpig[n]&&pigpen[i].start!=pigpen[i].pigpenpig[n]){
                        pigpen[i].end=pigpen[i].pigpenpig[n-1];
                        pigpen[i].end->next=NULL;
                        pig *p1=pigpen[i].pigpenpig[n];
                        pigpen[i].pigpenpig[n]=NULL;
                        pigpen[i].sum--;
                        total--;
                        delete p1;
                    }
                    else{
                        pigpen[i].pigpenpig[n-1]->next=pigpen[i].pigpenpig[n]->next;
                        pig *p1=pigpen[i].pigpenpig[n];
                        for(int k=n;k<pigpen[i].sum-1;k++){
                            pigpen[i].pigpenpig[k]=pigpen[i].pigpenpig[k+1];
                        }
                        pigpen[i].pigpenpig[pigpen[i].sum-1]=NULL;
                        pigpen[i].sum--;
                        total--;
                        delete p1;
                        n--;
                    }
                }
            }
        }
        setpage();
    }
}

void MainWindow::on_exit_clicked()
{
    file1.setFileName("C:/Users/LEGION/Desktop/Qtcode/pigfarm/record.txt");
    bool isok=file1.open(QIODevice::WriteOnly);
    if(isok){
        QDataStream data(&file1);
        /*天数day
          金钱money
          总猪数total
          病猪数illpig*/
        data<<QString::number(day);
        data<<QString::number(money);
        data<<QString::number(total);
        data<<QString::number(illpig);
        for(int i=0;i<100;i++){
            data<<QString::number(pigpen[i].sum);
            for(int j=0;j<pigpen[i].sum;j++){
                data<<QString::number(i);
                data<<QString::number(pigpen[i].pigpenpig[j]->species);
                data<<QString::number(pigpen[i].pigpenpig[j]->growday);
                data<<QString::number(pigpen[i].pigpenpig[j]->ill);
                data<<QString::number(pigpen[i].pigpenpig[j]->preill);
                data<<QString::number(pigpen[i].pigpenpig[j]->weight);
            }
        }
    }
    file1.close();
}

void MainWindow::on_Continue_clicked()
{
    ui->background->setPixmap(QPixmap(":/new/prefix1/image/background.jpg"));
    ui->play->setVisible(false);
    ui->Continue->setVisible(false);
    ui->pen1->setVisible(true);
    ui->pen2->setVisible(true);
    ui->pen3->setVisible(true);
    ui->pen4->setVisible(true);
    ui->pen5->setVisible(true);
    ui->pen6->setVisible(true);
    ui->pen7->setVisible(true);
    ui->pen8->setVisible(true);
    ui->pen9->setVisible(true);
    ui->pen10->setVisible(true);
    ui->left->setVisible(true);
    ui->right->setVisible(true);
    ui->buy->setVisible(true);
    ui->exit->setVisible(true);
    ui->black->setVisible(true);
    ui->flower->setVisible(true);
    ui->bigflower->setVisible(true);
    ui->record->setVisible(true);
    ui->pennum->setVisible(true);
    ui->money->setVisible(true);
    ui->total->setVisible(true);
    ui->illpig->setVisible(true);
    ui->killill->setVisible(true);
    ui->day->setVisible(true);
    ui->timebutton->setVisible(true);
    file1.setFileName("C:/Users/LEGION/Desktop/Qtcode/pigfarm/record.txt");
    bool isok1=file1.open(QIODevice::ReadOnly);
    if(isok1){
        QDataStream data(&file1);
        QString a,b,c;
        data>>a;
        day=a.toUtf8().toInt();
        data>>a;
        money=a.toUtf8().toInt();
        data>>a;
        total=a.toUtf8().toInt();
        data>>a;
        illpig=a.toUtf8().toInt();
        for(int i=0;i<100;i++){
            data>>b;
            pigpen[i].sum=b.toUtf8().toInt();
            if(pigpen[i].sum==0) continue;
            for(int j=0;j<pigpen[i].sum;j++){
                pig *p1=new pig;
                data>>c;
                p1->pigpen=c.toUtf8().toInt();
                data>>c;
                p1->species=c.toUtf8().toInt();
                data>>c;
                p1->growday=c.toUtf8().toInt();
                data>>c;
                p1->ill=c.toUtf8().toInt();
                data>>c;
                p1->preill=c.toUtf8().toInt();
                data>>c;
                p1->weight=c.toUtf8().toInt();
                pigpen[i].pigpenpig[j]=p1;
                if(j==0){pigpen[i].start=pigpen[i].pigpenpig[j];pigpen[i].pigpenpig[j]->next=NULL;}
                if(j==pigpen[i].sum-1) pigpen[i].end=pigpen[i].pigpenpig[j];
                if(j!=0){
                    pigpen[i].pigpenpig[j-1]->next=pigpen[i].pigpenpig[j];
                    pigpen[i].pigpenpig[j]->next=NULL;
                }
            }
        }
    }
    file1.close();
    file.setFileName("C:/Users/LEGION/Desktop/Qtcode/pigfarm/buyandsell.txt");
    bool isok=file.open(QIODevice::ReadOnly);
    if(isok){
        QTextStream stream(&file);
        QString str=stream.readLine();
        while(!str.isNull()){
            addrecord(str);
            str=stream.readLine();
        }
    }
    file.close();
    file1.setFileName("C:/Users/LEGION/Desktop/Qtcode/pigfarm/record.txt");
    file1.open(QFile::WriteOnly|QFile::Truncate);
    file1.close();
    setpage();
}
