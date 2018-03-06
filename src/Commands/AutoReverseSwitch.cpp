#include "AutoReverseSwitch.h"

namespace ReverseSwitchTrajectories {

extern const unsigned int kTrajectoryLength;
extern const robovikes::TrajectoryPoint leftTrajectories[];
extern const robovikes::TrajectoryPoint rightTrajectories[];

}

static const int kPointDurationMillis = 10;

AutoReverseSwitch::AutoReverseSwitch()
: ChassisMotionProfileCommand(
    ReverseSwitchTrajectories::leftTrajectories,
    ReverseSwitchTrajectories::rightTrajectories,
    ReverseSwitchTrajectories::kTrajectoryLength,
    kPointDurationMillis)
{
}


