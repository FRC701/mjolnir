/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "AutoFullDoubleRightSwitch.h"
#include "AutoRightSwitch.h"
#include "AutoRightSwitchReverse.h"
#include "SetArmPosition.h"
#include "PrepSwitch.h"
#include "SetIntake.h"
#include "Delay.h"
#include "AutoSwitchIntake.h"
#include "Intaking.h"
#include "AutoSwitchIntakeReverse.h"
#include "IntakeEngage.h"
#include "SetArmPosConditional.h"
#include "AutoRightSwitch.h"
#include "AutoPostRightSwitch.h"


AutoFullDoubleRightSwitch::AutoFullDoubleRightSwitch() {
	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.
  //Drop cube in switch
  AddSequential(new AutoRightSwitch);
  AddSequential(new PrepSwitch);
  AddSequential(new SetIntake(-1.0));
  AddSequential(new SetArmPosition(9500));
  AddSequential(new Delay(0.5));
  AddSequential(new AutoRightSwitchReverse());
  //Intake cube
  AddParallel(new IntakeEngage());
  AddSequential(new SetArmPosConditional(7500));
  AddSequential(new Delay(0.25));
  AddSequential(new SetArmPosition(0));
  AddParallel(new AutoSwitchIntake);
  AddSequential(new SetIntake(1.0));
  AddSequential(new SetArmPosition(9500));
  //Drive back
  AddSequential(new AutoSwitchIntakeReverse);
  //Put new cube in switch
  AddSequential(new AutoRightSwitch);
  AddSequential(new PrepSwitch);
  AddSequential(new SetIntake(-1.0));
  AddSequential(new Delay(0.5));
  AddSequential(new SetArmPosition(9500));
  AddSequential(new Delay(0.5));
  //post switch
  AddSequential(new AutoPostRightSwitch());




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
