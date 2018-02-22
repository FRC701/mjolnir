#include "AutoRun.h"

namespace AutoRunTrajectories {

extern const unsigned int kTrajectoryLength;
extern const robovikes::TrajectoryPoint leftTrajectories[];
extern const robovikes::TrajectoryPoint rightTrajectories[];

}

static const int kPointDurationMillis = 10;

AutoRun::AutoRun()
: ChassisMotionProfileCommand(
    AutoRunTrajectories::leftTrajectories,
    AutoRunTrajectories::rightTrajectories,
    AutoRunTrajectories::kTrajectoryLength,
    kPointDurationMillis)
{
}


