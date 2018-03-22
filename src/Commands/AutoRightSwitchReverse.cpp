#include "AutoRightSwitchReverse.h"

namespace RightSwitchReverseTrajectories {

extern const unsigned int kTrajectoryLength;
extern const robovikes::TrajectoryPoint leftTrajectories[];
extern const robovikes::TrajectoryPoint rightTrajectories[];

}

static const int kPointDurationMillis = 10;

AutoRightSwitchReverse::AutoRightSwitchReverse()
: ChassisMotionProfileCommand(
    RightSwitchReverseTrajectories::leftTrajectories,
    RightSwitchReverseTrajectories::rightTrajectories,
    RightSwitchReverseTrajectories::kTrajectoryLength,
    kPointDurationMillis)
{
}


