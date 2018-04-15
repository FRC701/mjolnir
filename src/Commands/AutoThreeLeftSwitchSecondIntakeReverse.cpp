#include "AutoThreeLeftSwitchSecondIntakeReverse.h"

namespace ThreeLeftSwitchSecondIntakeReverseTrajectories {

extern const unsigned int kTrajectoryLength;
extern const robovikes::TrajectoryPoint leftTrajectories[];
extern const robovikes::TrajectoryPoint rightTrajectories[];

}

static const int kPointDurationMillis = 10;

AutoThreeLeftSwitchSecondIntakeReverse::AutoThreeLeftSwitchSecondIntakeReverse()
: ChassisMotionProfileCommand(
    ThreeLeftSwitchSecondIntakeReverseTrajectories::leftTrajectories,
    ThreeLeftSwitchSecondIntakeReverseTrajectories::rightTrajectories,
    ThreeLeftSwitchSecondIntakeReverseTrajectories::kTrajectoryLength,
    kPointDurationMillis)
{
}


