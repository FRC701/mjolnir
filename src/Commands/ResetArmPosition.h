#ifndef ResetArmPosition_H
#define ResetArmPosition_H

#include "Commands/InstantCommand.h"

class ResetArmPosition : public frc::InstantCommand {
public:
	ResetArmPosition();
	void Initialize();
};

#endif  // ResetArmPosition_H
