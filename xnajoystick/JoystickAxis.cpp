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

#include "StdAfx.h"
#include "JoystickAxis.h"

namespace XnaJoystick
{
	JoystickAxis::JoystickAxis(DIJOYSTATE2 &argJoyState)
		:mX(argJoyState.lX)
		,mY(argJoyState.lY)
		,mZ(argJoyState.lZ)
		,mRotX(argJoyState.lRx)
		,mRotY(argJoyState.lRy)
		,mRotZ(argJoyState.lRz)
	{
	}

	int JoystickAxis::X::get()
	{
		return mX;
	}

	int JoystickAxis::Y::get()
	{
		return mY;
	}

	int JoystickAxis::Z::get()
	{
		return mZ;
	}

	int JoystickAxis::RotX::get()
	{
		return mRotX;
	}

	int JoystickAxis::RotY::get()
	{
		return mRotY;
	}

	int JoystickAxis::RotZ::get()
	{
		return mRotZ;
	}
};