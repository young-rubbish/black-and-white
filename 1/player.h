#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QMessageBox>
class Player : public QObject
{
    Q_OBJECT
    int score=2;
    bool ishuman;   
public:
    explicit Player(QObject *parent = nullptr);    
    void setidentify(int n){identify=n;}
    int (*q)[10];
    int identify=0;
    void setscore(int n){score+=n;}
    void clearscore(){score=2;}
    int getscore(){return score;}
    bool setchesspiece(int x, int y);
signals:

public slots:
};

#endif // PLAYER_H
