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

#include "JoystickInitEffect.h"

using namespace System;

namespace XnaJoystick
{
	[Flags]
	public enum class JoystickFlagsEffect
	{
		None=0,
		Solo=DIES_SOLO,
		NoDownload=DIES_NODOWNLOAD 
	};

	public ref class JoystickEffect : public IDisposable
	{
	public:
		static const int NominalMax=DI_FFNOMINALMAX;
		static const int Infinite=INFINITE;
	public:
		~JoystickEffect();
		!JoystickEffect();
		void Start(int argIterations,JoystickFlagsEffect argFlags);
		void Start(int argIterations);
		void Start(JoystickFlagsEffect argFlags);
		void Start();
	private:
		// Track whether Dispose has been called.
		bool mDisposed;
		LPDIRECTINPUTDEVICE8 mDevice;
		LPDIRECTINPUTEFFECT mEffect;
	internal:
		JoystickEffect(LPDIRECTINPUTDEVICE8 argDevice,LPDIRECTINPUTEFFECT argEffect);
	};
};