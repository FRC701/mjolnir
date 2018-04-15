#include "AutoThreeLeftSwitchSecondIntake.h"

namespace ThreeLeftSwitchSecondIntakeTrajectories {

extern const unsigned int kTrajectoryLength;
extern const robovikes::TrajectoryPoint leftTrajectories[];
extern const robovikes::TrajectoryPoint rightTrajectories[];

}

static const int kPointDurationMillis = 10;

AutoThreeLeftSwitchSecondIntake::AutoThreeLeftSwitchSecondIntake()
: ChassisMotionProfileCommand(
    ThreeLeftSwitchSecondIntakeTrajectories::leftTrajectories,
    ThreeLeftSwitchSecondIntakeTrajectories::rightTrajectories,
    ThreeLeftSwitchSecondIntakeTrajectories::kTrajectoryLength,
    kPointDurationMillis)
{
}


