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
            namespace Result
            {
                enum Win32Result
                {
                    Yes = 0x00000006, No = 0x00000007, Cancel = 0x00000002,
                    Abort = 0x00000003, Retry = 0x00000004, Ignore = 0x00000005,
                    Close = 0x00000008, Help = 0x00000009, TryAgain = 0x0000000a,
                    Continue = 0x0000000b
                };
            }
        }
    }
}

