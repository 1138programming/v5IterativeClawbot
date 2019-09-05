#ifndef _COMMANDS_DELAY_H_
#define _COMMANDS_DELAY_H_

#include "libIterativeRobot/commands/Command.h"

class Delay: public libIterativeRobot::Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    Delay(int duration, int id);
  private:
    int startTime;
    int duration;
    int id;
};

#endif // _COMMANDS_DELAY_H_
