#include "Chassis.h"
#include "Commands/TankDrive.h"
#include "RobotMap.h"

const char Chassis::kSubsystemName[] = "Chassis";
std::shared_ptr<Chassis> Chassis::self;

std::shared_ptr<Chassis> Chassis::getInstance() {
  if (! self) {
    self = std::shared_ptr<Chassis>(new Chassis);
  }
  return self;
}


Chassis::Chassis() : Subsystem(kSubsystemName),
    left1Wheel(RobotMap::kIDLeft1Wheel),
    left2Wheel(RobotMap::kIDLeft2Wheel),
    right1Wheel(RobotMap::kIDLeft2Wheel),
    right2Wheel(RobotMap::kIDLeft2Wheel)
{
  SetUpTalons();
}

void Chassis::InitDefaultCommand() {
	SetDefaultCommand(new TankDrive);
}

void Chassis::SetTankDrive(double left, double right) {
  left1Wheel.Set(left);
  right1Wheel.Set(right);
}

void Chassis::SetUpTalons(){
  left1Wheel.SetInverted(true);
  // left1Wheel.SetControlMode() is now part of Set().
  // If we need control modes, we need to track the control mode as a member variable
  left1Wheel.ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder,
                                          kPID_PrimaryClosedLoop,
                                          kTimeout_DontBlock);
  // left1Wheel.ConfigEncoderCodesPerRev(); MIA?
  left1Wheel.ConfigForwardSoftLimitEnable(false, kTimeout_DontBlock);
  left1Wheel.ConfigReverseSoftLimitEnable(false, kTimeout_DontBlock);
  // left1Wheel.SetSensorDirection() MIA?
  right1Wheel.SetInverted(false);

  left2Wheel.Follow(left1Wheel);
  right2Wheel.Follow(right1Wheel);


}
