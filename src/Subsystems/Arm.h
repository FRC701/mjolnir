#ifndef Arm_H
#define Arm_H

#include <Commands/Subsystem.h>
#include <DoubleSolenoid.h>
#include <ctre/phoenix.h>
#include <AnalogInput.h>

class Arm : public frc::Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities


  static const char kSubsystemName[];
  static std::shared_ptr<Arm> self;

  WPI_TalonSRX leftArmMotor;
  WPI_TalonSRX rightArmMotor;
  frc::DoubleSolenoid brake;

  frc::AnalogInput pot;

public:
  static std::shared_ptr<Arm> getInstance();


  Arm();

  int GetArmPotValue() const;

  double GetArmPotVoltage() const;

	void InitDefaultCommand();
};

#endif  // Arm_H
