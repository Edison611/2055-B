#include "main.h"
#include "pros/llemu.hpp"
#include "pros/misc.h"
#include "pros/motors.h"
#include "pros/rtos.hpp"
#include <string>
#include <iostream>

void setShooter(int shooter_power) {
    shooter1.move(shooter_power);
    shooter2.move(shooter_power);
}

bool shoot = false;
int desiredPower = 120;

void setShooterMotors() {   
    double tbh = 0.0;
    double lastError = 10.0;
    int error;
    double gain = 0.0001;
    int up = controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_UP);
    int down = controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN);

    desiredPower = desiredPower + 10*up;
    desiredPower = desiredPower - 10*down;

    if (desiredPower > 120) {
        desiredPower = 120;
    }

    if (desiredPower < 40) {
        desiredPower = 40;
    }

    int targetRPM = desiredPower*4;

    /*
    power = power + 1000*up;
    power = power - 1000*down;

    if (power > 12000) {
        power = 12000;
    }

    if (power < 2000) {
        power = 2000;
    }
    */
    int shooter = controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_X);
    if (shooter == 1) {
        if (shoot == true) {
            shoot = false;
        }
        else {
            shoot = true;
        }
    }

    
    controller.set_text(1, 1, "Flywheel: " + std::to_string(desiredPower));
    pros::lcd::set_text(1, "Actual: " + std::to_string(shooter1.get_actual_velocity()));
    //pros::lcd::set_text(2, "Actual: " + std::to_string(shooter2.get_actual_velocity()));

    int power = desiredPower;

    if (shoot == true) {
        
        double actual1 = shooter1.get_actual_velocity();
        //double actual2 = shooter1.get_actual_velocity();
        lastError = error;
        error = targetRPM - actual1;
        power += gain*error; 
        
        pros::lcd::set_text(6, "Power: " + std::to_string(power));
        pros::lcd::set_text(2, "Error: " + std::to_string(error));

        //if (power > 12000) {
        //    power = 12000;
        //}  

        //if(lastError>0 != error>0){
        //    power = 0.5*(power+tbh);
        //    tbh = power ;
        //}
        
        setShooter(power);
    }
    else {
        setShooter(0);
    }
}
