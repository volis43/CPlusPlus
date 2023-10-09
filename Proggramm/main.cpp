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
		case OnButtonClicked1:
			MessageBoxA(hWnd, "I never app ", "c", MB_OK);
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


