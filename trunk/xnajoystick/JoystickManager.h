//	 Wrapper for xna input joystick
//
//   Copyright (C) <2010>  <Oscar Hernández Bañó>

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

namespace XnaJoystick
{
		struct DI_ENUM_CONTEXT
		{
				DIJOYCONFIG* pPreferredJoyCfg;
				bool bPreferredJoyCfgValid;
				LPDIRECTINPUT8 dinput;
				std::vector<LPDIRECTINPUTDEVICE8> devices;
		};

		ref class JoystickManager sealed
		{      
			public:
				static JoystickManager ^GetInstance();
				~JoystickManager();
				property bool NoJoystick { bool get(); }
				property array<JoystickDevice^> ^Devices { array<JoystickDevice^> ^get(); }
				property int NumberJoystick { int get(); }
				void Detect();
			private:
				static JoystickManager ^mInstance=nullptr;
				IntPtr mHwndExclusive;
				LPDIRECTINPUT8 mDI;
				bool mNoJoystick;
				array<JoystickDevice^> ^mDevices;
				
				static void CreateInstance();
				//std::vector<LPDIRECTINPUTDEVICE8> mDevices;

				 // El constructor privado no permite que se genere un constructor por defecto
        // (que es público)
				JoystickManager(void);
				bool GetDevices();
				bool GetContextListJoystick(DI_ENUM_CONTEXT &argEnumContext);
		};
};
