#include <iostream>
#include <windows.h>

int main()
{
	HWND hwnd;

	hwnd = GetDesktopWindow();
	SendMessage(hwnd,WM_SYSCOMMAND, SC_MONITORPOWER, 0);
	
	//SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM)2);



	
	//Sleep(1000000);

	//SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM)-1);

	return 0; 

}