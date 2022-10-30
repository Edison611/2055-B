#include "main.h"
#include "pros/llemu.hpp"
#include <string>


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

        // tracking
        trackPos();

        // endgame
        //endgame();

        pros::delay(10);
    }
}
