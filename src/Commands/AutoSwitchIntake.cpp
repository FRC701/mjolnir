#include "AutoSwitchIntake.h"

namespace SwitchIntakeTrajectories {

extern const unsigned int kTrajectoryLength;
extern const robovikes::TrajectoryPoint leftTrajectories[];
extern const robovikes::TrajectoryPoint rightTrajectories[];

}

static const int kPointDurationMillis = 10;

AutoSwitchIntake::AutoSwitchIntake()
: ChassisMotionProfileCommand(
    SwitchIntakeTrajectories::leftTrajectories,
    SwitchIntakeTrajectories::rightTrajectories,
    SwitchIntakeTrajectories::kTrajectoryLength,
    kPointDurationMillis)
{
}


