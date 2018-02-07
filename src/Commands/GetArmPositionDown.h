#ifndef GetArmPositionDown_H
#define GetArmPositionDown_H

#include "Commands/InstantCommand.h"
#include "Subsystems/Arm.h"
#include "Preferences.h"

class GetArmPositionDown : public frc::InstantCommand {
public:
	GetArmPositionDown();
	void Initialize();
};

#endif  // GetArmPositionDown_H
