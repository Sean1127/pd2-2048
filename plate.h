#ifndef PLATE
#define PLATE

#include <QLabel>

class Plate: public QLabel{
public:
    // constructor
    Plate(int plax, int play, int i);

    void setx(int a);
    int getx();
    void sety(int a);
    int gety();
    void setNumber(int a);
    void setImage(int a);
private:
    int x;
    int y;
    int num;
};

#endif // PLATE

