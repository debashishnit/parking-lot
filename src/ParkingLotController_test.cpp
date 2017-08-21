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

    };
};
