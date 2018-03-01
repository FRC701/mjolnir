/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <Commands/Subsystem.h>
#include <ctre/phoenix.h>
#include <Commands/SetClimber.h>

class Climber : public frc::Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

  static const char kSubsystemName[];
  static std::shared_ptr<Climber> self;

  WPI_TalonSRX ClimberMotor;


public:
  static std::shared_ptr<Climber> getInstance();


	Climber();
	void InitDefaultCommand() override;
	void Climb(double speed);
};

