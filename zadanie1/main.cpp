#include<iostream>
#include"Point.h"
using namespace std;

//jk
int main()
{
	Point dzej('%', 4, 1, 10);
	Point kej('*', 7, 100,25);
	cout << kej.getY();
	dzej.display();

	dzej.setX(6);
	dzej.setY(1);
	dzej.setColor(25);
	dzej.setSign('J');


	kej.setY(1);
	kej.setSign('K');
	kej.setColor(50);

	dzej.display();
	kej.display();
	

	return 0;
}