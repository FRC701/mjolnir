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
    right1Wheel(RobotMap::kIDRight1Wheel),
    right2Wheel(RobotMap::kIDRight2Wheel)
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

void Chassis::SetUpTalons() {
  left1Wheel.ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative,
                                          kPID_PrimaryClosedLoop,
                                          kTimeout_10Millis);
  left1Wheel.ConfigForwardSoftLimitEnable(false, kTimeout_10Millis);
  left1Wheel.ConfigReverseSoftLimitEnable(false, kTimeout_10Millis);
  left1Wheel.SetSensorPhase(true);
  left1Wheel.SetInverted(true);
  left2Wheel.SetInverted(true);

  right1Wheel.ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative,
                                          kPID_PrimaryClosedLoop,
                                          kTimeout_10Millis);
  right1Wheel.ConfigForwardSoftLimitEnable(false, kTimeout_10Millis);
  right1Wheel.ConfigReverseSoftLimitEnable(false, kTimeout_10Millis);
  right1Wheel.SetSensorPhase(true);
  right1Wheel.SetInverted(false);
  right2Wheel.SetInverted(false);

  left2Wheel.Follow(left1Wheel);
  right2Wheel.Follow(right1Wheel);
}

int Chassis::getLeftVelocity()
{
  return left1Wheel.GetSelectedSensorVelocity(kPID_PrimaryClosedLoop);
}

int Chassis::getRightVelocity()
{
  return right1Wheel.GetSelectedSensorVelocity(kPID_PrimaryClosedLoop);
}
