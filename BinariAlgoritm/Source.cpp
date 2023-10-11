#include <iostream>
#include <vector>
#include <algorithm>

bool Bin_Search(std::vector<int> arr, int num)
{
	int left = 0;
	int right = arr.size() - 1;

	int middle;
	while (left <= right)
	{
		middle = (left + right) / 2;
		if (arr[middle] == num)
		{
			return 1;
		}
		if (arr[middle] < num)
		{
			left = middle + 1;
		}
		else
		{
			right = middle - 1;
		}
	}
	return 0;
}

int main () 
{
	int io = 0;
	int go = 0;
	
	while (true)
	{
		std::cin >> go;
			
		if (go == io)
		{
			std::cout << "return to real life!" << std::endl;
			
			break;
		}
	}
	
	std::vector<int> arr = {go};
	
	for (int n : arr) 
	{
		std::cout << n;
	}
	
	
	
	
	std::cout << Bin_Search(arr, 1);
}