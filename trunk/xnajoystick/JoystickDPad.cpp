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

#include "JoystickDPad.h"

namespace XnaJoystick
{
	JoystickDPad::JoystickDPad(DWORD argPOV)
	{
		mUp = ButtonState::Released;
		mRight = ButtonState::Released;
		mDown = ButtonState::Released;
		mLeft = ButtonState::Released;

		if (argPOV == -1)
			return;

		if (argPOV > 27000 || argPOV < 9000)
			mUp = ButtonState::Pressed;

		if (0 < argPOV && argPOV < 18000)
			mRight = ButtonState::Pressed;

		if (9000 < argPOV && argPOV < 27000)
			mDown = ButtonState::Pressed;

		if (18000 < argPOV)
			mLeft = ButtonState::Pressed;
	}

	ButtonState JoystickDPad::Up::get()
	{
		return mUp;
	}

	ButtonState JoystickDPad::Right::get()
	{
		return mRight;
	}

	ButtonState JoystickDPad::Down::get()
	{
		return mDown;
	}

	ButtonState JoystickDPad::Left::get()
	{
		return mLeft;
	}
};