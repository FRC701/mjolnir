#include "ResetArmPosition.h"
#include "Subsystems/Arm.h"

ResetArmPosition::ResetArmPosition() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
  Requires(Arm::getInstance().get());
}

// Called just before this Command runs the first time
void ResetArmPosition::Initialize() {
  Arm::getInstance()->ResetArmPos();
}

// Called repeatedly when this Command is scheduled to run
