#ifndef ArmUp_H
#define ArmUp_H

#include "Commands/Command.h"
#include "Subsystems/Arm.h"

class ArmUp : public frc::Command {
public:
	ArmUp(double speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double mSpeed;
};

#endif  // ArmUp_H
