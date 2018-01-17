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

 frc::DoubleSolenoid actuator;

public:
  enum RampValue{kArmIn = frc::DoubleSolenoid::kForward, kArmOut = frc::DoubleSolenoid::kReverse};

  static std::shared_ptr<Ramp> getInstance();

  void SetRamp(RampValue value);

};

#endif /* SRC_SUBSYSTEMS_RAMP_H_ */
