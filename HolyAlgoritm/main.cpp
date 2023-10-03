#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <Windows.h>
#include <conio.h>

HANDLE hConsole;

class HolyList {
public:
    std::vector<int> numbers{ 1, 2, 3, 4 };
    
    };

void flagi(HolyList& list) {
    for (int i = 0; i < list.numbers.size(); i++)
    {
       
        
    }
};


void io(HolyList& list) {
    std::cout << "\n";
    for (int t : list.numbers) 
    {
        std::cout << " " << t;
    }
};

    int main() {
        
        HolyList list;

        while(true)
        {

        int choose = 0;
        int index = 0;
        int num = 0;
        int put = 0;
        int dell = 0;
        int prov = 0;
        int n1 = 0;
        int n2 = 0;
        int nexti = 0;
        
        std::string End = "Y";

        auto it = std::find(list.numbers.begin(), list.numbers.end(), nexti);

        auto id = list.numbers.begin();

        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, 6);

        std::cout << "\n1) check \n2) add() \n3) switch(#, #2) \n4) next --> number \n5) get(#) \n6) size() \n7) loop() ? \n8) loop list () \n9) remove(#) \n----------------  \n10) Exit " << std::endl;

        io(list);

        std::cout << "\n";
        std::cin >> choose;

        switch (choose) 
        {

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
            while (true) 
            {

                std::cout << " Is  Next numbers() --> ";
                std::cin >> nexti;
                it = std::find(list.numbers.begin(), list.numbers.end(), nexti);
                if (it != list.numbers.end()) {
                    auto next = it + 1;
                    if (next != list.numbers.end()) {
                        std::cout << *next;
                        std::cout << " to finish? Y / N ? " << std::endl;
                        
                        std::cin >> End;
                        
                        if (End == "Y" || "y") {
                            break;
                        }
                        else if (End == "N" || "n") {
                            continue;
                        }         
                    }
                    else {
                        std::cout << "No next number";
                        
                    }
                }
                else {
                    std::cout << "Not Found";
                }
            } 
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

            io(list);

            std::cout << "\nEnter 2 elements to loop: ";
            int n1, n2;
            std::cin >> n1 >> n2;

            std::cout << "First element: " << n1 << std::endl;
            std::cout << "Second element: " << n2 << std::endl;

            list.numbers[n1] = false;
            list.numbers[n2] = false;

            for (int i = 0; i < list.numbers.size(); i++) 
            {
                if (list.numbers[i] == false) 
                {
                    std::cout << "\nFirst false element index: " << i << std::endl;
                    break;
                }
            }

            io(list);

            break;
        case 8:
            std::cout << "Loop " << std::endl;
            
            for (int i = 0; i < list.numbers.size(); i++) 
            {
                if (list.numbers[i] == 0) 
                {
                    break; 
                }

                list.numbers[i] = 0; 
                io(list); 

                list.numbers[i] = 1; 

                io(list); 
                
            }
                return 0;
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

            if (id != list.numbers.end()) 
            {
                list.numbers.erase(id);
                Sleep(1000);
                std::cout << " Successfull removed " << dell << "!" << std::endl;
            }
        
            else
            {
                std::cout << " Number not find" << std::endl;
            }

            SetConsoleTextAttribute(hConsole, 2);


            io(list);

            break;
       
        
        case 10:
            return 0;
            break;
}

        }
        return 0;
    }
