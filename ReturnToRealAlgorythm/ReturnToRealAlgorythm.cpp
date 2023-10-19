#include <iostream>
#include <Windows.h>
#include <vector>
#include <algorithm>
#include <string>

// НУЖНО РЕАЛИЗОВАТЬ БИНАРНЫЙ ПОИСК ОТДЕЛЬНОЙ ФУНКУИЕЙ!!! А ИНПЧЕ ВАЛИ НАФИГ С C++.

// where - где искать: объект - экземпляр класса, реализующего интерфейс Indexable

// what - с чем сравнивать: объект - экземпляр класса, реализущего интерфейс MyComparable

class stringi
{
public:
	std::vector<std::string> fio{ };
};


class ide 
{
public:
	std::vector<std::string> id{ };

};

class erattos 
{
public:
	std::vector<std::string> error{ };
};

bool hasDupl(const std::vector<std::string>& ids)
{
	std::vector<std::string> sortedIDS(ids);

	auto last = std::unique(sortedIDS.begin(), sortedIDS.end());

	return last != sortedIDS.end();
}


int main()
{
	while (true) {

		stringi fia;
		ide ids;
		erattos errs;
		/*int ds = 0;*/
		std::string ds;
		std::string familia;
		std::string name;
		std::string otchestvo;

		std::string err;

		std::cin >> ds;

		ids.id.push_back(ds);

		// Тут нужно сделать стринг чтоб помнил i и s  . 220997

		for (int u = 0; u < ids.id.size(); u++)
		{
			std::cout << ids.id[u] << ",";  // Тут нужно убить запятую!!! А иначе выкени свой комп в мусорку

			bool hasDuplicatesIds = hasDupl(ids.id);
			
			if (hasDuplicatesIds) {
				std::cout << "Вектор ids содержит повторяющиеся символы." << std::endl;
			}
		}

		std::cout << "Input familia, name, otchestvo" << std::endl;

		std::cin >> familia;
		std::cin >> name;
		std::cin >> otchestvo;

		fia.fio.push_back(familia);
		fia.fio.push_back(name);
		fia.fio.push_back(otchestvo);

		for (int i = 0; i < fia.fio.size(); i++)
		{
			std::cout << fia.fio[i] << ",";  // Тут нужно убить запятую!!! А иначе выкени свой комп в мусорку 

		  /*for (int i = 0; i < fia.fio.size(); i++)
				std::cout << fia.fio[i] << ", ";*/
		}


		std::cin >> err;

		errs.error.push_back(err);

	}

}
