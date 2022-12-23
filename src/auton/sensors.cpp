#include "main.h"

void reset_sensors() {
    encLeft.reset();
    encRight.reset();
    //encMiddle.reset();
}

double averagePos() {
    double average = (encRight.get_value() + encLeft.get_value())/2.0;
    return average;
}

class MotorPos {
    public:
        int a = 1;
};
