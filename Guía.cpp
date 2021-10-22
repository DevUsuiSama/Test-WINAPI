/*
 * Created on Sun Jan 31 2021
 *
 * Copyright (c) 2021 UsuiSama
 */

#define __WIN32_X86_MODERN_THEME__

#include <win32_x86/App/LinkLibraries.hpp>
#include <win32_x86/Theme/Win32Theme.hpp>

struct App : win32_x86::Win32HandleEvents // Herencia
{
	bool Win32InitInstance(HINSTANCE hInstance, unique_ptr<win32_x86::UI::Win32Window>* window, win32_x86::Tool::Rectangle rect) override
	{
		rect.x = 0; // Eje X => Inicializar en 0 para luego llamar al metodo CenterScreen.
		rect.y = 0; // Eje Y => Inicializar en 0 para luego llamar al metodo CenterScreen.
		rect.width = 400;
		rect.height = 240;

		try
		{
#pragma warning(disable : 26812) // Acá bueno. Había un warning rompe bolas y lo deshabilite.
			* window = make_unique<win32_x86::UI::Win32Window>(L"Guía", win32_x86::UI::Win32Window::Style::wsSysMenu, rect, hInstance);
#pragma warning(default : 26812)
		}
		catch (...)
		{
			return false;
		}

		(*window)->Create(); // Crea. Mejor dicho dibuja desde 0 una ventana.
		//(*window)->HideTitleBar(); // Ocultar el icono y la barra de titulo.
		(*window)->CenterScreen(); // Centrar la ventana en la pantalla.

		if (!(*window)->GetHWND()) return false; // Comprobamos que la ventana allá sido creado correctamente.

		(*window)->Show(); // Mostrar Ventana
		(*window)->Update(); // Actualizar Ventana
		return true;
	}

	void Win32Close() override
	{
		if (Win32MessageBox::Show(L"¿Desea salir de la aplicación?",
			Win32Button::YesNo | Win32DefaultButton::Button1 | Win32Icon::Question) == Win32Result::Yes)
			win32_system.close();
	}
};

int __stdcall wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
{
	__unreferenced_parameters__(nCmdShow, hPrevInstance, lpCmdLine);
	win32_x86::Manager::Win32Application::Start(hInstance, []() { return win32_x86::Manager::Win32Application::Make<App>(); });
	//win32_x86::Theme::Win32OldTheme::EnableTheme();
	return win32_x86::Manager::Win32Application::MessageLoop(); // Bucle de Mensajes
}



