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
#include "JoystickInitEffect.h"

namespace XnaJoystick
{
	JoystickInitEffectAxis::JoystickInitEffectAxis(int argAxes,int argDuraction)
	{
		Axes=argAxes;
		Duraction=argDuraction;
	}
	JoystickInitEffect::JoystickInitEffect()
		:mDisposed(false)
		,mAxes(NULL)
		,mDuraction(NULL)
	{
		mInitEffect=new DIEFFECT;
		memset(mInitEffect,0,sizeof(DIEFFECT));
		mInitEffect->dwSize=(DWORD) sizeof(DIEFFECT);
		mInitEffect->dwTriggerButton=DIEB_NOTRIGGER;
		mInitEffect->dwTriggerRepeatInterval=0;
		mInitEffect->lpEnvelope=NULL;
		Type=JoystickInitEffectType::None;
	}

	JoystickInitEffect::~JoystickInitEffect(void)
	{
		this->!JoystickInitEffect();
		mDisposed=true;
	}

	JoystickInitEffect::!JoystickInitEffect(void)
	{
		if (mInitEffect!=NULL)
			delete mInitEffect;
		if (mAxes!=NULL)
			delete mAxes;
		if (mDuraction!=NULL)
			delete mDuraction;
	}

	LPDIEFFECT JoystickInitEffect::InitEffect::get()
	{
		return mInitEffect;
	}

	JoystickInitEffectType JoystickInitEffect::Type::get()
	{
		return (JoystickInitEffectType) (mInitEffect->dwFlags & ~DIEFF_OBJECTOFFSETS);
	}

	void JoystickInitEffect::Type::set(JoystickInitEffectType argType)
	{
		mInitEffect->dwFlags=(int) argType | DIEFF_OBJECTOFFSETS;
	}

	int JoystickInitEffect::Duration::get()
	{
		return mInitEffect->dwDuration;
	}

	void JoystickInitEffect::Duration::set(int argValue)
	{
		mInitEffect->dwDuration=argValue;
	}

	int JoystickInitEffect::SamplePeriod::get()
	{
		return mInitEffect->dwSamplePeriod;
	}

	void JoystickInitEffect::SamplePeriod::set(int argValue)
	{
		mInitEffect->dwSamplePeriod=argValue;
	}

	int JoystickInitEffect::Gain::get()
	{
		return mInitEffect->dwGain;
	}

	void JoystickInitEffect::Gain::set(int argValue)
	{
		mInitEffect->dwGain=argValue;
	}

	int JoystickInitEffect::StartDelay::get()
	{
		return mInitEffect->dwStartDelay;
	}

	void JoystickInitEffect::StartDelay::set(int argValue)
	{
		mInitEffect->dwStartDelay=argValue;
	}

	void JoystickInitEffect::Axes::set(array<JoystickInitEffectAxis> ^argAxis)
	{
		const int pNumAxes=argAxis->Length;

		mAxes=new DWORD[pNumAxes];
		mDuraction=new LONG[pNumAxes];
		for(int i=0;i<pNumAxes;i++)
		{
			JoystickInitEffectAxis pAxes=argAxis[i];
			mAxes[i]=pAxes.Axes;
			mDuraction[i]=pAxes.Duraction;
		}
		mInitEffect->cAxes=pNumAxes;
		mInitEffect->rgdwAxes=mAxes;
		mInitEffect->rglDirection=mDuraction;
	}

	JoystickInitEffectConstantForce::JoystickInitEffectConstantForce()
		:JoystickInitEffect()
	{
		mConstantForce=new DICONSTANTFORCE;
		memset(mConstantForce,0,sizeof(DICONSTANTFORCE));
		mInitEffect->cbTypeSpecificParams=sizeof(DICONSTANTFORCE);
		mInitEffect->lpvTypeSpecificParams=mConstantForce;
	}

	JoystickInitEffectConstantForce::~JoystickInitEffectConstantForce()
	{
		this->!JoystickInitEffectConstantForce();
	}

	JoystickInitEffectConstantForce::!JoystickInitEffectConstantForce()
	{
		if (mConstantForce!=NULL)
			delete mConstantForce;
	}

	int JoystickInitEffectConstantForce::Magnitude::get()
	{
		return mConstantForce->lMagnitude;
	}

	void JoystickInitEffectConstantForce::Magnitude::set(int argValue)
	{
		mConstantForce->lMagnitude=argValue;
	}

	const ::GUID &JoystickInitEffectConstantForce::GUID::get()
	{
		return GUID_ConstantForce;
	}
};