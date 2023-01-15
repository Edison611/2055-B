#include "main.h"

void reset_sensors() {
    driveLeftBack.tare_position();
    driveRightBack.tare_position();
    driveLeftFront.tare_position();
    driveRightFront.tare_position();
    encLeft.reset_position();
    encRight.reset_position();
    encMiddle.reset();
}

//double averagePos() {
    //double average = (encRight.get_value() + encLeft.get_value())/2.0;
    //return average;
//}

