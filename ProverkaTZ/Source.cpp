#include <iostream>
#include <list>

//using std::cout;
//using std::endl;
using std::list;
using std::string;

int main() {
	
	std::list<int> numbers{ 1, 2, 3, 4, 5, 6 };
	std::list<int> rei { };
	std::list<int> c{ 1,5,6,7,8,4,5,3,2,3,4,5,6,7,4,32,34,23 };
	std::list<int> ag;
	
	
	//std::cout << ag;


	std::list<string> words = { "die", "milk", "pay", "eys", "lool", "death", "ar" };
	words.remove("pay");

	for (auto word : words)
	{
		std::cout << words << std::endl;
	}
	

	//std::list<string> words(2);
	
	

	//std::cout << "It's just size words how string " <<  words;

	std::list<int> list1;
	std::list<int> list2(5);
	
	int first{ numbers.front() };
	int last{ numbers.back() };
	int size = numbers.size();
	
	c.resize(8);
	c.resize(6, 8);
	numbers.resize(0);

	std::cout << "Firs:" << first << std::endl;
	std::cout << "Last:" << last << std::endl;
	std::cout << "Size:" << size << std::endl;

	for (int n : numbers)
		std::cout << n << "\t";
	std::cout << std::endl;

	if (rei.empty()) {
		std::cout << "The list is empty:" << std::endl;
	}
	else {
		std::cout << "The list is not empty:" << std::endl;
	}
	for (auto iter = numbers.begin(); iter != numbers.end(); iter++) 
	{
		std::cout << *iter << "\t";
	}
	std::cout << std::endl;
	
	return 0;
}