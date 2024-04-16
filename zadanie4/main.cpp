#include<iostream>
#include<conio.h>
#include<windows.h>
#include "textbox.hpp"

int main() 
{
    // Pierwsza część programu
    Edit e;
    e.setPosition(2, 1);
    e.setLength(50);
    e.setText("Kot ma na imie Richard");

    e.setTextColor(Color::Blue);
    e.setBackgroundColor(Color::Yellow);

    std::string s = e.getText();
    std::cout << "Textbox 1" << std::endl;
    std::cout << "Zawartosc pola tekstowego: " << s;
    _getch();

    e.userText();
    system("cls");

    s = e.getText();
    std::cout << "Zawartosc pola tekstowego: " << s;
    _getch();

    system("cls");
    std::cout << "Textbox 2" << std::endl;
    Edit e2(e);

    e2.setPosition(21, 37);
    e2.setBackgroundColor(Color::Magenta);
    s = e2.getText();

    std::cout << "Zawartość pola tekstowego: " << s;
    _getch();
    e2.userText();
    system("cls");

    s = e2.getText();
    std::cout << "Zawartość pola tekstowego: " << s;
    _getch();

   //Druga część programu
    system("cls");
    std::cout << "Druga część programu" << std::endl;
    std::cout << yellow << "A" << red << "l" << blue << "a" << green << "m" << gray << "a"
        << lblue << "k" << lyellow << "o" << cyan << "t" << magenta << "a";



    std::cout << std::make_tuple(Color::Yellow, Color::Red) << "Miauu" << std::endl;
    _getch();
    return 0;
}
