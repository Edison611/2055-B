#include "main.h"

double averagePos() {
    double average = (encRight.get_value() + encLeft.get_value() + encMiddle.get_value())/3;
    return average;
}

void position(int goTo) {
    double kP = 0.0;
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

        prevError = error;
    }
}

