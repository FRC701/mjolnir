#ifndef BrakeOff_H
#define BrakeOff_H

#include "Commands/Command.h"

class BrakeOff : public frc::Command {
public:
  BrakeOff();
  void Initialize();
  void Execute();
  bool IsFinished();
  void End();
  void Interrupted();
};

#endif
