#include "AutoLeftScale.h"

namespace LeftScaleTrajectories {

extern const unsigned int kTrajectoryLength;
extern const robovikes::TrajectoryPoint leftTrajectories[];
extern const robovikes::TrajectoryPoint rightTrajectories[];

}

static const int kPointDurationMillis = 10;

AutoLeftScale::AutoLeftScale()
: ChassisMotionProfileCommand(
    LeftScaleTrajectories::leftTrajectories,
    LeftScaleTrajectories::rightTrajectories,
    LeftScaleTrajectories::kTrajectoryLength,
    kPointDurationMillis)
{
}


