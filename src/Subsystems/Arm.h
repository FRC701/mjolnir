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
  void SetUpTalons();
  int calibrateEncoderDown;
  int calibratePotDown;



public:
  static std::shared_ptr<Arm> getInstance();


  Arm();


	void InitDefaultCommand();
	int GetPosition();
	int GetVelocity();
	void SetArmMove(double speed);
	bool IsForwardLimitSwitchClosed();
	bool IsReverseLimitSwitchClosed();
	double GetArmPotVoltage();
	int GetArmPotValue();
	void SetArmPositionDown(int potentiometer, int encoder);
	void SetArmPositionUp(int potentiometer, int encoder);
	int CalculateEncoderPos();


};

#endif  // Arm_H
