// 2.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "2.h"
#pragma warning(disable : 4996)
#define _CRT_SECURE_NO_WARNINGS

#define MAX_LOADSTRING 100

#define ID_ButtonCreate 3

// Global Variables:

int x = 0;
//���������� ����������:
int nX = 10,//�-���������� ���.�����. ���� ��������� ����
nY = 10,//y-���������� ���.�����. ���� ��������� ����
nW = 100,// ������ ��������� ����
nH = 100,//������ ��������� ����
nW_main = 500,// ������ �������� ����
nH_main = 800;// ������ �������� ����

char p8[200];
char p6[200];
char p7[200];

HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name
HWND hWnd, hChild;
static HWND hEdit1, hEdit2;
// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
ATOM				MyRegisterClassChild(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK	WndProcChild(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_MY2, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);
	MyRegisterClassChild(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY2));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY2));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_MY2);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

ATOM MyRegisterClassChild(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProcChild;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY2));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCE(IDI_MY2);
	wcex.lpszClassName = L"��������";
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);
   hChild = CreateWindow(L"��������", NULL, WS_CHILDWINDOW | WS_VISIBLE, 170, 100, 100, 100, hWnd, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
HBRUSH hBrush = CreateSolidBrush(RGB(0, 255, 0));
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	static BOOL bToRight = 1, bToDown = 1;
	static int nChildLeft = 170, nChildTop = 100, nChildWidht = 100, intChildHeight = 100;
	switch (message)
	{
	case WM_CREATE://� ������ �������� �������� ���� ������� ������
		SetTimer(hWnd, ID_TIMER, 5, NULL);//������� ������ 
		ShowWindow(hChild, SW_SHOWNORMAL);
		return 0;
	case WM_TIMER:
		if (x % 100 == 0)
		{
			MoveWindow(hChild, nChildLeft, nChildTop, nChildWidht++, intChildHeight, TRUE);
		}
		hBrush = CreateSolidBrush(RGB(nChildTop, nChildLeft, intChildHeight));
		SetClassLong(hChild, GCL_HBRBACKGROUND, (LONG)(hBrush));// ��������� �� �������
		if (bToRight)// ���� ����� ���������� ������ 
			nChildLeft = nChildLeft + 3;//����������� �-���������� ��������� ����
		else nChildLeft = nChildLeft - 3;//����� ��������� �-����������
		if (nChildLeft + nChildWidht > nW_main)//���� ��������� ������ ������� ���� 
			bToRight = 0;//��������� ������ ������
		if (nChildLeft < 0) //���� ��������� ����� ������� ����
			bToRight = 1;//��������� ������ �����
		if (intChildHeight + nChildTop > nH_main)
			bToDown = 0;
		if (nChildTop < 0)
			bToDown = 1;
		if (bToDown)// ���� ����� ���������� ������ 
			nChildTop = nChildTop + 1;//����������� �-���������� ��������� ����
		else nChildTop = nChildTop - 1;//�������� ����

		if (nChildTop + intChildHeight > nH_main) bToDown = 0;//���� ��������� ������ ������� 
		MoveWindow(hChild, nChildLeft, nChildTop, nChildWidht, intChildHeight, TRUE);// ���������� �������� ����
		UpdateWindow(hChild);
		UpdateWindow(hWnd);

		x++;
		break;
	case WM_SIZE:
		// ������ ���������� ������� �������� ����
		nW_main = LOWORD(lParam);
		// ������ ���������� ������� �������� ����
		nH_main = HIWORD(lParam);
		break;
	case WM_COMMAND:
	{
		wmId = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		case WM_CREATE://� ������ �������� �������� ���� ������� ������
			ShowWindow(hChild, SW_SHOWNORMAL);
			return 0;
		case WM_SIZE:
			// ������ ���������� ������� �������� ����
			nW_main = LOWORD(lParam);
			// ������ ���������� ������� �������� ����
			nH_main = HIWORD(lParam);
			break;
		case ID_ButtonCreate:
			ShowWindow(hChild, SW_SHOWNORMAL);
			break;
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	}
	case WM_PAINT:
	{
		hdc = BeginPaint(hWnd, &ps);
		// TODO: Add any drawing code that uses hdc here...
		EndPaint(hWnd, &ps);
	}
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

LRESULT CALLBACK WndProcChild(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
	case WM_COMMAND:
		wmId = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// ��������� ����� � ����:
		switch (wmId)
		{
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO: �������� ����� ��� ���������...
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
