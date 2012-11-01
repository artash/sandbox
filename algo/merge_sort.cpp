#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

template<typename T>
void printArray(const std::vector<T>& vec)
{
	std::copy(vec.begin(), vec.end(), std::ostream_iterator<T>(std::cout, " "));
	std::cout << "\n";
}

template<typename T>
std::vector<T> merge(const std::vector<T>& elems1, const std::vector<T>& elems2)
{
	std::vector<T> result;
	result.reserve(elems1.size() + elems2.size());
	typename std::vector<T>::const_iterator cit1 = elems1.begin();
	typename std::vector<T>::const_iterator cit2 = elems2.begin();

	while(cit1 != elems1.end() && cit2 != elems2.end())
	{
		result.push_back((*cit1 < *cit2) ? *cit1++ : *cit2++);
	}

	std::back_insert_iterator<std::vector<T> > bi(result);
	std::copy(cit1, elems1.end(), bi);
	std::copy(cit2, elems2.end(), bi);

	return result;
}

template<typename T>
std::vector<T> mergeSort(std::vector<T>& elems, typename std::vector<T>::iterator from, typename std::vector<T>::iterator to)
{	
	if(std::distance(from, to) > 1)
	{
		//std::cout << "the distance is " << std::distance(from, to) << std::endl;
        	typename std::vector<T>::iterator middle = from;
	        std::advance(middle, std::distance(from, to) / 2);
        	std::vector<T> sorted1 = mergeSort( elems, from, middle );
	        std::vector<T> sorted2 = mergeSort( elems, middle, to);
	        return merge(sorted1, sorted2);
	}
	else
	{
		return std::vector<T>(1, *from);
	}
}

template<typename T>
std::vector<T> mergeSort(std::vector<T>& elems)
{
	return mergeSort(elems, elems.begin(), elems.end());
}
	


int main() 
{	
	int sorted1[] = { 1, 3, 5, 7, 9, 11 };
	int sorted2[] = { 0, 2, 4, 6, 8, 10 };
	std::vector<int> sv1(sorted1, sorted1 + sizeof(sorted1) / sizeof(int));
	std::vector<int> sv2(sorted2, sorted2 + sizeof(sorted2) / sizeof(int));
	std::vector<int> merged = merge(sv1, sv2);
	printArray(sv1);
	printArray(sv2);
	printArray(merged);

	int unsorted[] = { 23, 44, 2, 64, 8, 3, 75, 445, 1, 52, 75, 37, 453, 8, 2, 80 };
	std::vector<int> uv(unsorted, unsorted + sizeof(unsorted) / sizeof(int));
	printArray(uv);
	std::vector<int> sv = mergeSort(uv);
	printArray(sv);

	return 0;
}
