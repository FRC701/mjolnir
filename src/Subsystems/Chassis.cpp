#include "Chassis.h"
#include "Commands/TankDrive.h"
#include "RobotMap.h"

namespace {

#if 0
static const double kGearRatioNumerator = 26.0;
static const double kGearRatioDenominator = 36.0;
// todo Use this for a ft/sec display on the dashboard
static const double kWheelGearRatio = kGearRatioNumerator  / kGearRatioDenominator;
#endif

double calcFeedforward() {
/*
  static const double kMaxUnitsPer100ms = 5500.0;
  // static const double kUnitsPerRev = 4096.0;
  // double rpm = (kMaxUnitsPer100ms * 600.0) / kUnitsPerRev;
  double feedforward = 1023.0 / kMaxUnitsPer100ms;
  return feedforward;
*/

  return 0.25;  // Determined experimentally
}

}


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
    p(0.0625), i(0.0), d(p*10), f(calcFeedforward())
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
  // left1Wheel.SetControlMode() is now part of Set().
  // If we need control modes, we need to track the control mode as a member variable
  left1Wheel.ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative,
                                          kPID_PrimaryClosedLoop,
                                          kTimeout_10Millis);
  left1Wheel.ConfigForwardSoftLimitEnable(false, kTimeout_10Millis);
  left1Wheel.ConfigReverseSoftLimitEnable(false, kTimeout_10Millis);
  left1Wheel.Config_kP(kSlot0, p, kTimeout_10Millis);
  left1Wheel.Config_kI(kSlot0, i, kTimeout_10Millis);
  left1Wheel.Config_kD(kSlot0, d, kTimeout_10Millis);
  left1Wheel.Config_kF(kSlot0, f, kTimeout_10Millis);
  /* status 10 provides the trajectory target for motion profile AND motion magic */
  left1Wheel.SetStatusFramePeriod(StatusFrameEnhanced::Status_10_MotionMagic, 10, kTimeout_10Millis);
  left1Wheel.SetSensorPhase(true);
  left1Wheel.SetInverted(true);
  left2Wheel.SetInverted(true);

  left1Wheel.ConfigMotionProfileTrajectoryPeriod(TrajectoryDuration_0ms, kTimeout_10Millis);
  /* status 10 provides the trajectory target for motion profile AND motion magic */
  left1Wheel.SetStatusFramePeriod(StatusFrameEnhanced::Status_10_MotionMagic, 10, kTimeout_10Millis);
  left1Wheel.SetSensorPhase(true);
  left1Wheel.SetInverted(true);
  left2Wheel.SetInverted(true);

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
  /* status 10 provides the trajectory target for motion profile AND motion magic */
  right1Wheel.SetStatusFramePeriod(StatusFrameEnhanced::Status_10_MotionMagic, 10, kTimeout_10Millis);
  right1Wheel.SetSensorPhase(true);
  right1Wheel.SetInverted(false);
  right2Wheel.SetInverted(false);

  right1Wheel.ConfigMotionProfileTrajectoryPeriod(TrajectoryDuration_0ms, kTimeout_10Millis);
  /* status 10 provides the trajectory target for motion profile AND motion magic */
  right1Wheel.SetStatusFramePeriod(StatusFrameEnhanced::Status_10_MotionMagic, 10, kTimeout_10Millis);
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
int Chassis::GetLeftPosition(){
  return left1Wheel.GetSelectedSensorPosition(kSlot0);
}

int Chassis::GetRightPosition(){
  return right1Wheel.GetSelectedSensorPosition(kSlot0);
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

void Chassis::ConfigMotionProfileTrajectoryPeriod(int trajectoryDurationMillis) {
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

void Chassis::SetMotionMagic(int position)
{
  left1Wheel.Set(ControlMode::MotionMagic, position);
}

int Chassis::GetLeftPosError()
{
  return left1Wheel.GetClosedLoopError(kSlot1);
}
static double calcP(){
 static const double kEigthUnitsPerRev = 4096.0/ 1.0;
 double pGain = 1* 1023.0/kEigthUnitsPerRev;
 return pGain;
}

void Chassis::SetUpMotionMagic() {
 left1Wheel.SetStatusFramePeriod(StatusFrameEnhanced::Status_13_Base_PIDF0, 10, kTimeout_10Millis);
 left1Wheel.SetStatusFramePeriod(StatusFrameEnhanced::Status_10_MotionMagic, 10, kTimeout_10Millis);
 left1Wheel.ConfigNominalOutputForward(0, kTimeout_10Millis);
 left1Wheel.ConfigNominalOutputReverse(0, kTimeout_10Millis);
 left1Wheel.ConfigPeakOutputForward(1, kTimeout_10Millis);
 left1Wheel.ConfigPeakOutputReverse(-1, kTimeout_10Millis);

 static const double kF = calcFeedforward();
 static const double kP = calcP();
 static const double kI = 0;
 static const double kD = 0;
 static const double kMaxVelocity = 3675;
 static const int kCruiseVelocity = kMaxVelocity; //Sensor Units per 100ms
 static const int kMotionAcceleration = kCruiseVelocity * 2; //Sensor Units per 100ms/sec

 left1Wheel.SelectProfileSlot(kSlot1, kPID_PrimaryClosedLoop);
 left1Wheel.Config_kF(kSlot1, kF, kTimeout_10Millis);
 left1Wheel.Config_kP(kSlot1, kP, kTimeout_10Millis);
 left1Wheel.Config_kI(kSlot1, kI, kTimeout_10Millis);
 left1Wheel.Config_kD(kSlot1, kD, kTimeout_10Millis);
 left1Wheel.ConfigMotionCruiseVelocity(kCruiseVelocity, kTimeout_10Millis);
 left1Wheel.ConfigMotionAcceleration(kMotionAcceleration, kTimeout_10Millis);
 left1Wheel.SelectProfileSlot(kSlot0, kPID_PrimaryClosedLoop);
}
