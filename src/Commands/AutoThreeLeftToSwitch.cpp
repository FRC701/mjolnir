#include <Commands/AutoThreeLeftToSwitch.h>

namespace ThreeLeftToSwitchTrajectories {

extern const unsigned int kTrajectoryLength;
extern const robovikes::TrajectoryPoint leftTrajectories[];
extern const robovikes::TrajectoryPoint rightTrajectories[];

}

static const int kPointDurationMillis = 10;

AutoThreeLeftToSwitch::AutoThreeLeftToSwitch()
: ChassisMotionProfileCommand(
    ThreeLeftToSwitchTrajectories::leftTrajectories,
    ThreeLeftToSwitchTrajectories::rightTrajectories,
    ThreeLeftToSwitchTrajectories::kTrajectoryLength,
    kPointDurationMillis)
{
}


