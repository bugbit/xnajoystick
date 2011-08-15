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

#pragma once

#include <dinput.h>

using namespace System;

namespace XnaJoystick
{
	public enum class JoystickInitEffectType
	{
		None=0,
		Cartesian=DIEFF_CARTESIAN,
		Polar=DIEFF_POLAR ,
		Spherical=DIEFF_SPHERICAL 
	};

	public value struct JoystickInitEffectAxis
	{
	public:
		static const int X=DIJOFS_X;
		static const int Y=DIJOFS_Y;
	public:
		JoystickInitEffectAxis(int argAxes,int argDirection);
	public:
		property int Axes;
		property int Duraction;
	};

	public ref class JoystickInitEffect abstract : public IDisposable
	{
	public:
		static const int Infinite=INFINITE;
	public:
		virtual ~JoystickInitEffect(void);
		!JoystickInitEffect(void);
	public:	
		property JoystickInitEffectType Type { JoystickInitEffectType get(); void set(JoystickInitEffectType); }
		property int Duration { int get(); void set(int); }
		property int SamplePeriod { int get(); void set(int); }
		property int Gain { int get(); void set(int); }
		property int StartDelay { int get(); void set(int); }
		property array<JoystickInitEffectAxis> ^Axes { void set(array<JoystickInitEffectAxis>^); }
	protected:
		JoystickInitEffect();	
	protected:
		LPDIEFFECT mInitEffect;
	private:
		// Track whether Dispose has been called.
		bool mDisposed;
		LPDWORD mAxes;
		LPLONG mDuraction;
	internal:
		property const ::GUID &GUID { virtual const ::GUID &get() abstract; }
		property LPDIEFFECT InitEffect { LPDIEFFECT get(); }
	};

	public ref class JoystickInitEffectConstantForce : public JoystickInitEffect
	{
	public:
		JoystickInitEffectConstantForce();
		virtual ~JoystickInitEffectConstantForce();
		!JoystickInitEffectConstantForce();
	public:
		property int Magnitude { int get(); void set(int); }
	private:
		LPDICONSTANTFORCE mConstantForce;
	internal:
		property const ::GUID &GUID { virtual const ::GUID &get() override; }
	};
};