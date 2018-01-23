#ifndef SetRamp_H
#define SetRamp_H

#include "Commands/InstantCommand.h"
#include "../Subsystems/Ramp.h"

class SetRamp : public frc::InstantCommand {
public:
      SetRamp(Ramp::RampValue value);
      void Initialize();
private:
        Ramp::RampValue mValue;
};

#endif
