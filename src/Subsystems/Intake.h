#ifndef INTAKE_H
#define INTAKE_H

#include "Commands/Subsystem.h"
#include "ctre/Phoenix.h"

class Intake: public frc::Subsystem {
private:
	static const char kSubsystemName[];
	static std::shared_ptr<Intake> self;
  WPI_TalonSRX leftIntake;
  WPI_TalonSRX rightIntake;

public:
  static std::shared_ptr<Intake> getInstance();

  Intake();

	void InitDefaultCommand();
	void SetIntake(double speed);

};

#endif
