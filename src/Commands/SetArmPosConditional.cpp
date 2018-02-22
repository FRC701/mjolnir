/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "SetArmPosConditional.h"

SetArmPosConditional::SetArmPosConditional(int position)
: SetArmPosition(position)
{

}

// Called repeatedly when this Command is scheduled to run
void SetArmPosConditional::Execute() {
  if(Arm::getInstance()->GetPosition() >= mPosition)
  {
    SetArmPosition::Execute();
  }
}

bool SetArmPosConditional::IsFinished() {
  if(Arm::getInstance()->GetPosition() >= mPosition)
   {
     return SetArmPosition::IsFinished();
   }
  else
  {
    return true;
  }
}
// Make this return true when this Command no longer needs to run execute()
