#include "Puncher.h"
#include "Commands/SlingShot.h"
#include "RobotMap.h"
#include "DoubleSolenoid.h"
#include "Commands/SetSlingDisengagement.h"


static const int kSlotIndex = 0;


static frc::DoubleSolenoid::Value kMotorEngage = frc::DoubleSolenoid::kForward;
static frc::DoubleSolenoid::Value kMotorDisengage = frc::DoubleSolenoid::kReverse;


const char Puncher::kSubsystemName[] = "Puncher";

std::shared_ptr<Puncher> Puncher::self;

std::shared_ptr<Puncher> Puncher::getInstance() {
  if (! self) {
    self = std::shared_ptr<Puncher>(new Puncher);
  }
  return self;
}
static double calcFeedforward() {
  static const double kMaxUnitsPer100ms = 1000.0;
  // static const double kUnitsPerRev = 4096.0;
  // double rpm = (kMaxUnitsPer100ms * 600.0) / kUnitsPerRev;
  double feedforward = 1023.0 / kMaxUnitsPer100ms;
  return feedforward;
}
static double calcP(){
  static const double kUnitsPerRev = 4096.0/ 2.0;
  double pGain = 1.0* 1023.0/kUnitsPerRev;
  return pGain;
}

Puncher::Puncher() : Subsystem(kSubsystemName),
    pullSling(RobotMap::kIDPullSling),
    releaseSling(RobotMap::kIDSlingForward, RobotMap::kIDSlingReverse)
{
  MotorEngage();
  SetUpTalon();
}

void Puncher::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
  SetDefaultCommand(new SlingShot(0.0));
}

void Puncher::SetSlingShot(double mSpeed)
{
  pullSling.Set(ControlMode::PercentOutput, mSpeed);

}

void Puncher::SetPosition(double position){
  pullSling.Set(ControlMode::MotionMagic, position);
}

void Puncher::SetUpTalon(){
  pullSling.ConfigForwardLimitSwitchSource(LimitSwitchSource_FeedbackConnector, LimitSwitchNormal_NormallyOpen, kTimeout_10Millis);
  pullSling.ConfigReverseLimitSwitchSource(LimitSwitchSource_FeedbackConnector, LimitSwitchNormal_NormallyClosed, kTimeout_10Millis);
  pullSling.SetInverted(true);
  pullSling.SetSensorPhase(true);

}

double Puncher::GetPuncherLimit() {
  return pullSling.GetSensorCollection().IsFwdLimitSwitchClosed();
}

void Puncher::MotorDisengage() {
  releaseSling.Set(kMotorEngage);
}

void Puncher::MotorEngage() {
  releaseSling.Set(kMotorDisengage);
}

int Puncher::GetVelocity()
{
 return pullSling.GetSelectedSensorVelocity(kPID_PrimaryClosedLoop);
}

int Puncher::GetPosition(){
  return pullSling.GetSelectedSensorPosition(kPID_PrimaryClosedLoop);
}

void Puncher::SetUpMotionMagic() {
  pullSling.SetStatusFramePeriod(StatusFrameEnhanced::Status_13_Base_PIDF0, 10, kTimeout_10Millis);
  pullSling.SetStatusFramePeriod(StatusFrameEnhanced::Status_10_MotionMagic, 10, kTimeout_10Millis);

  pullSling.ConfigNominalOutputForward(0, kTimeout_10Millis);
  pullSling.ConfigNominalOutputReverse(0, kTimeout_10Millis);
  pullSling.ConfigPeakOutputForward(1, kTimeout_10Millis);
  pullSling.ConfigPeakOutputReverse(-1, kTimeout_10Millis);

  pullSling.SetNeutralMode(NeutralMode::Brake);

  static const double kF = calcFeedforward();
  static const double kP = calcP();
  static const double kI = 0;
  static const double kD = 0;
  static const double kMaxVelocity = 1000.0 * 2;
  static const int kCruiseVelocity = kMaxVelocity; //Sensor Units per 100ms
  static const int kMotionAcceleration = kCruiseVelocity * 40; //Sensor Units per 100ms/sec

  pullSling.SelectProfileSlot(kSlotIndex, kPID_PrimaryClosedLoop);
  pullSling.Config_kF(kSlotIndex, kF, kTimeout_10Millis);
  pullSling.Config_kP(kSlotIndex, kP, kTimeout_10Millis);
  pullSling.Config_kI(kSlotIndex, kI, kTimeout_10Millis);
  pullSling.Config_kD(kSlotIndex, kD, kTimeout_10Millis);
  pullSling.ConfigMotionCruiseVelocity(kCruiseVelocity, kTimeout_10Millis);
  pullSling.ConfigMotionAcceleration(kMotionAcceleration, kTimeout_10Millis);
}

int Puncher::GetPositionError(){
  return pullSling.GetClosedLoopError(kSlotIndex);
}

void Puncher::ResetPuncherPos(){
  pullSling.SetSelectedSensorPosition(0, kPID_PrimaryClosedLoop, kTimeout_10Millis);
}

double Puncher::GetCurrent(){
  return pullSling.GetOutputCurrent();
}

double Puncher::IsCubeIn() {
  return pullSling.GetSensorCollection().IsRevLimitSwitchClosed();
}
// Put methods for controlling this subsystem
// here. Call these from Commands.

