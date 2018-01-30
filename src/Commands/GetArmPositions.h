#ifndef GetArmPositions_H
#define GetArmPositions_H

#include "Commands/InstantCommand.h"
#include "Subsystems/Arm.h"

class GetArmPositions : public frc::InstantCommand {
public:
	GetArmPositions();
	void Initialize();
};

#endif  // GetArmPositions_H
