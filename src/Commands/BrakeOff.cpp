#include "BrakeOff.h"
#include "Subsystems/Arm.h"

BrakeOff::BrakeOff() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
  Requires(Arm::getInstance().get());
}

// Called once when the command executes
void BrakeOff::Initialize() {
  Arm::getInstance()->DisengageBrake();
}
