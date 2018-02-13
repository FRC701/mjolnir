/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "BrakeOff.h"
#include "Subsystems/Arm.h"

BrakeOff::BrakeOff() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
  Requires(Arm::getInstance().get());
}

// Called just before this Command runs the first time
void BrakeOff::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void BrakeOff::Execute() {
  Arm::getInstance()->DisengageBrake();
}

// Make this return true when this Command no longer needs to run execute()
bool BrakeOff::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void BrakeOff::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BrakeOff::Interrupted() {

}
