#include "AutoThreeRightSwitchFirstIntakeReverse.h"

namespace ThreeRightSwitchFirstIntakeReverseTrajectories {

extern const unsigned int kTrajectoryLength;
extern const robovikes::TrajectoryPoint leftTrajectories[];
extern const robovikes::TrajectoryPoint rightTrajectories[];

}

static const int kPointDurationMillis = 10;

AutoThreeRightSwitchFirstIntakeReverse::AutoThreeRightSwitchFirstIntakeReverse()
: ChassisMotionProfileCommand(
    ThreeRightSwitchFirstIntakeReverseTrajectories::leftTrajectories,
    ThreeRightSwitchFirstIntakeReverseTrajectories::rightTrajectories,
    ThreeRightSwitchFirstIntakeReverseTrajectories::kTrajectoryLength,
    kPointDurationMillis)
{
}


