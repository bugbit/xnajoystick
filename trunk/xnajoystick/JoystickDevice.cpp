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
#include "DXJoystick.h"

namespace XnaJoystick
{
	BOOL CALLBACK EnumObjectsCallback( const DIDEVICEOBJECTINSTANCE *argDIDoi,VOID *argContext)
	{
		DI_ENUM_DEVICE *pEnumDevice=(DI_ENUM_DEVICE *) argContext;
		DIPROPRANGE pDIPrg;

		if(argDIDoi->dwType & DIDFT_AXIS)
		{
			pEnumDevice->Flags.S.Axis=true;
			pDIPrg.diph.dwSize = sizeof( DIPROPRANGE );
			pDIPrg.diph.dwHeaderSize = sizeof( DIPROPHEADER );
			pDIPrg.diph.dwHow = DIPH_BYID;
			pDIPrg.diph.dwObj = argDIDoi->dwType; // Specify the enumerated axis
			pDIPrg.lMin = pEnumDevice->MinRange;
			pDIPrg.lMax = pEnumDevice->MaxRange;
			//// Set the range for the axis
			if( FAILED( pEnumDevice->Device->SetProperty( DIPROP_RANGE, &pDIPrg.diph ) ) )
					return DIENUM_STOP;
		}
		if(argDIDoi->guidType == GUID_XAxis)
			pEnumDevice->Flags.S.XAxis=true;
		if(argDIDoi->guidType == GUID_YAxis)
			pEnumDevice->Flags.S.YAxis=true;
		if(argDIDoi->guidType == GUID_ZAxis)
			pEnumDevice->Flags.S.ZAxis=true;	
		if(argDIDoi->guidType == GUID_RxAxis)
			pEnumDevice->Flags.S.RXAxis=true;
		if(argDIDoi->guidType == GUID_RyAxis)
			pEnumDevice->Flags.S.RYAxis=true;
		if(argDIDoi->guidType == GUID_RzAxis)
			pEnumDevice->Flags.S.RZAxis=true;

		return DIENUM_CONTINUE;
	}

	JoystickDevice::JoystickDevice(LPDIRECTINPUTDEVICE8 argDevice):mDisposed(false),mDevice(NULL)
	{
		DIDEVCAPS pCaps;
		DI_ENUM_DEVICE pEnumDevice;
		// A data format specifies which controls on a device we are interested in,
			// and how they should be reported. This tells DInput that we will be
			// passing a DIJOYSTATE2 structure to IDirectInputDevice::GetDeviceState().
		if (FAILED(argDevice->SetDataFormat(&c_dfDIJoystick2)))
			return;
		// Set the cooperative level to let DInput know how this device should
		// interact with the system and with other DInput applications.
		/*if( FAILED( mDevice->SetCooperativeLevel( hDlg, DISCL_EXCLUSIVE|DISCL_FOREGROUND)))
			return;*/
		pCaps.dwSize=sizeof(pCaps);
		if (FAILED(argDevice->GetCapabilities(&pCaps)))
			return;
		pEnumDevice.Flags.Mask=0;
		pEnumDevice.Device=argDevice;
		pEnumDevice.MinRange=Joystick.MinRange;
		pEnumDevice.MaxRange=Joystick.MaxRange;
		// Enumerate the joystick objects. The callback function enabled user
    // interface elements for objects that are found, and sets the min/max
    // values property for discovered axes.
    if( FAILED(argDevice->EnumObjects(EnumObjectsCallback, (VOID*)&pEnumDevice, DIDFT_ALL)))
			pEnumDevice.Flags.Mask=0;
		mCapabilities=JoystickCapabilities(pCaps,pEnumDevice);
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

	JoystickCapabilities JoystickDevice::Capabilities::get()
	{
		return mCapabilities;
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

		return JoystickState(pJoyState,mCapabilities);
	}

	JoystickEffect ^JoystickDevice::CreateEffect(JoystickInitEffect ^argInitEffect)
	{
		LPDIRECTINPUTEFFECT pEffect;

		if (FAILED(mDevice->CreateEffect(argInitEffect->GUID,argInitEffect->InitEffect,&pEffect,NULL)))
			return nullptr;

		return gcnew JoystickEffect(pEffect);
	}
};