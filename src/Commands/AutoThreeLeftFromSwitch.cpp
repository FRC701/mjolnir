#include "AutoThreeLeftFromSwitch.h"

namespace ThreeLeftFromSwitchTrajectories {

extern const unsigned int kTrajectoryLength;
extern const robovikes::TrajectoryPoint leftTrajectories[];
extern const robovikes::TrajectoryPoint rightTrajectories[];

}

static const int kPointDurationMillis = 10;

AutoThreeLeftFromSwitch::AutoThreeLeftFromSwitch()
: ChassisMotionProfileCommand(
    ThreeLeftFromSwitchTrajectories::leftTrajectories,
    ThreeLeftFromSwitchTrajectories::rightTrajectories,
    ThreeLeftFromSwitchTrajectories::kTrajectoryLength,
    kPointDurationMillis)
{
}


