/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "AutoSelector.h"
#include "GameData.h"

#include "Commands/Scheduler.h"

using robovikes::GameData;

AutoSelector::AutoSelector(
    frc::Command* _leftCommand,
    frc::Command* _rightCommand)
: leftCommand(_leftCommand),
  rightCommand(_rightCommand)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void AutoSelector::Initialize() {
  GameData::Side side = GameData::GetOurSwitchSide();

  if (side == GameData::Left) {
    frc::Scheduler::GetInstance()->AddCommand(leftCommand);
  } else if (side == GameData::Right) {
    frc::Scheduler::GetInstance()->AddCommand(rightCommand);
  }
}

