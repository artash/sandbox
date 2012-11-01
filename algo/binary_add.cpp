#include <iostream>

unsigned* binaryAdd(unsigned* lhs, unsigned* rhs, unsigned size)
{
	unsigned* sum = new unsigned[size + 1];
	// carry flag
	int cf = 0;
	for (int i = size; i > 0; --i)
	{
		sum[i] = (lhs[i-1] + rhs[i-1] + cf) % 2;
		cf = lhs[i-1] + rhs[i-1] + cf > 1 ? 1 : 0;
	}
	sum[0] = cf;
	return sum;
}

template<typename T>
void printArray(T *p, int size, const char * prefix = "")
{
	std:: cout << prefix;
	for (int i = 0; i < size; ++i)
	{
		std::cout << p[i] << " ";
	}
	std::cout <<"\n";
}

int main(int argc, void **argv)
{
	unsigned left[] =  {1,1,0,0,1,1,1};
	unsigned right[] = {1,1,0,0,0,0,1};
	int size = sizeof(left) / sizeof(unsigned);

	printArray(left, size, "  ");
	printArray(right, size, "  ");
	unsigned* sum = binaryAdd(left, right, size);
	printArray(sum, size + 1);
	
	return 0;
}



