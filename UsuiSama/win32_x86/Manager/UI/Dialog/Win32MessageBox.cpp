/*
 * Created on Sat Jan 2 2021
 *
 * Copyright (c) 2021 UsuiSama
 * 
 * FrameWork creado para la facilitación de manejo del entorno grafico WIN32.
 */
#include "Win32MessageBox.hpp"

int win32_x86::UI::Dialog::Win32MessageBox::Show(const wchar_t* Text, const wchar_t* Title, unsigned int Type)
{
	try
	{
		__memory_allocation__(win32_x86::UI::Dialog::Win32MessageBox, message)();
		int maux = MessageBox(message->GetHWND(), Text, Title, Type);
		__free_memory__(message);
		return maux;
	}
	catch (...)
	{
		MessageBox(nullptr, L"No hay [memoria] disponible!!!", L"Win32 Diagnostics", MB_OK | MB_DEFBUTTON1 | MB_ICONERROR);
		return 0;
	}
}

int win32_x86::UI::Dialog::Win32MessageBox::Show(const wchar_t* Text, unsigned int Type)
{
	try
	{
		__memory_allocation__(win32_x86::UI::Dialog::Win32MessageBox, message)();
		int maux = MessageBox(message->GetHWND(), Text, message->GetTitle(), Type);
		__free_memory__(message);
		return maux;
	}
	catch (...)
	{
		MessageBox(nullptr, L"No hay [memoria] disponible!!!", L"Win32 Diagnostics", MB_OK | MB_DEFBUTTON1 | MB_ICONERROR);
		return 0;
	}
}

int win32_x86::UI::Dialog::Win32MessageBox::$Show(const wchar_t* Text, const wchar_t* Title, unsigned int Type)
{
	return MessageBox(nullptr, Text, Title, Type);
}

