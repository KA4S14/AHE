#include<iostream>
#include"Point.cpp"
using namespace std;


int main()
{
	Point dzej('%', 4, 1, 37);
	Point kej('*', 7, 100, 36);

	
	cout << kej.getY();
	dzej.display();

	dzej.setX(6);
	dzej.setY(1);
	dzej.setSign('J');

	kej.setY(1);
	kej.setSign('K');

	dzej.display();
	kej.display();


	return 0;
}