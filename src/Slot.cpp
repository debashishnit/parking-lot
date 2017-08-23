
#include "../includes/Slot.h"

Slot::Slot(int number) {

    this->number = number;
}

Slot::~Slot() {

}

int Slot::getSlotNumber() {
    return this->number;
}
