#include "ArmMove.h"
#include "Subsystems/Arm.h"
#include "OI.h"


ArmMove::ArmMove() {
  Requires(Arm::getInstance().get());

}

// Called just before this Command runs the first time
void ArmMove::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void ArmMove::Execute() {
    double right = OI::getInstance()->getCoDriverRightYAxis();
    Arm::getInstance()->SetArmMove(-right);
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
