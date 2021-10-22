/*
 * Created on Sat Jan 2 2021
 *
 * Copyright (c) 2021 UsuiSama
 * 
 * FrameWork creado para la facilitación de manejo del entorno grafico WIN32.
 */
#include "Win32Window.hpp"

win32_x86::UI::Win32Window::Win32Window(const wchar_t* lpWindowName, unsigned long dwStyle, win32_x86::Tool::Rectangle rect, HINSTANCE hInstance, HWND m_hWnd)
{
	this->m_hWnd = m_hWnd;
	this->lpWindowName = lpWindowName;
	this->dwStyle = dwStyle;
	this->rect = rect;
	this->hInstance = hInstance;
}

void win32_x86::UI::Win32Window::Create()
{
	m_hWnd = CreateWindow(L"myWindowClass", lpWindowName, dwStyle, rect.x, rect.y, rect.width, rect.height, nullptr, nullptr, hInstance, nullptr);
}

void win32_x86::UI::Win32Window::CenterScreen()
{
	int screenWidth = GetSystemMetrics(SM_CXSCREEN);
	int screenHeight = GetSystemMetrics(SM_CYSCREEN);
	RECT clientRect;

	GetClientRect(m_hWnd, &clientRect);
	AdjustWindowRect(&clientRect, dwStyle, FALSE);

	int clientWidth;
	int clientHeight;

	__$compute_client(clientWidth, clientRect.right, clientRect.left);
	__$compute_client(clientHeight, clientRect.bottom, clientRect.top);

	int x, y;

	__$compute_xy_axis(x, screenWidth, clientWidth, 2); // screenWidth / 2 - clientWidth / 2
	__$compute_xy_axis(y, screenHeight, clientHeight, 2); // screenHeight / 2 - clientHeight / 2
	SetWindowPos(m_hWnd, NULL, x, y, clientWidth, clientHeight, 0);
}

void win32_x86::UI::Win32Window::HideTitleBar()
{
	SetWindowLong(m_hWnd, GWL_STYLE, WS_BORDER);
}

void win32_x86::UI::Win32Window::Show()
{
	ShowWindow(m_hWnd, SW_SHOW);
}

void win32_x86::UI::Win32Window::Update()
{
	UpdateWindow(m_hWnd);
}

void win32_x86::UI::Win32Window::EnableScrollBar(int maxElement, int y, int height, int range)
{
	RECT rc{ 0 };
	GetClientRect(m_hWnd, &rc);
	SCROLLINFO scroll{ 0 };

	ZeroMemory(&scroll, sizeof(scroll));
	scroll.cbSize = sizeof(SCROLLINFO);
	scroll.fMask = SIF_ALL;
	scroll.nMin = 0;
	scroll.nMax = ComputeMaximumHeight(maxElement, y, height, range);
	scroll.nPage = rc.bottom - rc.top;
	scroll.nPos = 0;
	scroll.nTrackPos = 0;
	SetScrollInfo(m_hWnd, SB_VERT, &scroll, TRUE);
	ShowScrollBar(m_hWnd, SB_VERT, TRUE);
}

void win32_x86::UI::Win32Window::DisableScrollBar(int& iVScrollBarPos)
{
	iVScrollBarPos = 0; // Reiniciar la posicion de la barra de deplazamiento.
	ShowScrollBar(m_hWnd, SB_VERT, FALSE); // Ocultar la barra de deplazamiento.
}

HWND win32_x86::UI::Win32Window::GetHWND() const
{
	return m_hWnd;
}

const wchar_t* win32_x86::UI::Win32Window::GetTitle() const
{
	return lpWindowName;
}

win32_x86::UI::Win32Window::~Win32Window()
{
	DestroyWindow(m_hWnd);
}

int win32_x86::UI::Win32Window::ComputeMaximumHeight(int maxElement, int y, int height, int range)
{
	int i;	// Esta variable se encargará de acumular las repeticiones del bucle.
	__asm	// ➣ Assembly c++ x86  2021
	{
		mov		i, 0x0				; [mov] => Asignar el valor[0] a[i].
	$loop:
		mov		ebx, maxElement		; [mov] => Asignar el valor de[maxElement] a[ebx].
		cmp		i, ebx				; [cmp] => Comparar valor de[i] y[ecx].
		je		$end				; [je]  => Salta a la etiqueta, si es igual.Condición[<(i == ebx ? true : false)>].
		jmp		$sum				; [jmp] => Salta a la etiqueta, sin condicional.
	$continue:
		inc		i					; [inc] => Incrementar contador.
		jmp		$loop				; [jmp] => Salta a la etiqueta, sin condicional.
	$sum:
		mov		ebx, y				; [mov] => Asignar valor de[y] a[ebx].
		add		ebx, height			; [add] => Sumar.Ejemplo ->[<ebx = ebx + height>].
		add		ebx, range			; [add] => Sumar.Ejemplo ->[<ebx = ebx + range>].
		mov		y, ebx				; [mov] => Asignar valor de[ebx] a[y]
		jmp		$continue			; [jmp] => Salta a la etiqueta, sin condicional.
	$end:
		mov		eax, y				; [mov] => Asignar valor de[y] al registro[eax]->Es el que retornara el valor obtenido.
	}
}
