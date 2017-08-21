/*
 * ParkingLotController.cpp
 *
 *  Created on: Aug 22, 2017
 *      Author: debashish.g
 */

#include "../includes/ParkingLotController.h"

#include <iostream>

ParkingLotController::ParkingLotController(int maxSlots) {
    // TODO Auto-generated constructor stub
    for(int availableSlot=1; availableSlot<=maxSlots; availableSlot++) {
        this->availableSlots.push(availableSlot);
    }

}

ParkingLotController::~ParkingLotController() {
    // TODO Auto-generated destructor stub
}

bool ParkingLotController::isSlotAvailable() {
    return !this->availableSlots.empty() ;
}

std::vector<int> ParkingLotController::getAvailableSlots() {
    std::vector<int> slotAvailable;
    while(!this->availableSlots.empty()) {
        slotAvailable.push_back(this->availableSlots.top());
        this->availableSlots.pop();
    }

    return slotAvailable;
}

void ParkingLotController::park(std::string carRegistrationNumber, std::string color) {
    Car carWaitingToPark = Car(carRegistrationNumber, color);

    if(this->isSlotAvailable()) {
        this->allotAvailableParkingSlot(carWaitingToPark);
    }

}

void ParkingLotController::allotAvailableParkingSlot(Car carReadyToPark) {
    int firstAvailableSlot = this->availableSlots.top();

    this->cars.insert(std::make_pair(firstAvailableSlot, carReadyToPark));

    this->availableSlots.pop();

    Slot allotedSlot = Slot(firstAvailableSlot);
}


