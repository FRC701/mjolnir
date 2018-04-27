/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Intaking.h"
#include "SetArmPosition.h"
#include "IntakeEngage.h"
#include "SetIntake.h"
#include "DrawSling.h"
#include "Delay.h"
#include "SetArmPosConditional.h"
#include "SetPuncherPos.h"

Intaking::Intaking() {

  //AddParallel(new SetPuncherPos(7000));
  AddParallel(new IntakeEngage());
  AddSequential(new SetArmPosConditional(7500));
  AddSequential(new Delay(0.25));
  AddParallel(new SetArmPosition(0));
  //AddParallel(new DrawSling(24000));
  AddSequential(new SetIntake(1.0));
  AddSequential(new Delay(1.0));
  //AddParallel(new SetArmPosition(9500)); //7700
  AddSequential(new SetIntake(0.0));
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
