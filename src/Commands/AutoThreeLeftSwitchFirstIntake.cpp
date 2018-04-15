#include "AutoThreeLeftSwitchFirstIntake.h"

namespace ThreeLeftSwitchFirstIntakeTrajectories {

extern const unsigned int kTrajectoryLength;
extern const robovikes::TrajectoryPoint leftTrajectories[];
extern const robovikes::TrajectoryPoint rightTrajectories[];

}

static const int kPointDurationMillis = 10;

AutoThreeLeftSwitchFirstIntake::AutoThreeLeftSwitchFirstIntake()
: ChassisMotionProfileCommand(
    ThreeLeftSwitchFirstIntakeTrajectories::leftTrajectories,
    ThreeLeftSwitchFirstIntakeTrajectories::rightTrajectories,
    ThreeLeftSwitchFirstIntakeTrajectories::kTrajectoryLength,
    kPointDurationMillis)
{
}


