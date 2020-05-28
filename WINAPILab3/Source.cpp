#include <Windows.h>
#include <tchar.h>
#include "resource.h"


LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);
HWND HCombo1;
TCHAR String1[] = _T("Москва");
TCHAR String2[] = _T("Санкт-Петербург");
TCHAR String3[] = _T("Волгоград");
TCHAR String4[] = _T("Самара");
TCHAR String5[] = _T("Астрахань");
TCHAR String6[] = _T("Нижний Новгород");
TCHAR String7[] = _T("Тверь");
TCHAR String8[] = _T("Смоленск");
TCHAR String9[] = _T("Брянск");
TCHAR String10[] = _T("Курск");
TCHAR String11[] = _T("Прага");
TCHAR String12[] = _T("Париж");
TCHAR String13[] = _T("Лондон");
TCHAR String14[] = _T("Генуя");
TCHAR String15[] = _T("Бизнес");
TCHAR String16[] = _T("Эконом");
TCHAR WinName[] = _T("MainFrame");
TCHAR MenuName[] = _T("MENU");

int WINAPI _tWinMain(HINSTANCE This,		 // Дескриптор текущего приложения 
	HINSTANCE Prev, 	// В современных системах всегда 0 
	LPTSTR cmd, 		// Командная строка 
	int mode) 		// Режим отображения окна
{
	HWND hWnd;		// Дескриптор главного окна программы 
	MSG msg; 		// Структура для хранения сообщения 
	WNDCLASS wc; 	// Класс окна
	HINSTANCE hInstance = This;
	// Определение класса окна 
	wc.hInstance = hInstance;
	wc.lpszClassName = WinName; 				// Имя класса окна 
	wc.lpfnWndProc = WndProc; 					// Функция окна 
	wc.style = CS_HREDRAW | CS_VREDRAW; 			// Стиль окна 
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION); 		// Стандартная иконка 
	wc.hCursor = LoadCursor(NULL, IDC_ARROW); 		// Стандартный курсор 
	wc.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1); 					// меню 
	wc.cbClsExtra = 0; 						// Нет дополнительных данных класса 
	wc.cbWndExtra = 0; 						// Нет дополнительных данных окна 
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	//wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1); 	// Заполнение окна белым цветом 

	
		// Регистрация класса окна
	if (!RegisterClass(&wc)) return 0;

	// Создание окна 
	hWnd = CreateWindow(WinName,			// Имя класса окна 
		_T("Покупка билета"), 		// Заголовок окна 
		WS_OVERLAPPEDWINDOW, 		// Стиль окна 
		CW_USEDEFAULT,				// x 
		CW_USEDEFAULT, 				// y	 Размеры окна 
		CW_USEDEFAULT, 				// width 
		CW_USEDEFAULT, 				// Height 
		HWND_DESKTOP, 				// Дескриптор родительского окна 
		NULL, 						// Нет меню 
		hInstance, 						// Дескриптор приложения 
		NULL); 					// Дополнительной информации нет 

	ShowWindow(hWnd, mode); 				// Показать окно

	// Цикл обработки сообщений 
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg); 		// Функция трансляции кодов нажатой клавиши 
		DispatchMessage(&msg); 		// Посылает сообщение функции WndProc() 
	}
	//DialogBoxParam(This, MAKEINTRESOURCE(IDD_DIALOG1),0, DlgProc,0);
	return 0;
}


// Оконная функция вызывается операционной системой
// и получает сообщения из очереди для данного приложения

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC hdc, hCompatibleDC; //создаём контекст устройства
	HANDLE hbitmap, holdbitmap;
	RECT rect;
	BITMAP bitmap;
	PAINTSTRUCT ps; //создаём экземпляр структуры графического вывода
	//RECT rect2 = { x - 100, y - 100, x + 100, y + 100 };
	static int i = 0;
	//HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255));
	//HPEN pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
	
	//static int   sw;
	static HINSTANCE hInstance;

	switch (message)		 // Обработчик сообщений
	{

	case  WM_COMMAND:
		switch (wParam) {
		case ID_40001:   //Купить билет
		{
			
			InvalidateRect(hWnd, NULL, TRUE);
			DialogBoxParam(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), 0, DlgProc, 0);
		}
			break;
		case ID_40004:  //Флот
		{
		
			MessageBox(hWnd, _T("Все рейсы выполняются на самолетах ведущих мировых производителей: Airbus (61 лайнеров), Boeing (23 лайнера) и Embraer (17 лайнеров). Всего в нашем парке 101 воздушное судно."),
				_T("Информация: Флот"), MB_OK|MB_ICONINFORMATION); // MB_YESNO
			InvalidateRect(hWnd, NULL, TRUE);
		}
		     break;
		case ID_40005:  //О компании
		{
		
			MessageBox(hWnd, _T("Контакты:\nТелефон (бесплатно по России): 8 800 700–0909"),
				_T("Информация: О компании"), MB_OK|MB_ICONINFORMATION); // MB_YESNO
			InvalidateRect(hWnd, NULL, TRUE);
		}
		     break;
		case ID_40006:  //Россия
		{
			
			MessageBox(hWnd, _T("Москва\nСанкт-Петербург\nВолгоград\nСамара\nАстрахань\nНижний Новгород\nТверь\nСмоленск\nБрянск\nКурск"),
				_T("Направления: Россия"), MB_OK); // MB_YESNO
			InvalidateRect(hWnd, NULL, TRUE);
		}
		     break;
		case ID_40007:  //Международные рейсы
		{
			
			MessageBox(hWnd, _T("Париж\nПрага\nЛондон\nГенуя"),
				_T("Направления: Международные рейсы"), MB_OK); // MB_YESNO
			InvalidateRect(hWnd, NULL, TRUE);
		}
			break;
		case ID_40003:   //Выход
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
		hCompatibleDC = CreateCompatibleDC(hdc);  //"C:\\Users\\Настя\\source\\repos\\WINAPILab3\\WINAPILab3\\PLANE.bmp"
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

//Москва; Санкт-Петербург; Волгоград; Самара; Астрахань; Нижний Новгород; Тверь; Смоленск; Брянск; Курск
BOOL CALLBACK DlgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	TCHAR str_1[250];
	static int i1 = 0, i2=0, i3=0, i4=0, i5=0;
	switch (message)		 // Обработчик сообщений
	{
	case WM_INITDIALOG:  //Инициализация диалогового окна
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
	case WM_COMMAND:     //Обработчик команд
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
				MessageBox(hWnd, _T("Покупка билета совершена!"), _T("Сообщение"), MB_OK); // MB_YESNO
				EndDialog(hWnd, 0);
			}
			if ((i1&&i2&&i3&&i4&&i5) == 0)
				MessageBox(hWnd, _T("Введены не все данные!"), _T("Сообщение"), MB_OK);
		}
			break;
		case IDCANCEL:      //Нажата кнопка "Отмена"
			EndDialog(hWnd, 0);        //Закрыть диалог
			break;
		}
	}
	break;
	case WM_CLOSE:       //Обработка кнопки закрытия окна
	{
		EndDialog(hWnd, 0);
		return TRUE;
	}
	break;
	default:
		return FALSE;

	}
}
