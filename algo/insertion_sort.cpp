#include <iostream>


void insertionSort(int *p, int size)
{
	for (int i = 1; i < size; ++i)
	{
		int insert = p[i];
		for(int j = i - 1; j >= 0; --j)
		{
			if (p[j + 1] < p[j]) 
			{
				int t = p[j];
				p[j] = p[j+1];
				p[j+1] = t;
			}
			else
			{
				break;
			}
		}
	}
}

void printArray(int *p, int size)
{
	for (int i = 0; i < size; ++i)
	{
		std::cout << p[i] << " ";
	}
	std::cout <<"\n";
}

int main(int argc, void** argv)
{
	int numbers[] = {53, 54, 3, 56, 2, 6 ,8, 0, 11, 10, 17};
	printArray(numbers, sizeof(numbers)/sizeof(int));
	insertionSort(numbers, sizeof(numbers)/sizeof(int));
	printArray(numbers, sizeof(numbers)/sizeof(int));
}

