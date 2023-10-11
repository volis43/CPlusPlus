#include <iostream>
#include <Windows.h>
#include <vector>
#include <algorithm>

HANDLE hConsole;


class Arri {
    
   // std::vector<int> arr = { };

};

//void io() {
//    Arri arr;
//
//    for (int arrs : arr)
//    {
//        std::cout << arrs << " ";
//    }
//}

    bool Bin_Search(std::vector<int> arr, int num) {
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


int main()
{
    //class Arri arr;
   
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 6);

    std::cout << "Main menu\n 1) binari poisk\n 2) 1000\n 3) pyzurki\n ";
    while (true)
    {
        int go = 0;
        int baffer;

        std::vector<int> arr = { };

        while (std::cout << " <-- Proverka ", std::cin >> go) {
            
            arr.push_back(go);
        
            for (int arrs : arr)
            {
                std::cout << arrs << " ";
            }

            std::sort(arr.begin(), arr.end());

            std::cout << "\n" << Bin_Search(arr, 9);
           
            if (go == 0) 
                {
                std::cout << " End " << std::endl;
                    return 0;
                }
        }

    }

}
