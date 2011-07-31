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

#include "StdAfx.h"
#include "JoystickButtons.h"

using namespace System::Collections::Generic;

namespace XnaJoystick
{
	JoystickButtons::JoystickButtons(void)
	{
		mButtons=gcnew array<ButtonState> {};
	}

	JoystickButtons::JoystickButtons(LPBYTE argButtons,unsigned argLng)
	{
		int pLng=argLng-1;
		
		for (;pLng>=0 && !argButtons[pLng];pLng--);
		mButtons=(array<ButtonState>^) Array::CreateInstance(ButtonState::typeid,pLng+1);
		for(int i=0;i<=pLng;i++)
			mButtons[i]=(*argButtons++ & 0x80) ? ButtonState::Pressed : ButtonState::Released;
	}

	ButtonState JoystickButtons::GetButtonState(int argIndex)
	{
		if (argIndex<0 || argIndex>=mButtons->Length)
			return ButtonState::Released;

		return mButtons[argIndex];
	}
};
