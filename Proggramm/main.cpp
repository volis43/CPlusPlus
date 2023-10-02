#include <Windows.h>
#include "resource.h";
#include "SoftWareDefinitions.h";
#include <mmsystem.h>


int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInt, LPSTR args, int ncmdshow) {

	WNDCLASS SoftWareMainClass = NewWindowClass((HBRUSH)COLOR_WINDOW, LoadCursor(NULL, IDC_ARROW), hInst, LoadIcon(hInst, MAKEINTRESOURCE(IDI_ICON1)),
		L"MainWndClass", SoftwareMainProcedure);

	if (!RegisterClassW(&SoftWareMainClass)) { return -1; }

	MSG SoftwareMainMessage = { 0 };

	CreateWindow(L"MainWndClass", L"HolyC", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100, 100, 500, 250, NULL, NULL, NULL, NULL);

	while (GetMessage(&SoftwareMainMessage, NULL, NULL, NULL)) {
		TranslateMessage(&SoftwareMainMessage);
		DispatchMessage(&SoftwareMainMessage);

	}
	return 0;

}

WNDCLASS NewWindowClass(HBRUSH BGColor, HCURSOR Cursor, HINSTANCE hInst, HICON Icon, LPCWSTR Name, WNDPROC Procedure) {

	WNDCLASS NWC = { 0 };

	NWC.hIcon = Icon;
	NWC.hCursor = Cursor;
	NWC.hInstance = hInst;
	NWC.lpszClassName = Name;
	NWC.hbrBackground = BGColor;
	NWC.lpfnWndProc = Procedure;

	return NWC;
}

LRESULT CALLBACK SoftwareMainProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
	switch (msg) {
	case WM_COMMAND:
		switch (wp) {
		case OnMenuAction1:
			MessageBoxA(hWnd, "Menu was 1 clicked!", "Menu worked", MB_OK);
			break;
		case OnButtonClicked:
			MessageBoxA(hWnd, "Yes, is Holyc", "oki", MB_OK);
			break;
		case OnExitSoftware:
			PostQuitMessage(0);
			break;
		default: break;
		}
		break;
		
		
		//case OnMenuAction2:
			//MessageBoxA(hWnd, "Menu was 2 clicked!", "Menu worked", MB_OK);
			
			//break;
		
		//case OnMenuAction3:
			//MessageBoxA(hWnd, "Menu was 3 clicked!", "Menu worked", MB_OK);
			
			//break;
		//default: break;
		//}


	case WM_CREATE:
		MainWndAddMenus(hWnd);
		MainWndAddWidget(hWnd);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default: return DefWindowProc(hWnd, msg, wp, lp);
	}
}

void MainWndAddMenus(HWND hWnd) {
	HMENU RootMenu = CreateMenu();
	
	HMENU SubMenu = CreateMenu();

	HMENU SubActionMenu = CreateMenu();
	
	

	AppendMenu(SubActionMenu, MF_STRING, OnMenuAction1, L"Menu 1");
	AppendMenu(SubActionMenu, MF_STRING, OnMenuAction2, L"Menu 2");
	AppendMenu(SubActionMenu, MF_STRING, OnMenuAction3, L"Menu 3");
	AppendMenu(SubActionMenu, MF_SEPARATOR, NULL, NULL);

	AppendMenu(SubMenu, MF_POPUP, (UINT_PTR)SubActionMenu, L"Action");
	AppendMenu(RootMenu, MF_POPUP, (UINT_PTR)SubMenu, L"File");
	AppendMenu(SubMenu, MF_STRING, OnExitSoftware, L"Exit");
	
	//AppendMenu(RootMenu, MF_POPUP, (UINT_PTR)SubMenu, L"Second");
	SetMenu(hWnd, RootMenu);
}

void MainWndAddWidget(HWND hWnd) {
	CreateWindowA("static", "HolyC ", WS_VISIBLE | WS_CHILD | ES_CENTER, 5, 5, 490, 20, hWnd, NULL, NULL, NULL);

	hEditControl = CreateWindowA("edit", "",  WS_VISIBLE | WS_CHILD, 5, 30, 490, 20, hWnd, NULL, NULL, NULL);

	CreateWindowA("button", "click", WS_VISIBLE | WS_CHILD | ES_CENTER, 5, 60, 120, 30, hWnd, (HMENU)OnButtonClicked, NULL, NULL);
}



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


    void booleanList(HolyList& list) {

        std::vector<bool> isFalse(numbers.size(), false);

        int rertu = 0;


        std::cout << "List is " << numbers[rertu] << " reruro " << numbers.size(), false;

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

    std::cout << "1) check element in list" << std::endl;
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
