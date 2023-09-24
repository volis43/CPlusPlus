#include <Windows.h>

int ScreenWidth, ScreenHeight;
int Interval = 100;

LRESULT CALLBACK Melter(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
    switch (Msg)
    {
    case WM_CREATE:
    {
        HDC Desktop = GetDC(HWND_DESKTOP);
        HDC Window = GetDC(hWnd);

        BitBlt(Window, 0, 0, ScreenWidth, ScreenHeight, Desktop, 0, 0, SRCCOPY);
        ReleaseDC(hWnd, Window);
        ReleaseDC(HWND_DESKTOP, Desktop);

        SetTimer(hWnd, 0, Interval, 0);
        ShowWindow(hWnd, SW_SHOW);
        break;
    }
    case WM_PAINT:
    {
        ValidateRect(hWnd, 0);
        break;
    }
    case WM_TIMER:
    {
        HDC Window = GetDC(hWnd);
        int X = (rand() % ScreenWidth) - (150 / 2),
            Y = (rand() % 15),
            Width = (rand() % 150);
        BitBlt(Window, X, Y, Width, ScreenHeight, Window, X, 0, SRCCOPY);
        ReleaseDC(hWnd, Window);
        break;
    }
    case WM_DESTROY:
    {
        KillTimer(hWnd, 0);
        PostQuitMessage(0);
        break;
    }
    return 0;
    }
    return DefWindowProc(hWnd, Msg, wParam, lParam);
}

int APIENTRY WinMain(HINSTANCE Inst, HINSTANCE Prev, LPSTR Cmd, int showcmd)
{
    // Get the width & height of current display
    ScreenWidth = GetSystemMetrics(SM_CXSCREEN);
    ScreenHeight = GetSystemMetrics(SM_CYSCREEN);

    WNDCLASSA wndClass = { 0 };
    wndClass.lpfnWndProc = Melter;
    wndClass.hInstance = Inst;
    wndClass.hCursor = LoadCursorW(0, IDC_ARROW);
    wndClass.lpszClassName = "ScreenMelter";

    if (RegisterClassA(&wndClass))
    {
        // Create the "melter" overlapping window.
        HWND hWnd = CreateWindowExA(WS_EX_TOPMOST, "ScreenMelter", 0, WS_POPUP,
            0, 0, ScreenWidth, ScreenHeight, HWND_DESKTOP, 0, Inst, 0);
        if (hWnd)
        {
            // seed for randomization
            srand(GetTickCount());
            MSG Msg = { 0 };
            // Run the melter loop
            while (Msg.message != WM_QUIT)
            {
                if (PeekMessageA(&Msg, 0, 0, 0, PM_REMOVE))
                {
                    TranslateMessage(&Msg);
                    DispatchMessageA(&Msg);
                }
            }
        }
    }
    return 0;
}

int main()
{
    HINSTANCE hInstance = GetModuleHandle(NULL);
    return WinMain(hInstance, NULL, GetCommandLineA(), 0);
}