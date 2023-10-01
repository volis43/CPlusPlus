#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <Windows.h>
#include <conio.h>

HANDLE hConsole;

class HolyList {
public:
    std::vector<int> numbers{ 1, 2, 3, 4, 1 };


    void booleanList(HolyList& list) {
        std::vector<bool> isFalse(numbers.size(), false);

        int currentIndex = 0;

        while (true) {
            if (!isFalse[currentIndex]) {

                std::cout << " NUmbers " << numbers[currentIndex] << " Sosto" << isFalse[currentIndex];

                isFalse[currentIndex] = true;
            }

            currentIndex = (currentIndex + 1) % numbers.size();

            bool allTrue = true;
            for (bool b : isFalse) {
                if (!b) {
                    allTrue = false;
                    break;
                }
            }
            if (allTrue) {
                break;
            }
        }
    };

    
    void io(HolyList& list) {
        std::cout << "\n";
        for (int t : list.numbers) {
            std::cout << " " << t;
        }
    }


    int main() {

        
        

        int choose = 0;
        int index = 0;
        int num = 0;
        int put = 0;
        int dell = 0;
        int prov = 0;

        HolyList list;

        auto id = list.numbers.begin();

        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, 6);

        std::cout << "1) check" << std::endl;
        std::cout << "2) add()" << std::endl;
        std::cout << "3) switch(#, #2)" << std::endl;
        std::cout << "5) get(#)" << std::endl;
        std::cout << "6) size()" << std::endl;
        std::cout << "7) loop() ?" << std::endl;
        std::cout << "8) loop list ()" << std::endl;
        std::cout << "9) remove(#)" << std::endl;
        std::cout << "----------------" << std::endl;
        std::cout << "10) gdData()" << std::endl;
        std::cout << "11) SetData(#)" << std::endl;
        std::cout << "12) next --> number" << std::endl;

        io(list);

        std::cout << "\n";
        std::cin >> choose;

        switch (choose) {

        case 1:
            std::cout << "Just check element in list ;) " << std::endl;

            std::cin >> prov;

            id = std::find(list.numbers.begin(), list.numbers.end(), prov);

            std::cout << *id << " Yes, exists";

            break;

        case 2:
            std::cout << "Enter number to add list";
            std::cin >> num;

            list.numbers.push_back(num);

            io(list);
            break;

        case 3:
            std::cout << "Select 1 item you want to swap with" << std::endl;
            std::cin >> index;
            std::cin >> num;

            for (int& y : list.numbers) {
                if (y == index) {
                    y = num;
                }
            }

            io(list);
            break;

        case 4:
            std::cout << "Is 4 " << std::endl;
            break;
        case 5:
            std::cout << "Get(#)" << std::endl;

            hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hConsole, 4);

            std::cout << "Choose element" << std::endl;

            std::cin >> put;

            id = std::find(list.numbers.begin(), list.numbers.end(), put);

            if (id != list.numbers.end()) {

                std::cout << "You get element " << *id << std::endl;
            }
            else {
                std::cout << "Sorry element not find :)" << std::endl;
            }
            break;

        case 6:
            std::cout << "Size list " << std::endl;
            std::cout << list.numbers.size();
            break;
        case 7:
            std::cout << "Loop boolean" << std::endl;

            list.booleanList(list);


            break;
        case 8:
            std::cout << "Is 8" << std::endl;
            break;
        case 9:

            std::cout << "Remove(#)" << std::endl;

            SetConsoleTextAttribute(hConsole, 2);

            std::cout << "search" << std::endl;

            for (int t : list.numbers)
            {
                std::cout << t << " ";
                Sleep(1000);
            }

            SetConsoleTextAttribute(hConsole, 4);

            std::cout << "\n" << "Last element " << list.numbers.back();

            std::cout << "\n" << "here is a free cell (  )" << std::endl;

            std::cin >> dell;

            std::cout << "(" << dell << ")";

            id = std::find(list.numbers.begin(), list.numbers.end(), dell);

            if (id != list.numbers.end()) {
                list.numbers.erase(id);
                Sleep(1000);
                std::cout << " Successfull removed " << dell << "!" << std::endl;
            }

            else {
                std::cout << " Number not find" << std::endl;


            }

            SetConsoleTextAttribute(hConsole, 2);


            io(list);

            break;
        case 10:
            std::cout << "Is 10" << std::endl;
            break;
        }

        return 0;
    }