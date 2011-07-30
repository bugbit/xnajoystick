#include "StdAfx.h"

#include "dxutil.h"

#include "JoystickDevices.h"

namespace XnaJoystick
{	
	static BOOL CALLBACK EnumJoysticksCallback(const DIDEVICEINSTANCE *pdidInstance,VOID* pContext);

	JoystickDevices ^JoystickDevices::GetInstance()
	{ 
		if (mInstance == nullptr)
			CreateInstance();
		return mInstance;
	}

	void JoystickDevices::CreateInstance()
	{
		if (mInstance == nullptr)
    {
        mInstance = gcnew JoystickDevices();
    }
	}
	
	JoystickDevices::JoystickDevices(void):mDI(NULL),mNoJoystick(false),mDevices(gcnew List<JoystickDevice^>())
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
				mNoJoystick=mDevices->Count>0;
		}
	}

	JoystickDevices::~JoystickDevices()
	{
		SAFE_RELEASE(mDI);
	}

	bool JoystickDevices::GetDevices()
	{
		DI_ENUM_CONTEXT pEnumContext;
		 
		if (!GetContextListJoystick(pEnumContext))
			return false;
		if( FAILED( mDI->EnumDevices( DI8DEVCLASS_GAMECTRL,EnumJoysticksCallback,&pEnumContext, DIEDFL_ATTACHEDONLY)))
			return false;
		std::vector<LPDIRECTINPUTDEVICE8>::iterator it=pEnumContext.devices.begin(),itend=pEnumContext.devices.end();
		for (;it!=itend;it++)
			mDevices->Add(gcnew JoystickDevice(*it));

		return true;
	}

	bool JoystickDevices::GetContextListJoystick(DI_ENUM_CONTEXT &argEnumContext)
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