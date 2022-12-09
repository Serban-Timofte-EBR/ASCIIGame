#include <windows.h>
#include <iostream>
using namespace std;
#define FILE_MENU_POSITION 1
#define FILE_MENU_ATTACK 2
#define FILE_MENU_EXIT 3
#define FILE_MENU_DAMAGE 4
#define FILE_MENU_EARN 5
// name to be chage
LRESULT CALLBACK procedureWD(HWND, UINT, WPARAM, LPARAM);
void addMenu(HWND);
void controls(HWND);
HMENU mainMenu;
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow)
{
//MessageBox(NULL,"Hello","My first GUI",MB_OK);
WNDCLASSW windowTemplate = {0};

windowTemplate.hbrBackground = (HBRUSH)COLOR_WINDOW;
windowTemplate.hCursor = LoadCursor(NULL, IDC_ARROW);
windowTemplate.hInstance = hInst;
windowTemplate.lpszClassName = L"WindowTemplate";
windowTemplate.lpfnWndProc = procedureWD;
if(!RegisterClassW(&windowTemplate))
{
return -1;
}
CreateWindowW(L"WindowTemplate", L"Game Menu", WS_OVERLAPPEDWINDOW | WS_VISIBLE,
100, 100, 400, 500, NULL, NULL, NULL, NULL);
MSG msg = {0};
while( GetMessage(&msg, NULL, NULL, NULL) )
{
TranslateMessage(&msg);
DispatchMessage(&msg);
}
return 0;
}
LRESULT CALLBACK procedureWD(HWND hwnd, UINT msg, WPARAM wpar, LPARAM lpar)
{
HDC hdc;
switch(msg)
{
case WM_COMMAND:
switch(wpar)
{
case FILE_MENU_EXIT:
DestroyWindow(hwnd);
break;
case FILE_MENU_ATTACK:
MessageBeep(MB_APPLMODAL);
break;
}
break;
case WM_CREATE:
addMenu(hwnd);
controls(hwnd);
break;
case WM_DESTROY:
PostQuitMessage(0);
break;
default:


return DefWindowProcW(hwnd, msg, wpar, lpar);
}
}
void addMenu(HWND hwnd)
{
mainMenu = CreateMenu();
HMENU dropMenu = CreateMenu();
AppendMenu(dropMenu, MF_STRING, FILE_MENU_POSITION, "Choose position");
AppendMenu(dropMenu, MF_SEPARATOR, NULL, NULL);
AppendMenu(dropMenu, MF_STRING, FILE_MENU_ATTACK, "Attack ");
AppendMenu(dropMenu, MF_STRING, FILE_MENU_DAMAGE, "Damage System");
AppendMenu(dropMenu, MF_SEPARATOR, NULL, NULL);
AppendMenu(dropMenu, MF_STRING, FILE_MENU_EARN, "Earning System");
AppendMenu(mainMenu, MF_STRING,NULL,"Intro");
AppendMenu(mainMenu, MF_POPUP,(UINT_PTR)dropMenu, "Shooter Game Rules");
AppendMenu(mainMenu, MF_STRING, NULL, "Creators");
AppendMenu(mainMenu, MF_STRING,NULL,"Help");
AppendMenu(mainMenu, MF_STRING, FILE_MENU_EXIT, "Exit");
SetMenu(hwnd,mainMenu);
}
void controls(HWND hwnd)
{
CreateWindowW(L"Static", L"Text",
WS_VISIBLE | WS_CHILD, 200, 100, 400, 250, hwnd, NULL, NULL, NULL);
}
