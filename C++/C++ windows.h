#include <windows.h>

void Stealth()
{
 HWND Stealth;
 AllocConsole();
 Stealth = FindWindowA("ConsoleWindowClass", NULL);
 ShowWindow(Stealth,0);
}

LRESULT CALLBACK WindowsProcedure(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow){
 Stealth();
 //MessageBox(NULL, "HELLO", "My first GUI", MB_OK);

//hInst - instancja aplikacji (ID nadawane przez system)

 WNDCLASSW wc = {0};
 wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
 wc.hCursor = LoadCursor(NULL, IDC_ARROW);
 wc.hInstance = hInst;
 wc.lpszClassName = L"myWindowClass";
 wc.lpfnWndProc = WindowsProcedure;

 if (!RegisterClassW(&wc))
    return -1;

 CreateWindowW(L"myWindowClass", L"Moje okno", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100, 100, 500, 500, NULL, NULL, NULL, NULL);

 MSG msg = {0};

 while(GetMessage((&msg), NULL, NULL, NULL ))
 {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
 }
 return 0;

}

LRESULT CALLBACK WindowsProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp){

    switch (msg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProcW(hWnd, msg, wp, lp);
    }
}


