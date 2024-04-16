#ifndef TEXTBOX_HPP
#define TEXTBOX_HPP

#include <iostream>
#include <windows.h>
#include <conio.h>
#include<tuple>


enum class Color
{
    Black = 0,
    Blue = 1,
    Green = 2,
    Cyan = 3,
    Red = 4,
    Magenta = 5,
    Yellow = 6,
    White = 7,
    Gray = 8,


    LBlue = 9,
    LGreen = 10,
    LCyan = 11,
    LRed = 12,
    LMagenta = 13,
    LYellow = 14,
    LWhite = 15
};

class Edit 

{

private:

    COORD position;
    int length;

    std::string text;
    Color textColor;
    Color backgroundColor;

public:

    Edit();

    void setPosition(int x, int y);
    void setLength(int len);

    void setText(const std::string& txt);
    void setTextColor(Color color);
    void setBackgroundColor(Color color);

    std::string getText() const;
    void userText();
};

std::ostream& setColor(std::ostream& os, Color textColor, Color backgroundColor);

std::ostream& operator<<(std::ostream& os, const std::tuple<Color, Color>& colors);

std::ostream& yellow(std::ostream& os);
std::ostream& red(std::ostream& os);
std::ostream& blue(std::ostream& os);
std::ostream& green(std::ostream& os);
std::ostream& gray(std::ostream& os);

std::ostream& lblue(std::ostream& os);
std::ostream& lyellow(std::ostream& os);
std::ostream& cyan(std::ostream& os);
std::ostream& magenta(std::ostream& os);
std::ostream& defcolor(std::ostream& os);

#endif // TEXTBOX_HPP
