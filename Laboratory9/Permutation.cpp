#include "Permutation.h"
#include <iostream>

Permutation::Permutation() : arr_nums(nullptr), n(0)
{
}

Permutation::Permutation(unsigned int num)
{
	size_t order = 0;
	unsigned int temp = num;
	while (temp) {
		++order;
		temp /= 10;
	}
	n = order;

	arr_nums = new unsigned int[order];
	int i = 1;
	for (int i = order - 1; i >= 0; --i) {
		arr_nums[i] = num % 10;
		num /= 10;
	}
}

Permutation::Permutation(unsigned int n, unsigned int*& P) : n(n), arr_nums(new unsigned int[n])
{
	for (int i = 0; i < n; ++i)
		arr_nums[i] = P[i]; // нужно ли удалять nullptr если хочу переопределить указатель
}

Permutation::~Permutation()
{
	delete[] arr_nums;
}

Permutation& Permutation::operator= (Permutation& P)
{
	n = P.n;
	delete[] arr_nums;
	arr_nums = new unsigned int[n];
	for (int i = 0; i < n; ++i)
		arr_nums[i] = P.arr_nums[i];
	//arr_nums = P.arr_nums;
	return *this;
}

Permutation& Permutation::operator*(Permutation& P)
{
	if (n == P.n) {
		unsigned int* temp = new unsigned int[n];
		for (int i = 0; i < n; ++i) {
			temp[i] = P.arr_nums[arr_nums[i]-1];
			arr_nums[i] = temp[i];
		}
		//arr_nums = temp;
		delete[] temp;
		return *this;
	}
	else
		throw 1;
}

Permutation& Permutation::next()
{
	int non_increasing_len = 0;
	int index = 0; // индекс первого элемента неубывающей последовательсности
	int count = 0;
	int turning_num = arr_nums[0];
	for (int i = 0; i < n - 1; ++i) {
		if (arr_nums[i] >= arr_nums[i + 1]) {
			++count;
			non_increasing_len = std::max(non_increasing_len, count);
		}
		else {
			non_increasing_len = std::max(non_increasing_len, count);
			index = i - non_increasing_len + 1; // с нуля
			turning_num = arr_nums[index - 1];
			count = 0;
		}

	}
	int minimal_more_num_index = index;
	int minimal_more_num = INT_MAX; // минимально большее число (index) чем turning_num
	for (int i = index; i < index + non_increasing_len; ++i) {
		if (turning_num < arr_nums[i] && arr_nums[i] < minimal_more_num) {
			minimal_more_num_index = i;
			minimal_more_num = arr_nums[i];
		}
	}
	if (index != 0) {
		std::swap(arr_nums[index - 1], arr_nums[minimal_more_num_index]); // можно ли написать через тернарный оператор если то if без else

		for (int i = index; i < index + non_increasing_len; ++i)
			for (int j = i + 1; j < n; ++j)
				if (arr_nums[i] > arr_nums[j])
					std::swap(arr_nums[i], arr_nums[j]);
	}
	return *this;
}




Permutation& Permutation::previous()
{
	int increasing_len = 0;
	int index = 0; 
	int count = 0;
	int turning_num = arr_nums[0];
	for (int i = 0; i < n - 1; ++i) {
		if (arr_nums[i] <= arr_nums[i + 1]) {
			++count;
			increasing_len = std::max(increasing_len, count);
		}
		else {
			if (increasing_len < count) {
				increasing_len = count;
				index = i - increasing_len + 1;
			}
			count = 0;
		}
	}
	turning_num = arr_nums[index - 1];

	int max_more_num_index = index;
	int max_more_num = -1;
	for (int i = index; i < index + increasing_len; ++i) {
		if (turning_num < arr_nums[i] && arr_nums[i] > max_more_num) {
			max_more_num_index = i;
			max_more_num = arr_nums[i];
		}
	}
	if (index > 0) std::swap(arr_nums[index - 1], arr_nums[max_more_num_index]);

	for (int i = index; i < index + increasing_len; ++i) // sort
		for (int j = i + 1; j < index + increasing_len; ++j)
			if (arr_nums[i] < arr_nums[j])
				std::swap(arr_nums[i], arr_nums[j]);
	return *this;
}

Permutation& Permutation::operator++()
{
	for (int i = 0; i < n; ++i)
		++arr_nums[i];
	return *this;
}

Permutation& Permutation::operator--()
{
	for (int i = 0; i < n; ++i)
		--arr_nums[i];
	return *this;
}

bool Permutation::operator<(Permutation& P)
{
	if (n == P.n) {
		for (int i = 0; i < n; ++i)
			if (arr_nums[i] < P.arr_nums[i])
				return true;
			else if (arr_nums[i] != P.arr_nums[i])
				return false;
	}
	else
		throw 1;
}

bool Permutation::operator==(Permutation& P) {
	if (n == P.n) {
		for (int i = 0; i < n; ++i)
			if (arr_nums[i] != P.arr_nums[i])
				return false;
	}
	else
		throw 1;
}

bool Permutation::operator!=(Permutation& P)
{
	return !(*this == P);
}

bool Permutation::operator>(Permutation& P)
{
	return !(*this < P) && (*this != P) ;
}

bool Permutation::operator>=(Permutation& P)
{
	return !(*this < P);
}

bool Permutation::operator<=(Permutation& P)
{
	return (*this < P) || (*this == P);
}

void Permutation::print() const{
	for (int i = 0; i < n; ++i) {
		std::cout << arr_nums[i];
	}
}

//std::ostream& operator<< (std::ostream& os, const Permutation& P) {
//	P.print(os);
//	return os;
//}