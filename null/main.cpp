#define STRICT 1 
#include <windows.h>
#include <iostream.h>

VOID CALLBACK TimerProc(HWND hWnd, UINT nMsg, UINT nIDEvent, DWORD dwTime)
{

    LPWSTR wallpaper_file = L"C:\\Wallpapers\\wallpaper.png";
    int return_value = SystemParametersInfo(SPI_SETDESKWALLPAPER, 0, wallpaper_file, SPIF_UPDATEINIFILE);


    cout << "Programmatically change the desktop wallpaper periodically: " << dwTime << '\n';
    cout.flush();
}

int main(int argc, char* argv[], char* envp[])
{
    int Counter = 0;
    MSG Msg;

    UINT TimerId = SetTimer(NULL, 0, 2000, &TimerProc); //2000 milliseconds

    cout << "TimerId: " << TimerId << '\n';
    if (!TimerId)
        return 16;

    while (GetMessage(&Msg, NULL, 0, 0))
    {
        ++Counter;
        if (Msg.message == WM_TIMER)
            cout << "Counter: " << Counter << "; timer message\n";
        else
            cout << "Counter: " << Counter << "; message: " << Msg.message << '\n';
        DispatchMessage(&Msg);
    }

    KillTimer(NULL, TimerId);
    return 0;
}