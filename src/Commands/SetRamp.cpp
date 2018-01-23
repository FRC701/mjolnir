#include <Commands/SetRamp.h>

SetRamp::SetRamp(Ramp::RampValue value) :
  mValue(value) {

  Requires(Ramp::getInstance().get());
}

void SetRamp::Initialize() {
  Ramp::getInstance()->SetRamp(mValue);
}
