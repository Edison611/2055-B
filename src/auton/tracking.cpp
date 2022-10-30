#include "pros/llemu.hpp"
#include <string>
#include "main.h"

void trackPos() {
    pros::lcd::set_text(3, "Left Encoder: " + std::to_string(encLeft.get_value()));
    pros::lcd::set_text(4, "Right Encoder: " + std::to_string(encRight.get_value()));
    pros::lcd::set_text(5, "Middle Encoder: " + std::to_string(encMiddle.get_value()));
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_Y)) {
        reset_sensors();
    }
    //pros::lcd::set_text(6, std::to_string(averagePos()));
}