#pragma once

#include <dinput.h>

#include "JoystickButtons.h"

namespace XnaJoystick
{
	public ref struct JoystickState
	{
	public:
		JoystickState();
		JoystickState(DIJOYSTATE2 &argJoyState);
		property bool IsConnected
		{
			bool get()
			{
				return mConnected;
			}
		}
		property JoystickButtons ^Buttons
		{
			JoystickButtons ^get()
			{
				return mButtons;
			}
		}
	private:
		bool mConnected;
		JoystickButtons ^mButtons;
	};
};