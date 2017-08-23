/*
 * ParkingQueryHelper.cpp
 *
 *  Created on: Aug 22, 2017
 *      Author: debashish.g
 */

#include "../includes/ParkingQueryHelper.h"

std::unordered_map<std::string, std::vector<std::string> > ParkingQueryHelper::colorRegistrationNumberMap;
std::unordered_map<std::string, std::vector<int> > ParkingQueryHelper::carColorSlotMap;
std::unordered_map<std::string, int> ParkingQueryHelper::registrationNumberSlotNumberMap;

ParkingQueryHelper::ParkingQueryHelper() {

}

ParkingQueryHelper::~ParkingQueryHelper() {

}

std::vector<std::string> ParkingQueryHelper::getRegistrationNumbersForCarsWithColor(std::string color) {
    std::vector<std::string> res;

    if(colorRegistrationNumberMap.find(color) != colorRegistrationNumberMap.end()) {
        res = colorRegistrationNumberMap[color];
    }

    return res;
}

int ParkingQueryHelper::getSlotNumberForRegistrationNumber(std::string registrationNumber) {
    if(registrationNumberSlotNumberMap.find(registrationNumber) != registrationNumberSlotNumberMap.end()) {
        return registrationNumberSlotNumberMap[registrationNumber];
    }

    return -1;
}

std::vector<int> ParkingQueryHelper::getSlotNumbersForCarsWithColor(std::string color) {
    std::vector<int> res;

    if(carColorSlotMap.find(color) != carColorSlotMap.end()) {
        res = carColorSlotMap[color];
    }

    return res;
}

void ParkingQueryHelper::addToCarColorSlotMap(Car carReadyToPark, Slot allocatedSlot) {
    std::vector<int> slotsAllocatedToCarsWithColor = carColorSlotMap[carReadyToPark.getColor()];

    slotsAllocatedToCarsWithColor.push_back(allocatedSlot.getSlotNumber());

    carColorSlotMap[carReadyToPark.getColor()] = slotsAllocatedToCarsWithColor;
}

void ParkingQueryHelper::addToColorRegistrationNumberMap(Car carReadyToPark) {
    std::vector<std::string> registrationNumberListForCarsWithColor = colorRegistrationNumberMap[carReadyToPark.getColor()];

    registrationNumberListForCarsWithColor.push_back(carReadyToPark.getRegistrationNumber());

    colorRegistrationNumberMap[carReadyToPark.getColor()] = registrationNumberListForCarsWithColor;
}

void ParkingQueryHelper::addToSlotNumberRegistrationNumberMap(Car carReadyToPark, Slot allotedSlot) {
    registrationNumberSlotNumberMap[carReadyToPark.getRegistrationNumber()] = allotedSlot.getSlotNumber();
}

void ParkingQueryHelper::deleteFromCarColorSlotMap(Car c, Slot s) {
    std::vector<int> slotsOccupiedByCarWithColor = carColorSlotMap[c.getColor()];

    slotsOccupiedByCarWithColor.erase(std::remove(slotsOccupiedByCarWithColor.begin(), slotsOccupiedByCarWithColor.end(), s.getSlotNumber()), slotsOccupiedByCarWithColor.end());

    carColorSlotMap[c.getColor()] = slotsOccupiedByCarWithColor;
}

void ParkingQueryHelper::deleteFromColorRegistrationNumberMap(Car c) {
    std::vector<std::string> registrationNumbersOfCarsWithColor = colorRegistrationNumberMap[c.getColor()];

    registrationNumbersOfCarsWithColor.erase(remove(registrationNumbersOfCarsWithColor.begin(), registrationNumbersOfCarsWithColor.end(), c.getRegistrationNumber()), registrationNumbersOfCarsWithColor.end());

    colorRegistrationNumberMap[c.getColor()] = registrationNumbersOfCarsWithColor;
}

void ParkingQueryHelper::deleteFromSlotNumberRegistrationNumberMap(Car c) {
    if(registrationNumberSlotNumberMap.find(c.getRegistrationNumber()) != registrationNumberSlotNumberMap.end()) {
        registrationNumberSlotNumberMap.erase(c.getRegistrationNumber());
    }
}
