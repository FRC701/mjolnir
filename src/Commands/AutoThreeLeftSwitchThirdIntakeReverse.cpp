#include "AutoThreeLeftSwitchThirdIntakeReverse.h"

namespace ThreeLeftSwitchThirdIntakeReverseTrajectories {

extern const unsigned int kTrajectoryLength;
extern const robovikes::TrajectoryPoint leftTrajectories[];
extern const robovikes::TrajectoryPoint rightTrajectories[];

}

static const int kPointDurationMillis = 10;

AutoThreeLeftSwitchThirdIntakeReverse::AutoThreeLeftSwitchThirdIntakeReverse()
: ChassisMotionProfileCommand(
    ThreeLeftSwitchThirdIntakeReverseTrajectories::leftTrajectories,
    ThreeLeftSwitchThirdIntakeReverseTrajectories::rightTrajectories,
    ThreeLeftSwitchThirdIntakeReverseTrajectories::kTrajectoryLength,
    kPointDurationMillis)
{
}


