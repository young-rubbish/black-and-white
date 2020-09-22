#include "player.h"

Player::Player(QObject *parent) : QObject(parent)
{

}

bool Player::setchesspiece(int x,int y)
{
    if(q[x][y]) {
        QMessageBox::critical(0,"无效的落子","无效的落子，请重试！");
        return false;
    }
    q[x][y]=identify;
    return true;
}
