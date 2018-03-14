#include "AutoPostLeftSwitch.h"

namespace PostLeftSwitchTrajectories {

extern const unsigned int kTrajectoryLength;
extern const robovikes::TrajectoryPoint leftTrajectories[];
extern const robovikes::TrajectoryPoint rightTrajectories[];

}

static const int kPointDurationMillis = 10;

AutoPostLeftSwitch::AutoPostLeftSwitch()
: ChassisMotionProfileCommand(
    PostLeftSwitchTrajectories::leftTrajectories,
    PostLeftSwitchTrajectories::rightTrajectories,
    PostLeftSwitchTrajectories::kTrajectoryLength,
    kPointDurationMillis)
{
}


