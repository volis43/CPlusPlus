#include <windows.h>
#include <iostream>
#include <string>

int main()
{
	

	for (int y = 0; y <= 90; y++) {
		while (int h = 8) {

			SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM)2);

		}
	}
	

	//Sleep(10000)

	//SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM)-1);


}
