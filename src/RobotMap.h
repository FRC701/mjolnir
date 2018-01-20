#ifndef ROBOTMAP_H
#define ROBOTMAP_H

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "WPILib.h"
#include "ctre/Phoenix.h"

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around
 */
class RobotMap {
public:

//..........Motors..........

  //..........Chassis..........
	  static const int kIDRight1Wheel = 1;
	  static const int kIDRight2Wheel = 2;
	  static const int kIDLeft1Wheel = 3;
	  static const int kIDLeft2Wheel = 4;
	//..........Intake..........
	  static const int kIDLeftIntake = 5;
	  static const int kIDRightIntake = 6;
	//..........Arm..........
	  static const int kIDLeftArm = 50;
	  static const int kIDRightArm = 51;
	//.........Sling.........
	  static const int kIDPullSling1 = 7;
	  static const int kIDPullSling2 = 8;

//..........Solenoids..........

	//..........Arm..........
	  static const int kIDBrakeForward = 0;
	  static const int kIDBrakeReverse = 7;

	static void init();
};

// TODO Refactor to a constants.h?

// See TalanSRX::ConfigSelectedFeedbackSensor() pidIdx
static const int kPID_PrimaryClosedLoop = 0;
static const int kPID_CascadedClosedLoop = 1;

// See TalanSRX::ConfigSelectedFeedbackSensor() timoutMs
static const int kTimeout_DontBlock = 0;
static const int kTimeout_10Millis = 10;

#endif
