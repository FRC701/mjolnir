/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <Commands/Command.h>
#include "SetArmPosition.h"
#include "Subsystems/Arm.h"

class SetArmPosConditional : public SetArmPosition {
public:
	SetArmPosConditional(int position);
	void Execute() override;
	bool IsFinished() override;
};

