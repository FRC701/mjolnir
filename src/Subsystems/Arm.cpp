#include "Arm.h"
#include "Commands/ArmMove.h"
#include "RobotMap.h"


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
  brake(RobotMap::kIDBrakeForward, RobotMap::kIDBrakeReverse)
{

  SetUpTalons();

}

void Arm::InitDefaultCommand() {
 SetDefaultCommand(new ArmMove);
}

void Arm::SetArmMove(double speed) {
 leftArmMotor.Set(speed);
}

void Arm::SetUpTalons() {
  leftArmMotor.ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative,
                                         kPID_PrimaryClosedLoop,
                                         kTimeout_10Millis);
 leftArmMotor.ConfigForwardSoftLimitEnable(false, kTimeout_10Millis);
 leftArmMotor.ConfigReverseSoftLimitEnable(false, kTimeout_10Millis);
 leftArmMotor.SetSensorPhase(true);
 leftArmMotor.SetInverted(true);
 rightArmMotor.SetInverted(true);


 rightArmMotor.Follow(leftArmMotor);

}

int Arm::GetVelocity()
{
 return leftArmMotor.GetSelectedSensorVelocity(kPID_PrimaryClosedLoop);
}

bool Arm::IsForwardLimitSwitchClosed()
{
  return leftArmMotor.GetSensorCollection().IsFwdLimitSwitchClosed();
}

bool Arm::IsReverseLimitSwitchClosed()
{
  return leftArmMotor.GetSensorCollection().IsRevLimitSwitchClosed();
}


// Put methods for controlling this subsystem
// here. Call these from Commands.
