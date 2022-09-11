#include "main.h"


void my_opcontrol() {
    while(true) {
        // drive
        setDriveMotors();

        // intake
        setIntakeMotors();

        // indexer
        setIndexerMotors();

        // shooter
        setShooterMotors();

        pros::delay(10);
    }
}
