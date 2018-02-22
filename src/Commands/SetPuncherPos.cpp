/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "SetPuncherPos.h"
#include "Subsystems/Puncher.h"

SetPuncherPos::SetPuncherPos(int position) : mPosition(position), counter(0) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
  Requires(Puncher::getInstance().get());
}

// Called just before this Command runs the first time
void SetPuncherPos::Initialize() {
  Puncher::getInstance()->MotorEngage();

}

// Called repeatedly when this Command is scheduled to run
void SetPuncherPos::Execute() {
  Puncher::getInstance()->SetSlingShot(1.0);
}

// Make this return true when this Command no longer needs to run execute()
bool SetPuncherPos::IsFinished() {
  static const double kMaxCurrent = 100;
  std::shared_ptr<Puncher> puncher = Puncher::getInstance();
	return puncher->GetPosition() >= mPosition
	    || puncher->GetPuncherLimit()
	    || puncher->GetCurrent() > kMaxCurrent;
}

// Called once after isFinished returns true
void SetPuncherPos::End() {
  Puncher::getInstance()->SetSlingShot(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetPuncherPos::Interrupted() {
  Puncher::getInstance()->SetSlingShot(0.0);
}
