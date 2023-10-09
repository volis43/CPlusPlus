
#include <Windows.h>
#include <iostream>

int main()
{
	//Не робит
	/*ExitWindowsEx(EWX_POWEROFF | EWX_FORCEIFHUNG,
		SHTDN_REASON_MINOR_OTHER);*/

	WinExec("shutdown -s -t 0", SW_HIDE);

   /* system("shutdown -s")*/; // закрывает Windows через минуту

}



