#ifndef Ramp_H
#define Ramp_H
#include "Commands/Subsystem.h"
#include "RobotMap.h"
#include "DoubleSolenoid.h"
#include "ctre/Phoenix.h"

class Ramp : public frc::Subsystem {
private:

  static const char kSubsystemName[];
  static std::shared_ptr<Ramp> self;
  Ramp();
  //Command goes here

 WPI_TalonSRX rampMotor;

 frc::DoubleSolenoid actuator;

 void SetUpTalons();

public:
  enum RampValue{kArmIn = frc::DoubleSolenoid::kForward, kArmOut = frc::DoubleSolenoid::kReverse};

  static std::shared_ptr<Ramp> getInstance();


  void SetRamp(RampValue value);

  void SetRampMotor(double speed);


};






#endif /* SRC_SUBSYSTEMS_RAMP_H_ */
