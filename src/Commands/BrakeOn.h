#ifndef BrakeOn_H
#define BrakeOn_H

#include "Commands/Command.h"

class BrakeOn : public frc::Command {
public:
  BrakeOn();
  void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // BrakeOn_H
