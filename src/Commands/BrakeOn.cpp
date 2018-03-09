#include "BrakeOn.h"
#include "Subsystems/Arm.h"

BrakeOn::BrakeOn() {
  Requires(Arm::getInstance().get());
}

// Called just before this Command runs the first time
void BrakeOn::Initialize() {
  Arm::getInstance()->EngageBrake();
}

// Called repeatedly when this Command is scheduled to run
void BrakeOn::Execute() {
  Arm::getInstance()->SetArmMove(0.0);
}

// Make this return true when this Command no longer needs to run execute()
bool BrakeOn::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void BrakeOn::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BrakeOn::Interrupted() {

}
