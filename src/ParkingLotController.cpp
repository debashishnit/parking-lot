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

std::vector<int> ParkingLotController::getAvailableSlots() {
    std::vector<int> slotAvailable;
    while(!this->availableSlots.empty()) {
        slotAvailable.push_back(this->availableSlots.top());
        this->availableSlots.pop();
    }

    return slotAvailable;
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

    return firstAvailableSlot;
}

std::vector<std::string> ParkingLotController::getRegistrationNumbersForCarsWithColor(std::string color) {
    return ParkingQueryHelper::getRegistrationNumbersForCarsWithColor(color);
}

std::vector<int> ParkingLotController::getSlotNumbersForCarsWithColor(std::string color) {
    return ParkingQueryHelper::getSlotNumbersForCarsWithColor(color);
}

bool ParkingLotController::releaseSlot(int slotNumber) {
    std::unordered_map<int, Car>::iterator it;

    if(this->cars.find(slotNumber) != this->cars.end()) {
        it = this->cars.find(slotNumber);

        this->availableSlots.push(slotNumber);

        ParkingQueryHelper::deleteFromCarColorSlotMap((*it).second , Slot(slotNumber));

        ParkingQueryHelper::deleteFromColorRegistrationNumberMap((*it).second);

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
