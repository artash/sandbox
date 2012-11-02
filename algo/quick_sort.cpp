#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>


template<typename T>
void printArray(const std::vector<T>& vec)
{
	std::copy(vec.begin(), vec.end(), std::ostream_iterator<T>(std::cout, " "));
	std::cout << std::endl;
}


// partition function
void partition(std::vector<T>& vec, std::vector<T>::iterator from, std::vector<T>::iterator to)
{
	
}

template<typename T>
void quickSort(std::vector<T>& vec)
{
	
}

int main()
{
	int unsorted[] = { 47, 478, 21, 78, 33, 6, 239, 0, 4, 2, 8, 33, 8, 45, 2, 1, 7, 9 };
	std::vector<int> uv(unsorted, unsorted + sizeof(unsorted) / sizeof(int));
	printArray(uv);
	quickSort(uv);
	printArray(uv);

	return 0;
}
