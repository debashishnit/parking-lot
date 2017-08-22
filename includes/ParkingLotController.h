/*
 * ParkingLotController.h
 *
 *  Created on: Aug 22, 2017
 *      Author: debashish.g
 */

#ifndef PARKINGLOTCONTROLLER_H_
#define PARKINGLOTCONTROLLER_H_

#include "../includes/Car.h"
#include "../includes/Slot.h"
#include "../includes/ParkingQueryHelper.h"

#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>

class ParkingLotController {
private:
    std::unordered_map<int, Car> cars;
    std::priority_queue<int, std::vector<int>, std::greater<int> > availableSlots;
public:
    ParkingLotController(int);
    virtual ~ParkingLotController();

    void park(std::string, std::string);
    bool isSlotAvailable();
    void allotAvailableParkingSlot(Car);

    std::vector<int> getAvailableSlots();

    static std::vector<std::string> getRegistrationNumbersForCarsWithColor(std::string);
    static std::vector<int> getSlotNumbersForCarsWithColor(std::string);

    void releaseSlot(int);

};

#endif /* PARKINGLOTCONTROLLER_H_ */