#ifndef ResetArmPosition_H
#define ResetArmPosition_H

#include "Commands/Command.h"

class ResetArmPosition : public frc::Command {
public:
	ResetArmPosition();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ResetArmPosition_H
