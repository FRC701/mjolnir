#include "AutoThreeRightFromSwitch.h"

namespace ThreeRightFromSwitchTrajectories {

extern const unsigned int kTrajectoryLength;
extern const robovikes::TrajectoryPoint leftTrajectories[];
extern const robovikes::TrajectoryPoint rightTrajectories[];

}

static const int kPointDurationMillis = 10;

AutoThreeRightFromSwitch::AutoThreeRightFromSwitch()
: ChassisMotionProfileCommand(
    ThreeRightFromSwitchTrajectories::leftTrajectories,
    ThreeRightFromSwitchTrajectories::rightTrajectories,
    ThreeRightFromSwitchTrajectories::kTrajectoryLength,
    kPointDurationMillis)
{
}


