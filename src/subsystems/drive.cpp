#include "main.h"
#include "pros/colors.h"
#include "pros/llemu.hpp"
#include "pros/misc.h"
#include "pros/rtos.hpp"
#include <cstdlib>
#include <iostream>
#include <string>


// DRIVER CONTROL FUNCTIONS

void setDrive(int left, int right) {
    driveLeftBack.move(left);
    driveLeftFront.move(left);
    driveRightBack.move(right);
    driveRightFront.move(right);
}


void setDriveMotors() {
    
    int deadband = 5;

    double drive = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    double turn = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X);

    pros::lcd::set_text(5, "drive: " + std::to_string(drive));
    pros::lcd::set_text(6, "turn: " + std::to_string(turn));

    // Robot will not move with slight joystick movement
    /*
    if (abs(drive) > deadband || abs(turn) > deadband){
    // Makes the bot move exponentially fast
        if (abs(drive) > 50){
            drive = (10/(1+exp(-(abs(drive)/10) - 5))) * 1.2 - 0.5;
        }
        else {
            drive = (5*pow((1/5)*(abs(drive-5))/10, 3.0)) * 1.2 ;
        }
        if (abs(turn) > 50){
            drive = (10/(1+exp(-(abs(turn)/10) - 5))) * 1.2 - 0.5;
        }
        else {
            drive = (5*pow((1/5)*(abs(turn-5))/10, 3.0)) * 1.2 ;
        }
    }
  
    else {
        drive = 0;
        turn = 0;
    }
    
    // Reverses controls for the other direction
    if (drive < 0){
        drive = -drive;
    }
    if (turn < 0){
        turn = -turn;
    }
    */
    double left = drive + turn;
    double right = drive - turn;

    setDrive(left, right);

}

double averagePos() {
    double average = (encRight.get_value() + encLeft.get_value() + encMiddle.get_value())/3.0;
    return average;
}

void translate(int units, int voltage) {
    int direction = abs(units)/units;

    reset_sensors();

    while (fabs(averagePos()) < abs(units)) {
        setDrive(voltage * direction, voltage * direction);
        pros::delay(10);
    }
    setDrive(-10 * direction, -10 * direction); 
    pros::delay(100);
    setDrive(0, 0);
}

