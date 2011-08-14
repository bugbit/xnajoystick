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

#include "JoystickState.h"
#include "JoystickCapabilities.h"

using namespace System;

namespace XnaJoystick
{
	public ref class Joystick sealed
	{
		public:
			static void DetectJoysticks();
			static JoystickState GetState(int argIndex);
			static JoystickState GetState();
			static JoystickCapabilities GetCapabilities(int argIndex);
			static JoystickCapabilities GetCapabilities();
			static property bool NoJoystick { bool get(); }
			static property int NumberJoystick { int get(); }
			static property int IdxJoystickDefault { int get(); void set(int); }
			static int MinRange=-1000;
			static int MaxRange=1000;
	private:
			static int mIdxJoystickDefault=0;
	};
};
