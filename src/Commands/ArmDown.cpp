#include "ArmDown.h"

ArmDown::ArmDown(double speed)
: mSpeed(speed) {
  Requires(Arm::getInstance().get());

}

// Called just before this Command runs the first time
void ArmDown::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void ArmDown::Execute() {
  Arm::getInstance()->SetArmMove(mSpeed);

}

// Make this return true when this Command no longer needs to run execute()
bool ArmDown::IsFinished() {
	return Arm::getInstance()->IsReverseLimitSwitchClosed();
}

// Called once after isFinished returns true
void ArmDown::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ArmDown::Interrupted() {

}
