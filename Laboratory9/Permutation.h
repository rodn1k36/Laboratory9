#pragma once
#include <iostream>

class Permutation
{
private:
	size_t n = 0;
	unsigned int* arr_nums = nullptr;
public:
	Permutation() = default;
	Permutation(unsigned int n);
	Permutation(unsigned int n, unsigned int* &P);
	//friend std::ostream& operator <<(std::ostream& os, Permutation& P);
	Permutation& operator* (Permutation& P);
	Permutation& next ();
	Permutation& previous();
	Permutation& operator++ ();
	Permutation& operator-- ();
	bool operator== (Permutation& P);
	bool operator!= (Permutation& P);
	bool operator< (Permutation& P);
	bool operator> (Permutation& P);
	bool operator>= (Permutation& P);
	bool operator<= (Permutation& P);
	void print();
};