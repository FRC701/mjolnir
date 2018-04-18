#include "AutoThreeLeftSwitchThirdIntake.h"

namespace ThreeLeftSwitchThirdIntakeTrajectories {

extern const unsigned int kTrajectoryLength;
extern const robovikes::TrajectoryPoint leftTrajectories[];
extern const robovikes::TrajectoryPoint rightTrajectories[];

}

static const int kPointDurationMillis = 10;

AutoThreeLeftSwitchThirdIntake::AutoThreeLeftSwitchThirdIntake()
: ChassisMotionProfileCommand(
    ThreeLeftSwitchThirdIntakeTrajectories::leftTrajectories,
    ThreeLeftSwitchThirdIntakeTrajectories::rightTrajectories,
    ThreeLeftSwitchThirdIntakeTrajectories::kTrajectoryLength,
    kPointDurationMillis)
{
}


