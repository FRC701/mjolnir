#include "GetArmPositionDown.h"

GetArmPositionDown::GetArmPositionDown() {
  Requires(Arm::getInstance().get());
}

// Called once when the command executes
void GetArmPositionDown::Initialize() {
  int armPotDown = Arm::getInstance()->GetArmPotValue();
  int armEncoderDown = Arm::getInstance()->GetPosition();
  Arm::getInstance()->SetArmPositionDown(armPotDown, armEncoderDown);
}
