#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QPushButton>
#include <QMainWindow>
#include <board.h>
#include <QPainter>
#include <player.h>
#include <QLabel>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void paintEvent(QPaintEvent *);
    int a[10][10]={{0},{0}};
    Player*player;
    Board*p;
    QPushButton*btn;
    QLabel*showscore;
public slots:
    void start();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
