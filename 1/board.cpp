#include "board.h"
#include <QDebug>
Board::Board(QWidget *parent) : QLabel(parent)
{
}

void Board::mousePressEvent(QMouseEvent *ev)
{
    int v=ev->x()/50;int u=ev->y()/50;
    bool ll=current->setchesspiece(v,u);
    if(!ll) return;
    int l=changechess(v,u);
    if(current->q[v][u]==0) return;
    current->setscore(l);
    QString A;A="先手方\n"+QString::number(current->getscore());
    ppp->setText(A);
    int d=current->getscore();
    i++;
    if(i>1) i=0;
    if(i==1) current+=1;
    else current-=1;
    current->setscore((l-1)*(-1));
    A="后手方\n"+QString::number(current->getscore());
    (ppp+1)->setText(A);
    check(d);
    if(check1()==0) {QMessageBox::information(0,"游戏","对方无子可下，请继续落子");i++;if(i>1) i=0;if(i==1) current+=1;else current-=1;}
    update();
}

int Board::changechess(int x,int y)
{
    int dir[8][2] = {{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1}};
    int tmpX,tmpY,l=0;
    int i = 0;
    bool flag0=0;
    for(i=0; i<8; i++){
        tmpX = x;
        tmpY = y;
        bool flag=0;
        int k=0;
        while(1){
        tmpX += dir[i][0];
        tmpY += dir[i][1];//八个方向之一
        if(tmpX<0||tmpX>10||tmpY<0||tmpY>10) break;
        if((tmpX==0||tmpX==10||tmpY==0||tmpY==10)&&current->q[tmpX][tmpY]!=current->identify) break;
        if(current->q[tmpX][tmpY]==0)break;
        if(current->q[tmpX][tmpY]==current->identify&&k==0)break;
        if(current->q[tmpX][tmpY]==current->identify){flag0=1;flag=1;break;}
        k++;
        }
        if(flag){
            while((tmpX != x) || (tmpY != y)){
                tmpX -= dir[i][0];
                tmpY -= dir[i][1];
                current->q[tmpX][tmpY]=current->identify;
                l++;
            }
        }
    }
    if(!flag0) {QMessageBox::critical(0,"无效的落子","无效的落子，请重试！");current->q[x][y]=0;}
    return l;
}
void Board::check(int y)
{
    bool flag1=1,flag2=1,flag3=1;
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
           if(current->q[i][j]==1) flag1=0;
           if(current->q[i][j]==2) flag2=0;
           if(current->q[i][j]==0) flag3=0;
        }
    }
    if(flag1) {QMessageBox::information(0,"游戏结束","后手方胜！");}
    if(flag2) {QMessageBox::information(0,"游戏结束","先手方胜！");}
    if(flag3) {
        int x=current->getscore();
        if(x>y){if(current->identify==1){QMessageBox::information(0,"游戏结束","先手方胜！");return;}
                 else {QMessageBox::information(0,"游戏结束","先手方胜！");return;}}
        else if(x==y) {QMessageBox::information(0,"游戏结束","平局！");return;}
        else {if(current->identify==2){QMessageBox::information(0,"游戏结束","先手方胜！");return;}
               else {QMessageBox::information(0,"游戏结束","先手方胜！");return;}}
    }

}

bool Board::check1()
{
    bool k=0;
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            int dir[8][2] = {{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1}};
            int tmpX,tmpY;
            for(int p=0; p<8; p++){
                tmpX = i;
                tmpY = j;
                int b=0;
                while(1){
                tmpX += dir[p][0];
                tmpY += dir[p][1];//八个方向之一
                if(tmpX<0||tmpX>9||tmpY<0||tmpY>9) break;
                if((tmpX==0||tmpX==10||tmpY==0||tmpY==10)&&current->q[tmpX][tmpY]!=current->identify) break;
                if(current->q[tmpX][tmpY]==0)break;
                if(current->q[tmpX][tmpY]==current->identify&&b==0)break;
                if(current->q[tmpX][tmpY]==current->identify){k=1;return k;}
                b++;
                }
                }
        }
    }
    return k;
}





