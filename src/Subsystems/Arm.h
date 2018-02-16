#ifndef Arm_H
#define Arm_H

#include <Commands/Subsystem.h>
#include <DoubleSolenoid.h>
#include <ctre/phoenix.h>
#include <AnalogInput.h>
#include <Preferences.h>

class Arm : public frc::Subsystem {

private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities


  static const char kSubsystemName[];
  static std::shared_ptr<Arm> self;

  WPI_TalonSRX leftArmMotor;
  WPI_TalonSRX rightArmMotor;
  frc::DoubleSolenoid brake;
  frc::AnalogInput armPot;
  int calibrateEncoderDown;
  int calibratePotDown;

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
  int GetArmPotValue();
  int GetArmPotVoltage();
  void ResetArmPos();
	bool IsForwardLimitSwitchClosed();
	bool IsReverseLimitSwitchClosed();

	void SetArmPositionDown(int potentiometer, int encoder);
	void SetArmPositionUp(int potentiometer, int encoder);
	int CalculateEncoderPos();

};

#endif  // Arm_H
