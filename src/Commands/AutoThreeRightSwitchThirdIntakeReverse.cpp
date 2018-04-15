#include "AutoThreeRightSwitchThirdIntakeReverse.h"

namespace ThreeRightSwitchThirdIntakeReverseTrajectories {

extern const unsigned int kTrajectoryLength;
extern const robovikes::TrajectoryPoint leftTrajectories[];
extern const robovikes::TrajectoryPoint rightTrajectories[];

}

static const int kPointDurationMillis = 10;

AutoThreeRightSwitchThirdIntakeReverse::AutoThreeRightSwitchThirdIntakeReverse()
: ChassisMotionProfileCommand(
    ThreeRightSwitchThirdIntakeReverseTrajectories::leftTrajectories,
    ThreeRightSwitchThirdIntakeReverseTrajectories::rightTrajectories,
    ThreeRightSwitchThirdIntakeReverseTrajectories::kTrajectoryLength,
    kPointDurationMillis)
{
}


