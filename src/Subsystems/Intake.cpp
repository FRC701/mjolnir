#include "Intake.h"
#include "Commands/SetIntake.h"
#include "RobotMap.h"

static frc::DoubleSolenoid::Value kIntakeEngage = frc::DoubleSolenoid::kForward;
static frc::DoubleSolenoid::Value kIntakeDisengage = frc::DoubleSolenoid::kReverse;

const char Intake::kSubsystemName[] = "Intake";

std::shared_ptr<Intake> Intake::self;

std::shared_ptr<Intake> Intake::getInstance() {
	if (! self) {
		self = std::shared_ptr<Intake>(new Intake);
	}
	return self;
}

Intake::Intake() : Subsystem(kSubsystemName),
    intakeMotorTop(RobotMap::kIDIntakeMotorTop),
    intakeMotorBottom(RobotMap::kIDIntakeMotorBottom),
    intakeSolenoid(RobotMap::kIDIntakeForward, RobotMap::kIDIntakeReverse)
{
    intakeSolenoid.Set(DoubleSolenoid::kForward);
    intakeMotorTop.SetInverted(true);
    intakeMotorBottom.SetInverted(true);
}

void Intake::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new ::SetIntake(0.0));
}
void Intake::SetIntake(double speed){
  intakeMotorTop.Set(speed);
  intakeMotorBottom.Set(speed);
}

void Intake::IntakeEngage(){
  intakeSolenoid.Set(kIntakeEngage);
}

void Intake::IntakeDisengage(){
  intakeSolenoid.Set(kIntakeDisengage);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
