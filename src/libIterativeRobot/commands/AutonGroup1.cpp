#include "libIterativeRobot/commands/AutonGroup1.h"
#include "libIterativeRobot/commands/AutonGroup2.h"
#include "libIterativeRobot/commands/Delay.h"
#include "libIterativeRobot/commands/Iterations.h"
#include "libIterativeRobot/commands/LambdaGroup.h"

AutonGroup1::AutonGroup1() {
  libIterativeRobot::LambdaGroup* lambda2 = new libIterativeRobot::LambdaGroup();
  lambda2->addSequentialCommand(new Delay(100, 3));
  lambda2->addSequentialCommand(new Delay(100, 4));

  libIterativeRobot::LambdaGroup* lambda = new libIterativeRobot::LambdaGroup();
  lambda->addSequentialCommand(new Delay(100, 1));
  lambda->addSequentialCommand(new Delay(300, 2));
  lambda->addParallelCommand(lambda2);

  addSequentialCommand(new Delay(500, 0));
  addParallelCommand(lambda);
}
