#include "AutoSwitchSide.h"

namespace robovikes {
namespace SwitchSideTrajectory {

extern const unsigned int kTrajectoryLength;
extern const robovikes::TrajectoryPoint leftTrajectory[];
extern const robovikes::TrajectoryPoint rightTrajectory[];

}
}

static const int kMillis_50 = 50;

AutoSwitchSide::AutoSwitchSide()
: ChassisMotionProfileCommand(
    robovikes::SwitchSideTrajectory::leftTrajectory,
    robovikes::SwitchSideTrajectory::rightTrajectory,
    robovikes::SwitchSideTrajectory::kTrajectoryLength,
    kMillis_50)
{
}


