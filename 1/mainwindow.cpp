#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    showscore=new QLabel[2];
    showscore[0].setParent(this);
    showscore[0].move(100,50);
    showscore[0].setFixedSize(50,50);
    showscore[0].autoFillBackground();
    showscore[1].setParent(this);
    showscore[1].move(450,50);
    showscore[1].setFixedSize(50,50);
    showscore[1].autoFillBackground();
    btn = new QPushButton("开始游戏",this);
    btn->setFixedSize(200,50);
    btn->move(200,100);
    p = new Board(this);
    p->setFixedSize(496,496);
    p->move(52,252);
    player=new Player[2];
    player[0].setidentify(1);
    player[0].q=a;
    player[1].setidentify(2);
    player[1].q=a;
    p->current=player;
    p->ppp=showscore;
    connect(btn,SIGNAL(clicked(bool)),this,SLOT(start()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter p(this);
         p.setPen(QPen(Qt::black,5));
         for(int i=0;i<11;i++)
         {p.drawLine(QPoint(52,250+50*i),QPoint(548,250+50*i));
          p.drawLine(QPoint(50+50*i,252),QPoint(50+50*i,748));
         }
         int i=0;
         while(i<10)
         {
             int j=0;
             p.setPen(Qt::transparent);
             while(j<10)
             {
             if(a[i][j]==1) {p.setBrush(Qt::black);p.drawPie(52+50*i,252+50*j,48,48,0,360*16);}
             if(a[i][j]==2) { p.setBrush(Qt::white);p.drawPie(52+50*i,252+50*j,48,48,0,360*16);}
             j++;
             }
             i++;
         }

}

void MainWindow::start()
{
    for(int i=0;i<10;i++)
    {for(int j=0;j<10;j++)a[i][j]=0;}
  a[4][4]=1;
  a[5][5]=1;
  a[4][5]=2;
  a[5][4]=2;
  p->current=player;
  player->clearscore();
  (player+1)->clearscore();
  update();
}


