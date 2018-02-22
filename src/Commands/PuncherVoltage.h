#pragma once

#include <Commands/Command.h>

class PuncherVoltage : public frc::Command {
public:
	PuncherVoltage();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};

