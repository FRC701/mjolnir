#include "SetArmPosition.h"
#include "Subsystems/Arm.h"

SetArmPosition::SetArmPosition(int position) : mPosition(position), counter(0) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
  Requires(Arm::getInstance().get());
}

// Called just before this Command runs the first time
void SetArmPosition::Initialize() {
  Arm::getInstance()->DisengageBrake();
}

// Called repeatedly when this Command is scheduled to run
void SetArmPosition::Execute() {
  Arm::getInstance()->SetArmPos(mPosition);
}

// Make this return true when this Command no longer needs to run execute()
bool SetArmPosition::IsFinished() {
 static const int kAcceptableError = 1000;
 if(abs(Arm::getInstance()->GetPositionError()) < kAcceptableError){
   if (counter > 30)
   {
     Arm::getInstance()->EngageBrake();
     counter = 0;
     return true;
   }
   else {
     ++counter;
     return false;
     }
   }
   else {
     counter = 0;
     return false;
     }
}


// Called once after isFinished returns true
void SetArmPosition::End() {
  Arm::getInstance()->SetArmMove(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetArmPosition::Interrupted() {
  End();
}
