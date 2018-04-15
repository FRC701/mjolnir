/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "AutoFullTripleRightSwitch.h"
#include "AutoRightSwitch.h"
#include "PrepSwitch.h"
#include "SetIntake.h"
#include "SetArmPosition.h"
#include "Delay.h"
#include "AutoThreeRightFromSwitch.h"
#include "AutoThreeRightSwitchFirstIntake.h"
#include "AutoThreeRightSwitchFirstIntakeReverse.h"
#include "AutoThreeRightToSwitch.h"
#include "AutoThreeRightSwitchSecondIntake.h"
#include "AutoThreeRightSwitchSecondIntakeReverse.h"
#include "AutoThreeRightSwitchThirdIntake.h"
#include "AutoThreeRightSwitchThirdIntakeReverse.h"

AutoFullTripleRightSwitch::AutoFullTripleRightSwitch() {
  //First cube
  AddSequential(new AutoRightSwitch);
  AddSequential(new PrepSwitch);
  AddSequential(new SetIntake(-0.3));
  AddSequential(new SetArmPosition(9500));
  AddSequential(new Delay(0.15));
  //Second cube
  AddSequential(new AutoThreeRightFromSwitch);
  AddParallel(new AutoThreeRightSwitchFirstIntake);
  AddSequential(new SetIntake(1.0));
  AddSequential(new Delay(0.15));
  AddSequential(new PrepSwitch);
  AddSequential(new AutoThreeRightSwitchFirstIntakeReverse);
  AddSequential(new AutoThreeRightToSwitch);
  AddSequential(new SetIntake(-0.3));
  AddSequential(new SetArmPosition(9500));
  AddSequential(new Delay(0.15));
  //Third cube
  AddSequential(new AutoThreeRightFromSwitch);
  AddParallel(new AutoThreeRightSwitchSecondIntake);
  AddSequential(new SetIntake(1.0));
  AddSequential(new Delay(0.15));
  AddSequential(new PrepSwitch);
  AddSequential(new AutoThreeRightSwitchSecondIntakeReverse);
  AddSequential(new AutoThreeRightToSwitch);
  AddSequential(new SetIntake(-0.3));
  AddSequential(new SetArmPosition(9500));
  AddSequential(new Delay(0.15));
  //Third cube
  AddSequential(new AutoThreeRightFromSwitch);
  AddParallel(new AutoThreeRightSwitchThirdIntake);
  AddSequential(new SetIntake(1.0));
  AddSequential(new Delay(0.15));
  AddSequential(new PrepSwitch);
  AddSequential(new AutoThreeRightSwitchThirdIntakeReverse);
  AddSequential(new AutoThreeRightToSwitch);
  AddSequential(new SetIntake(-0.3));
  AddSequential(new SetArmPosition(9500));
  AddSequential(new Delay(0.15));
}
