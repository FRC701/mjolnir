#include "AutoThreeLeftSwitchFirstIntakeReverse.h"

namespace ThreeLeftSwitchFirstIntakeReverseTrajectories {

extern const unsigned int kTrajectoryLength;
extern const robovikes::TrajectoryPoint leftTrajectories[];
extern const robovikes::TrajectoryPoint rightTrajectories[];

}

static const int kPointDurationMillis = 10;

AutoThreeLeftSwitchFirstIntakeReverse::AutoThreeLeftSwitchFirstIntakeReverse()
: ChassisMotionProfileCommand(
    ThreeLeftSwitchFirstIntakeReverseTrajectories::leftTrajectories,
    ThreeLeftSwitchFirstIntakeReverseTrajectories::rightTrajectories,
    ThreeLeftSwitchFirstIntakeReverseTrajectories::kTrajectoryLength,
    kPointDurationMillis)
{
}


