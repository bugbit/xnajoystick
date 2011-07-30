// Archivo DLL principal.

#include "stdafx.h"

#include "DXJoystick.h"
#include "JoystickDevices.h"

namespace XnaJoystick
{
	JoystickState ^Joystick::GetState(int argIndex)
	{
		List<JoystickDevice^> ^pDevices=JoystickDevices::GetInstance()->Devices;

		if (argIndex<0 || argIndex>=pDevices->Count)
			return gcnew JoystickState();

		return pDevices[argIndex]->GetState();
	}

	JoystickState ^Joystick::GetState(PlayerIndex argPlayerIndex)
	{
		return GetState((int) argPlayerIndex);
	}

	JoystickState ^Joystick::GetState()
	{
		return GetState(PlayerIndex::One);
	}
};