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

#include "JoystickDPad.h"
#include "JoystickButtons.h"
#include "JoystickAxis.h"
#include "JoystickCapabilities.h"

namespace XnaJoystick
{
	public value struct JoystickState
	{
	public:
		JoystickState(DIJOYSTATE2 &argJoyState,JoystickCapabilities argCaps);
		property bool IsConnected {	bool get(); }
		property JoystickButtons Buttons { JoystickButtons get(); }	
		property JoystickDPad DPad { JoystickDPad get(); }
		property JoystickAxis Axis { JoystickAxis get(); }
	private:
		bool mConnected;
		JoystickButtons mButtons;
		JoystickDPad mDPad;
		JoystickAxis mAxis;
	};
};