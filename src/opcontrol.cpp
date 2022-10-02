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

        // endgame
        //endgame();

        //get_temp();

        pros::delay(10);
    }
}
