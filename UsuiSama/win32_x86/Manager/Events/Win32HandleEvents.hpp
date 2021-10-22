/*
 * Created on Sat Jan 2 2021
 *
 * Copyright (c) 2021 UsuiSama
 *
 * FrameWork creado para la facilitación de manejo del entorno grafico WIN32.
 */
#pragma once

#include <win32_x86/Manager/UI/Win32Window.hpp>

#include <functional>
#include <memory>
#include <thread>
#include <chrono>
#include <string>
#include <sstream>

using std::unique_ptr;	// Un plus para gestionar la memoria mas efecicientemente.
using std::make_unique; // Para asignar una dirección de memoria. [De la RAM a un Puntero].
using std::move;		// Cambiar asignaciones. [Puntero].
using std::this_thread::sleep_for;
using std::chrono::seconds;
using std::chrono::milliseconds;
using std::wstringstream;

#define __memory_allocation__(T, V)  unique_ptr<T> V = make_unique<T>
#define __free_memory__(T)           T = nullptr
#define __translate_pointer__        return move

#define __win32_x86_build_object__(T, V)  \
{ __memory_allocation__(T, V)(); __translate_pointer__(V); }

namespace win32_x86
{
    namespace Events
    {
        // Enumerador
        enum Win32Message
        {
            $Win32Create = 0x0001,
            $Win32Close = 0x0010,
            $Win32Destroy = 0x0002
        };

        // Estructura de Datos
        struct Win32Parameters
        {
            const wchar_t* icon;
            const wchar_t* arrow;
            HBRUSH bitmap;
        };

        struct HandleEvents
        {
            virtual Win32Parameters $Win32Parameters();
            virtual bool Win32InitInstance(HINSTANCE hInstance, unique_ptr<win32_x86::UI::Win32Window>* window, win32_x86::Tool::Rectangle rect);
            virtual long Win32NChitTest(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
            virtual void Win32Create();
            virtual void Win32KeyUp(WPARAM wParam);
            virtual void Win32Command(HWND hWnd, WPARAM wParam, HINSTANCE hInstance);
            virtual void Win32VScroll(WPARAM wParam);
            virtual long Win32MouseWheel(WPARAM wParam);
            virtual void Win32DrawItem(LPARAM lParam);
            virtual long Win32Notify(HWND hWnd, LPARAM lParam);
            virtual long Win32CtlColorBtn();
            virtual void Win32Paint();
            virtual void Win32Close();
            virtual void Win32Destroy();
        };
    }
}



