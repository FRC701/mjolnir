#include "AutoSwitchIntakeReverse.h"

namespace SwitchIntakeReverseTrajectories {

extern const unsigned int kTrajectoryLength;
extern const robovikes::TrajectoryPoint leftTrajectories[];
extern const robovikes::TrajectoryPoint rightTrajectories[];

}

static const int kPointDurationMillis = 10;

AutoSwitchIntakeReverse::AutoSwitchIntakeReverse()
: ChassisMotionProfileCommand(
    SwitchIntakeReverseTrajectories::leftTrajectories,
    SwitchIntakeReverseTrajectories::rightTrajectories,
    SwitchIntakeReverseTrajectories::kTrajectoryLength,
    kPointDurationMillis)
{
}


