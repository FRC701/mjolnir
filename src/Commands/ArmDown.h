#ifndef ArmDown_H
#define ArmDown_H

#include "Commands/Command.h"
#include "Subsystems/Arm.h"

class ArmDown : public frc::Command {
public:
	ArmDown(double speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double mSpeed;
};

#endif  // ArmDown_H
