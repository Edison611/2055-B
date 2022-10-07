#include "main.h"

void reset_sensors() {
    encLeft.reset();
    encRight.reset();
    encMiddle.reset();
}

double averagePos() {
    double average = (encRight.get_value() + encLeft.get_value() + encMiddle.get_value())/3.0;
    return average;
}
