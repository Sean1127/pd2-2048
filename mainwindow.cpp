#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap bgp(":/Dirt.png");
    bgp = bgp.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bgp);
    this->setPalette(palette);
    setboardp(ui->A1,ui->A2,ui->A3,ui->A4,ui->B1,ui->B2,ui->B3,ui->B4,ui->C1,ui->C2,ui->C3,ui->C4,ui->D1,ui->D2,ui->D3,ui->D4);
    score = 0;
}
int MainWindow::best = 0;

void MainWindow::ActionRight(int (&board)[4][4])
{
    if (end(boardp) == false && win(boardp) == false)
    {
    // move every to the rightest
    int i, j;
    for (j = 0; j < 4; j++)
    {
        for (i = 2; i >= 0; i--)
        {
            if (checkEmpty(i,j) == false)
            {
                while (checkEmpty(i + 1,j) == true && i != 3)
                {
                    setboard(i + 1,j,board[j][i]);
                    setboard(i,j,0);
                    i++;
                }
            }
        }
    }

    // combine number
    for (j = 0; j < 4; j++)
    {
        for (i = 3; i > 0; i--)
        {
            if (checkEmpty(i,j) == false && board[j][i] == board[j][i - 1])
            {
                setboard(i,j,2*board[j][i]);
                setboard(i - 1,j,0);
                score += board[j][i];
                if (best < score)
                    best = score;
            }
        }
    }

    // move again
    for (j = 0; j < 4; j++)
    {
        for (i = 2; i >= 0; i--)
        {
            if (checkEmpty(i,j) == false)
            {
                while (checkEmpty(i + 1,j) == true && i != 3)
                {
                    setboard(i + 1,j,board[j][i]);
                    setboard(i,j,0);
                    i++;
                }
            }
        }
    }
    createNewNum();
    setImage(boardp);
    }
}

void MainWindow::ActionLeft(int (&board)[4][4])
{
    if (end(boardp) == false && win(boardp) == false)
    {
    // move every to the leftest
    int i, j;
    for (j = 0; j < 4; j++)
    {
        for (i = 1; i < 4; i++)
        {
            if (checkEmpty(i,j) == false)
            {
                while (checkEmpty(i - 1,j) == true && i != 0)
                {
                    setboard(i - 1,j,board[j][i]);
                    setboard(i,j,0);
                    i--;
                }
            }
        }
    }

    // combine number
    for (j = 0; j < 4; j++)
    {
        for (i = 0; i < 3; i++)
        {
            if (checkEmpty(i,j) == false && board[j][i] == board[j][i + 1])
            {
                setboard(i,j,2*board[j][i]);
                setboard(i + 1,j,0);
                score += board[j][i];
                if (best < score)
                    best = score;
            }
        }
    }

    // move again
    for (j = 0; j < 4; j++)
    {
        for (i = 1; i < 4; i++)
        {
            if (checkEmpty(i,j) == false)
            {
                while (checkEmpty(i - 1,j) == true && i != 0)
                {
                    setboard(i - 1,j,board[j][i]);
                    setboard(i,j,0);
                    i--;
                }
            }
        }
    }

    createNewNum();
    setImage(boardp);
    }
}

void MainWindow::ActionDown(int (&board)[4][4])
{
    if (end(boardp) == false && win(boardp) == false)
    {
    // move every to the bottom
    int i, j;
    for (j = 0; j < 4; j++)
    {
        for (i = 2; i >= 0; i--)
        {
            if (checkEmpty(j,i) == false)
            {
                while (checkEmpty(j,i + 1) == true && i != 3)
                {
                    setboard(j,i + 1,board[i][j]);
                    setboard(j,i,0);
                    i++;
                }
            }
        }
    }

    // combine number
    for (j = 0; j < 4; j++)
    {
        for (i = 3; i > 0; i--)
        {
            if (checkEmpty(j,i) == false && board[i][j] == board[i - 1][j])
            {
                setboard(j,i,2*board[i][j]);
                setboard(j,i - 1,0);
                score += board[i][j];
                if (best < score)
                    best = score;
            }
        }
    }

    // move again
    for (j = 0; j < 4; j++)
    {
        for (i = 2; i >= 0; i--)
        {
            if (checkEmpty(j,i) == false)
            {
                while (checkEmpty(j,i + 1) == true && i != 3)
                {
                    setboard(j,i + 1,board[i][j]);
                    setboard(j,i,0);
                    i++;
                }
            }
        }
    }

    createNewNum();
    setImage(boardp);
    }
}

void MainWindow::ActionUp(int (&board)[4][4])
{
    if (end(boardp) == false && win(boardp) == false)
    {
    // move every to the top
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 1; j < 4; j++)
        {
            if (checkEmpty(i,j) == false)
            {
                while (checkEmpty(i,j - 1) == true && j != 0)
                {
                    setboard(i,j - 1,board[j][i]);
                    setboard(i,j,0);
                    j--;
                }
            }
        }
    }

    // combine number
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (checkEmpty(i,j) == false && board[j][i] == board[j + 1][i])
            {
                setboard(i,j,2*board[j][i]);
                setboard(i,j + 1,0);
                score += board[j][i];
                if (best < score)
                    best = score;
            }
        }
    }

    // move again
    for (i = 0; i < 4; i++)
    {
        for (j = 1; j < 4; j++)
        {
            if (checkEmpty(i,j) == false)
            {
                while (checkEmpty(i,j - 1) == true && j != 0)
                {
                    setboard(i,j - 1,board[j][i]);
                    setboard(i,j,0);
                    j--;
                }
            }
        }
    }

    createNewNum();
    setImage(boardp);
    }
}

void MainWindow::start()
{
    // initial board and score to 0
    cleanboard();
    score = 0;
    ui->gameboard->setPixmap(QPixmap(QString::fromUtf8(":/board.png")));

    // create 2 items
    for (int n = 0; n < 2; n++)
    {
        int i = pickRandPlace();
        setboard(i%4, i/4, mergeRandNum());
    }
    setImage(boardp);
}

bool MainWindow::end(QLabel *ptr[4][4])
{
    // check if board is full
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (checkEmpty(i,j) == true)
            {
                return false;
            }
        }
    }

    // check if no more move
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            // vertical check
            if (board[i][j] == board[i + 1][j])
            {
                return false;
            }
            // horizontal check
            if (board[j][i] == board[j][i + 1])
            {
                return false;
            }
        }
    }
    // defeated screen
    ui->gameboard->setPixmap(QPixmap(QString::fromUtf8(":/Game Over.jpg")));
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            ptr[i][j]->clear();
        }
    }
    return true;
}

bool MainWindow::win(QLabel *ptr[4][4])
{
    // check 2048 reached
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (board[i][j] == 2048)
            {
                ui->gameboard->setPixmap(QPixmap(QString::fromUtf8(":/You-win.jpg")));
                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        ptr[i][j]->clear();
                    }
                }
                return true;
            }
        }
    }
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
    board[y][x] = num;
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
    int x = temp%4;
    int y = temp/4;
    while (checkEmpty(x, y) == false)
    {
        temp = rand()%16;
        x = temp%4;
        y = temp/4;
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
            case 0:
                ptr[i][j]->clear();
                break;
            }
        }
    }
    QFont font("System", 32, QFont::Bold);
    ui->score->setText(QString("SCORE: %1").arg(score));
    ui->score->setFont(font);
    ui->score->setStyleSheet("QLabel { background-color : 0; color : white; }");
    ui->best->setText(QString("BEST: %1").arg(best));
    ui->best->setFont(font);
    ui->best->setStyleSheet("QLabel { background-color : 0; color : white; }");
}

bool MainWindow::checkEmpty(int x, int y)
{
    if (board[y][x] == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void MainWindow::createNewNum()
{
    bool space = false;
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (checkEmpty(i,j) == true)
            {
                space = true;
                break;
            }
        }
    }
    if (space == true)
    {
        int temp = pickRandPlace();
        setboard(temp%4, temp/4, mergeRandNum());
    }
}

void MainWindow::setboardp(QLabel *A1, QLabel *A2, QLabel *A3, QLabel *A4, QLabel *B1, QLabel *B2, QLabel *B3, QLabel *B4, QLabel *C1, QLabel *C2, QLabel *C3, QLabel *C4, QLabel *D1, QLabel *D2, QLabel *D3, QLabel *D4)
{
    boardp[0][0] = A1;
    boardp[0][1] = A2;
    boardp[0][2] = A3;
    boardp[0][3] = A4;
    boardp[1][0] = B1;
    boardp[1][1] = B2;
    boardp[1][2] = B3;
    boardp[1][3] = B4;
    boardp[2][0] = C1;
    boardp[2][1] = C2;
    boardp[2][2] = C3;
    boardp[2][3] = C4;
    boardp[3][0] = D1;
    boardp[3][1] = D2;
    boardp[3][2] = D3;
    boardp[3][3] = D4;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    // press arrow key
    if (event->key() == Qt::Key_D)
    {
        ActionRight(board);
    }
    else if (event->key() == Qt::Key_A)
    {
        ActionLeft(board);
    }
    else if (event->key() == Qt::Key_S)
    {
        ActionDown(board);
    }
    else if (event->key() == Qt::Key_W)
    {
        ActionUp(board);
    }
}

void MainWindow::on_restart_clicked()
{
    start();
}
