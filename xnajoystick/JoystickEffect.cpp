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
#include "JoystickEffect.h"

namespace XnaJoystick
{
	JoystickEffect::JoystickEffect(LPDIRECTINPUTDEVICE8 argDevice,LPDIRECTINPUTEFFECT argEffect)
		:mDisposed(false)
		,mDevice(argDevice)
		,mEffect(argEffect)
	{
	}

	JoystickEffect::~JoystickEffect()
	{
		this->!JoystickEffect();
		mDisposed=true;
	}

	JoystickEffect::!JoystickEffect()
	{
		SAFE_RELEASE(mEffect);
	}

	void JoystickEffect::Start(int argIterations,JoystickFlagsEffect argFlags)
	{
		HRESULT pResult;

		mDevice->Acquire();
		pResult=mEffect->Start(argIterations,(int) argFlags);
		switch (pResult)
		{
			case DIERR_INCOMPLETEEFFECT:
				throw gcnew ArgumentException("Effect::Start DIERR_INCOMPLETEEFFECT");
			case DIERR_INVALIDPARAM:
				throw gcnew ArgumentException("Effect::Start DIERR_INVALIDPARAM");
			case DIERR_NOTEXCLUSIVEACQUIRED:
				throw gcnew ArgumentException("Effect::Start DIERR_NOTEXCLUSIVEACQUIRED");
			case DIERR_NOTINITIALIZED:
				throw gcnew ArgumentException("Effect::Start DIERR_NOTINITIALIZED");
			case  DIERR_UNSUPPORTED:
				throw gcnew ArgumentException("Effect::Start  DIERR_UNSUPPORTED");
			case DI_OK:
				return;
			default:
				throw gcnew ArgumentException("FAILED CreateEffect");
		}
	}

	void JoystickEffect::Start(int argIterations)
	{
		Start(argIterations,JoystickFlagsEffect::None);
	}

	void JoystickEffect::Start(JoystickFlagsEffect argFlags)
	{
		Start(1,argFlags);
	}
		
	void JoystickEffect::Start()
	{
		Start(JoystickFlagsEffect::None);
	}
};