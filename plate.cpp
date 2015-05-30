#include "plate.h"


Plate::Plate(int plax, int play, int i)
{
    x = plax;
    y = play;
    num = i;
}

void Plate::setx(int a)
{
    x = a;
}

int Plate::getx()
{
    return x;
}

void Plate::sety(int a)
{
    y = a;
}

int Plate::gety()
{
    return y;
}

void Plate::setNumber(int a)
{
    num = a;
}

void Plate::setImage(int a)
{
    setNumber(a);
    switch (num) {
    case 2:
        setPixmap(QPixmap(QString::fromUtf8(":/Stick.png")));
        break;
    case 4:
        setPixmap(QPixmap(QString::fromUtf8(":/Wood_Planks.png")));
        break;
    case 8:
        setPixmap(QPixmap(QString::fromUtf8(":/Cobblestone.png")));
        break;
    case 16:
        setPixmap(QPixmap(QString::fromUtf8(":/Iron_Ingot.png")));
        break;
    case 32:
        setPixmap(QPixmap(QString::fromUtf8(":/Gold_Ingot.png")));
        break;
    case 64:
        setPixmap(QPixmap(QString::fromUtf8(":/Diamond.png")));
        break;
    case 128:
        setPixmap(QPixmap(QString::fromUtf8(":/Wooden_Sword.png")));
        break;
    case 256:
        setPixmap(QPixmap(QString::fromUtf8(":/Stone_Sword.png")));
        break;
    case 512:
        setPixmap(QPixmap(QString::fromUtf8(":/Iron_Sword.png")));
        break;
    case 1024:
        setPixmap(QPixmap(QString::fromUtf8(":/Gold_Sword.png")));
        break;
    case 2048:
        setPixmap(QPixmap(QString::fromUtf8(":/Diamond_Sword.png")));
        break;
    }
}
