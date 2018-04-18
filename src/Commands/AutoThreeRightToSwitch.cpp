#include "AutoThreeRightToSwitch.h"

namespace ThreeRightToSwitchTrajectories {

extern const unsigned int kTrajectoryLength;
extern const robovikes::TrajectoryPoint leftTrajectories[];
extern const robovikes::TrajectoryPoint rightTrajectories[];

}

static const int kPointDurationMillis = 10;

AutoThreeRightToSwitch::AutoThreeRightToSwitch()
: ChassisMotionProfileCommand(
    ThreeRightToSwitchTrajectories::leftTrajectories,
    ThreeRightToSwitchTrajectories::rightTrajectories,
    ThreeRightToSwitchTrajectories::kTrajectoryLength,
    kPointDurationMillis)
{
}


