/*
 * Created on Sat Jan 2 2021
 *
 * Copyright (c) 2021 UsuiSama
 *
 * FrameWork creado para la facilitación de manejo del entorno grafico WIN32.
 */
#ifdef __WIN32WINDOW_HPP__
#include <win32_x86/Manager/Win32Application.hpp>
#endif // __WIN32WINDOW_HPP__

 //#ifndef __WIN32TOOL_HPP__
 //#define __WIN32TOOL_HPP__

namespace win32_x86
{
    namespace Tool
    {
#ifndef __WIN32WINDOW_HPP__
#ifndef __WIN32TOOL_HPP__
#define __WIN32TOOL_HPP__
        // Estructura de datos
        struct Rectangle { int x, y, width, height; };
#endif // !__WIN32TOOL_HPP__
#else
#ifdef __WIN32TOOL_HPP__
#undef __WIN32TOOL_HPP__
        struct Win32Tool : win32_x86::Manager::Win32Application
        {
            explicit Win32Tool() = default;
            static HBITMAP $LoadBitmap(LPCWSTR lpBitmapName);
            static long $SendMessage(UINT Msg, WPARAM wParam, LPARAM lParam);
        };
#endif // !__WIN32TOOL_HPP__
#endif // __WIN32WINDOW_HPP__
    }
}

//#endif // !__WIN32TOOL_HPP__


