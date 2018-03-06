/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "LightsOn.h"
#include "Subsystems/Lights.h"

LightsOn::LightsOn() {
  Requires(Lights::getInstance().get());
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void LightsOn::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void LightsOn::Execute() {
  Lights::getInstance()->SetLights(Relay::kOn);
}

// Make this return true when this Command no longer needs to run execute()
bool LightsOn::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void LightsOn::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LightsOn::Interrupted() {

}
