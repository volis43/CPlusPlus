#include <windows.h>
#include <conio.h>
#include <winuser.h>

int main() {
    const wchar_t* test = L"G:\\18fuJZ.jpg";

    int result = SystemParametersInfoW(SPI_SETDESKWALLPAPER, 0, (LPVOID)test, SPIF_UPDATEINIFILE);
}