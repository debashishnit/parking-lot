
#include "../includes/ParkingLotController.h"

#include <iostream>

ParkingLotController::ParkingLotController() {

}

ParkingLotController::ParkingLotController(int maxSlots) {

    for(int availableSlot=1; availableSlot<=maxSlots; availableSlot++) {
        this->availableSlots.push(availableSlot);
    }

}

ParkingLotController::~ParkingLotController() {

}

bool ParkingLotController::isSlotAvailable() {
    return !this->availableSlots.empty() ;
}

int ParkingLotController::allocateSlot(std::string carRegistrationNumber, std::string color) {
    Car carReadyToPark = Car(carRegistrationNumber, color);

    if(this->isSlotAvailable()) {
        int firstAvailableSlot = this->availableSlots.top();

        this->cars.insert(std::make_pair(firstAvailableSlot, carReadyToPark));

        this->availableSlots.pop();

        Slot allotedSlot = Slot(firstAvailableSlot);

        ParkingQueryHelper::addToCarColorSlotMap(carReadyToPark, allotedSlot);

        ParkingQueryHelper::addToColorRegistrationNumberMap(carReadyToPark);

        ParkingQueryHelper::addToSlotNumberRegistrationNumberMap(carReadyToPark, allotedSlot);

        return firstAvailableSlot;
    }

    return -1;

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
