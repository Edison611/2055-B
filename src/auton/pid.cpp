#include "main.h"

// Bot Sizes - All measurements will be in Inches

int disFromCenterM = 4;
int disFromCenterR = 4;
int disFromCenterL = 4;

double wheelRadius = 2.75;
double pi = 3.14;
double wheelCircum = 2 * wheelRadius * pi;

//

/*
void turn(int radius, int angle) {
    bool enable = true;
    double right = angle    ;
    while (enable) {
        int rightError = right - encRight.get_value();
        int leftError = left - encLeft.get_value();

        double kP = 0.09;
        double motorPowerR = rightError * kP;
        double motorPowerL = leftError * kP

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
    }
    //setDrive(0,0);
}

*/



/*
void PIDSystem(int goTo) {
    double kP = 0.2;
    double kI = 0.0;
    double kD = 0.0;

    int error ;
    int prevError = 0;
    int derivative;
    int totalError = 0;

    bool enablePID = true;

    while (enablePID) {
        // Proportional
        error = averagePos() - goTo;

        // Integral 
        //totalError += error;

        // Derivative
        //derivative = error - prevError;

        int motorPower = error * kP + derivative * kD + totalError * kI;
        
        setDrive(motorPower, motorPower);

        prevError = error;
    }
}

*/