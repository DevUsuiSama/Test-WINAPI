/*
 * Created on Sat Jan 2 2021
 *
 * Copyright (c) 2021 UsuiSama
 * 
 * FrameWork creado para la facilitación de manejo del entorno grafico WIN32.
 */
#pragma once

#include <win32_x86/Manager/Tool/Win32Tool.hpp>

extern "C" {
#include <Windows.h>
}

#ifndef __WIN32WINDOW_HPP__
#define __WIN32WINDOW_HPP__

namespace win32_x86
{
	namespace UI
	{
		/* MACRO => Preprocesador
		 * Velocidad frente a tamaño:
		 *	El principal beneficio del uso de las macros es que ofrece un tiempo de ejecución más rápido.
		 *	Durante el preprocesamiento, una macro se expande (reemplazada por su definición) alineada cada vez que se utiliza.
		 *	Una definición de función se produce una vez, con independencia de cuántas veces se le llame.
		 *	Las macros pueden aumentar el tamaño del código, pero no tienen la sobrecarga asociada con las llamadas a funciones.
		 */
#define __$compute_client(r, a, b) __asm /* ➣ Assembly c++ x86  2021 */\
{ \
	__asm mov	eax, (a) /* [mov] => Asigna el valor de [a] en el registro [eax] */\
	__asm sub	eax, (b) /* [sub] => Resta [eax] con [b] -> [eax = eax - b]	*/\
	__asm mov	(r), eax /* [mov] => Asigna el valor almacenado en el registro [eax] en [r] */\
}

#define __$compute_xy_axis(rxy, xy1, xy2, pxy) __asm /* ➣ Assembly c++ x86  2021 */\
{ \
	__asm mov	eax, (xy2)	/* [mov] => Asigna el valor de [xy2] en el registro [eax] */\
	__asm mov	ebx, (pxy)	/* [mov] => Asigna el valor de [pxy] en el registro [ebx] */\
	__asm xor	edx, edx	/* [xor] => [ V ⊕ F = V] En este caso seria, [ V ⊕ V = 0] */\
	__asm div	ebx			/* [div] => Realiza un división -> [eax = eax:edx / ebx] */\
	__asm mov	ecx, eax	/* [mov] => Asigna el valor obtenido de la operación aritmética almacenada en el registro [eax] al registro [ecx] */\
	__asm mov	eax, (xy1)	/* [mov] => Asigna el valor de [xy1] en el registro [eax] */\
	__asm mov	ebx, (pxy)	/* [mov] => Asigna el valor de [pxy] en el registro [ebx] */\
	__asm xor	edx, edx	/* [xor] => [ V ⊕ F = V] En este caso seria, [ V ⊕ V = 0] */\
	__asm div	ebx			/* [div] => Realiza un división -> [eax = edx:eax / ebx] */\
	__asm sub	eax, ecx	/* [sub] => Resta el valor obtenido de la operación aritmética almacenada en el registro [eax] con [ecx] -> [eax = eax - ecx] */\
	__asm mov	(rxy), eax	/* [mov] => Asigna el valor de [eax] a [rxy] */\
}

		class Win32Window
		{
		public:
			// Enumerador
			enum Style
			{
				wsSysMenu = 0x00080000L, 		wsMinimizeBox = 0x00020000L,
				wsMaximizeBox = 0x00010000L, 	wsDisable = 0x08000000L,
				wsBorder = 0x00800000L
			};
			// Constructor
			explicit Win32Window() = default;
			explicit Win32Window(const wchar_t* lpWindowName, unsigned long dwStyle, win32_x86::Tool::Rectangle rect, HINSTANCE hInstance, HWND m_hWnd = NULL);
			// Metodos
			void Create();
			void CenterScreen();
			void HideTitleBar();
			void Show();
			void Update();
			void EnableScrollBar(int maxElement, int y, int height, int range);
			void DisableScrollBar(int& iVScrollBarPos);
			const wchar_t* GetTitle() const;
			HWND GetHWND() const;
			// Destructor
			~Win32Window();

		private:
			// Metodos con encapsulamiento privado
			int ComputeMaximumHeight(int maxElement, int y, int height, int range);
			// Atributos
			HWND m_hWnd;
			const wchar_t* lpWindowName;
			unsigned long dwStyle;
			win32_x86::Tool::Rectangle rect;
			HINSTANCE hInstance;
		};
	}
}

#endif // !__WIN32WINDOW_HPP__


