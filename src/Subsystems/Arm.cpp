#include "Arm.h"
#include "../RobotMap.h"

const char Arm::kSubsystemName[] = "Arm";

std::shared_ptr<Arm> Arm::self;

std::shared_ptr<Arm> Arm::getInstance() {
        if (! self) {
          self = std::shared_ptr<Arm>(new Arm);
        }
        return self;
}

Arm::Arm() : Subsystem(kSubsystemName),
  leftArmMotor(RobotMap::kIDLeftArm),
  rightArmMotor(RobotMap::kIDRightArm),
  brake(RobotMap::kIDBrakeForward, RobotMap::kIDBrakeReverse),
  pot(RobotMap::kIDArmPot)
{


}

void Arm::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());

}

int Arm::GetArmPotValue() const {
  return pot.GetValue();
}

double Arm::GetArmPotVoltage() const {
  return pot.GetVoltage();
}
