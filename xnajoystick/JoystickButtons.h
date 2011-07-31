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

using namespace System;
using namespace Microsoft::Xna::Framework::Input;

namespace XnaJoystick
{
	/*
			X = (buttons[0] == 0 ? ButtonState.Released : ButtonState.Pressed);
			Y = (buttons[1] == 0 ? ButtonState.Released : ButtonState.Pressed);
			A = (buttons[2] == 0 ? ButtonState.Released : ButtonState.Pressed);
			B = (buttons[3] == 0 ? ButtonState.Released : ButtonState.Pressed);
			Back = (buttons[4] == 0 ? ButtonState.Released : ButtonState.Pressed);
			Start = (buttons[5] == 0 ? ButtonState.Released : ButtonState.Pressed);
			LeftShoulder = (buttons[6] == 0 ? ButtonState.Released : ButtonState.Pressed);
			RightShoulder = (buttons[7] == 0 ? ButtonState.Released : ButtonState.Pressed);
			LeftStick = (buttons[8] == 0 ? ButtonState.Released : ButtonState.Pressed);
			RightStick = (buttons[9] == 0 ? ButtonState.Released : ButtonState.Pressed);
			*/

	public enum JoystickButtonsIndex
	{
		X=0,Y,A,B,Back,Start,LeftShoulder,RightShoulder,LeftStick,RightStick
	};

	public value struct JoystickButtons
	{
	public:
		JoystickButtons(LPBYTE argButtons,unsigned argLng);
		ButtonState GetButtonState(int argIndex);
		property ButtonState X
		{
			inline ButtonState get()
			{
				return GetButtonState((int) JoystickButtonsIndex::X);
			}
		}
		property ButtonState Y
		{
			inline ButtonState get()
			{
				return GetButtonState((int) JoystickButtonsIndex::Y);
			}
		}
		property ButtonState A
		{
			inline ButtonState get()
			{
				return GetButtonState((int) JoystickButtonsIndex::A);
			}
		}
		property ButtonState B
		{
			inline ButtonState get()
			{
				return GetButtonState((int) JoystickButtonsIndex::B);
			}
		}
		property ButtonState Back
		{
			inline ButtonState get()
			{
				return GetButtonState((int) JoystickButtonsIndex::Back);
			}
		}
		property ButtonState Start
		{
			inline ButtonState get()
			{
				return GetButtonState((int) JoystickButtonsIndex::Start);
			}
		}
		property ButtonState LeftShoulder
		{
			inline ButtonState get()
			{
				return GetButtonState((int) JoystickButtonsIndex::LeftShoulder);
			}
		}
		property ButtonState RightShoulder
		{
			inline ButtonState get()
			{
				return GetButtonState((int) JoystickButtonsIndex::RightShoulder);
			}
		}
		property ButtonState LeftStick
		{
			inline ButtonState get()
			{
				return GetButtonState((int) JoystickButtonsIndex::LeftStick);
			}
		}
		property ButtonState RightStick
		{
			inline ButtonState get()
			{
				return GetButtonState((int) JoystickButtonsIndex::RightStick);
			}
		}
	private:
		array<ButtonState> ^mButtons;
	};
};
