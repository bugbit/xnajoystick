#pragma once

#include <dinput.h>

#include "JoystickState.h"

using namespace System;

namespace XnaJoystick
{
	ref struct JoystickState;

	public ref class JoystickDevice : public IDisposable
	{
	public:
		JoystickDevice(LPDIRECTINPUTDEVICE8 argDevice);
		~JoystickDevice(void);
		!JoystickDevice(void);
		JoystickState ^GetState();
	private:
		// Track whether Dispose has been called.
		 bool mDisposed;
		 LPDIRECTINPUTDEVICE8 mDevice;
	};
};