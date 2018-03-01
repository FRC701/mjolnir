/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "IntakingCondition.h"
#include "SetArmPosition.h"
#include "IntakeEngage.h"
#include "SetIntake.h"
#include "DrawSling.h"
#include "IntakingCondition.h"
#include "Delay.h"
#include "Subsystems/Arm.h"
#include "SetSlingDisengagement.h"

IntakingCondition::IntakingCondition(int position) {
  if(Arm::getInstance()->GetPosition() <= 0)
  {
    AddSequential(new DrawSling(3500));
    AddSequential(new SetSlingDisengagement());
    AddSequential(new DrawSling(7500));
    AddSequential(new IntakeEngage);
    AddSequential(new SetIntake(1.0));
    AddSequential(new Delay(1.0));
    AddSequential(new SetArmPosition(7500));
    AddSequential(new SetIntake(0.0));
  }
  else if(Arm::getInstance()->GetPosition() > 0 && Arm::getInstance()->GetPosition() < 7000)
  {
    AddSequential(new SetArmPosition(0.0));
    AddSequential(new DrawSling(3500));
    AddSequential(new SetSlingDisengagement());
    AddSequential(new DrawSling(7500));
    AddSequential(new IntakeEngage);
    AddSequential(new SetIntake(1.0));
    AddSequential(new Delay(1.0));
    AddSequential(new SetArmPosition(7500));
    AddSequential(new SetIntake(0.0));
  }
  else
  {
    AddSequential(new SetArmPosition(7000));
    AddSequential(new SetArmPosition(0));
    AddSequential(new DrawSling(3500));
    AddSequential(new SetSlingDisengagement());
    AddSequential(new DrawSling(7500));
    AddSequential(new IntakeEngage);
    AddSequential(new SetIntake(1.0));
    AddSequential(new Delay(1.0));
    AddSequential(new SetArmPosition(7500));
    AddSequential(new SetIntake(0.0));
  }

	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.

	// To run multiple commands at the same time,
	// use AddParallel()
	// e.g. AddParallel(new Command1());
	//      AddSequential(new Command2());
	// Command1 and Command2 will run in parallel.

	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.
}
