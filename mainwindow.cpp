#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setboardp(ui->A1,ui->A2,ui->A3,ui->A4,ui->B1,ui->B2,ui->B3,ui->B4,ui->C1,ui->C2,ui->C3,ui->C4,ui->D1,ui->D2,ui->D3,ui->D4);
}

int MainWindow::ActionRight(int (&board)[4][4])
{
}

int MainWindow::ActionLeft(int (&board)[4][4])
{
}

int MainWindow::ActionDown(int (&board)[4][4])
{
}

int MainWindow::ActionUp(int (&board)[4][4])
{
}

void MainWindow::start()
{
    // initial step
    cleanboard();
    for (int n = 0; n < 2; n++)
    {
        int i = pickRandPlace();
        setboard(i%4, i/4, mergeRandNum());
    }
    //while (end() == false)
    //{
        setImage(boardp);
    //}
}

bool MainWindow::end()
{
    // check if board is full
    // check if no more move
    // pop dialog
    // return
    return false;
}

void MainWindow::cleanboard()
{
    // set board to 0
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            setboard(i,j,0);
        }
    }
}

void MainWindow::setboard(int x, int y, int num)
{
    board[x][y] = num;
}

int MainWindow::mergeRandNum()
{
    // generate number 2 and 4, ratio 7:1
    srand(time(NULL));
    if (rand()%8 == 1)
    {
        return 4;
    }
    else
    {
        return 2;
    }
}

int MainWindow::pickRandPlace()
{
    // choose from 16
    srand(time(NULL));
    int temp = rand()%16;
    while (checkEmpty(temp) == false)
    {
        temp = rand()%16;
    }
    return temp;
}

void MainWindow::setImage(QLabel *ptr[4][4])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            switch (board[i][j]) {
            case 2:
                ptr[i][j]->setPixmap(QPixmap(QString::fromUtf8(":/Stick.png")));
                break;
            case 4:
                ptr[i][j]->setPixmap(QPixmap(QString::fromUtf8(":/Wood_Planks.png")));
                break;
            case 8:
                ptr[i][j]->setPixmap(QPixmap(QString::fromUtf8(":/Cobblestone.png")));
                break;
            case 16:
                ptr[i][j]->setPixmap(QPixmap(QString::fromUtf8(":/Iron_Ingot.png")));
                break;
            case 32:
                ptr[i][j]->setPixmap(QPixmap(QString::fromUtf8(":/Gold_Ingot.png")));
                break;
            case 64:
                ptr[i][j]->setPixmap(QPixmap(QString::fromUtf8(":/Diamond.png")));
                break;
            case 128:
                ptr[i][j]->setPixmap(QPixmap(QString::fromUtf8(":/Wooden_Sword.png")));
                break;
            case 256:
                ptr[i][j]->setPixmap(QPixmap(QString::fromUtf8(":/Stone_Sword.png")));
                break;
            case 512:
                ptr[i][j]->setPixmap(QPixmap(QString::fromUtf8(":/Iron_Sword.png")));
                break;
            case 1024:
                ptr[i][j]->setPixmap(QPixmap(QString::fromUtf8(":/Gold_Sword.png")));
                break;
            case 2048:
                ptr[i][j]->setPixmap(QPixmap(QString::fromUtf8(":/Diamond_Sword.png")));
                break;
            }
        }
    }
}

bool MainWindow::checkEmpty(int a)
{
    int x = a%4;
    int y = a/4;
    if (board[x][y] == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void MainWindow::setboardp(QLabel *A1, QLabel *A2, QLabel *A3, QLabel *A4, QLabel *B1, QLabel *B2, QLabel *B3, QLabel *B4, QLabel *C1, QLabel *C2, QLabel *C3, QLabel *C4, QLabel *D1, QLabel *D2, QLabel *D3, QLabel *D4)
{
    boardp[0][0] = A1;
    boardp[1][0] = A2;
    boardp[2][0] = A3;
    boardp[3][0] = A4;
    boardp[0][1] = B1;
    boardp[1][1] = B2;
    boardp[2][1] = B3;
    boardp[3][1] = B4;
    boardp[0][2] = C1;
    boardp[1][2] = C2;
    boardp[2][2] = C3;
    boardp[3][2] = C4;
    boardp[0][3] = D1;
    boardp[1][3] = D2;
    boardp[2][3] = D3;
    boardp[3][3] = D4;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    // press arrow key
    if (event->key() == Qt::Key_Right)
    {
        ActionRight(board);
    }
    else if (event->key() == Qt::Key_Left)
    {
        ActionLeft(board);
    }
    else if (event->key() == Qt::Key_Down)
    {
        ActionDown(board);
    }
    else if (event->key() == Qt::Key_Up)
    {
        ActionUp(board);
    }
}

void MainWindow::on_restart_clicked()
{
    start();
}
