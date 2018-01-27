#ifndef ArmMove_H
#define ArmMove_H

#include "Commands/Command.h"

class ArmMove : public frc::Command {
public:
	ArmMove();

	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:

};

#endif  // ArmMove_H
