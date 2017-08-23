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
    ParkingLotController();
    ParkingLotController(int);
    virtual ~ParkingLotController();

    bool isSlotAvailable();

    int park(std::string, std::string);

    int allotAvailableParkingSlot(Car);
    bool releaseSlot(int);

    void showStatus();
};

#endif /* PARKINGLOTCONTROLLER_H_ */
