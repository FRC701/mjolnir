/*----------------------------------------------------------------------------*/
/* CopyLeft (c) 2017-2018 FIRST. All Lefts Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "AutoFullTripleLeftSwitch.h"
#include "AutoLeftSwitch.h"
#include "PrepSwitch.h"
#include "SetIntake.h"
#include "SetArmPosition.h"
#include "Delay.h"
#include "AutoThreeLeftFromSwitch.h"
#include "AutoThreeLeftSwitchFirstIntake.h"
#include "AutoThreeLeftSwitchFirstIntakeReverse.h"
#include "AutoThreeLeftToSwitch.h"
#include "AutoThreeLeftSwitchSecondIntake.h"
#include "AutoThreeLeftSwitchSecondIntakeReverse.h"
#include "AutoThreeLeftSwitchThirdIntake.h"
#include "AutoThreeLeftSwitchThirdIntakeReverse.h"

AutoFullTripleLeftSwitch::AutoFullTripleLeftSwitch() {
  //First cube
    AddSequential(new AutoLeftSwitch);
    AddSequential(new PrepSwitch);
    AddSequential(new SetIntake(-0.3));
    AddSequential(new SetArmPosition(9500));
    AddSequential(new Delay(0.15));
    //Second cube
    AddSequential(new AutoThreeLeftFromSwitch);
    AddParallel(new AutoThreeLeftSwitchFirstIntake);
    AddSequential(new SetIntake(1.0));
    AddSequential(new Delay(0.15));
    AddSequential(new PrepSwitch);
    AddSequential(new AutoThreeLeftSwitchFirstIntakeReverse);
    AddSequential(new AutoThreeLeftToSwitch);
    AddSequential(new SetIntake(-0.3));
    AddSequential(new SetArmPosition(9500));
    AddSequential(new Delay(0.15));
    //Third cube
    AddSequential(new AutoThreeLeftFromSwitch);
    AddParallel(new AutoThreeLeftSwitchSecondIntake);
    AddSequential(new SetIntake(1.0));
    AddSequential(new Delay(0.15));
    AddSequential(new PrepSwitch);
    AddSequential(new AutoThreeLeftSwitchSecondIntakeReverse);
    AddSequential(new AutoThreeLeftToSwitch);
    AddSequential(new SetIntake(-0.3));
    AddSequential(new SetArmPosition(9500));
    AddSequential(new Delay(0.15));
    //Third cube
    AddSequential(new AutoThreeLeftFromSwitch);
    AddParallel(new AutoThreeLeftSwitchThirdIntake);
    AddSequential(new SetIntake(1.0));
    AddSequential(new Delay(0.15));
    AddSequential(new PrepSwitch);
    AddSequential(new AutoThreeLeftSwitchThirdIntakeReverse);
    AddSequential(new AutoThreeLeftToSwitch);
    AddSequential(new SetIntake(-0.3));
    AddSequential(new SetArmPosition(9500));
    AddSequential(new Delay(0.15));
}
