#ifndef SetArmPosition_H
#define SetArmPosition_H

#include "Commands/Command.h"

class SetArmPosition : public frc::Command{
private:
  int mPosition;
public:
	SetArmPosition(int position);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // SetArmPosition_H
