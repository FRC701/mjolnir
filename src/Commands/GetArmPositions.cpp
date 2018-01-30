#include "GetArmPositions.h"

GetArmPositions::GetArmPositions() {
	Requires(Arm::getInstance().get());
}

// Called once when the command executes
void GetArmPositions::Initialize() {
  double Pos1 = Arm::getInstance()->GetArmPotValue();
  double ArmEncoder = Arm::getInstance()->GetPosition();

}
