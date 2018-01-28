#include "Puncher.h"
#include "Commands/SlingShot.h"
#include "RobotMap.h"
#include "DoubleSolenoid.h"


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

Puncher::Puncher() : Subsystem(kSubsystemName),
    pullSling1(RobotMap::kIDPullSling1),
    pullSling2(RobotMap::kIDPullSling2),
    releaseSling(RobotMap::kIDReleaseSling, RobotMap::kIDGetSling)
{
  MotorEngage();

}

void Puncher::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
  SetDefaultCommand(new SlingShot(0.0));
}
void Puncher::SetSlingShot(double mSpeed)
{
  pullSling1.Set(mSpeed);
  pullSling2.Set(mSpeed);

}

double Puncher::GetPuncherLimit() {
  return pullSling1.GetSensorCollection().IsFwdLimitSwitchClosed();
}

void Puncher::MotorDisengage() {
  releaseSling.Set(kMotorEngage);
}

void Puncher::MotorEngage() {
  releaseSling.Set(kMotorDisengage);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

