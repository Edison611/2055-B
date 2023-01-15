#include "pros/llemu.hpp"
#include "pros/misc.h"
#include "main.h"
#include "pros/motors.h"
#include "pros/rtos.hpp"
#include <string>

void setIndexer(int power) {
    indexer.move_voltage(power);
}


void setIndexerMotors() {
    int push = 12000 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_A));
    //pros::lcd::set_text(6, std::to_string(indexer.get_encoder_units()));
    setIndexer(push);
}

void setPush() {
    while (indexer.get_encoder_units() < 360) {
        setIndexer(12000);
    }
    setIndexer(0);
    indexer.tare_position();
}

void setShoot() {
    setIndexer(12000);
    pros::delay(275);
    setIndexer(0);
}
/*
void setIndexerRetract() {
    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A) == 1) {
        while (indexer.get_encoder_units() < 90) {
            setIndexer(12000);
        }
        while (indexer.get_encoder_units() > 0) {
            setIndexer(-12000);
        }
    indexer.tare_position();
    }
}
*/