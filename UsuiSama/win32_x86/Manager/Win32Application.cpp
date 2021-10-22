/*
 * Created on Sat Jan 2 2021
 *
 * Copyright (c) 2021 UsuiSama
 *
 * FrameWork creado para la facilitación de manejo del entorno grafico WIN32.
 */
#include "Win32Application.hpp"

void win32_x86::Manager::Win32Application::Start(HINSTANCE hInstance, std::function<unique_ptr<win32_x86::Events::HandleEvents>()> app)
{
	auxapp = app(); // Pasar Parametros
	// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	//  MyRegisterClass
	hInst = hInstance;
	auto parameters = auxapp->$Win32Parameters();

	WNDCLASSEXW wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = Win32EventControl;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, parameters.icon);
	wcex.hCursor = LoadCursor(nullptr, parameters.arrow);
	wcex.hbrBackground = parameters.bitmap;
	wcex.lpszMenuName = 0;
	wcex.lpszClassName = L"myWindowClass";
	wcex.hIconSm = LoadIcon(wcex.hInstance, parameters.arrow);

	RegisterClassExW(&wcex);

	// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	// InitInstance

	win32_x86::Tool::Rectangle rect{ 0 };

	hInst = hInstance;
	if (app()->Win32InitInstance(hInstance, &window, rect))
		error = false;
}

int win32_x86::Manager::Win32Application::MessageLoop()
{
	if (!error)
	{
		static MSG msg;
		// Bucle principal de mensajes:
		while (GetMessage(&msg, NULL, 0, 0) > 0)
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		return (int)msg.wParam;
	}
	else
	{
		win32_x86::UI::Dialog::Win32MessageBox::Show(L"La cagaste mal viejo!!! XD", L"Win32 Diagnostics", win32_x86::UI::Dialog::Button::Win32Button::Ok |
			win32_x86::UI::Dialog::DefaultButton::Win32DefaultButton::Button1 | win32_x86::UI::Dialog::Icon::Win32Icon::Error);
		return EXIT_FAILURE;
	}
}

void win32_x86::Manager::Win32Application::close()
{
	if (window != nullptr)
	{
		wstringstream wss;

		wss << L"El objeto [<window>] alojado en la memoria [<" << L"0x" << window.get() << L">] se eliminará."
			<< L"\n\nEliminando...\nRegistrando Operación...\n[Win32System(Fecha:=\"" << __DATE__ << L"\", Hora:=\"" << __TIME__ << "\")]";

		MessageBox(window->GetHWND(), wss.str().c_str(), L"Win32System", MB_OK | MB_DEFBUTTON1 | MB_ICONINFORMATION);
		window = nullptr;
	}
}

void win32_x86::Manager::Win32Application::scroll_bar(WPARAM wParam, int& iVScrollBarPos) // XDD
{
	auto mensaje = LOWORD(wParam);
	int posicion = -1;
	if (mensaje == SB_THUMBPOSITION || mensaje == SB_THUMBTRACK)
		posicion = HIWORD(wParam);
	else if (mensaje == SB_LINEDOWN)
		posicion = iVScrollBarPos + 10;
	else if (mensaje == SB_LINEUP)
		posicion = iVScrollBarPos - 10;
	if (posicion == -1)
		return;
	// Desplazamos el contenido del área de cliente de la ventana especificada.
	ScrollWindow(window->GetHWND(), 0, UpdateScrollBar(posicion, iVScrollBarPos), NULL, NULL);
	iVScrollBarPos = posicion;
}

void win32_x86::Manager::Win32Application::scroll_bar_mouse_wheel(int y, int& iVScrollBarPos)
{
	int posicion = -1;
	if (y > 0)
		posicion = iVScrollBarPos - 10; // Up => Subir
	else
		posicion = iVScrollBarPos + 10; // Down => Bajar
	if (posicion == -1)
		return;
	// Desplazamos el contenido del área de cliente de la ventana especificada.
	ScrollWindow(window->GetHWND(), 0, UpdateScrollBar(posicion, iVScrollBarPos), NULL, NULL);
	iVScrollBarPos = posicion;
}

long win32_x86::Manager::Win32Application::mouse_move(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	long mouse = DefWindowProc(hWnd, message, wParam, lParam);
	if (mouse == HTCLIENT) mouse = HTCAPTION;
	return mouse;
}

void win32_x86::Manager::Win32Application::paint(std::function<void(HDC&, PAINTSTRUCT&)> process)
{
	try
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(window->GetHWND(), &ps);
		process(hdc, ps);
		EndPaint(window->GetHWND(), &ps);
	}
	catch (...)
	{
		window = nullptr;
	}
}

void win32_x86::Manager::Win32Application::Win32Close()
{
	window = nullptr;
}

void win32_x86::Manager::Win32Application::ReleaseResourceAndExit()
{
	throw "exit";
}

void win32_x86::Manager::Win32Application::Exit()
{
	window = nullptr;
	ExitProcess(0);
}

HINSTANCE win32_x86::Manager::Win32Application::GetInstance()
{
	return hInst;
}

HWND win32_x86::Manager::Win32Application::GetHWND()
{
	return window->GetHWND();
}

LPCWSTR win32_x86::Manager::Win32Application::GetTitle()
{
	return window->GetTitle();
}

win32_x86::UI::Win32Window* win32_x86::Manager::Win32Application::GetWindow()
{
	return window.get();
}

unique_ptr<win32_x86::Events::HandleEvents> win32_x86::Manager::Win32Application::auxapp{ nullptr };
unique_ptr<win32_x86::UI::Win32Window> win32_x86::Manager::Win32Application::window{ nullptr };
HINSTANCE win32_x86::Manager::Win32Application::hInst{ nullptr };
bool win32_x86::Manager::Win32Application::error = true;

long win32_x86::Manager::Win32Application::Win32EventControl(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		/*case WM_NCHITTEST:
			return auxapp->Win32NChitTest(hWnd, message, wParam, lParam);
		case WM_CREATE:
			auxapp->Win32Create();
			break;
		case WM_KEYUP:
			auxapp->Win32KeyUp(wParam);
			break;
		case WM_COMMAND:
			auxapp->Win32Command(hWnd, wParam, hInst);
			break;
		case WM_VSCROLL:
			auxapp->Win32VScroll(wParam);
			break;
		case WM_MOUSEWHEEL:
			return auxapp->Win32MouseWheel(wParam);
		case WM_DRAWITEM:
			auxapp->Win32DrawItem(lParam);
			break;
		case WM_NOTIFY:
			return auxapp->Win32Notify(hWnd, lParam);
			break;
		case WM_CTLCOLORBTN:
			return auxapp->Win32CtlColorBtn();
		case WM_PAINT:
			auxapp->Win32Paint();
			break;*/
	case WM_CLOSE:
		auxapp->Win32Close();
		break;
	case WM_DESTROY:
		auxapp->Win32Destroy();
		auxapp = nullptr;
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

int win32_x86::Manager::Win32Application::UpdateScrollBar(int& y, int iVScrollBarPos)
{
	POINT point;
	SCROLLINFO scroll = { 0 };
	scroll.cbSize = sizeof(SCROLLINFO);
	scroll.fMask = SIF_POS;
	scroll.nPos = y;
	scroll.nTrackPos = 0;
	SetScrollInfo(window->GetHWND(), SB_VERT, &scroll, TRUE); // Asignamos los nuevos datos al scroll
	GetScrollInfo(window->GetHWND(), SB_VERT, &scroll); // Obtenemos los datos al scroll
	y = scroll.nPos;
	point.x = 0;
	point.y = y - iVScrollBarPos;
	return -point.y;
}

