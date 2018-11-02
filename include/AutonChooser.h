#ifndef AUTONCHOOSER_H
#define AUTONCHOOSER_H

#include "display/lvgl.h"

#include <vector>

class AutonChooser {
  private:
    static size_t numAutons;
    static std::vector<char*> autonNames;
    static size_t auton;

    // LVGL Objects
    static lv_obj_t* scrollLeft;
    static lv_obj_t* autonName;
    static lv_obj_t* scrollRight;

    AutonChooser();
    static AutonChooser* instance;
  public:
    static lv_res_t updateAutonName(lv_obj_t* btn);
    void init(size_t numAutons, std::vector<char*> autonNames);
    size_t getAutonChoice();

    static AutonChooser* getInstance();
};

#endif
