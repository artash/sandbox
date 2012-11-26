#include <iostream>
#include <algorithm>
#include <iterator>

template<typename T>
void printArray(T* arr, int size)
{
	std::copy(arr, arr + size, std::ostream_iterator<T>(std::cout, " "));
}


void swap(char& a, char& b)
{
	char t = a;
	a = b;
	b = t;
}

char* reverse(char* p)
{
	int len = strlen(p);
	for(int i = 0; i < len / 2; ++i)
	{
		swap(p[i], p[len - i - 1]);
	}
}


int main()
{
	char p[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
	reverse(p);
	printArray(p, sizeof(p) / sizeof(char));
}

