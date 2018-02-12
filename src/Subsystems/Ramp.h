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

  frc::DoubleSolenoid actuator;

public:
  enum RampValue{kRelease = frc::DoubleSolenoid::kForward,
                 kDontRelease = frc::DoubleSolenoid::kReverse};

  static std::shared_ptr<Ramp> getInstance();

  void InitDefaultCommand();
  void SetRamp(RampValue value);

};

#endif /* SRC_SUBSYSTEMS_RAMP_H_ */
