#include "AutoLeftSideRightScaleOne.h"

namespace LeftSideRightScaleOneTrajectories {

extern const unsigned int kTrajectoryLength;
extern const robovikes::TrajectoryPoint leftTrajectories[];
extern const robovikes::TrajectoryPoint rightTrajectories[];

}

static const int kPointDurationMillis = 10;

AutoLeftSideRightScaleOne::AutoLeftSideRightScaleOne()
: ChassisMotionProfileCommand(
    LeftSideRightScaleOneTrajectories::leftTrajectories,
    LeftSideRightScaleOneTrajectories::rightTrajectories,
    LeftSideRightScaleOneTrajectories::kTrajectoryLength,
    kPointDurationMillis)
{
}


