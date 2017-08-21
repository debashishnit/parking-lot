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

#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>

class ParkingLotController {
private:

public:
    std::unordered_map<int, Car> cars;
    std::priority_queue<int, std::vector<int>, std::greater<int> > availableSlots;

    ParkingLotController(int);
    virtual ~ParkingLotController();

    void park(std::string, std::string);
    bool isSlotAvailable();
    void allotAvailableParkingSlot(Car);

    std::vector<int> getAvailableSlots();

    void releaseSlot(int);

};

#endif /* PARKINGLOTCONTROLLER_H_ */
