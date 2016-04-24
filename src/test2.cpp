// STANDARD LIBRARIES
#include <iostream>
//#include <stdio>
//#include <stdlib>

// OTHER LIBRARIES
//#include "MyStack.h"
//#include "MyQueue.h"

// NAMESPACES
using namespace std;


// CLASS DEFINITIONS
template <class A_type> class calc {
public:
	A_type multiply(A_type x, A_type y);
	A_type add(A_type x, A_type y);
};

// FUNCTION DEFINITIONS
void swap (int& first, int& second);



int main(int argc, char *argv[]) {	//

	for (int i = 0; i < argc; ++i) {
		cout << argv[i] << endl;
	}


	int x;
	int& foo = x;
	foo = 56;
	cout << x << endl;


	int a = 2;
	int b = 3;
	cout << a << " " << b << endl;
	
	swap(a, b);

	cout << a << " " << b << endl;
	

	calc <int> clc1;// = calc<int>();
	cout << clc1.multiply(2, 3) << endl;
	cout << clc1.add(2, 3) << endl;

	calc <double> clc2;// = calc<double>();
	cout << clc2.multiply(2.0, 3.5) << endl;
	cout << clc2.add(2.0, 3.5) << endl;




	




	return 0;
}


void swap(int& first, int& second) {
	int temp = first;
	first = second;
	second = temp;
}



template <class A_type> A_type calc<A_type>::multiply(A_type x, A_type y) {
	return x*y;
}

template <class A_type> A_type calc<A_type>::add(A_type x, A_type y) {
	return x+y;
}
