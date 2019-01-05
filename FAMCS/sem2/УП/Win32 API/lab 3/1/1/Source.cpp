#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>

#define ID_Red1 1
#define ID_Red2 2
#define ID_Green1 3
#define ID_Green2 4
#define ID_Blue1 5
#define ID_Blue2 6


LONG WINAPI WndProc(HWND, UINT, WPARAM, LPARAM);


int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR     lpCmdLine,
	int       nCmdShow) {
	HWND hwnd, hRed1, hRed2, hGreen1, hGreen2, hBlue1, hBlue2;
	MSG msg;
	WNDCLASS w;
	memset(&w, 0, sizeof(WNDCLASS));
	w.style = CS_HREDRAW | CS_VREDRAW;
	w.lpfnWndProc = WndProc;
	w.hInstance = hInstance;
	w.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	w.lpszClassName = L"My Class";
	RegisterClass(&w);
	hwnd = CreateWindow(L"My Class", L"Win Api 32", WS_OVERLAPPEDWINDOW,
		300, 200, 500, 400, NULL, NULL, hInstance, NULL);

	hRed1 = CreateWindow(L"button", L"������� +", WS_CHILD | WS_VISIBLE,
		20, 20, 180, 30, hwnd, (HMENU)ID_Red1, hInstance, NULL);
	hRed2 = CreateWindow(L"button", L"������� -", WS_CHILD | WS_VISIBLE,
		20, 60, 180, 30, hwnd, (HMENU)ID_Red2, hInstance, NULL);
	hGreen1 = CreateWindow(L"button", L"������� +", WS_CHILD | WS_VISIBLE,
		20, 100, 180, 30, hwnd, (HMENU)ID_Green1, hInstance, NULL);
	hGreen2 = CreateWindow(L"button", L"������� -", WS_CHILD | WS_VISIBLE,
		20, 140, 180, 30, hwnd, (HMENU)ID_Green2, hInstance, NULL);
	hBlue1 = CreateWindow(L"button", L"����� +", WS_CHILD | WS_VISIBLE,
		20, 180, 180, 30, hwnd, (HMENU)ID_Blue1, hInstance, NULL);
	hBlue2 = CreateWindow(L"button", L"����� -", WS_CHILD | WS_VISIBLE,
		20, 220, 180, 30, hwnd, (HMENU)ID_Blue2, hInstance, NULL);

	//button1
	//CreateWindow(L"button", L"+", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
	//	10, 10,//coord-s of left up corner
	//	80, 30,   //width, height
	//	hwnd, (HMENU)10000, hInstance, NULL);
	//

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}


LONG WINAPI WndProc(HWND hwnd, UINT Message, WPARAM wparam, LPARAM lparam) {
	HDC hdc; //�������� ��� ���������
	PAINTSTRUCT ps; //��������� ��� ���������
	int wmId, wmEvent;

	static short Red = 255, Green = 255, Blue = 255;// ������������ �����
	static COLORREF mycolor = RGB(Red, Green, Blue);//������� ����
	HBRUSH hBr;//�����  
	RECT Rect;//������������� ��� �����������
	Rect.left = 250;
	Rect.top = 60;
	Rect.right = 440;
	Rect.bottom = 205;

	switch (Message) {

	case WM_COMMAND:
		wmId = LOWORD(wparam);
		wmEvent = HIWORD(wparam);
		// ��������� ����� � ���� ��� ��������� �� ��������� ����
		switch (wmId)
		{
		case ID_Red1: Red += 5; if (Red>255)Red = 255;
			break;
		case ID_Red2: Red -= 5; if (Red<0)Red = 0;
			break;
		case ID_Green1: Green += 5; if (Green>255)Green = 255;
			break;
		case ID_Green2: Green -= 5; if (Green<0)Green = 0;
			break;
		case ID_Blue1: Blue += 5; if (Blue>255)Blue = 255;
			break;
		case ID_Blue2: Blue -= 5; if (Blue<0)Blue = 0;
			break;
			/*case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
			case IDM_EXIT:
			DestroyWindow(hWnd);
			break;*/
		}
		// �������� ���� 
		mycolor = RGB(Red, Green, Blue);
		// �������� �������, ��������������� ��������������, ��������� ����������
		InvalidateRect(hwnd, &Rect, TRUE);
		UpdateWindow(hwnd);
		break;

	case WM_PAINT:
		//�������� �������� ��� ���������
		hdc = BeginPaint(hwnd, &ps);
		//������� �������� ����� ������� �����
		hBr = CreateSolidBrush(mycolor);
		//���������� ������������� Rect ������ hBr
		FillRect(hdc, &Rect, hBr);
		//������� �������� ����� ������� �����
		hBr = CreateSolidBrush(RGB(0, 0, 0));
		//������ ����� ������ �������������� 
		FrameRect(hdc, &Rect, hBr);
		//����������� ��������
		EndPaint(hwnd, &ps);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hwnd, Message, wparam, lparam);
	}
	return 0;
}