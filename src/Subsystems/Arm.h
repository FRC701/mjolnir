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
  DoubleSolenoid brake;

  void SetUpTalons();
  void SetUpMotionMagic();


public:
  static std::shared_ptr<Arm> getInstance();

  Arm();
	void InitDefaultCommand();
  int GetVelocity();
  int GetPosition();
  void SetArmMove(double speed);
  void SetArmPos(int position);
  void EngageBrake();
  void DisengageBrake();
  int GetPositionError();

};

#endif  // Arm_H
