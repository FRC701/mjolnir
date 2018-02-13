#include "Ramp.h"
#include "DoubleSolenoid.h"
#include "Commands/SetRamp.h"
#include "RobotMap.h"

const char Ramp::kSubsystemName[] = "Ramp";

std::shared_ptr<Ramp> Ramp::self;

std::shared_ptr<Ramp> Ramp::getInstance() {
  if (! self) {
     self = std::shared_ptr<Ramp>(new Ramp);
  }
  return self;
}


Ramp::Ramp() : Subsystem(kSubsystemName),
    actuator(RobotMap::kIDRampForward, RobotMap::kIDRampReverse)
{
  actuator.Set(DoubleSolenoid::kForward);
}

void Ramp::InitDefaultCommand(){
   SetDefaultCommand(new ::SetRamp(kRelease));
}

void Ramp::SetUpRamp(RampValue value) {
  actuator.Set(static_cast<DoubleSolenoid::Value>(value));
}
