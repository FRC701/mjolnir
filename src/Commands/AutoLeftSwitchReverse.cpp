#include "AutoLeftSwitchReverse.h"

namespace LeftSwitchReverseTrajectories {

extern const unsigned int kTrajectoryLength;
extern const robovikes::TrajectoryPoint leftTrajectories[];
extern const robovikes::TrajectoryPoint rightTrajectories[];

}

static const int kPointDurationMillis = 10;

AutoLeftSwitchReverse::AutoLeftSwitchReverse()
: ChassisMotionProfileCommand(
    LeftSwitchReverseTrajectories::leftTrajectories,
    LeftSwitchReverseTrajectories::rightTrajectories,
    LeftSwitchReverseTrajectories::kTrajectoryLength,
    kPointDurationMillis)
{
}


