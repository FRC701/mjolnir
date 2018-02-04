#include "Robot.h"

// This is the one file that needs WPILib.h in order to properly expand START_ROBOT_CLASS
#include "WPILib.h"

#include "OI.h"
#include <iostream>
#include "Subsystems/Arm.h"
#include "Subsystems/Chassis.h"
#include "Subsystems/Intake.h"
#include "Subsystems/Ramp.h"
#include "Commands/TankDrive.h"
#include "SmartDashboard/SmartDashboard.h"
#include "GameData.h"

using robovikes::GameData;

std::unique_ptr<OI> Robot::oi;

Robot::Robot():
    autonomousCommand(nullptr) {

}

std::string SideToString(robovikes::GameData::Side side){
  std::string sideString = "Left";
  switch(side) {
    case GameData::Left:
      sideString = "Left";
      break;
    case GameData::Right:
      sideString = "Right";
      break;
    default:
      sideString = "Unknown";
      break;
      }
  return sideString;
}

void Robot::RobotInit() {
	RobotMap::init();
		Arm::getInstance();
    Chassis::getInstance();
		Intake::getInstance();
		Ramp::getInstance();

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	// This MUST be here. If the OI creates Commands (which it very likely
	// will), constructing it during the construction of CommandBase (from
	// which commands extend), subsystems are not guaranteed to be
	// yet. Thus, their requires() statements may grab null pointers. Bad
	// news. Don't move it.

	// instantiate the command used for the autonomous period
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS
	autonomousCommand.reset(new AutonomousCommand());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS
  }

/**
 * This function is called when the disabled button is hit.
 * You can use it to reset subsystems before shutting down.
 */
void Robot::DisabledInit(){

}

void Robot::DisabledPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit() {
	if (autonomousCommand.get() != nullptr)
		autonomousCommand->Start();
}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
	SmartDashboard::PutString("Our Switch", SideToString(robovikes::GameData::GetOurSwitchSide()));
	SmartDashboard::PutString("Scale", SideToString(robovikes::GameData::GetScaleSide()));
	SmartDashboard::PutString("Their Switch", SideToString(robovikes::GameData::GetTheirSwitchSide()));

}

void Robot::TeleopInit() {
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to
	// continue until interrupted by another command, remove
	// these lines or comment it out.
	if (autonomousCommand.get() != nullptr) autonomousCommand->Cancel();


}


void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();

  SmartDashboard::PutNumber("Left Velocity (u/100ms)", Chassis::getInstance()->getLeftVelocity());
  SmartDashboard::PutNumber("Right Velocity (u/100ms)", Chassis::getInstance()->getRightVelocity());

  SmartDashboard::PutNumber("Arm Velocity (u/100ms)", Arm::getInstance()->GetVelocity());
  SmartDashboard::PutNumber("Arm Position", Arm::getInstance()->GetPosition());
  SmartDashboard::PutNumber("Pot Value", Arm::getInstance()->GetArmPotValue());
  SmartDashboard::PutNumber("Arm Voltage", Arm::getInstance()->GetArmPotVoltage());
  SmartDashboard::PutNumber("Encoder Position", Arm::getInstance()->CalculateEncoderPos());
  SmartDashboard::PutNumber("Motion Magic Error", Arm::getInstance()->GetPositionError());

  SmartDashboard::PutString("Our Switch", SideToString(robovikes::GameData::GetOurSwitchSide()));
  SmartDashboard::PutString("Scale", SideToString(robovikes::GameData::GetScaleSide()));
  SmartDashboard::PutString("Their Switch", SideToString(robovikes::GameData::GetTheirSwitchSide()));
}

void Robot::TestPeriodic() {
	// lw->Run();
}

START_ROBOT_CLASS(Robot);

