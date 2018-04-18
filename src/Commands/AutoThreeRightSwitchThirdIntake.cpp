#include "AutoThreeRightSwitchThirdIntake.h"

namespace ThreeRightSwitchThirdIntakeTrajectories {

extern const unsigned int kTrajectoryLength;
extern const robovikes::TrajectoryPoint leftTrajectories[];
extern const robovikes::TrajectoryPoint rightTrajectories[];

}

static const int kPointDurationMillis = 10;

AutoThreeRightSwitchThirdIntake::AutoThreeRightSwitchThirdIntake()
: ChassisMotionProfileCommand(
    ThreeRightSwitchThirdIntakeTrajectories::leftTrajectories,
    ThreeRightSwitchThirdIntakeTrajectories::rightTrajectories,
    ThreeRightSwitchThirdIntakeTrajectories::kTrajectoryLength,
    kPointDurationMillis)
{
}


