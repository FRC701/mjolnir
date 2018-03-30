#include "AutoLeftSideRightScaleThree.h"

namespace LeftSideRightScaleThreeTrajectories {

extern const unsigned int kTrajectoryLength;
extern const robovikes::TrajectoryPoint leftTrajectories[];
extern const robovikes::TrajectoryPoint rightTrajectories[];

}

static const int kPointDurationMillis = 10;

AutoLeftSideRightScaleThree::AutoLeftSideRightScaleThree()
: ChassisMotionProfileCommand(
    LeftSideRightScaleThreeTrajectories::leftTrajectories,
    LeftSideRightScaleThreeTrajectories::rightTrajectories,
    LeftSideRightScaleThreeTrajectories::kTrajectoryLength,
    kPointDurationMillis)
{
}


