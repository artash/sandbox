#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

template<typename T>
void swap(T& a, T& b)
{
	T t = a;
	a = b;
	b = t;
}

template<typename T>
void insertionSort(std::vector<T>& elems)
{
	for (typename std::vector<T>::size_type i = 1; i < elems.size(); ++i)
	{
		typename std::vector<T>::size_type k = i - 1;
		while (k >= 0 && elems[k] > elems[k+1])
		{
			swap(elems[k], elems[k+1]);
			--k;
		}
	} 
}

template<typename T>
void printArray(const std::vector<T>& vec) 
{
	std::copy(vec.begin(), vec.end(), std::ostream_iterator<T>(std::cout, ", "));
	std::cout << "\n";
}

int main()
{
	int raw[] = { 23, 25, 3, 367, 2, 77, 32, 11, 7543, 4, 4, 7, 3, 9, 34, 55 };
	std::vector<int> elems(raw, raw + sizeof(raw)/sizeof(int));
	printArray(elems);
	insertionSort(elems);
	printArray(elems);
	return 0;
}

