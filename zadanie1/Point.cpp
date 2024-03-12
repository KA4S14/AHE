#include "Point.h"
using namespace std;



void Point::display() const
{
   //cursor position
    cout << "\033[" << y << ";" << x << "H";
    // color set by ANSI escape codes
    cout << "\033[38;5;" << color << "m";
    cout << sign;
    //color reset
    cout << "\033[0m";
}

void Point::setSign(char new_s)
{
    sign = new_s;

}

void Point::setX(int new_x)
{
    x = new_x;
}

void Point::setY(int new_y)
{
    y = new_y;
}

void Point::setColor(int new_color)
{
    color = new_color;
}

char Point::getSign() const
{
    return sign;
}

int Point::getX() const
{
    return x;
}

int Point::getY() const
{
    return y;
}

int Point::getColor() const
{
    return color;
}
