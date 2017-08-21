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

        ParkingLotController pc1(6);
        pc1.park("KA-01-HH-9999", "White");

        std::vector<int> slotsOccupiedByCarWithColor;
        slotsOccupiedByCarWithColor = pc1.getSlotNumbersForCarsWithColor("White");
        ASSERTM(" occupied slot is correct " , slotsOccupiedByCarWithColor[0] == 1);

        std::vector<std::string> registrationNumberForCarsWithColor;
        registrationNumberForCarsWithColor = pc1.getRegistrationNumbersForCarsWithColor("White");
        ASSERTM(" occupied registration number is " , registrationNumberForCarsWithColor[0].compare("KA-01-HH-9999") == 0);
    };
};
