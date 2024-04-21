#pragma once
#include <iostream>

class Permutation
{
private:
	size_t n = 0;
	unsigned int* arr_nums = nullptr;
public:
	Permutation();
	Permutation(unsigned int n);
	Permutation(unsigned int n, unsigned int* &P);
	~Permutation();
	Permutation& operator= (Permutation& P);
	//std::ostream& operator <<(std::ostream& os);
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
	//std::ostream& operator<< (std::ostream& os);
	void print() const;
};