#ifndef SetSlingDisengagement_H
#define SetSlingDisengagement_H

#include "Commands/InstantCommand.h"
#include "Subsystems/Puncher.h"

class SetSlingDisengagement : public frc::InstantCommand {
public:
	SetSlingDisengagement();
	void Initialize();
private:
};

#endif  // SetSlingDisengagement_H
