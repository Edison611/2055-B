#include "main.h"
#include "pros/llemu.hpp"
#include "pros/misc.h"
#include "pros/motors.h"
#include <string>
#include <iostream>

void setShooter(int shooter_power) {
    shooter1 = shooter_power;
    shooter2 = shooter_power;
    //shooter1.move(shooter_power);
    //shooter2.move(shooter_power);
}

bool shoot = false;
void setShooterMotors() {
    int up = controller.get_digital(pros::E_CONTROLLER_DIGITAL_UP);
    int down = controller.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN);
    int shooter = controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_X);
    if (shooter == 1) {
        if (shoot == true) {
            shoot = false;
        }
        else {
            shoot = true;
        }
    }
    if (shoot == true) {
        setShooter(127);
    }
    else {
        setShooter(0);
    }
}
