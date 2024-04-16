#include "textbox.hpp"

Edit::Edit() : position({ 0, 0 }), length(0), textColor(Color::White), backgroundColor(Color::Black) {}

void Edit::setPosition(int x, int y) 
{
    position = {static_cast<SHORT>(x), static_cast<SHORT>(y)};

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

void Edit::setLength(int len) 
{
    length = len;
}



void Edit::setText(const std::string& txt) 
{
    text = txt;
}

void Edit::setTextColor(Color color) 
{
    textColor = color;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), static_cast<int>(textColor) 
     (static_cast<int>(backgroundColor) << 4));
}

void Edit::setBackgroundColor(Color color) 
{
    backgroundColor = color;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), static_cast<int>(textColor) 
     (static_cast<int>(backgroundColor) << 4));
}

std::string Edit::getText() const 
{
    return text;
}

void Edit::userText() 
{



    while (true) 
    {



        if (_kbhit()) 
        {


            char ch = _getch();
            if (ch == '\r') 
            { 
                break;
            }


            else if (ch == '\b') 
            { 

                if (!text.empty()) 
                {
                    text.pop_back();
                    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
                    std::cout << text << ' ';

                    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
                }
            }
            else 
            { 
                text += ch;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);

                std::cout << text;
            }
        }
    }
}







std::ostream& setColor(std::ostream& os, Color textColor, Color backgroundColor)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), static_cast<int>(textColor) 
    | (static_cast<int>(backgroundColor) << 4));


    return os;
}

std::ostream& operator<<(std::ostream& os, const std::tuple<Color, Color>& colors)
{
    Color textColor = std::get<0>(colors);
    Color backgroundColor = std::get<1>(colors);
    return setColor(os, textColor, backgroundColor);
}









std::ostream& yellow(std::ostream& os) 
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    return os;
}

std::ostream& red(std::ostream& os)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
    return os;
}

std::ostream& blue(std::ostream& os) 
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    return os;
}

std::ostream& green(std::ostream& os)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    return os;
}

std::ostream& gray(std::ostream& os) 
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    return os;
}

std::ostream& lblue(std::ostream& os)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    return os;
}

std::ostream& lyellow(std::ostream& os) 
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY);
    return os;
}

std::ostream& cyan(std::ostream& os) 
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    return os;
}

std::ostream& magenta(std::ostream& os) 
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    return os;
}

std::ostream& defcolor(std::ostream& os) 
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    return os;
}