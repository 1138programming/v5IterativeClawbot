#include "AutonChooser.h"

size_t AutonChooser::numAutons;
std::vector<const char*> AutonChooser::autonNames;
size_t AutonChooser::auton;

// LVGL Objects
lv_obj_t* AutonChooser::scrollLeft;
lv_obj_t* AutonChooser::autonName;
lv_obj_t* AutonChooser::scrollRight;

AutonChooser* AutonChooser::instance;

AutonChooser::AutonChooser() {
  autonNames.push_back("Auton1");
  autonNames.push_back("Auton2");

  numAutons = autonNames.size();
}

lv_res_t AutonChooser::updateAutonName(lv_obj_t* btn) {
  if (btn == scrollRight) {
    if (auton >= numAutons)
      auton = 0;
    else
      auton++;
  } else if (btn == scrollLeft) {
    if (auton <= 0)
      auton = numAutons - 1;
    else
      auton--;
  }
  lv_label_set_text(autonName, autonNames[auton]);
  return LV_RES_OK;
}

void AutonChooser::init(size_t numAutons) {
  this->autonNames = autonNames;
  auton = 0;

  lv_obj_t* par = lv_obj_create(lv_scr_act(), NULL);

  scrollRight = lv_btn_create(par, NULL);
  lv_obj_t* scrollRightLabel = lv_label_create(scrollRight, NULL);
  lv_label_set_text(scrollRightLabel, ">");
  lv_btn_set_action(scrollRight, LV_BTN_ACTION_PR, updateAutonName);

  autonName = lv_label_create(par, NULL);
  lv_label_set_text(autonName, autonNames[auton]);

  scrollLeft = lv_btn_create(par, NULL);
  lv_obj_t* scrollLeftLabel = lv_label_create(scrollLeft, NULL);
  lv_label_set_text(scrollLeftLabel, "<");
  lv_btn_set_action(scrollLeft, LV_BTN_ACTION_PR, updateAutonName);
}


AutonChooser* AutonChooser::getInstance() {
  if (instance == 0) {
    instance = new AutonChooser();
  } else {
    return instance;
  }
}
