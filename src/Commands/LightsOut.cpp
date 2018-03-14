/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "LightsOut.h"
#include "Subsystems/Lights.h"

LightsOut::LightsOut() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
  Requires(Lights::getInstance().get());
}

// Called once when the command executes
void LightsOut::Initialize() {
  Lights::getInstance()->SetLights(Relay::kOff);
}
