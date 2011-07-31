//	 Wrapper for xna input joystick
//
//   Copyright (C) <2010>  <Oscar Hern�ndez Ba��>

//   This program is free software: you can redistribute it and/or modify
//   it under the terms of the GNU General Public License as published by
//   the Free Software Foundation, either version 3 of the License, or
//   (at your option) any later version.

//   This program is distributed in the hope that it will be useful,
//   but WITHOUT ANY WARRANTY; without even the implied warranty of
//   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//   GNU General Public License for more details.

//   You should have received a copy of the GNU General Public License
//   along with this program.  If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include <dinput.h>
#include <dinputd.h>

#include <vector>

#include "JoystickDevice.h"

using namespace System::Collections::Generic;

namespace XnaJoystick
{
		struct DI_ENUM_CONTEXT
		{
				DIJOYCONFIG* pPreferredJoyCfg;
				bool bPreferredJoyCfgValid;
				LPDIRECTINPUT8 dinput;
				std::vector<LPDIRECTINPUTDEVICE8> devices;
		};

		ref class JoystickDevices sealed
		{      
			public:
				static JoystickDevices ^GetInstance();
				~JoystickDevices();
				property bool NoJoystick
				{
					bool get()
					{
						return mNoJoystick;
					}
				}
				property List<JoystickDevice^> ^Devices
				{
					List<JoystickDevice^> ^get()
					{
						return mDevices;
					}
				}
			private:
				static JoystickDevices ^mInstance=nullptr;
				LPDIRECTINPUT8 mDI;
				bool mNoJoystick;
				List<JoystickDevice^> ^mDevices;
				
				static void CreateInstance();
				//std::vector<LPDIRECTINPUTDEVICE8> mDevices;

				 // El constructor privado no permite que se genere un constructor por defecto
        // (que es p�blico)
				JoystickDevices(void);
				bool GetDevices();
				bool GetContextListJoystick(DI_ENUM_CONTEXT &argEnumContext);
		};
};