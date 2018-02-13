#include "ArmMove.h"
#include "Subsystems/Arm.h"
#include "OI.h"

ArmMove::ArmMove() {
  Requires(Arm::getInstance().get());

}

// Called just before this Command runs the first time
void ArmMove::Initialize() {
  //Arm::getInstance()->DisengageBrake();
}

// Called repeatedly when this Command is scheduled to run
void ArmMove::Execute() {
  std::shared_ptr<Arm> arm = Arm::getInstance();

  std::shared_ptr<OI> oi = OI::getInstance();

  double left = oi->getCoDriverLeftYAxis();
  arm->SetArmMove(-left);
}

// Make this return true when this Command no longer needs to run execute()
bool ArmMove::IsFinished() {
	return false;
}

//
void ArmMove::End() {

}

void ArmMove::Interrupted() {

}
