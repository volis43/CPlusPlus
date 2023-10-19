#include <iostream>
#include <Windows.h>
#include <vector>
#include <algorithm>
#include <string>

// НУЖНО РЕАЛИЗОВАТЬ БИНАРНЫЙ ПОИСК ОТДЕЛЬНОЙ ФУНКУИЕЙ!!! А ИНПЧЕ ВАЛИ НАФИГ С C++.

// where - где искать: объект - экземпляр класса, реализующего интерфейс Indexable

// what - с чем сравнивать: объект - экземпляр класса, реализущего интерфейс MyComparable

bool hasDupl(const std::vector<std::string>& ids)
{
	std::vector<std::string> sortedIDS(ids);

	auto last = std::unique(sortedIDS.begin(), sortedIDS.end());

	return last != sortedIDS.end();
}


int main()
{
	std::string iHateYou = " I hate you ";
	while(true){
		std::cout << iHateYou;
	}

}
