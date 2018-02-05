#include "ResetArmPosition.h"
#include "Subsystems/Arm.h"

ResetArmPosition::ResetArmPosition() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
  Requires(Arm::getInstance().get());
}

// Called just before this Command runs the first time
void ResetArmPosition::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void ResetArmPosition::Execute() {
  Arm::getInstance()->ResetArmPos();
}

// Make this return true when this Command no longer needs to run execute()
bool ResetArmPosition::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ResetArmPosition::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ResetArmPosition::Interrupted() {

}
