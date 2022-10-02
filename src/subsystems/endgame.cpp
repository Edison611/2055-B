
#include "pros/misc.h"
#include "main.h"
#include "pros/rtos.hpp"


void endgame() {
    if (pros::E_CONTROLLER_DIGITAL_LEFT && pros::E_CONTROLLER_DIGITAL_L1) {
        piston.set_value(true);
        pros::delay(1000);
        piston.set_value(false);
    }
}