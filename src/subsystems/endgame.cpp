
#include "pros/misc.h"
#include "main.h"
#include "pros/rtos.hpp"


void endgame() {
    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L1) == 1) {
        piston.set_value(true);
        pros::delay(2000);
        piston.set_value(false);
    }
}