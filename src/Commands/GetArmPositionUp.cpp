#include <Commands/GetArmPositionUp.h>
#include <Preferences.h>

GetArmPositionUp::GetArmPositionUp() {
	Requires(Arm::getInstance().get());
}

// Called once when the command executes
void GetArmPositionUp::Initialize() {
  int armPotUp = Arm::getInstance()->GetArmPotValue();
  int armEncoderUp = Arm::getInstance()->GetPosition();
  Arm::getInstance()->SetArmPositionUp(armPotUp, armEncoderUp);
}
