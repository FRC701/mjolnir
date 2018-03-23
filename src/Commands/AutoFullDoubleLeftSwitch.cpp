/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "AutoFullDoubleLeftSwitch.h"
#include "PrepSwitch.h"
#include "AutoLeftSwitch.h"
#include "SetArmPosition.h"
#include "SetIntake.h"
#include "Delay.h"
#include "AutoLeftSwitchReverse.h"
#include "IntakeEngage.h"
#include "SetArmPosConditional.h"
#include "AutoSwitchIntake.h"
#include "AutoSwitchIntakeReverse.h"
#include "AutoPostLeftSwitch.h"
#include "DrawSling.h"


AutoFullDoubleLeftSwitch::AutoFullDoubleLeftSwitch() {
	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.
  //Go to switch and drop cube
  AddSequential(new AutoLeftSwitch);
  AddSequential(new PrepSwitch);
  AddSequential(new SetIntake(-1.0));
  AddSequential(new Delay(0.5));
  AddSequential(new SetArmPosition(9500));
  AddSequential(new Delay(0.5));
  //Go back to start position
  AddSequential(new AutoLeftSwitchReverse());
  //Intake cube
  AddParallel(new IntakeEngage());
  AddSequential(new SetArmPosConditional(7500));
  AddSequential(new Delay(0.25));
  AddSequential(new SetArmPosition(0));
  AddParallel(new AutoSwitchIntake);
  AddParallel(new DrawSling(2666));
  AddSequential(new SetIntake(1.0));
  AddSequential(new SetArmPosition(9500));
  //Drive back
  AddSequential(new AutoSwitchIntakeReverse);
  //Put new cube in switch
  AddSequential(new AutoLeftSwitch);
  AddSequential(new PrepSwitch);
  AddSequential(new SetIntake(-1.0));
  AddSequential(new Delay(0.5));
  AddSequential(new SetArmPosition(9500));
  AddSequential(new Delay(0.5));
  //post switch
  AddSequential(new AutoPostLeftSwitch());



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
