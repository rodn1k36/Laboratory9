#include "Permutation.h"
#include <iostream>

int main() {
	unsigned int* arr = new unsigned int[4];
	arr[0] = 4;
	arr[1] = 3;
	arr[2] = 2;
	arr[3] = 1;

	Permutation b(4321);
	/*b.next();
	b.print(); */
	std::cout << '\n';
	Permutation a(2314);
	Permutation c;
	c = b * a;
	c.print();
	//a.previous();
	delete[] arr;
}