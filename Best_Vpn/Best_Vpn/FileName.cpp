#include <iostream>
#include <windows.h>

int main()
{
	const char* str = "C:\\Users\\volis\\source\\repos\\Best_Vpn\\Best_Vpn\\x64\\Debug\\ss.png";
	
	SystemParametersInfoA(SPI_SETDESKWALLPAPER, 0, (void*)str, SPIF_UPDATEINIFILE | SPIF_SENDCHANGE);
	
	return 0;
}