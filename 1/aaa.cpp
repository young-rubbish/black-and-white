int judgeRole(int x, int y, chessrole)//当前坐标x，y，，，，，当前角色
{

    int dir[8][2] = {{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1}};
    int tmpX = x,tmpY = y;
    int i = 0, eatNum = 0;

    if(chessStatus[tmpX][tmpY] != Empty){
        return 0;
    }//此格子如果有子就结束


    for(i=0; i<8; i++){
        tmpX = x;
        tmpY = y;
        tmpX += dir[i][0];
        tmpY += dir[i][1];//八个方向之一

        if(tmpX < 10 && tmpX >= 0 && tmpY <10 && tmpY >= 0
            && (chessStatus[tmpX][tmpY] != currentRole) && (chessStatus[tmpX][tmpY] != Empty)){
            //如果没有出界    并且    相邻棋子不是自己的棋子   并且    不是空的
            tmpX += dir[i][0];
            tmpY += dir[i][1];
            //向选定方向走一步，再判断该方向还是否是自己棋子

            while(tmpX <10 && tmpX >= 0 && tmpY < 10 && tmpY >= 0){
                if(chessStatus[tmpX][tmpY] == Empty){
                    break;
                }//有空位跳出循环，上一个if个条件也不满足，换下一个方向
                if(chessStatus[tmpX][tmpY] == currentRole){/到自己的棋子代表可以吃子


                   //开始往后退
                    while((tmpX != x) || (tmpY != y)){
                        tmpX -= dir[i][0];
                        tmpY -= dir[i][1];

                        改变颜色，update

                        eatNum++;   //吃子累计
                    }//一直退到初始点击位置
                    break;//跳出循环，结束该方向的判断
                }

                tmpX += dir[i][0];
                tmpY += dir[i][1];//没找到自己棋子就再走一步
                                                                }



        }
    }
    return eatNum;
}
