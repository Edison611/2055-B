#include "main.h"
#include "pros/llemu.hpp"
#include "pros/rtos.hpp"

void redRight() {
    driveCalc(11.775);
    pros::delay(100);
    turnCalc(90);
    pros::delay(100);
    //driveCalc(11.775);
    pros::delay(100);
    //turnCalc(180);

    // First Turn
    //driveCoord(640, 500);

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
    setDrive(0, 0);

    // Two Shots
    setShooter(9500);
    pros::delay(4000);
    setShoot();
    pros::delay(4000);
    setShoot();
    setShooter(0);
}

void test() {
    //setDrive(10, -10);
    //driveCoord(640, 640);
    //driveCalc(11.775);
    //setDrive(11, 11);
    //turnCalc(90);
}