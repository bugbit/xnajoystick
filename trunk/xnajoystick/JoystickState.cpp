#include "StdAfx.h"

#include "JoystickState.h"

namespace XnaJoystick
{
	JoystickState::JoystickState()
	{
		mConnected=false;
		mButtons=gcnew JoystickButtons();
	}

	JoystickState::JoystickState(DIJOYSTATE2 &argJoyState)
	{
		mButtons=gcnew JoystickButtons(argJoyState.rgbButtons,sizeof(argJoyState.rgbButtons));
	}
};
