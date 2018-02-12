#include "Intake.h"
#include "Commands/SetIntake.h"
#include "RobotMap.h"

const char Intake::kSubsystemName[] = "Intake";

std::shared_ptr<Intake> Intake::self;

std::shared_ptr<Intake> Intake::getInstance() {
	if (! self) {
		self = std::shared_ptr<Intake>(new Intake);
	}
	return self;
}

Intake::Intake() : Subsystem(kSubsystemName),
    intakeMotor(RobotMap::kIDIntakeMotor),
    intakeSolenoid(RobotMap::kIDIntakeForward, RobotMap::kIDIntakeReverse)
{
    intakeSolenoid.Set(DoubleSolenoid::kForward);
}

void Intake::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new ::SetIntake(0.0));
}
void Intake::SetIntake(double speed){
  intakeMotor.Set(speed);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

