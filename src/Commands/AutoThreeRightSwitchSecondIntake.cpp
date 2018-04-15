#include "AutoThreeRightSwitchSecondIntake.h"

namespace ThreeRightSwitchSecondIntakeTrajectories {

extern const unsigned int kTrajectoryLength;
extern const robovikes::TrajectoryPoint leftTrajectories[];
extern const robovikes::TrajectoryPoint rightTrajectories[];

}

static const int kPointDurationMillis = 10;

AutoThreeRightSwitchSecondIntake::AutoThreeRightSwitchSecondIntake()
: ChassisMotionProfileCommand(
    ThreeRightSwitchSecondIntakeTrajectories::leftTrajectories,
    ThreeRightSwitchSecondIntakeTrajectories::rightTrajectories,
    ThreeRightSwitchSecondIntakeTrajectories::kTrajectoryLength,
    kPointDurationMillis)
{
}


