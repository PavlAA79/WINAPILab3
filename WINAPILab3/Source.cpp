#include <Windows.h>
#include <tchar.h>
#include "resource.h"


LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);
HWND HCombo1;
TCHAR String1[] = _T("������");
TCHAR String2[] = _T("�����-���������");
TCHAR String3[] = _T("���������");
TCHAR String4[] = _T("������");
TCHAR String5[] = _T("���������");
TCHAR String6[] = _T("������ ��������");
TCHAR String7[] = _T("�����");
TCHAR String8[] = _T("��������");
TCHAR String9[] = _T("������");
TCHAR String10[] = _T("�����");
TCHAR String11[] = _T("�����");
TCHAR String12[] = _T("�����");
TCHAR String13[] = _T("������");
TCHAR String14[] = _T("�����");
TCHAR String15[] = _T("������");
TCHAR String16[] = _T("������");
TCHAR WinName[] = _T("MainFrame");
TCHAR MenuName[] = _T("MENU");

int WINAPI _tWinMain(HINSTANCE This,		 // ���������� �������� ���������� 
	HINSTANCE Prev, 	// � ����������� �������� ������ 0 
	LPTSTR cmd, 		// ��������� ������ 
	int mode) 		// ����� ����������� ����
{
	HWND hWnd;		// ���������� �������� ���� ��������� 
	MSG msg; 		// ��������� ��� �������� ��������� 
	WNDCLASS wc; 	// ����� ����
	HINSTANCE hInstance = This;
	// ����������� ������ ���� 
	wc.hInstance = hInstance;
	wc.lpszClassName = WinName; 				// ��� ������ ���� 
	wc.lpfnWndProc = WndProc; 					// ������� ���� 
	wc.style = CS_HREDRAW | CS_VREDRAW; 			// ����� ���� 
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION); 		// ����������� ������ 
	wc.hCursor = LoadCursor(NULL, IDC_ARROW); 		// ����������� ������ 
	wc.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1); 					// ���� 
	wc.cbClsExtra = 0; 						// ��� �������������� ������ ������ 
	wc.cbWndExtra = 0; 						// ��� �������������� ������ ���� 
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	//wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1); 	// ���������� ���� ����� ������ 

	
		// ����������� ������ ����
	if (!RegisterClass(&wc)) return 0;

	// �������� ���� 
	hWnd = CreateWindow(WinName,			// ��� ������ ���� 
		_T("������� ������"), 		// ��������� ���� 
		WS_OVERLAPPEDWINDOW, 		// ����� ���� 
		CW_USEDEFAULT,				// x 
		CW_USEDEFAULT, 				// y	 ������� ���� 
		CW_USEDEFAULT, 				// width 
		CW_USEDEFAULT, 				// Height 
		HWND_DESKTOP, 				// ���������� ������������� ���� 
		NULL, 						// ��� ���� 
		hInstance, 						// ���������� ���������� 
		NULL); 					// �������������� ���������� ��� 

	ShowWindow(hWnd, mode); 				// �������� ����

	// ���� ��������� ��������� 
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg); 		// ������� ���������� ����� ������� ������� 
		DispatchMessage(&msg); 		// �������� ��������� ������� WndProc() 
	}
	//DialogBoxParam(This, MAKEINTRESOURCE(IDD_DIALOG1),0, DlgProc,0);
	return 0;
}


// ������� ������� ���������� ������������ ��������
// � �������� ��������� �� ������� ��� ������� ����������

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC hdc, hCompatibleDC; //������ �������� ����������
	HANDLE hbitmap, holdbitmap;
	RECT rect;
	BITMAP bitmap;
	PAINTSTRUCT ps; //������ ��������� ��������� ������������ ������
	//RECT rect2 = { x - 100, y - 100, x + 100, y + 100 };
	static int i = 0;
	//HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255));
	//HPEN pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
	
	//static int   sw;
	static HINSTANCE hInstance;

	switch (message)		 // ���������� ���������
	{

	case  WM_COMMAND:
		switch (wParam) {
		case ID_40001:   //������ �����
		{
			
			InvalidateRect(hWnd, NULL, TRUE);
			DialogBoxParam(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), 0, DlgProc, 0);
		}
			break;
		case ID_40004:  //����
		{
		
			MessageBox(hWnd, _T("��� ����� ����������� �� ��������� ������� ������� ��������������: Airbus (61 ��������), Boeing (23 �������) � Embraer (17 ��������). ����� � ����� ����� 101 ��������� �����."),
				_T("����������: ����"), MB_OK|MB_ICONINFORMATION); // MB_YESNO
			InvalidateRect(hWnd, NULL, TRUE);
		}
		     break;
		case ID_40005:  //� ��������
		{
		
			MessageBox(hWnd, _T("��������:\n������� (��������� �� ������): 8 800 700�0909"),
				_T("����������: � ��������"), MB_OK|MB_ICONINFORMATION); // MB_YESNO
			InvalidateRect(hWnd, NULL, TRUE);
		}
		     break;
		case ID_40006:  //������
		{
			
			MessageBox(hWnd, _T("������\n�����-���������\n���������\n������\n���������\n������ ��������\n�����\n��������\n������\n�����"),
				_T("�����������: ������"), MB_OK); // MB_YESNO
			InvalidateRect(hWnd, NULL, TRUE);
		}
		     break;
		case ID_40007:  //������������� �����
		{
			
			MessageBox(hWnd, _T("�����\n�����\n������\n�����"),
				_T("�����������: ������������� �����"), MB_OK); // MB_YESNO
			InvalidateRect(hWnd, NULL, TRUE);
		}
			break;
		case ID_40003:   //�����
		{
			DestroyWindow(hWnd);
		}
			break;
		}
	case WM_PAINT:
	{
		
		HDC hdc = BeginPaint(hWnd, &ps);
		/*if (sw == 1)
		{

		}
		if (sw == 2)
		{

		}*/
		hbitmap = LoadImage(NULL, L"PLANE.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		GetObject(hbitmap, sizeof(BITMAP), &bitmap);
		hCompatibleDC = CreateCompatibleDC(hdc);  //"C:\\Users\\�����\\source\\repos\\WINAPILab3\\WINAPILab3\\PLANE.bmp"
		holdbitmap = SelectObject(hCompatibleDC, hbitmap);
		GetClientRect(hWnd, &rect);
		StretchBlt(hdc, 0, 0, rect.right, rect.bottom, hCompatibleDC, 0, 0, bitmap.bmWidth, bitmap.bmHeight, SRCCOPY);
		SelectObject(hCompatibleDC, holdbitmap);
		EndPaint(hWnd, &ps);
	}
	break;
	case WM_DESTROY: PostQuitMessage(0); break;
	default: return DefWindowProc(hWnd, message, wParam, lParam);
	}

	return 0;
}

//������; �����-���������; ���������; ������; ���������; ������ ��������; �����; ��������; ������; �����
BOOL CALLBACK DlgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	TCHAR str_1[250];
	static int i1 = 0, i2=0, i3=0, i4=0, i5=0;
	switch (message)		 // ���������� ���������
	{
	case WM_INITDIALOG:  //������������� ����������� ����
	{
	     HCombo1 = GetDlgItem(hWnd, IDC_COMBO1);
		 SendMessage(HCombo1, CB_ADDSTRING, 0, (LPARAM)String1);
		 SendMessage(HCombo1, CB_ADDSTRING, 0, (LPARAM)String2);
		 SendMessage(HCombo1, CB_ADDSTRING, 0, (LPARAM)String3);
		 SendMessage(HCombo1, CB_ADDSTRING, 0, (LPARAM)String4);
		 SendMessage(HCombo1, CB_ADDSTRING, 0, (LPARAM)String5);
		 SendMessage(HCombo1, CB_ADDSTRING, 0, (LPARAM)String6);
		 SendMessage(HCombo1, CB_ADDSTRING, 0, (LPARAM)String7);
		 SendMessage(HCombo1, CB_ADDSTRING, 0, (LPARAM)String8);
		 SendMessage(HCombo1, CB_ADDSTRING, 0, (LPARAM)String9);
		 SendMessage(HCombo1, CB_ADDSTRING, 0, (LPARAM)String10);
		 SendMessage(HCombo1, CB_ADDSTRING, 0, (LPARAM)String11);
		 SendMessage(HCombo1, CB_ADDSTRING, 0, (LPARAM)String12);
		 SendMessage(HCombo1, CB_ADDSTRING, 0, (LPARAM)String13);
		 SendMessage(HCombo1, CB_ADDSTRING, 0, (LPARAM)String14);
		 HCombo1 = GetDlgItem(hWnd, IDC_COMBO2);
		 SendMessage(HCombo1, CB_ADDSTRING, 0, (LPARAM)String1);
		 SendMessage(HCombo1, CB_ADDSTRING, 0, (LPARAM)String2);
		 SendMessage(HCombo1, CB_ADDSTRING, 0, (LPARAM)String3);
		 SendMessage(HCombo1, CB_ADDSTRING, 0, (LPARAM)String4);
		 SendMessage(HCombo1, CB_ADDSTRING, 0, (LPARAM)String5);
		 SendMessage(HCombo1, CB_ADDSTRING, 0, (LPARAM)String6);
		 SendMessage(HCombo1, CB_ADDSTRING, 0, (LPARAM)String7);
		 SendMessage(HCombo1, CB_ADDSTRING, 0, (LPARAM)String8);
		 SendMessage(HCombo1, CB_ADDSTRING, 0, (LPARAM)String9);
		 SendMessage(HCombo1, CB_ADDSTRING, 0, (LPARAM)String10);
		 SendMessage(HCombo1, CB_ADDSTRING, 0, (LPARAM)String11);
		 SendMessage(HCombo1, CB_ADDSTRING, 0, (LPARAM)String12);
		 SendMessage(HCombo1, CB_ADDSTRING, 0, (LPARAM)String13);
		 SendMessage(HCombo1, CB_ADDSTRING, 0, (LPARAM)String14);
		 HCombo1 = GetDlgItem(hWnd, IDC_COMBO3);
		 SendMessage(HCombo1, CB_ADDSTRING, 0, (LPARAM)String15);
		 SendMessage(HCombo1, CB_ADDSTRING, 0, (LPARAM)String16);
	}
	break;
	case WM_COMMAND:     //���������� ������
	{
		switch (LOWORD(wParam))
		{
		case IDC_COMBO1:
		{
			if (HIWORD(wParam) == CBN_SELENDOK)
			{
				i1 = SendMessage(HCombo1,CB_GETCURSEL, 0, 0);
				//SendMessage(hWnd, CB_GETLBTEXT, i1, LPARAM(str_1));
			}
			
		}
			break;
		case IDC_COMBO2:
		{
			if (HIWORD(wParam) == CBN_SELENDOK)
				
			{
				i2 = SendMessage(HCombo1, CB_GETCURSEL, 0, 0);
			}
		}
		break;
		case IDC_COMBO3:
		{
			if (HIWORD(wParam) == CBN_SELENDOK)
			{
				i3 = SendMessage(HCombo1, CB_GETCURSEL, 0, 0);
			}
		}
		break;
		case IDC_EDIT1:
		{
			if (HIWORD(wParam) == EN_CHANGE)
			{
				i4++;
			
			}
		}
	
		break;
		case IDC_EDIT2:
		{
			if (HIWORD(wParam) == EN_CHANGE)
			{
				i5++;
				
			}
		}
		break;
		case IDOK:
		//MessageBox(hWnd, str_1, _T("info"), NULL); // MB_YESNO
		{
			if ((i1&&i2&&i3&&i4&&i5) != 0)
			{
				MessageBox(hWnd, _T("������� ������ ���������!"), _T("���������"), MB_OK); // MB_YESNO
				EndDialog(hWnd, 0);
			}
			if ((i1&&i2&&i3&&i4&&i5) == 0)
				MessageBox(hWnd, _T("������� �� ��� ������!"), _T("���������"), MB_OK);
		}
			break;
		case IDCANCEL:      //������ ������ "������"
			EndDialog(hWnd, 0);        //������� ������
			break;
		}
	}
	break;
	case WM_CLOSE:       //��������� ������ �������� ����
	{
		EndDialog(hWnd, 0);
		return TRUE;
	}
	break;
	default:
		return FALSE;

	}
}
