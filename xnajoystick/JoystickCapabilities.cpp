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
#include "JoystickCapabilities.h"
#include "JoystickDevice.h"

namespace XnaJoystick
{
	JoystickCapabilities::JoystickCapabilities(DIDEVCAPS &argCaps,DI_ENUM_DEVICE &pEnumDevice)
		:mEnumDevice(pEnumDevice)
		,mType((JoystickType) GET_DIDEVICE_TYPE(argCaps.dwDevType))
		,mSubType((JoystickSubType) GET_DIDEVICE_SUBTYPE(argCaps.dwDevType))
		,mNumberButtons(argCaps.dwButtons)
		,mNumberDPad(argCaps.dwPOVs)
		,mNumberAxes(argCaps.dwAxes)
		,mConnected(true)
	{		
	}

	JoystickType JoystickCapabilities::Type::get()
	{
		return mType;
	}

	JoystickSubType JoystickCapabilities::SubType::get()
	{
		return mSubType;
	}

	int JoystickCapabilities::NumberButtons::get()
	{
		return mNumberButtons;
	}

	int JoystickCapabilities::NumberDPad::get()
	{
		return mNumberDPad;
	}

	int JoystickCapabilities::NumberAxes::get()
	{
		return mNumberAxes;
	}

	bool JoystickCapabilities::IsConnected::get()
	{
		return mConnected;
	}

  bool JoystickCapabilities::HasAxisX::get()
	{
		return mEnumDevice.Flags.S.XAxis;
	}

  bool JoystickCapabilities::HasAxisY::get()
	{
		return mEnumDevice.Flags.S.YAxis;
	}

  bool JoystickCapabilities::HasAxisZ::get()
	{
		return mEnumDevice.Flags.S.ZAxis;
	}

  bool JoystickCapabilities::HasAxisRotX::get()
	{
		return mEnumDevice.Flags.S.RXAxis;
	}

  bool JoystickCapabilities::HasAxisRotY::get()
	{
		return mEnumDevice.Flags.S.RYAxis;
	}

  bool JoystickCapabilities::HasAxisRotZ::get()
	{
		return mEnumDevice.Flags.S.RZAxis;
	}

  bool JoystickCapabilities::HasLeftVibrationMotor::get()
	{
		return false;
	}

  bool JoystickCapabilities::HasRightVibrationMotor::get()
	{
		return false;
	}

  bool JoystickCapabilities::HasVoiceSupport::get()
	{
		return false;
	}
};
