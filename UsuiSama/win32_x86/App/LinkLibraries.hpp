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
    // ========================================================================================
    // Handle Events => Manejas Eventos
    using Win32HandleEvents = win32_x86::Manager::Win32Application;
    // ========================================================================================
}

// ========================================================================================
// Message Box => Caja de Mensajes
using win32_x86::UI::Dialog::Win32MessageBox;
using win32_x86::UI::Dialog::Button::Win32Button;               // Botón
using win32_x86::UI::Dialog::DefaultButton::Win32DefaultButton; // Botón seleccionado por defecto
using win32_x86::UI::Dialog::Icon::Win32Icon;                   // Icono
using win32_x86::UI::Dialog::Result::Win32Result;               // Identificadores de los botones
// ========================================================================================

// ========================================================================================
// Objeto => Sin Constructor
win32_x86::Manager::Win32Application win32_system;
// ========================================================================================


