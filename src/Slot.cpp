/*
 * Slot.cpp
 *
 *  Created on: Aug 21, 2017
 *      Author: debashish.g
 */

#include "../includes/Slot.h"

Slot::Slot(int number) {
    // TODO Auto-generated constructor stub
    this->number = number;
}

Slot::~Slot() {
    // TODO Auto-generated destructor stub
}

int Slot::getSlotNumber() {
    return this->number;
}
