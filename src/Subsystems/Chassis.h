#ifndef CHASSIS_H
#define CHASSIS_H

#include "Commands/Subsystem.h"
#include "ctre/Phoenix.h"

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

  double p, i, d, f;

  void SetUpTalons();
  void SetUpMotionMagic();


public:
	static std::shared_ptr<Chassis> getInstance();
	Chassis();

	void SetTankDrive(double left, double right);
	void InitDefaultCommand();

	int getLeftVelocity();
	int getRightVelocity();
	int GetLeftPosition();
	int GetRightPosition();

	// Motion Profile Support
	void SetModePercentOutput();
	void SetModeMotionProfile();
	void ClearMotionProfileTrajectories();
	void SetMotionProfileSetValue(SetValueMotionProfile setValue);
	void ConfigMotionProfileTrajectoryPeriod(int pointDurationMillis);
	void PushMotionProfileTrajectory(const TrajectoryPoint& leftTrajectoryPoint,
	                                 const TrajectoryPoint& rightTrajectoryPoint);
	void ProcessMotionProfileBuffer();
	void GetMotionProfileStatus(MotionProfileStatus* leftStatus,
	                            MotionProfileStatus* rightStatus);
	void SetMotionMagic(int position);
	int GetLeftPosError();
	int GetLeft1WheelVoltage();
};


#endif
