#ifndef CHASSIS_H
#define CHASSIS_H

#include "Commands/Subsystem.h"
#include "ctre/Phoenix.h"
#include "RobotMap.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class Chassis: public frc::Subsystem {
private:
  static const char kSubsystemName[];
  static std::shared_ptr<Chassis> self;

  WPI_TalonSRX left1Wheel;
  WPI_TalonSRX left2Wheel;
  WPI_TalonSRX right1Wheel;
  WPI_TalonSRX right2Wheel;

  void SetUpTalons();

public:
	static std::shared_ptr<Chassis> getInstance();
	Chassis();

	void SetTankDrive(double left, double right);
	void InitDefaultCommand();
};

#endif
