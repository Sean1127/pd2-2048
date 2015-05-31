#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QFont>
#include <ctime>
#include <cstdlib>
#include <QKeyEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    // game functions
    void start();
    bool end(QLabel *ptr[4][4]);
    bool win(QLabel *ptr[4][4]);
    void cleanboard();
    void setboard(int x, int i, int num);
    int mergeRandNum();
    int pickRandPlace();
    void setImage(QLabel *ptr[4][4]);
    bool checkEmpty(int x, int y);
    void createNewNum();
    void setboardp(QLabel *A1, QLabel *A2, QLabel *A3, QLabel *A4, QLabel *B1, QLabel *B2, QLabel *B3, QLabel *B4, QLabel *C1, QLabel *C2, QLabel *C3, QLabel *C4, QLabel *D1, QLabel *D2, QLabel *D3, QLabel *D4);

    // player functions
    void ActionRight(int (&board)[4][4]);
    void ActionLeft(int (&board)[4][4]);
    void ActionDown(int (&board)[4][4]);
    void ActionUp(int (&board)[4][4]);

    static int best;
private slots:
    void on_restart_clicked();

private:
    Ui::MainWindow *ui;
    void keyPressEvent(QKeyEvent *event);
    int board[4][4];
    QLabel *boardp[4][4];
    int score;
};

#endif // MAINWINDOW_H
