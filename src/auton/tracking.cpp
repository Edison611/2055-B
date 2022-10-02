#include <string>
void get_temp() {
    pros::lcd::print(4, std::to_string(shooter1.pros::c::motor_get_temperature(5)))
}