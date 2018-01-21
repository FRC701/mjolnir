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
    right2Wheel(RobotMap::kIDRight2Wheel),
    p(0.0), i(0.0), d(0.0), f(4.0)
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
  left1Wheel.Config_kP(kSlot0, p, kTimeout_10Millis);
  left1Wheel.Config_kI(kSlot0, i, kTimeout_10Millis);
  left1Wheel.Config_kD(kSlot0, d, kTimeout_10Millis);
  left1Wheel.Config_kF(kSlot0, f, kTimeout_10Millis);

  left1Wheel.SetSensorPhase(true);
  left1Wheel.SetInverted(true);
  left2Wheel.SetInverted(true);


  right1Wheel.ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative,
                                          kPID_PrimaryClosedLoop,
                                          kTimeout_10Millis);
  right1Wheel.ConfigForwardSoftLimitEnable(false, kTimeout_10Millis);
  right1Wheel.ConfigReverseSoftLimitEnable(false, kTimeout_10Millis);
  right1Wheel.Config_kP(kSlot0, p, kTimeout_10Millis);
  right1Wheel.Config_kI(kSlot0, i, kTimeout_10Millis);
  right1Wheel.Config_kD(kSlot0, d, kTimeout_10Millis);
  right1Wheel.Config_kF(kSlot0, f, kTimeout_10Millis);

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

// Motion Profile Support

void Chassis::SetModePercentOutput()
{
  left1Wheel.Set(ControlMode::PercentOutput, 0.0);
  right1Wheel.Set(ControlMode::PercentOutput, 0.0);
}

void Chassis::SetModeMotionProfile()
{
  left1Wheel.Set(ControlMode::MotionProfile, 0.0);
  right1Wheel.Set(ControlMode::MotionProfile, 0.0);
}

void Chassis::ClearMotionProfileTrajectories()
{
  left1Wheel.ClearMotionProfileTrajectories();
  right1Wheel.ClearMotionProfileTrajectories();
}

void Chassis::SetMotionProfileSetValue(SetValueMotionProfile setValue)
{
  left1Wheel.Set(ControlMode::MotionProfile, setValue);
  right1Wheel.Set(ControlMode::MotionProfile, setValue);
}

void Chassis::PushMotionProfileTrajectory(const TrajectoryPoint& leftTrajectoryPoint,
                                          const TrajectoryPoint& rightTrajectoryPoint)
{
  left1Wheel.PushMotionProfileTrajectory(leftTrajectoryPoint);
  right1Wheel.PushMotionProfileTrajectory(rightTrajectoryPoint);
}

void Chassis::ProcessMotionProfileBuffer()
{
  left1Wheel.ProcessMotionProfileBuffer();
  right1Wheel.ProcessMotionProfileBuffer();
}

void Chassis::GetMotionProfileStatus(MotionProfileStatus* leftStatus,
                                     MotionProfileStatus* rightStatus)
{
  left1Wheel.GetMotionProfileStatus(*leftStatus);
  right1Wheel.GetMotionProfileStatus(*rightStatus);
}
