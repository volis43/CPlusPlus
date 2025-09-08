#include <iostream>
#include <windows.h>

int main()
{
	while (true)
	{
		SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM)2);
	}
	return 0;
}