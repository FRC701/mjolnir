#include "SetSlingEngagement.h"

SetSlingEngagement::SetSlingEngagement()
{
  Requires(Puncher::getInstance().get());
}

// Called just before this Command runs the first time
void SetSlingEngagement::Initialize() {
  Puncher::getInstance()->MotorEngage();

}
