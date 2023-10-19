#include <iostream>
#include <Windows.h>
#include <vector>
#include <algorithm>
#include <string>

// НУЖНО РЕАЛИЗОВАТЬ БИНАРНЫЙ ПОИСК ОТДЕЛЬНОЙ ФУНКУИЕЙ!!! А ИНПЧЕ ВАЛИ НАФИГ С C++.

// where - где искать: объект - экземпляр класса, реализующего интерфейс Indexable

// what - с чем сравнивать: объект - экземпляр класса, реализущего интерфейс MyComparable

bool hasDupl(const std::vector<std::string>& items)
{
    std::vector<std::string> sortedItems(items);

    auto last = std::unique(sortedItems.begin(), sortedItems.end());

    return last != sortedItems.end();
}

int main()
{
    std::vector<std::string> C = {"C"};
    std::vector<std::string> ids;
    std::vector<std::string> fia;
    std::vector<std::string> Name;
    std::vector<std::string> Otchestvo;
    std::vector<std::string> errs;

    while (true) {

        
        std::string ds;
        std::string familia;
        std::string name;
        std::string otchestvo;
        std::string err;
        

        std::string choice;

        std::cin >> choice;

        if (choice == "C")
        {
           
            
            std::cout << " You add new student || student's " << std::endl;
            std::cout << " id ";
            std::cin >> ds;


            ids.push_back(ds);
            
            std::cout << " familia, name, otchestvo: ";
            std::cin >> familia >> name >> otchestvo;

            fia.push_back(familia);
            Name.push_back(name);
            Otchestvo.push_back(otchestvo);

            std::cout << " error ";
            std::cin >> err;
            errs.push_back(err);

            for (int y = 0; y < C.size(); y++)
            {
                std::cout << C[y] << " " ;
            }

            for (int i = 0; i < ids.size(); i++) 
            {
                std::cout << ids[i] << ",";
            }

            for (int q = 0; q < fia.size(); q++)
            {
                std::cout << fia[q] << ",";
            }

            for (int k = 0; k < Name.size(); k++)
            {
                std::cout << Name[k] << ",";
            }

            for (int j = 0; j < Otchestvo.size(); j++)
            {
                std::cout << Otchestvo[j];
            }

            bool hasDuplicatesIds = hasDupl(ids);


            if (hasDuplicatesIds) {
                std::cout << " DUPLICATE " << std::endl;
            }

           
        } 
        else if (choice == "R") 
        {
            std::cout << " Put number " << std::endl;
        }
    }
    return 0;
}