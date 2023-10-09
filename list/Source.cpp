#include <iostream>
#include <list>

int main()
{
	std::list<int> numbers{ 1,2,3,4 };
	int first{ numbers.front() };
	int last{ numbers.back() };

	std::cout << first << std::endl;
	std::cout << last << std::endl;

	for (int n : numbers) 
	{
		std::cout << n;
	}

	for (auto iter = numbers.begin(); iter != numbers.end(); iter++)
	{
		std::cout << *iter << "\t";
	}
	std::cout << std::endl;
}