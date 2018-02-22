#include "PuncherVoltage.h"
#include "Subsystems/Puncher.h"
#include "SmartDashboard/SmartDashboard.h"

PuncherVoltage::PuncherVoltage() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
  Requires(Puncher::getInstance().get());
}

// Called just before this Command runs the first time
void PuncherVoltage::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void PuncherVoltage::Execute() {
  Puncher::getInstance()->SetSlingShot(SmartDashboard::GetNumber("Puncher zeroing Voltage", 0.0));
}

// Make this return true when this Command no longer needs to run execute()
bool PuncherVoltage::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void PuncherVoltage::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PuncherVoltage::Interrupted() {

}
