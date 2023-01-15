#include "main.h"
#include "pros/llemu.hpp"
#include "pros/misc.h"
#include "pros/rtos.hpp"
#include <string>

void setCatapult(int power) {
    catapult.move(power);
} 

bool hold = false;

void setCatapultMotors() {
    if (bumper.get_value() == 1) {
        hold = true;
    }
    pros::lcd::set_text(1, "Bumper Switch: " + std::to_string(bumper.get_value()));
    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L1) == 1) {
        hold = false;
        // Shoot Catapult
        setCatapult(100);
        pros::delay(300);
        setCatapult(100);
    }
}

void cata_hold() {

	while (true) {
       
		if (hold) {
			int absPos = catapult.get_position();
        
            while (hold) {
                int power = (absPos - catapult.get_position())*1.25;
                setCatapult(power);
                pros::delay(10);
            }
        }
        pros::delay(10);
	}
    
}