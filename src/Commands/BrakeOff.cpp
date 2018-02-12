#include "BrakeOff.h"
#include "Subsystems/Arm.h"

BrakeOff::BrakeOff() {
  Requires(Arm::getInstance().get());
}

// Called just before this Command runs the first time
void BrakeOff::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void BrakeOff::Execute() {
  Arm::getInstance()->DisengageBrake();
}

// Make this return true when this Command no longer needs to run execute()
bool BrakeOff::IsFinished() {
  return false;
}

// Called once after isFinished returns true
void BrakeOff::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BrakeOff::Interrupted() {

}
