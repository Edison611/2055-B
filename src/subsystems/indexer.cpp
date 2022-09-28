#include "pros/llemu.hpp"
#include "pros/misc.h"
#include "main.h"
#include "pros/rtos.hpp"

void setPushIndexer(int power) {
    indexer.move_voltage(power);
}

void setRetractIndexer(int power) {
    indexer.move_velocity(12000);
}

void setIndexerMotors() {
    int push = 12000 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_A));
    setPushIndexer(push);
    /*
    if (push == 1) {
        setPushIndexer(11500);
        pros::delay(50);
    }
    
    setPushIndexer(push);
    */
    //pros::delay(1000);
    //setRetractIndexer(-(push));

    //indexer_power = 0;
}