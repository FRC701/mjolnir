#include "Commands/GetArmPositionUp.h"
#include "Commands/GetArmPositionDown.h"
#include "Calibrate.h"
#include "ArmUp.h"
#include "ArmDown.h"

Calibrate::Calibrate() {
	// Add Commands here:
  AddSequential(new ArmDown(0.25));
  AddSequential(new GetArmPositionDown);
  AddSequential(new ArmUp(0.25));
  AddSequential(new GetArmPositionUp);

	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.

	// To run multiple commands at the same time,
	// use AddParallel()
	// e.g. AddParallel(new Command1());
	//      AddSequential(new Command2());
	// Command1 and Command2 will run in parallel.
	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.
}
