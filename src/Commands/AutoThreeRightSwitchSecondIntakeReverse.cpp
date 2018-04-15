#include "AutoThreeRightSwitchSecondIntakeReverse.h"

namespace ThreeRightSwitchSecondIntakeReverseTrajectories {

extern const unsigned int kTrajectoryLength;
extern const robovikes::TrajectoryPoint leftTrajectories[];
extern const robovikes::TrajectoryPoint rightTrajectories[];

}

static const int kPointDurationMillis = 10;

AutoThreeRightSwitchSecondIntakeReverse::AutoThreeRightSwitchSecondIntakeReverse()
: ChassisMotionProfileCommand(
    ThreeRightSwitchSecondIntakeReverseTrajectories::leftTrajectories,
    ThreeRightSwitchSecondIntakeReverseTrajectories::rightTrajectories,
    ThreeRightSwitchSecondIntakeReverseTrajectories::kTrajectoryLength,
    kPointDurationMillis)
{
}


