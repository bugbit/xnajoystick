// Juguelandia.Input.DXJoystick.h

#pragma once

#include "JoystickState.h"

using namespace System;
using namespace Microsoft::Xna::Framework;

namespace XnaJoystick
{
	public ref class Joystick sealed
	{
		public:
			static JoystickState ^GetState(int argIndex);
			static JoystickState ^GetState(PlayerIndex argPlayerIndex);
			static JoystickState ^GetState();
	};
};
