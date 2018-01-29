#include "ArmUp.h"
#include "Subsystems/Arm.h"

ArmUp::ArmUp(double speed)
: mSpeed(speed) {
  Requires(Arm::getInstance().get());
}

// Called just before this Command runs the first time
void ArmUp::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void ArmUp::Execute() {
  Arm::getInstance()->SetArmMove(mSpeed);

}

// Make this return true when this Command no longer needs to run execute()
bool ArmUp::IsFinished() {
	return Arm::getInstance()->IsForwardLimitSwitchClosed();
}

// Called once after isFinished returns true
void ArmUp::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ArmUp::Interrupted() {

}
