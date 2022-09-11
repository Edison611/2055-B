#include "main.h"
#include "pros/llemu.hpp"
#include "pros/misc.h"
#include "pros/motors.h"
#include <string>
#include <iostream>

void setShooter(int shooter_power) {
    shooter1 = shooter_power;
    shooter2 = shooter_power;
}

void setShooterMotors() {
    int shooter  = 127 * controller.get_digital(DIGITAL_X);
    setShooter(shooter);
    pros::lcd::set_text(2, std::to_string(controller.get_digital(DIGITAL_X)));
    
}
