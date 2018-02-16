#ifndef GetArmPositions_H
#define GetArmPositions_H

#include "Commands/InstantCommand.h"
#include "Subsystems/Arm.h"
#include "Preferences.h"

class GetArmPositionUp : public frc::InstantCommand {
public:
	GetArmPositionUp();
	void Initialize();
};

#endif  // GetArmPositions_H
