/*
 * Created on Sat Jan 2 2021
 *
 * Copyright (c) 2021 UsuiSama
 *
 * FrameWork creado para la facilitación de manejo del entorno grafico WIN32.
 */
#pragma once

#ifndef __WIN32APPLICATION_HPP__
#define __WIN32APPLICATION_HPP__
#include "Events/Win32HandleEvents.hpp"

/* MACRO => Preprocesador
 * Velocidad frente a tamaño:
 *	El principal beneficio del uso de las macros es que ofrece un tiempo de ejecución más rápido.
 *	Durante el preprocesamiento, una macro se expande (reemplazada por su definición) alineada cada vez que se utiliza.
 *	Una definición de función se produce una vez, con independencia de cuántas veces se le llame.
 *	Las macros pueden aumentar el tamaño del código, pero no tienen la sobrecarga asociada con las llamadas a funciones.
 */

/*
 * __unreferenced_parameters y __unreferenced_parameter se expande al parámetro o expresión pasado.
 * Su propósito es evitar las advertencias del compilador sobre parámetros sin referencia.
 */
#define __unreferenced_parameters__(a, b, c) ((a), (b), (c))
#define __unreferenced_parameter__(a) (a)
/*
 * Convierte un valor entero en un tipo de recurso compatible con las funciones de administración de recursos.
 * Esta macro se utiliza en lugar de una cadena que contiene el nombre del recurso.
 */
#define __convert_int_to_urtype__(i) ((LPWSTR)((ULONG_PTR)((WORD)(i))))
/* Macro Obsoleto */
//#define __delete__(x) ({ delete (x); (x) = nullptr; })

namespace win32_x86
{
	namespace Manager
	{
		class Win32Application : public win32_x86::Events::HandleEvents // Herencia
		{
		public:
			/* Metodos */
			/* Da inicio a la ejecución del programa */
			static void Start(HINSTANCE hInstance, std::function<unique_ptr<win32_x86::Events::HandleEvents>()> app);
			/* Bucle De Mensajes */
			static int MessageLoop();
			/* Eventos */
			void close();
			void scroll_bar(WPARAM wParam, int& iVScrollBarPos);
			void scroll_bar_mouse_wheel(int y, int& iVScrollBarPos);
			long mouse_move(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
			void paint(std::function<void(HDC&, PAINTSTRUCT&)> process);
			/* Aplicamos Polimorfirmo => Estos de aplica a cualquier lenguaje que utiliza en el paradigma POO */
			virtual void Win32Close();
			/*
			 * Metodos con Plantilla [<Tipo de Datos Genericos>] => Esto se aplica en [<java>]
			 * tambien solo que con una sintaxis diferente.
			 */
			template <class T> static unique_ptr<T> Make() __win32_x86_build_object__(T, App)
			/*
			 * Salidad De Emergencia => Libera los recursos de un metodo como OnPaint()
			 * y su uso es exclusiva de OnPaint.
			 */
			static void ReleaseResourceAndExit();
			/* Salida de Emergencia */
			static void Exit();

		protected:
			/* Metodos con encapsulamiento Protegido [<Accesible solamente desde la clases hijos>] */
			HINSTANCE GetInstance();
			HWND GetHWND();
			LPCWSTR GetTitle();
			win32_x86::UI::Win32Window* GetWindow();

		private:
			/* Atributos y Metodos con Encapsulamiento Privado */
			static unique_ptr<win32_x86::Events::HandleEvents> auxapp;
			static unique_ptr<win32_x86::UI::Win32Window> window;
			static HINSTANCE hInst; // Almacena el identificador de la instancia en una variable global
			static bool error;
			static long __stdcall Win32EventControl(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
			static int UpdateScrollBar(int& y, int iVScrollBarPos);
		};
	}
}

// ===============================================================================
// MessageBox => Caja de Mensajes
#include "UI/Dialog/Win32MessageBox.hpp"
#include "UI/Dialog/Button/Win32Button.hpp"
#include "UI/Dialog/DefaultButton/Win32DefaultButton.hpp"
#include "UI/Dialog/Icon/Win32Icon.hpp"
#include "UI/Dialog/Result/Win32Result.hpp"
// ===============================================================================
#include "Tool/Win32Tool.hpp"

/*#include "Win32Button.hpp"
#include "Win32Vector.hpp"
#include "Win32UniquePtrVector.hpp"
#include "Win32Font.hpp"
#include "Win32Paint.hpp"*/

#endif // !__WIN32APPLICATION_HPP__

