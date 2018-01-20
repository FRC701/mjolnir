#ifndef SRC_COMMANDS_SLINGSHOT_H_
#define SRC_COMMANDS_SLINGSHOT_H_

#include "Commands/Command.h"

class SlingShot: public frc::Command {
public:
  SlingShot(double speed);
  virtual void Initialize();
  virtual void Execute();
  virtual bool IsFinished();
  virtual void End();
  virtual void Interrupted();

private:
  double mSpeed;

};

#endif /* SRC_COMMANDS_SLINGSHOT_H_ */
