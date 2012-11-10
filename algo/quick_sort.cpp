#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cassert>

template<typename T>
void printArray(const std::vector<T>& vec)
{
	std::copy(vec.begin(), vec.end(), std::ostream_iterator<T>(std::cout, " "));
	std::cout << std::endl;
}

template<typename T>
void swap(T& a, T& b)
{
	T t = a;
	a = b;
	b = t;
}

template<typename T>
typename std::vector<T>::iterator partition(std::vector<T>& vec, typename std::vector<T>::iterator from, typename std::vector<T>::iterator to)
{
	assert(distance(from, to) > 1);

	T& pivot = *from;
	typename std::vector<T>::iterator it1, it2;
	it1 = it2 = from + 1;
	for(; it1 != to; ++it1)
	{
		if (*it1 < pivot)
		{
			swap(*it1, *it2);
			++it2;
		}
	}

	--it2;
	swap(pivot, *it2);
	return it2;
	
}

template<typename T>
void quickSort(std::vector<T>& vec, typename std::vector<T>::iterator from, typename std::vector<T>::iterator to)
{
	//printArray(vec);
	//std::cout << "from=" << *from << " to-1=" << *(to-1) << std::endl;
        //std::cout << "the distance is " << std::distance(from, to) << std::endl << std::endl;
	if(std::distance(from, to) > 1)
	{
		typename std::vector<T>::iterator it = partition(vec, from, to);
		quickSort(vec, from, it);
		quickSort(vec, it + 1, to);
	}
	// if the distance is 1 there's nothing to do, it's a 0 or 1 element array which is already sorted
}

template<typename T>
void quickSort(std::vector<T>& vec)
{
	quickSort(vec, vec.begin(), vec.end());
}

int main()
{
	int unsorted[] = {15, 47, 478, 21, 78, 33, 6, 239, 0, 4, 2, 8, 33, 8, 45, 2, 1, 7, 9 };
	std::vector<int> uv(unsorted, unsorted + sizeof(unsorted) / sizeof(int));
	printArray(uv);
	quickSort(uv);
//	std::cout << *partition(uv, uv.begin(), uv.end()) << std::endl;
	printArray(uv);

	return 0;
}
