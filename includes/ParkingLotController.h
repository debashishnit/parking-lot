
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

    int allocateSlot(std::string, std::string);
    bool releaseSlot(int);

    void showStatus();
};

#endif
