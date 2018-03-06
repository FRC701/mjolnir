#include "AutoReverseSwitch.h"

namespace ReverseSwitchTrajectories {

extern const unsigned int kTrajectoryLength;
extern const robovikes::TrajectoryPoint ReverseTrajectories[];
extern const robovikes::TrajectoryPoint rightTrajectories[];

}

static const int kPointDurationMillis = 10;

AutoReverseSwitch::AutoReverseSwitch()
: ChassisMotionProfileCommand(
    ReverseSwitchTrajectories::ReverseTrajectories,
    ReverseSwitchTrajectories::rightTrajectories,
    ReverseSwitchTrajectories::kTrajectoryLength,
    kPointDurationMillis)
{
}


