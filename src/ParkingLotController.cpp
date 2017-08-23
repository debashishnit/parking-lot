/*
 * ParkingLotController.cpp
 *
 *  Created on: Aug 22, 2017
 *      Author: debashish.g
 */

#include "../includes/ParkingLotController.h"

#include <iostream>

ParkingLotController::ParkingLotController() {
    // TODO Auto-generated constructor stub
}

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

int ParkingLotController::park(std::string carRegistrationNumber, std::string color) {
    Car carWaitingToPark = Car(carRegistrationNumber, color);

    if(this->isSlotAvailable()) {
        int allotedSlot = this->allotAvailableParkingSlot(carWaitingToPark);

        return allotedSlot;
    }

    return -1;
}

int ParkingLotController::allotAvailableParkingSlot(Car carReadyToPark) {
    int firstAvailableSlot = this->availableSlots.top();

    this->cars.insert(std::make_pair(firstAvailableSlot, carReadyToPark));

    this->availableSlots.pop();

    Slot allotedSlot = Slot(firstAvailableSlot);

    ParkingQueryHelper::addToCarColorSlotMap(carReadyToPark, allotedSlot);

    ParkingQueryHelper::addToColorRegistrationNumberMap(carReadyToPark);

    ParkingQueryHelper::addToSlotNumberRegistrationNumberMap(carReadyToPark, allotedSlot);

    return firstAvailableSlot;
}

bool ParkingLotController::releaseSlot(int slotNumber) {
    std::unordered_map<int, Car>::iterator it;

    if(this->cars.find(slotNumber) != this->cars.end()) {
        it = this->cars.find(slotNumber);

        this->availableSlots.push(slotNumber);

        ParkingQueryHelper::deleteFromCarColorSlotMap((*it).second , Slot(slotNumber));

        ParkingQueryHelper::deleteFromColorRegistrationNumberMap((*it).second);

        ParkingQueryHelper::deleteFromSlotNumberRegistrationNumberMap((*it).second);

        this->cars.erase((*it).first);

        return true;
    }

    return false;
}


void ParkingLotController::showStatus() {
    std::unordered_map<int, Car> cars = this->cars;

    if(cars.size() == 0) std::cout << "empty " << std::endl;
    else{
        std::cout << "Slot No.    " << "Registration No.    " << "Colour" << std::endl;
        for(std::unordered_map<int,Car>::iterator it=cars.begin(); it != cars.end(); it++){

            std::cout << it->first << "            " << it->second.getRegistrationNumber() << "       " << it->second.getColor() << std::endl;

        }
    }

}
