#ifndef BOARD_H
#define BOARD_H
#include <QLabel>
#include <QMouseEvent>
#include <player.h>
class Board : public QLabel
{
    Q_OBJECT

public:
    explicit Board(QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent *ev);
    int changechess(int x, int y);
    Player*current;
    void check(int x);
    bool check1();
    int i=0;
    QLabel*ppp;
signals:

public slots:
};

#endif // BOARD_H
