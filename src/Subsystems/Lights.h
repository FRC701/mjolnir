/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <Commands/Subsystem.h>
#include "DigitalOutput.h"
#include "Relay.h"
#include "../commands/LightsOn.h"

class Lights : public frc::Subsystem {
private:
  static const char kSubsystemName[];
  static std::shared_ptr<Lights> self;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
  DigitalOutput light;
  LightsOn* defaultCommand;
public:
  static std::shared_ptr<Lights> getInstance();
	Lights();
	void InitDefaultCommand() override;
	void SetLights(Relay::Value value);
	bool IsLightsOn();
	void ToggleLights();
	LightsOn* GetLightsOnCommand();


};

