#include "AutoThreeRightSwitchFirstIntake.h"

namespace ThreeRightSwitchFirstIntakeTrajectories {

extern const unsigned int kTrajectoryLength;
extern const robovikes::TrajectoryPoint leftTrajectories[];
extern const robovikes::TrajectoryPoint rightTrajectories[];

}

static const int kPointDurationMillis = 10;

AutoThreeRightSwitchFirstIntake::AutoThreeRightSwitchFirstIntake()
: ChassisMotionProfileCommand(
    ThreeRightSwitchFirstIntakeTrajectories::leftTrajectories,
    ThreeRightSwitchFirstIntakeTrajectories::rightTrajectories,
    ThreeRightSwitchFirstIntakeTrajectories::kTrajectoryLength,
    kPointDurationMillis)
{
}


