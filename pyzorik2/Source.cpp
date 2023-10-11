#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int a[] = { 1,3,4,6,4,90 };

	for (int i = 0; i < 6; i++)
	{
		std::cout << a[i] << " ";
	}

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6 - 1 - i; j++) 
		{
			if (a[j] > a[j + 1]) 
				{
					std::swap(a[j], a[j + 1]);
				}
		}
	}
	std::cout << std::endl;

	for (int i = 0; i < 6; i++) {
		std::cout << a[i] << " ";
	}
}