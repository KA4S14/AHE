
#include <iostream>
#include"matrix.h"
using namespace std;


int main()
{
	//constructors
	matrix m;
	matrix copy(m);
	matrix jk;
	matrix bugf;
	matrix ig; 


	cout << "m:\n" << m << "\n";
	
	cout << "copy of m:\n" << copy << "\n";
	
	//get size
	cout<<m.getSIZE()<< " - number of elements\n";

	// get ij-element 
	cout<< copy.get(1, 0)<<" - retrive value of 1,0 element in matrix copy \n ";

	
	// set ij-element to value
	jk.set(0, 0, 0);
	jk.set(0, 1, 0);
	jk.set(1, 0, 1);
	jk.set(1, 1, 8);
	cout << "jk:\n"<<jk << "\n";

	// transpose of matrix 
	jk.transpose();
	cout << "transpose of jk:\n" << jk << "\n";


	// *
	cout << "jk:\n" << jk << "\n";
	cout << "m:\n" << m << "\n";
	cout <<"result of op * multiplication:jk*m\n "<< jk * m << endl;
	// *=
	jk *= m;
	cout << "jk:" << jk << "\n";
	cout << "m:" << m << "\n";
	cout << "jk as result of op *= multiplication:jk*=m \n" << jk << " \n";
	
	
	//+
	cout <<"result of op + addition:ig+copy \n" << ig + copy << "\n";
	cout << "ig:" << ig << "\n";
	cout << "copy:" << copy << "\n";
	//+=
	ig += copy;
	cout << "ig as result of op += addition: \n" << ig << " \n";

	

	//scalar *
	
	double loser = 25;
	cout << "bugf:" << bugf << "\n";
	cout << "result of op * scalar multiplication:bugf*25 \n" << bugf * loser << "\n";
	cout << "bugf:" << bugf << "\n";
	cout << "scalar:" << loser << "\n";
	//scalar *=
	bugf *= loser;
	cout << "result of op *= scalar multiplication bugf*=25: \n" << bugf << " \n";

	

	// =
	cout << "jk:\n" << jk << "\n";
	cout << "copy:\n" << copy << "\n";
	jk = copy;
	cout << "jk = copy :\n" << jk << "\n";
	//==
	cout << "jk:\n" << jk << "\n";
	cout << "ig:\n" << ig << "\n";
	if (jk == ig)
	{
		cout << "jk equals ig\n";
	}
	else
	{
		cout << "it's never been about equality between jk and ...\n";
	}
	

}

