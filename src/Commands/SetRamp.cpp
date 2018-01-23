#include <Commands/SetRamp.h>
#include "../Subsystems/Ramp.h"

SetRamp::SetRamp(Ramp::RampValue value) :
  mValue(value) {

  Requires(Ramp::getInstance().get());
}


void SetRamp::Initialize() {
  Ramp::getInstance()->SetRamp();
}
