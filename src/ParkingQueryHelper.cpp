/*
 * ParkingQueryHelper.cpp
 *
 *  Created on: Aug 22, 2017
 *      Author: debashish.g
 */

#include "../includes/ParkingQueryHelper.h"

#include <iostream>

std::unordered_map<std::string, std::vector<std::string> > ParkingQueryHelper::colorRegistrationNumberMap;
std::unordered_map<std::string, std::vector<int> > ParkingQueryHelper::carColorSlotMap;

ParkingQueryHelper::ParkingQueryHelper() {
    // TODO Auto-generated constructor stub

}

ParkingQueryHelper::~ParkingQueryHelper() {
    // TODO Auto-generated destructor stub
}

std::vector<std::string> ParkingQueryHelper::getRegistrationNumbersForCarsWithColor(std::string color) {
    std::vector<std::string> res;

    if(colorRegistrationNumberMap.find(color) != colorRegistrationNumberMap.end()) {
        res = colorRegistrationNumberMap[color];
    }

    return res;
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
