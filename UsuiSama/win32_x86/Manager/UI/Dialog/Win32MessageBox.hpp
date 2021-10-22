/*
 * Created on Sat Jan 2 2021
 *
 * Copyright (c) 2021 UsuiSama
 * 
 * FrameWork creado para la facilitación de manejo del entorno grafico WIN32.
 */
#pragma once

#include <win32_x86/Manager/Win32Application.hpp>

namespace win32_x86
{
	namespace UI
	{
		namespace Dialog
		{
			class Win32MessageBox : win32_x86::Manager::Win32Application
			{
			public:
				// Constructor
				explicit Win32MessageBox() = default;
				// Metodos Estaticos
				static int Show(const wchar_t* Text, const wchar_t* Title, unsigned int Type = NULL);
				static int Show(const wchar_t* Text, unsigned int Type = NULL);
				static int $Show(const wchar_t* Text, const wchar_t* Title, unsigned int Type = NULL);
			};
		}
	}
}




