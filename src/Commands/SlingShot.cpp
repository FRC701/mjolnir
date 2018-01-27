#include "SlingShot.h"
#include "OI.h"
#include "Subsystems/Puncher.h"

SlingShot::SlingShot(double speed): mSpeed(speed) {
  Requires(Puncher::getInstance().get());
}

void SlingShot::Initialize() {

}

void SlingShot::Execute() {
  Puncher::getInstance()->SlingShot(mSpeed);
}

bool SlingShot::IsFinished() {
    return Puncher::getInstance()->GetPuncherLimit();
}

void SlingShot::End() {

}

void SlingShot::Interrupted() {

}
