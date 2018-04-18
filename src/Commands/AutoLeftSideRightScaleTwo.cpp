#include "AutoLeftSideRightScaleTwo.h"

namespace LeftSideRightScaleTwoTrajectories {

extern const unsigned int kTrajectoryLength;
extern const robovikes::TrajectoryPoint leftTrajectories[];
extern const robovikes::TrajectoryPoint rightTrajectories[];

}

static const int kPointDurationMillis = 10;

AutoLeftSideRightScaleTwo::AutoLeftSideRightScaleTwo()
: ChassisMotionProfileCommand(
    LeftSideRightScaleTwoTrajectories::leftTrajectories,
    LeftSideRightScaleTwoTrajectories::rightTrajectories,
    LeftSideRightScaleTwoTrajectories::kTrajectoryLength,
    kPointDurationMillis)
{
}


