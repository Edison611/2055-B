#include "pros/llemu.hpp"
#include "pros/misc.h"
#include "main.h"
#include "pros/rtos.hpp"

void setPushIndexer(int power) {
    indexer = power;
}

void setRetractIndexer(int power) {
    indexer = power;
}

void setIndexerMotors() {

    int push = 127 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_A));
    setPushIndexer(push);
    //pros::delay(1000);
    //setRetractIndexer(-(push));

    //indexer_power = 0;
}