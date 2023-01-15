#include "main.h"
#include "pros/llemu.hpp"
#include "pros/rtos.hpp"
#include <string>

// Bot Sizes - All measurements will be in Inches

int disFromCenterM = 4;
double disFromCenterR = 6.25;
int disFromCenterL = 9;

double pi = 3.14;

double wheelRadiusM = 2.75;
double wheelCircumM = 2 * wheelRadiusM * pi;

double wheelRadiusS = 3.75/2.00;
double wheelCircumS = 2 * wheelRadiusS * pi;


/*
Turn 'x' degrees
while encoder units of all tracking wheels are less where it should go
(x/360)*(2*disFromCenter*pi)/wheelCircum = N    umber of Rotations
Number of Rotations * 360 = The Encoder Units required to turn x degrees
use PID system to get to that position
*/

void turnCalc(int angle) {
    double rotationS = ((angle/360.0)*(2*disFromCenterR*pi))/wheelCircumS;

    int req = rotationS*360;

    PID(req, -req);
}

/*
Drive 'x' inches in a straight line

degrees needed to travel by each wheel = (x/wheelCircum)*360
*/

void driveCalc(double distance) {
    int degrees = (distance/wheelCircumS)*360.00;

    PID(-degrees, -degrees);
}


void PID(int left, int right) {
    bool enable = true;
    double greater;
    int dirR;
    int dirL;
    double kP;
    int angle;

    // Calculate direction
    if (right < 0) {
        dirR = -1;
    }
    else {
        dirR = 1;
    }

    if (left < 0) {
        dirL = -1;
    }
    else {
        dirL = 1;
    }

    // Calculate Proportional Value
    

    right = abs(right);
    left = abs(left);

    while (enable) {
        trackPos();
        pros::lcd::set_text(2, std::to_string(greater));
        pros::delay(100);
        double rightError = right - fabs(encRight.get_position()/100.0);
        double leftError = left - fabs(encLeft.get_position()/100.0);

        double kP = 0.18;
        double motorPowerR = rightError * kP;
        double motorPowerL = leftError * kP;
        
        greater = rightError;

        if (greater > leftError) {
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
        
        if (motorPowerL < 8 && motorPowerR < 8) {
            setDrive(0,0);
            angle = (encLeft.get_position()/100.0) - (encRight.get_position()/100.0)/(disFromCenterR*2)*180/pi;
            
            enable = false;
            pros::lcd::set_text(1, "angle: " + std::to_string(angle));
            pros::delay(100);
        }
        
        if (fabs(greater) < 25) {
            setDrive(0,0);
            reset_sensors();
            enable = false;
        }

        setDrive(((dirL) * (-motorPowerL)), ((dirR) * (-motorPowerR)));
    }
}

/*
// General PID system template

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
        totalError += error;

        // Derivative
        derivative = error - prevError;

        int motorPower = error * kP + derivative * kD + totalError * kI;
        
        setDrive(motorPower, motorPower);

        prevError = error;
    }
}

*/