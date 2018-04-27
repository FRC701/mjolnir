#ifndef INTAKE_H
#define INTAKE_H

#include "Commands/Subsystem.h"
#include "ctre/Phoenix.h"
#include "DoubleSolenoid.h"

class Intake: public frc::Subsystem {
private:
	static const char kSubsystemName[];
	static std::shared_ptr<Intake> self;
  WPI_TalonSRX intakeMotorTop;
  WPI_TalonSRX intakeMotorBottom;
  DoubleSolenoid intakeSolenoid;

public:
  static std::shared_ptr<Intake> getInstance();

  Intake();

	void InitDefaultCommand();
	void SetIntake(double speed);
	void IntakeEngage();
	void IntakeDisengage();
	bool IsIntakeOn();

};

#endif
