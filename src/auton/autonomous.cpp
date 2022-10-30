#include "main.h"
#include "pros/llemu.hpp"
#include "pros/rtos.hpp"

//double circumference = pi*5.5;

void redRight() {
    turnPID(990, 730);
    setShooter(100);
    pros::delay(4000);
    setShoot();
    //pros::delay(100);
    setShooter(90);
    pros::delay(3000);
    setShoot();
    setShooter(0);
    pros::delay(1000);
    setIntake(-120);
    setDrive(0, 110);
    pros::delay(850);
    setDrive(0, 0);
    pros::delay(1000);
    setDrive(60, 60);
    pros::delay(1600);
    setIntake(0);
}

void redLeft() {
    setIntake(-100);
    pros::delay(1000);
    setDrive(100, 100);
    pros::delay(300);
    setIntake(0);
    setDrive(-100, -100);
    pros::delay(150);
    setDrive(0, 0);
    setDrive(0, 110);
    pros::delay(300);
    setShooter(123);
    pros::delay(6000);
    setShoot();
    pros::delay(4000);
    setShoot();
    setShooter(0);
    
}

void test() {
    //setPush();
}