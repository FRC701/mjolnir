#ifndef OI_H
#define OI_H

#include "Joystick.h"
#include "Buttons/JoystickButton.h"

class OI {
private:
  static std::shared_ptr<OI> self;
  std::shared_ptr<frc::Joystick> driver;
  frc::JoystickButton dA;
  frc::JoystickButton dB;
  frc::JoystickButton dX;
  frc::JoystickButton dY;
  frc::JoystickButton dLB;
  frc::JoystickButton dRB;

  std::shared_ptr<frc::Joystick> coDriver;
  frc::JoystickButton coA;
  frc::JoystickButton coB;
  frc::JoystickButton coX;
  frc::JoystickButton coY;
  frc::JoystickButton coLB;
  frc::JoystickButton coRB;
  frc::JoystickButton coStart;

public:
  static std::shared_ptr<OI> getInstance();

  OI();

  std::shared_ptr<frc::Joystick> getDriver();
  double getDriverLeftXAxis() const;
  double getDriverLeftYAxis() const;
  double getDriverRightXAxis() const;
  double getDriverRightYAxis() const;

  std::shared_ptr<frc::Joystick> getCoDriver();
  double getCoDriverLeftXAxis() const;
  double getCoDriverLeftYAxis() const;
  double getCoDriverRightXAxis() const;
  double getCoDriverRightYAxis() const;

  bool isDriverBPressed();
  bool isCodriverLBPressed();

  static const int kButtonA_ID = 1;
  static const int kButtonB_ID = 2;
  static const int kButtonX_ID = 3;
  static const int kButtonY_ID = 4;
  static const int kButtonLB_ID = 5;
  static const int kButtonRB_ID = 6;
  static const int kLeftXAxis_ID = 0;
  static const int kLeftYAxis_ID = 1;
  static const int kRightXAxis_ID = 4;
  static const int kRightYAxis_ID = 5;
  static const int kButtonStart_ID = 8;
};

#endif
