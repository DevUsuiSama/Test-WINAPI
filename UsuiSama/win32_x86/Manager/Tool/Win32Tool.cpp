#include "Win32Tool.hpp"

#ifdef __WIN32WINDOW_HPP__

HBITMAP win32_x86::Tool::Win32Tool::$LoadBitmap(LPCWSTR lpBitmapName)
{
	try
	{
		__MemoryAllocation__(win32_x86::Tool::Win32Tool, tool)();
		HBITMAP bitmap = LoadBitmap(tool->GetInstance(), lpBitmapName);
		__FreeMemory__(tool);
		return bitmap;
	}
	catch (...)
	{
		MessageBox(nullptr, L"No hay [memoria] disponible!!!", L"Win32 Diagnostics", MB_OK | MB_DEFBUTTON1 | MB_ICONERROR);
		return nullptr;
	}
}

long win32_x86::Tool::Win32Tool::$SendMessage(UINT Msg, WPARAM wParam, LPARAM lParam)
{
	try
	{
		__MemoryAllocation__(win32_x86::Tool::Win32Tool, tool)();
		long send = SendMessage(tool->GetHWND(), Msg, wParam, lParam);
		__FreeMemory__(tool);
		return send;
	}
	catch (...)
	{
		MessageBox(nullptr, L"No hay [memoria] disponible!!!", L"Win32 Diagnostics", MB_OK | MB_DEFBUTTON1 | MB_ICONERROR);
		return 0;
	}
}

#endif // __WIN32WINDOW_HPP__


