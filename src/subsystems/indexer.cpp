#include "pros/llemu.hpp"
#include "pros/misc.h"
#include "main.h"

void setIndexer(int index_power) {
    indexer = index_power;
    pros::lcd::set_text(1, "Indexer");
}

void setIndexerMotors() {

    int indexer_power = 127 * (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A));
    setIndexer(indexer_power);
    //indexer_power = 0;
}