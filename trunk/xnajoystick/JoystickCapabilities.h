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

namespace XnaJoystick
{
	struct DI_ENUM_DEVICE;

	public enum class JoystickType
	{
		Unknown=DI8DEVTYPEMOUSE_UNKNOWN,
		Joystick=DI8DEVTYPE_JOYSTICK,
		GamePad=DI8DEVTYPE_GAMEPAD,
		Driving=DI8DEVTYPE_DRIVING,
		Flight=DI8DEVTYPE_FLIGHT,
		FirstPerson=DI8DEVTYPE_1STPERSON,
		DeviceControl=DI8DEVTYPE_DEVICECTRL,
		ScreenPtr=DI8DEVTYPE_SCREENPOINTER,
		Remote=DI8DEVTYPE_REMOTE,
		Supplemental=DI8DEVTYPE_SUPPLEMENTAL
	};

	public enum class JoystickSubType
	{
		JoystickLimited=DI8DEVTYPEJOYSTICK_LIMITED,
		JoystickStandard=DI8DEVTYPEJOYSTICK_STANDARD,
		GamePadLimited=DI8DEVTYPEGAMEPAD_LIMITED,
		GamePadStandard=DI8DEVTYPEGAMEPAD_STANDARD,
		GamePadTilt=DI8DEVTYPEGAMEPAD_TILT,
		DrivingLimited =DI8DEVTYPEDRIVING_LIMITED,
		DrivingCombinedPedals=DI8DEVTYPEDRIVING_COMBINEDPEDALS,
		DrivingDualPedals=DI8DEVTYPEDRIVING_DUALPEDALS,
		DrivingThreePedals=DI8DEVTYPEDRIVING_THREEPEDALS,
		DrivingHandHeld=DI8DEVTYPEDRIVING_HANDHELD,
		FlightLimited=DI8DEVTYPEFLIGHT_LIMITED,
		FlightStick=DI8DEVTYPEFLIGHT_STICK,
		FlightYoke=DI8DEVTYPEFLIGHT_YOKE,
		FlightRemoteControl=DI8DEVTYPEFLIGHT_RC,
		FirstPersonLimited=DI8DEVTYPE1STPERSON_LIMITED,
		FirstPersonUnknown=DI8DEVTYPE1STPERSON_UNKNOWN,
		FirstPersonSixDegreesOfFreedom=DI8DEVTYPE1STPERSON_SIXDOF,
		FirstPersonShooter=DI8DEVTYPE1STPERSON_SHOOTER,
		ScreenPtrUnknown=DI8DEVTYPESCREENPTR_UNKNOWN,
		ScreenPtrLightGun=DI8DEVTYPESCREENPTR_LIGHTGUN,
		ScreenPtrLightPen=DI8DEVTYPESCREENPTR_LIGHTPEN,
		ScreenPtrTouch=DI8DEVTYPESCREENPTR_TOUCH,
		RemoteUnknown=DI8DEVTYPEREMOTE_UNKNOWN,
		DeviceControlUnknown=DI8DEVTYPEDEVICECTRL_UNKNOWN,
		DeviceControlCommsSelection=DI8DEVTYPEDEVICECTRL_COMMSSELECTION,
		DeviceControlCommsSelectionHardwired=DI8DEVTYPEDEVICECTRL_COMMSSELECTION_HARDWIRED,
		SupplementalUnknown=DI8DEVTYPESUPPLEMENTAL_UNKNOWN,
		SupplementalSecondHandController=DI8DEVTYPESUPPLEMENTAL_2NDHANDCONTROLLER,
		SupplementalHeadTracker=DI8DEVTYPESUPPLEMENTAL_HEADTRACKER,
		SupplementalHandTracker=DI8DEVTYPESUPPLEMENTAL_HANDTRACKER,
		SupplementalShiftStickGate=DI8DEVTYPESUPPLEMENTAL_SHIFTSTICKGATE,
		SupplementalShifter=DI8DEVTYPESUPPLEMENTAL_SHIFTER,
		SupplementalThrottle=DI8DEVTYPESUPPLEMENTAL_THROTTLE,
		SupplementalSplitThrottle=DI8DEVTYPESUPPLEMENTAL_SPLITTHROTTLE,
		SupplementalCombinedPedals=DI8DEVTYPESUPPLEMENTAL_COMBINEDPEDALS,
		SupplementalDualPedals=DI8DEVTYPESUPPLEMENTAL_DUALPEDALS,
		SupplementalThreePedals =DI8DEVTYPESUPPLEMENTAL_THREEPEDALS,
		SupplementalRudderPedals =DI8DEVTYPESUPPLEMENTAL_RUDDERPEDALS,
	};

	public value class JoystickCapabilities
	{
	public:
		JoystickCapabilities(DIDEVCAPS &argCaps,DI_ENUM_DEVICE &pEnumDevice);
		property JoystickType Type { JoystickType get(); }
		property JoystickSubType SubType { JoystickSubType get(); }
		property int NumberButtons { int get(); }
		property int NumberDPad { int get(); }
		property int NumberAxes { int get(); }
		property bool IsConnected {	bool get(); }
    property bool HasAxisX {	bool get(); }
    property bool HasAxisY {	bool get(); }
    property bool HasAxisZ {	bool get(); }
    property bool HasAxisRotX {	bool get(); }
    property bool HasAxisRotY {	bool get(); }
    property bool HasAxisRotZ {	bool get(); }
    property bool HasLeftVibrationMotor {	bool get(); }
    property bool HasRightVibrationMotor {	bool get(); }
    property bool HasVoiceSupport {	bool get(); }
	private:
		int mNumberButtons;
		int mNumberDPad;
		int mNumberAxes;
		bool mConnected;
		DI_ENUM_DEVICE &mEnumDevice;
		JoystickType mType;
		JoystickSubType mSubType;
	};
};