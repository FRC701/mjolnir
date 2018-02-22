#include "AutoLeftSwitch.h"

namespace LeftSwitchTrajectories {

extern const unsigned int kTrajectoryLength;
extern const robovikes::TrajectoryPoint leftTrajectories[];
extern const robovikes::TrajectoryPoint rightTrajectories[];

}

static const int kPointDurationMillis = 10;

AutoLeftSwitch::AutoLeftSwitch()
: ChassisMotionProfileCommand(
    LeftSwitchTrajectories::leftTrajectories,
    LeftSwitchTrajectories::rightTrajectories,
    LeftSwitchTrajectories::kTrajectoryLength,
    kPointDurationMillis)
{
}


