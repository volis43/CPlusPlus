#include <Windows.h>

int main()
{
	//18_fuJZ
	//99K4Kg504U4
	const char* imagePath = "G:\\photo_2023-09-27_04-47-16.jpg";
	int imageLen = strlen(imagePath) + 1;
	int wideLen = MultiByteToWideChar(CP_ACP, 0, imagePath, imageLen, NULL, 0);
	wchar_t* widePath = new wchar_t[wideLen];
	MultiByteToWideChar(CP_ACP, 0, imagePath, imageLen, widePath, wideLen);

	SystemParametersInfo(SPI_SETDESKWALLPAPER, 0, widePath, SPIF_UPDATEINIFILE);

	delete[] widePath;
	return 0;

}

