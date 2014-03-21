#include <windows.h>
// Will change to WxWidgets later
#define IDM_MYMENURESOURCE   3
int APIENTRY WinMain(HINSTANCE hThis, HINSTANCE hPrev, LPSTR cmd, int Show)
{
HWND HANDLE;
MSG MESSAGE;
const char *CLASSNAME = "MainWindow";
const char *WINDOW_TITLE[] = "PS4EMX";
bool Loop = 1;
WNDCLASS Wclass;
MSG msg;
Wclass.cbSize = sizeof(WNDCLASS);
Wclass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
Wclass.lpfnWndProc = (WNDPROC)WndProc;
Wclass.cbClsExtra = 0;
Wclass.cbWndExtra = 0;
Wclass.hIcon = LoadIcon(NULL, IDI_APPLICATION); // Easily changeable later
Wclass.hCursor = LoadCursor(NULL, IDC_ARROW); // Same as above
Wclass.hbrBackground = NULL;
Wclass.lpszClassName = CLASSNAME;
Wclass.lpszMenuName = MAKEINTRESOURCE(IDM_MYMENURESOUCE);
if(!RegisterClass(&Wclass))
{
return 0;
}
if (!(HANDLE = CreateWindowEx(WS_EX_APPWINDOW | WS_EX_WINDOWEDGE, clsName, title, WS_OVERLAPPEDWINDOW | WS_CLIPSIBLINGS
| WS_CLIPCHILDREN, CW_USEDEFAULT, CW_USEDEFAULT, 800, 640, NULL, NULL, hThis, NULL)))
     {    
       return 0;  
     }  
if(HANDLE == NULL)
{
  return FALSE;
}
ShowWindow(HANDLE, Show);
UpdateWindow(HANDLE);
while(Loop)
{
  TranslateMessage(&MESSAGE);
  DispatchMessage(&MESSAGE);
}
return MESSAGE.wParam;
}
LRESULT CALLBACK WINDOW(HWND hwnd, unsigned int message, WPARAM wparam, LPARAM lparam)
{
switch(message)
{
case
WM_PAINT: break;
// This won't be used for GPU stuff
case
WM_CLOSE: break;
// All cleanup goes here
default:
return DefWindowProc(hwnd, message, wparam, lparam);
}
return NULL;
}
