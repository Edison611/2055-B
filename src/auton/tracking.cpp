#include "pros/llemu.hpp"
#include <string>
#include "main.h"
#include "pros/rtos.hpp"

void trackPos() {
    //pros::lcd::set_text(3, "Left Encoder: " + std::to_string(driveLeftFront.get_encoder_units()));
    //pros::lcd::set_text(4, "Right Encoder: " + std::to_string(driveRightFront.get_encoder_units()));
    pros::lcd::set_text(3, "Left Encoder: " + std::to_string(encLeft.get_position()/100));
    pros::lcd::set_text(4, "Right Encoder: " + std::to_string(encRight.get_position()/100));
    pros::lcd::set_text(5, "Middle Encoder: " + std::to_string(encMiddle.get_value()));

    //pros::lcd::set_text(5, "Middle Encoder: " + std::to_string(encMiddle.get_value()));
    
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_Y)) {
        reset_sensors();
        controller.clear();
        pros::delay(200);
    }
    //pros::lcd::set_text(6, std::to_string(averagePos()));
}