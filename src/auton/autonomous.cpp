#include "main.h"
#include "pros/llemu.hpp"
#include "pros/rtos.hpp"

void redRight() {
    // First Turn
    turnPID(640, 500);

    // Two Shots
    setShooter(8750);
    pros::delay(4000);
    setShoot();
    //pros::delay(100);
    setShooter(8700);
    pros::delay(2000);
    setShoot();
    setShooter(0);
    pros::delay(100);

    // Roller
    // Turn
    /*
    setDrive(-60, -60);
    pros::delay(500);
    setDrive(0,0);
    setDrive(10, 65);
    pros::delay(1000);
    setDrive(0,0);
    */
    // Drive
    //setDrive(70, 70);
    //pros::delay(300);
    //setDrive(0, 0);
    
    // Turn 2
    //setDrive(0, 60);
    //pros::delay(50);

    // Roller
    /*
    setIntake(-100);
    pros::delay(500);
    setDrive(100, 100);
    pros::delay(300);
    setIntake(0);
    */

    // PID TEST (DO NOT USE)
    /*
    pros::delay(1000);
    turnPID(0, 900);
    pros::delay(335);
    reset_sensors();
    */

    //setIntake(-120);
    //turnPID(970, 720);
    //setIntake(0);
    
}

void redLeft() {

    // Roller
    setIntake(-100);
    pros::delay(1000);
    setDrive(100, 100);
    pros::delay(300);
    setIntake(0);

    // Position to shoot
    setDrive(-100, -100);
    pros::delay(200);
    setDrive(0, 0);
    setDrive(0, 20);
    pros::delay(200);

    // Two Shots
    setShooter(9500);
    pros::delay(4000);
    setShoot();
    pros::delay(4000);
    setShoot();
    setShooter(0);
}
