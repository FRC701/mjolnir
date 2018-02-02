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
  SetUpMotionMagic();
}

void Arm::InitDefaultCommand() {
  SetDefaultCommand(new ArmMove);
}

void Arm::SetArmMove(double speed) {
  leftArmMotor.Set(ControlMode::PercentOutput, speed);
}
void Arm::SetArmPos(int position){
  leftArmMotor.Set(ControlMode::MotionMagic, position);
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

void Arm::SetUpMotionMagic() {
  leftArmMotor.SetStatusFramePeriod(StatusFrameEnhanced::Status_13_Base_PIDF0, 10, kTimeout_10Millis);
  leftArmMotor.SetStatusFramePeriod(StatusFrameEnhanced::Status_10_MotionMagic, 10, kTimeout_10Millis);

  leftArmMotor.ConfigNominalOutputForward(0, kTimeout_10Millis);
  leftArmMotor.ConfigNominalOutputReverse(0, kTimeout_10Millis);
  leftArmMotor.ConfigPeakOutputForward(1, kTimeout_10Millis);
  leftArmMotor.ConfigPeakOutputReverse(-1, kTimeout_10Millis);

  static const double kF = 0.2;
  static const double kP = 0;
  static const double kI = 0;
  static const double kD = 0;
  static const int kSlotIndex = 0;
  static const int kCruiseVelocity = 6000; //Sensor Units per 100ms
  static const int kMotionAcceleration = 6000; //Sensor Units per 100ms/sec

  leftArmMotor.SelectProfileSlot(kSlotIndex, kPID_PrimaryClosedLoop);
  leftArmMotor.Config_kF(kSlotIndex, kF, kTimeout_10Millis);
  leftArmMotor.Config_kP(kSlotIndex, kP, kTimeout_10Millis);
  leftArmMotor.Config_kI(kSlotIndex, kI, kTimeout_10Millis);
  leftArmMotor.Config_kD(kSlotIndex, kD, kTimeout_10Millis);

  leftArmMotor.ConfigMotionCruiseVelocity(kCruiseVelocity, kTimeout_10Millis);
  leftArmMotor.ConfigMotionAcceleration(kMotionAcceleration, kTimeout_10Millis);


}


// Put methods for controlling this subsystem
// here. Call these from Commands.
