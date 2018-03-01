/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Climber.h"
#include "../RobotMap.h"

const char Climber::kSubsystemName[] = "Climber";

std::shared_ptr<Climber> Climber::self;
std::shared_ptr<Climber> Climber::getInstance() {
  if (! self) {
    self = std::shared_ptr<Climber>(new Climber);
  }
  return self;
}

Climber::Climber() : Subsystem(kSubsystemName),
    ClimberMotor(RobotMap::kIDClimber)
{


}

void Climber::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
  SetDefaultCommand(new SetClimber(0.0));
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void Climber::Climb(double speed){
  ClimberMotor.Set(speed);
}
