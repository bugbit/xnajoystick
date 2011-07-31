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

#include "dxutil.h"
#include "JoystickDevice.h"

namespace XnaJoystick
{
	JoystickDevice::JoystickDevice(LPDIRECTINPUTDEVICE8 argDevice):mDisposed(false),mDevice(NULL)
	{
		// A data format specifies which controls on a device we are interested in,
			// and how they should be reported. This tells DInput that we will be
			// passing a DIJOYSTATE2 structure to IDirectInputDevice::GetDeviceState().
		if (FAILED(argDevice->SetDataFormat(&c_dfDIJoystick2)))
			return;
		// Set the cooperative level to let DInput know how this device should
		// interact with the system and with other DInput applications.
		/*if( FAILED( mDevice->SetCooperativeLevel( hDlg, DISCL_EXCLUSIVE|DISCL_FOREGROUND)))
			return;*/
		mDevice=argDevice;
	}

	JoystickDevice::~JoystickDevice(void)
	{
		this->!JoystickDevice();
		mDisposed=true;
	}

	JoystickDevice::!JoystickDevice(void)
	{
		SAFE_RELEASE(mDevice);
	}

	JoystickState JoystickDevice::GetState()
	{
		HRESULT pResult;
		DIJOYSTATE2 pJoyState;

		if (mDevice==NULL)
			return JoystickState();
		pResult=mDevice->Poll();
		if(FAILED(pResult))
    {
        // DInput is telling us that the input stream has been
        // interrupted. We aren't tracking any state between polls, so
        // we don't have any special reset that needs to be done. We
        // just re-acquire and try again.
        pResult = mDevice->Acquire();
        while(pResult == DIERR_INPUTLOST)
            pResult = mDevice->Acquire();

        // hr may be DIERR_OTHERAPPHASPRIO or other errors.  This
        // may occur when the app is minimized or in the process of 
        // switching, so just try again later 
        return JoystickState();
    }
		if (FAILED(pResult=mDevice->GetDeviceState(sizeof(DIJOYSTATE2),&pJoyState)))
			return JoystickState();

		return JoystickState(pJoyState);
	}
};