#ifndef Ramp_H
#define Ramp_H
#include "Commands/Subsystem.h"
#include "RobotMap.h"
#include "DoubleSolenoid.h"


class Ramp : public Subsystem {
private:

  static const char kSubsystemName[];
  static std::shared_ptr<Ramp> self;

  Ramp();
  //Command goes here

  DoubleSolenoid actuator;
  double p;
  double i;
  double d;

public:
  enum RampValue{kArmIn = DoubleSolenoid::kForward, kArmOut = DoubleSolenoid::kReverse};

  static std::shared_ptr<Ramp> getInstance();


  void SetRamp();


};






#endif /* SRC_SUBSYSTEMS_RAMP_H_ */
