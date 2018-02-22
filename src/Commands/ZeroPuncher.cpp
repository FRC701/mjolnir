/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "ZeroPuncher.h"
#include "Subsystems/Puncher.h"

static const double kZeroVoltage = 0.0;
static const double kZeroCurrent = 0.0;
ZeroPuncher::ZeroPuncher() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
  Requires(Puncher::getInstance().get());
}

// Called just before this Command runs the first time
void ZeroPuncher::Initialize() {
  Puncher::getInstance()->MotorEngage();
}

// Called repeatedly when this Command is scheduled to run
void ZeroPuncher::Execute() {
  Puncher::getInstance()->SetSlingShot(kZeroVoltage);
}

// Make this return true when this Command no longer needs to run execute()
bool ZeroPuncher::IsFinished() {
	return Puncher::getInstance()->GetCurrent() >= kZeroCurrent;
  //return false;
}

// Called once after isFinished returns true
void ZeroPuncher::End() {
  return Puncher::getInstance()->SetSlingShot(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ZeroPuncher::Interrupted() {
  return Puncher::getInstance()->SetSlingShot(0);
}
