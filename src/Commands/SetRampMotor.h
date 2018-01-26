#ifndef SetRampMotor_H
#define SetRampMotor_H

#include "Commands/InstantCommand.h"
#include "../Subsystems/Ramp.h"

class SetRampMotor : public frc::InstantCommand {
public:
	SetRampMotor(double speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	  double mSpeed;

};

#endif  // SetRampMotor_H
