#include "StdAfx.h"
#include "JoystickButtons.h"

using namespace System::Collections::Generic;

namespace XnaJoystick
{
	JoystickButtons::JoystickButtons(void)
	{
		mButtons=gcnew array<ButtonState> {};
	}

	JoystickButtons::JoystickButtons(LPBYTE argButtons,unsigned argLng)
	{
		int pLng=argLng-1;
		List<ButtonState> ^pList=gcnew List<ButtonState>();

		for (;pLng>=0 && !argButtons[pLng];pLng--);
		//mButtons=(array<ButtonState>^) Array::CreateInstance(ButtonState::typeid,argLng);
		for(int i=0;i<=pLng;i++)
			pList->Add((*argButtons++ & 0x80) ? ButtonState::Pressed : ButtonState::Released);
		mButtons=pList->ToArray();
	}

	ButtonState JoystickButtons::GetButtonState(int argIndex)
	{
		if (argIndex<0 || argIndex>=mButtons->Length)
			return ButtonState::Released;

		return mButtons[argIndex];
	}
};
