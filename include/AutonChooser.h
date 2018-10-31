#ifndef AUTONCHOOSER_H
#define AUTONCHOOSER_H

#include "display/lvgl.h"

#include <vector>

class AutonChooser {
  private:
    AutonChooser();

    static AutonChooser* instance;
  public:
    void init();

    static AutonChooser* getInstance();
};

#endif
