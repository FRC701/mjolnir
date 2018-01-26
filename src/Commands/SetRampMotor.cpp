#include "SetRampMotor.h"
#include "../Subsystems/Ramp.h"
#include "SetRamp.h"
#include "OI.h"

SetRampMotor::SetRampMotor(double speed) : mSpeed(speed) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
  Requires(Ramp::getInstance().get());
}

// Called once when the command executes
void SetRampMotor::Initialize() {

}

void SetRampMotor::Execute() {
  Ramp::getInstance()->SetRampMotor(mSpeed);
}
bool SetRampMotor::IsFinished() {
  return false;
}

void SetRampMotor::End() {

}

void SetRampMotor::Interrupted(){

}
