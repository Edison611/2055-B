#include "main.h"
#include "pros/llemu.hpp"
#include "pros/misc.h"
#include "pros/motors.h"
#include <string>


void my_opcontrol() {
    while(true) {

	    if (bumper.get_value() == 1) {
		    setCatapult(0);
            //cata_hold();
	    }

        // drive
        setDriveMotors();

        // intake
        setIntakeMotors();

        // indexer
        setIndexerMotors();

        // catapult
        setCatapultMotors();


        // shooter
        //setShooterMotors();

        // tracking
        trackPos();

        // endgame
        //endgame();
        
        pros::delay(10);
    }
}
