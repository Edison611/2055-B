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

    // Receive input from the controller
    double drive = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    double turn = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X);

    double driveR = -(controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y));
    double turnR = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);


    // Deadband
    if (fabs(drive) < 5) {
        drive = 0;
    }

    if (fabs(turn) < 5) {
        turn = 0;
    }

    double left = (drive + turn) + (driveR + turnR);
    double right = (drive - turn) + (driveR - turnR);

    setDrive(left, right);

}


 

/*
void drivePID(int units) {
    while (enable) {
        double kP = 0.07;
        int P = units - averagePos();
        double motorPower = P * kP;
        if (motorPower > 127) {
            motorPower = 127;
        }
        if (P < 10) {
            enable = false;
        }
        setDrive(-motorPower, -motorPower);

    }
}
*/

void turnPID(int right, int left) {
    bool enable = true;
    int greater;
    bool rev = false;

    if (right < 0 && left < 0) {
        rev = true;
    }

    while (enable) {
        int rightError = right - encRight.get_value();
        int leftError = left - encLeft.get_value();

        double kP = 0.09;
        double motorPowerR = rightError * kP;
        double motorPowerL = leftError * kP;
        
        if (greater < leftError) {
            greater = rightError;
        }
        else {
            greater = leftError;
        }

        if (motorPowerR > 127) {
            motorPowerR = 127;
        }
        if (motorPowerL > 127) {
            motorPowerL = 127;
        }

        if (abs(greater) < 20) {
            reset_sensors();
            enable = false;
        }

        if (rev == true) {
            setDrive(motorPowerL, motorPowerR);
        }
        else {
            setDrive(-motorPowerL, -motorPowerR);
        }
    }
    setDrive(0,0);
}



void translate(int units, int voltage) {
    int direction = abs(units)/units;

    reset_sensors();

    while (fabs(averagePos()) < abs(units)) {
        setDrive(voltage * direction, voltage * direction);
        pros::delay(10);
    }

    setDrive(-10 * direction, -10 * direction); 

    pros::delay(50);

    setDrive(0, 0);
}



