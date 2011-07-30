#pragma once

#include <dinput.h>
#include <dinputd.h>

#include <vector>

#include "JoystickDevice.h"

using namespace System::Collections::Generic;

namespace XnaJoystick
{
		struct DI_ENUM_CONTEXT
		{
				DIJOYCONFIG* pPreferredJoyCfg;
				bool bPreferredJoyCfgValid;
				LPDIRECTINPUT8 dinput;
				std::vector<LPDIRECTINPUTDEVICE8> devices;
		};

		ref class JoystickDevices sealed
		{      
			public:
				static JoystickDevices ^GetInstance();
				~JoystickDevices();
				property bool NoJoystick
				{
					bool get()
					{
						return mNoJoystick;
					}
				}
				property List<JoystickDevice^> ^Devices
				{
					List<JoystickDevice^> ^get()
					{
						return mDevices;
					}
				}
			private:
				static JoystickDevices ^mInstance=nullptr;
				LPDIRECTINPUT8 mDI;
				bool mNoJoystick;
				List<JoystickDevice^> ^mDevices;
				
				static void CreateInstance();
				//std::vector<LPDIRECTINPUTDEVICE8> mDevices;

				 // El constructor privado no permite que se genere un constructor por defecto
        // (que es público)
				JoystickDevices(void);
				bool GetDevices();
				bool GetContextListJoystick(DI_ENUM_CONTEXT &argEnumContext);
		};
};
