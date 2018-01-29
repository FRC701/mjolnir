#ifndef Arm_H
#define Arm_H

#include <Commands/Subsystem.h>
#include <DoubleSolenoid.h>
#include <ctre/phoenix.h>

class Arm : public frc::Subsystem {

private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities


  static const char kSubsystemName[];
  static std::shared_ptr<Arm> self;

  WPI_TalonSRX leftArmMotor;
  WPI_TalonSRX rightArmMotor;
  frc::DoubleSolenoid brake;
  void SetUpTalons();



public:
  static std::shared_ptr<Arm> getInstance();


  Arm();


	void InitDefaultCommand();
	int GetVelocity();
	void SetArmMove(double speed);
	bool IsForwardLimitSwitchClosed();
	bool IsReverseLimitSwitchClosed();


};

#endif  // Arm_H
