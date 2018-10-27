#include "AutonChooser.h"

AutonChooser* AutonChooser::instance = 0;

AutonChooser::AutonChooser() {
  par = lv_obj_create(lv_scr_act(), NULL);
  menu = lv_ddlist_create(par, NULL);
}

void AutonChooser::setAutons(std::string options) {
  lv_ddlist_set_options(menu, options);
}

int AutonChooser::getAutonChoice() {
  lv_ddlist_get_selected(menu);
}

AutonChooser* AutonChooser::getInstance() {
  if (instance == 0) {
    instance = new AutonChooser();
  } else {
    return instance;
  }
}
