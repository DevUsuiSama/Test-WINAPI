/*
 * Created on Sat Jan 2 2021
 *
 * Copyright (c) 2021 UsuiSama
 *
 * FrameWork creado para la facilitación de manejo del entorno grafico WIN32.
 */
#pragma once
#ifndef __WIN32APPLICATION_HPP__
#error Deber incluir si o si la libreria [Win32Application.hpp] antes de incluir [Win32Theme.hpp].
#else
#if defined(__WIN32_X86_MODERN_THEME__) && defined(__WIN32_X86_OLD_THEME__)
#error No se puede aplicar dos temas a la misma vez.
#endif // __WIN32_X86_MODERN_THEME__ && __WIN32_X86_OLD_THEME__
#ifdef __WIN32_X86_MODERN_THEME__
/*
 * Copyright (c) 2020 Microsoft Corporation
 * Esta directiva como vemos fue proporcionado por Microsoft
 * ¿Qué es lo que hace?
 *	> Simple, ya que win32 utiliza una UI [<Interfaz Gráfica de Usuario>]
 *     antigua, es decir utiliza dibujos del sistema operativo más antigua que window XP.
 *	> Lo que hará esta directiva es cambiar eso dibujos antiguos,
 *     por uno más moderno.
 */
#pragma comment(linker,"\"/manifestdependency:type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif // __WIN32_X86_MODERN_THEME__
#ifdef __WIN32_X86_OLD_THEME__
#include <win32_x86/Manager/Win32Application.hpp>
#include <Uxtheme.h>
#pragma comment(lib, "UxTheme.lib")
namespace win32_x86
{
    namespace Theme
    {
        struct Win32OldTheme : win32_x86::Manager::Win32Application
        {
            /*
             * EnableTheme:
             * La finalidad de este procedimiento es la de habilitar temas utilizados
             * en windows93 hasta windows98.
             */
            static void EnableTheme()
            {
                try
                {
                    __memory_allocation__(win32_x86::Theme::Win32OldTheme, theme)();
                    SetWindowTheme(theme->GetHWND(), theme->GetTitle(), L" ");
                    __free_memory__(theme);
                }
                catch (...)
                {
                    win32_x86::UI::Dialog::Win32MessageBox::$Show(
                        L"No hay [memoria] disponible!!!",
                        L"Win32 Diagnostics",
                        win32_x86::UI::Dialog::Button::Win32Button::Ok |
                        win32_x86::UI::Dialog::DefaultButton::Win32DefaultButton::Button1 |
                        win32_x86::UI::Dialog::Icon::Win32Icon::Error
                    );
                }
            }
        };
    }
}
#endif // __WIN32_X86_OLD_THEME__
#endif // !__WIN32APPLICATION_HPP__

