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

#include "JoystickManager.h"

using namespace System::Collections::Generic;

namespace XnaJoystick
{	
	static BOOL CALLBACK EnumJoysticksCallback(const DIDEVICEINSTANCE *pdidInstance,VOID* pContext);

	JoystickManager ^JoystickManager::GetInstance()
	{ 
		if (mInstance == nullptr)
			CreateInstance();
		return mInstance;
	}

	void JoystickManager::CreateInstance()
	{
		if (mInstance == nullptr)
    {
        mInstance = gcnew JoystickManager();
    }
	}
	
	JoystickManager::JoystickManager(void):mDI(NULL),mNoJoystick(false),mDevices(gcnew array<JoystickDevice^> {})
	{
		HRESULT pResult;
		LPVOID pDI;

		// Register with the DirectInput subsystem and get a pointer
		// to a IDirectInput interface we can use.
		// Create a DInput object
		;
		if( !FAILED( pResult = DirectInput8Create( GetModuleHandle( NULL ), DIRECTINPUT_VERSION,IID_IDirectInput8, &pDI, NULL ) ) )
		{
			mDI=(LPDIRECTINPUT8)pDI;
			if (GetDevices())
				mNoJoystick=mDevices->Length>0;
		}
	}

	JoystickManager::~JoystickManager()
	{
		SAFE_RELEASE(mDI);
	}

	bool JoystickManager::NoJoystick::get()
	{
		return mNoJoystick;
	}
	
	array<JoystickDevice^> ^JoystickManager::Devices::get()
	{
		return mDevices;
	}

	int JoystickManager::NumberJoystick::get()
	{
		return mDevices->Length;
	}

	bool JoystickManager::GetDevices()
	{
		DI_ENUM_CONTEXT pEnumContext;
		 
		if (!GetContextListJoystick(pEnumContext))
			return false;
		if( FAILED( mDI->EnumDevices( DI8DEVCLASS_GAMECTRL,EnumJoysticksCallback,&pEnumContext, DIEDFL_ATTACHEDONLY)))
			return false;
		std::vector<LPDIRECTINPUTDEVICE8>::iterator it=pEnumContext.devices.begin(),itend=pEnumContext.devices.end();
		List<JoystickDevice^> ^pDevices=gcnew List<JoystickDevice^>();
		for (;it!=itend;it++)
			pDevices->Add(gcnew JoystickDevice(*it));
		mDevices=pDevices->ToArray();

		return true;
	}

	bool JoystickManager::GetContextListJoystick(DI_ENUM_CONTEXT &argEnumContext)
	{
		DIJOYCONFIG pPreferredJoyCfg = {0};
    IDirectInputJoyConfig8* pJoyConfig = NULL;

		argEnumContext.pPreferredJoyCfg = &pPreferredJoyCfg;
    argEnumContext.bPreferredJoyCfgValid = false;
    if( FAILED( mDI->QueryInterface( IID_IDirectInputJoyConfig8, (void**)&pJoyConfig)))
        return false;
    pPreferredJoyCfg.dwSize = sizeof( pPreferredJoyCfg );
    if( SUCCEEDED( pJoyConfig->GetConfig( 0, &pPreferredJoyCfg, DIJC_GUIDINSTANCE ) ) ) // This function is expected to fail if no joystick is attached
        argEnumContext.bPreferredJoyCfgValid = true;
    SAFE_RELEASE(pJoyConfig);
		argEnumContext.dinput=mDI;

		return true;
	}

	static BOOL CALLBACK EnumJoysticksCallback(const DIDEVICEINSTANCE *argInstance,VOID* argContext)
	{
		DI_ENUM_CONTEXT* pEnumContext = ( DI_ENUM_CONTEXT* )argContext;
		LPDIRECTINPUTDEVICE8 pDevice;

		if ( lstrcmpi(argInstance->tszProductName,L"Xbox 360")==0)
			return DIENUM_CONTINUE;
		// Obtain an interface to the enumerated joystick.
		if( FAILED(pEnumContext->dinput->CreateDevice( argInstance->guidInstance, &pDevice, NULL)))
			return DIENUM_CONTINUE;

		pEnumContext->devices.push_back(pDevice);

		return DIENUM_STOP;
	}
};