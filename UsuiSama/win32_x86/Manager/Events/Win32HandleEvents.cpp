/*
 * Created on Sat Jan 2 2021
 *
 * Copyright (c) 2021 UsuiSama
 * 
 * FrameWork creado para la facilitación de manejo del entorno grafico WIN32.
 */
#include "Win32HandleEvents.hpp"

win32_x86::Events::Win32Parameters win32_x86::Events::HandleEvents::$Win32Parameters()
{
    Win32Parameters style;
    style.arrow = IDC_ARROW;
    style.bitmap = reinterpret_cast<HBRUSH>(COLOR_3DSHADOW + 1);
    style.icon = IDI_APPLICATION;
    return style;
}

bool win32_x86::Events::HandleEvents::Win32InitInstance(HINSTANCE hInstance, unique_ptr<win32_x86::UI::Win32Window>* window, win32_x86::Tool::Rectangle rect)
{
    return false;
}

long win32_x86::Events::HandleEvents::Win32NChitTest(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    return 0;
}

void win32_x86::Events::HandleEvents::Win32Create()
{
    // . . .
}

void win32_x86::Events::HandleEvents::Win32KeyUp(WPARAM wParam)
{
    // . . .
}

void win32_x86::Events::HandleEvents::Win32Command(HWND hWnd, WPARAM wParam, HINSTANCE hInstance)
{
    // . . .
}

void win32_x86::Events::HandleEvents::Win32VScroll(WPARAM wParam)
{
    // . . .
}

long win32_x86::Events::HandleEvents::Win32MouseWheel(WPARAM wParam)
{
    return 0;
}

void win32_x86::Events::HandleEvents::Win32DrawItem(LPARAM lParam)
{
    // . . .
}

long win32_x86::Events::HandleEvents::Win32Notify(HWND hWnd, LPARAM lParam)
{
    return 0;
}

long win32_x86::Events::HandleEvents::Win32CtlColorBtn()
{
    return 0;
}

void win32_x86::Events::HandleEvents::Win32Paint()
{
    // . . .
}

void win32_x86::Events::HandleEvents::Win32Close()
{
    // . . .
}

void win32_x86::Events::HandleEvents::Win32Destroy()
{
    // . . .
}

