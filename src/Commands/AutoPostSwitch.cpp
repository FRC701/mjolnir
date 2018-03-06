#include "AutoPostSwitch.h"

namespace PostSwitchTrajectories {

extern const unsigned int kTrajectoryLength;
extern const robovikes::TrajectoryPoint leftTrajectories[];
extern const robovikes::TrajectoryPoint rightTrajectories[];

}

static const int kPointDurationMillis = 10;

AutoPostSwitch::AutoPostSwitch()
: ChassisMotionProfileCommand(
    PostSwitchTrajectories::leftTrajectories,
    PostSwitchTrajectories::rightTrajectories,
    PostSwitchTrajectories::kTrajectoryLength,
    kPointDurationMillis)
{
}


