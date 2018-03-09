/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Lights.h"
#include "../RobotMap.h"
#include "Commands/LightsOn.h"

const char Lights::kSubsystemName[] = "Lights";

std::shared_ptr<Lights> Lights::self;

std::shared_ptr<Lights> Lights::getInstance() {
        if (! self) {
          self = std::shared_ptr<Lights>(new Lights);
        }
        return self;
}

Lights::Lights() : Subsystem("Lights"), light(0) {

}

void Lights::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

void Lights::SetLights(Relay::Value value)
{
  light.Set(static_cast<Relay::Value>(value));
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
