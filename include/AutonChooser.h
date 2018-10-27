#ifndef AUTONCHOOSER_H
#define AUTONCHOOSER_H

#include "display/lvgl.h"

//#include <vector>
#include <string>

class AutonChooser {
  private:
    //std::vector<std::string> buttonNames;
    lv_obj_t* par;
    lv_obj_t* menu;

    AutonChooser();

    static AutonChooser* instance;
  public:
    void setAutons(std::string options);
    int getAutonChoice();
    static AutonChooser* getInstance();
};

#endif
