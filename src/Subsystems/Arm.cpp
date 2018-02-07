#include "Arm.h"
#include "Commands/ArmMove.h"
#include "RobotMap.h"


const char Arm::kSubsystemName[] = "Arm";
const std::string kKey = "ArmScale";

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
  armPot(RobotMap::kIDArmPot),
  calibrateEncoderDown(0),
  calibratePotDown(0)
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

 leftArmMotor.SetSelectedSensorPosition(CalculateEncoderPos(), kPID_PrimaryClosedLoop, kTimeout_10Millis);

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

int Arm::GetArmPotValue()
{
  return armPot.GetValue();
}

double Arm::GetArmPotVoltage()
{
  return armPot.GetVoltage();
}

int Arm::GetPosition()
{
  return leftArmMotor.GetSelectedSensorPosition(kPID_PrimaryClosedLoop);
}

void Arm::SetArmPositionDown(int potentiometer, int encoder)
{
  calibrateEncoderDown = encoder;
  calibratePotDown = potentiometer;
}

void Arm::SetArmPositionUp(int potentiometer, int encoder)
{
  double scaleFactor = (encoder - calibrateEncoderDown) / (potentiometer - calibratePotDown);
  Preferences::GetInstance()->PutDouble(kKey, scaleFactor);
}

int Arm::CalculateEncoderPos()
{
  return Preferences::GetInstance()->GetDouble(kKey,0) * GetPosition();
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
