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

#include "stdafx.h"

#include "DXJoystick.h"
#include "JoystickDevices.h"

namespace XnaJoystick
{
	JoystickState Joystick::GetState(int argIndex)
	{
		List<JoystickDevice^> ^pDevices=JoystickDevices::GetInstance()->Devices;

		if (argIndex<0 || argIndex>=pDevices->Count)
			return JoystickState();

		return pDevices[argIndex]->GetState();
	}

	JoystickState Joystick::GetState(PlayerIndex argPlayerIndex)
	{
		return GetState((int) argPlayerIndex);
	}

	JoystickState Joystick::GetState()
	{
		return GetState(PlayerIndex::One);
	}
};