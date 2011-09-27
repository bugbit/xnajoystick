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

#include "JoystickState.h"
#include "JoystickCapabilities.h"
#include "JoystickEffect.h"
#include "JoystickInitEffect.h"

using namespace System;
using namespace Microsoft::Xna::Framework;

namespace XnaJoystick
{
	struct DI_ENUM_DEVICE
	{
		union
		{
			unsigned Mask;			
			struct
			{
				unsigned Axis:1;
				unsigned XAxis:1;
				unsigned YAxis:1;
				unsigned ZAxis:1;
				unsigned RXAxis:1;
				unsigned RYAxis:1;
				unsigned RZAxis:1;
			} S;
		} Flags;
		LPDIRECTINPUTDEVICE8 Device;
		DWORD MinRange,MaxRange;
	};

	value struct JoystickState;

	public ref class JoystickDevice : public IDisposable
	{
	public:
		JoystickDevice(LPDIRECTINPUTDEVICE8 argDevice);
		~JoystickDevice(void);
		!JoystickDevice(void);
		JoystickState GetState();
		property JoystickCapabilities Capabilities { JoystickCapabilities get(); }
		JoystickEffect ^CreateEffect(JoystickInitEffect ^argInitEffect);
		void SetExclusive(Game ^argGame);
	private:
		// Track whether Dispose has been called.
		 bool mDisposed;
		 LPDIRECTINPUTDEVICE8 mDevice;
		 JoystickCapabilities mCapabilities;
	};
};