#include "pros/llemu.hpp"
#include "pros/misc.h"
#include "main.h"
#include "pros/rtos.hpp"

void setPushIndexer(int power) {
    indexer.move_voltage(power);
}


void setIndexerMotors() {
    int push = 12000 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_A));
    setPushIndexer(push);
}