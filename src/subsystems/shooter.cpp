#include "main.h"
#include "pros/llemu.hpp"
#include "pros/misc.h"
#include "pros/motors.h"
#include <string>
#include <iostream>

void setShooter(int shooter_power) {
    shooter1.move_voltage(shooter_power);
    shooter2 .move_voltage(shooter_power);
}

bool shoot = false;
int power = 12000;

void setShooterMotors() {   
    int up = controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_UP);
    int down = controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN);
    power = power + 1000*up;
    power = power - 1000*down;
    pros::lcd::set_text(3, "power: " + std::to_string(power));

    if (power > 12000) {
        power = 12000;
    }

    if (power < 2000) {
        power = 2000;
    }

    int shooter = controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_X);
    if (shooter == 1) {
        if (shoot == true) {
            shoot = false;
        }
        else {
            shoot = true;
        }
    }
    controller.set_text(1, 1, "Flywheel: " + std::to_string(power/1000));
    if (power < 10) {
        controller.clear();
    }
    if (shoot == true) {
        setShooter(power);
    }
    else {
        setShooter(0);
    }
}
