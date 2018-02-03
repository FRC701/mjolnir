#include "BrakeOn.h"
#include "Subsystems/Arm.h"

BrakeOn::BrakeOn() {

}

// Called just before this Command runs the first time
void BrakeOn::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void BrakeOn::Execute() {
  Arm::getInstance()->EngageBrake();
}

// Make this return true when this Command no longer needs to run execute()
bool BrakeOn::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void BrakeOn::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BrakeOn::Interrupted() {

}
