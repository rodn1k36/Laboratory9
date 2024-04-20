#include "Permutation.h"
#include <iostream>

int main() {
	unsigned int* arr = new unsigned int[4];
	arr[0] = 4;
	arr[1] = 3;
	arr[2] = 2;
	arr[3] = 1;
	Permutation a(4, arr);
	Permutation b(123678);
	b.next();

	b.print();
}