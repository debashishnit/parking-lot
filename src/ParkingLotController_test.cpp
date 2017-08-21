/*
 * ParkingLotController_test.cpp
 *
 *  Created on: Aug 22, 2017
 *      Author: debashish.g
 */

#include "../includes/ParkingLotController.h"

#include "cute.h"

class ParkingLotControllerTest {
public:
    ParkingLotControllerTest() {};
    void operator()() {
        ParkingLotController pc(6);

        //ASSERT_EQUAL(true , pc.isSlotAvailable());
        std::vector<int> allSlots = pc.getAvailableSlots();
        ASSERTM(" first available slot is correct" , allSlots[0] == 1);
        ASSERTM(" last  available slot is correct " , allSlots[5] == 6);
        ASSERTM(" number of avaialble slots is correct" , pc.cars.size() == 0);

        ParkingLotController pc1(6);
        pc1.park("KA-01-HH-9999", "White");

        //std::vector<int> allSlots1 = pc1.getAvailableSlots();
        ASSERTM(" first available slot is incorrect" , pc1.availableSlots.top() == 1);
        ASSERTM(" first available slot is correct now" , pc1.availableSlots.top() == 2);
        ASSERTM(" number of avaialble slots is correct" , pc1.cars.size() == 0);

        std::unordered_map<int, Car>::iterator it;
        it = pc1.cars.find(1);
        ASSERTM(" first car color" , it->second.getColor().compare("White") == 0);
        ASSERTM(" first car color" , it->second.getRegistrationNumber().compare("KA-01-HH-9999") == 0);
    };
};
