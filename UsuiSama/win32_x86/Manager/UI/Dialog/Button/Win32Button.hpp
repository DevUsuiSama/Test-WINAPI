/*
 * Created on Sat Jan 2 2021
 *
 * Copyright (c) 2021 UsuiSama
 * 
 * FrameWork creado para la facilitación de manejo del entorno grafico WIN32.
 */
#pragma once

namespace win32_x86
{
    namespace UI
    {
        namespace Dialog
        {
            namespace Button
            {
                enum Win32Button
                {
                    Ok = 0x00000000L, OkCancel = 0x00000001L,
                    AbortRetryIgnore = 0x00000002L, YesNoCancel = 0x00000003L,
                    YesNo = 0x00000004L, RetryCancel = 0x00000005L
                };
            }
        }
    }
}
