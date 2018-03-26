#include "AutoRightScale.h"

namespace RightScaleTrajectories {

extern const unsigned int kTrajectoryLength;
extern const robovikes::TrajectoryPoint leftTrajectories[];
extern const robovikes::TrajectoryPoint rightTrajectories[];

}

static const int kPointDurationMillis = 10;

AutoRightScale::AutoRightScale()
: ChassisMotionProfileCommand(
    RightScaleTrajectories::leftTrajectories,
    RightScaleTrajectories::rightTrajectories,
    RightScaleTrajectories::kTrajectoryLength,
    kPointDurationMillis)
{
}


