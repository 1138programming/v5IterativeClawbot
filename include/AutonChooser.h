#ifndef AUTONCHOOSER_H
#define AUTONCHOOSER_H

#include <vector>
#include <string>

class AutonChooser {
  private:
    //std::vector<std::string> buttonNames;
    lv_obj_t* par = lv_obj_create(lv_obj_create(lv_scr_act(), NULL));
  public:
    //void setAutons(std::vector<std::string> buttonNames);
    //int getAutonChoice();
};

#endif
