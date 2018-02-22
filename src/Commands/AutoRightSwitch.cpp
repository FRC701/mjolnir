#include "AutoRightSwitch.h"

namespace RightSwitchTrajectories {

extern const unsigned int kTrajectoryLength;
extern const robovikes::TrajectoryPoint leftTrajectories[];
extern const robovikes::TrajectoryPoint rightTrajectories[];

}

static const int kPointDurationMillis = 10;

AutoRightSwitch::AutoRightSwitch()
: ChassisMotionProfileCommand(
    RightSwitchTrajectories::leftTrajectories,
    RightSwitchTrajectories::rightTrajectories,
    RightSwitchTrajectories::kTrajectoryLength,
    kPointDurationMillis)
{
}


