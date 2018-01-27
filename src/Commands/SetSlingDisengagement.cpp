#include "SetSlingDisengagement.h"

SetSlingDisengagement::SetSlingDisengagement()
{
  Requires(Puncher::getInstance().get());
}

// Called once when the command executes
void SetSlingDisengagement::Initialize() {
  Puncher::getInstance()->MotorDisengage(Puncher::kMotorDisengage);

}
