#include "main.h"
#include "pros/colors.h"
#include "pros/llemu.hpp"
#include "pros/misc.h"
#include <cstdlib>
#include <iostream>


// DRIVER CONTROL FUNCTIONS

void setDrive(int left, int right) {
    driveLeftBack.move(left);
    driveLeftFront.move(left);
    driveRightBack.move(right);
    driveRightFront.move(right);
}


void setDriveMotors() {
    /*
    double turn = 0;
    double drive = 0;

    int y = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    int x = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X);

    if (abs(x) < 10) 
        x = 0;
    if (abs(y) < 10) 
        y = 0;
    setDrive(x, y);
    */
    
    int deadband = 5;
    int drive = 0;
    int turn = 0;

    int x = abs(controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X));
    int y = abs(controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y));

    // Robot will not move with slight joystick movement
    /*
    if (abs(y) > deadband || abs(x) > deadband){
    // Makes the bot move exponentially fast
        if (abs(y) > 50){
            drive = (10/(1+exp(-(abs(y)/10) - 5))) * 1.2 - 0.5;
        }
        else {
            drive = (5*pow((1/5)*(abs(y-5))/10, 3.0)) * 1.2 ;
        }
        if (abs(x) > 50){
            drive = (10/(1+exp(-(abs(x)/10) - 5))) * 1.2 - 0.5;
        }
        else {
            drive = (5*pow((1/5)*(abs(x-5))/10, 3.0)) * 1.2 ;
        }
    }

    else {
        drive = 0;
        turn = 0;
    }
    */
    // Reverses controls for the other direction
    if (y < 0){
        drive = -drive;
    }
    if (x < 0){
        turn = -turn;
    }
    double left = drive - turn;
    double right = drive + turn;

    setDrive(left, right);

}


