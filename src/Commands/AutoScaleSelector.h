/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <Commands/InstantCommand.h>

class AutoScaleSelector : public frc::InstantCommand {
private:
    frc::Command* leftCommand;
    frc::Command* rightCommand;
public:
	AutoScaleSelector(
	    frc::Command* leftCommand,
	    frc::Command* rightCommand);
	void Initialize() override;
};

