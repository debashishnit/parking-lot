/*
 * ParkingLotController_test.cpp
 *
 *  Created on: Aug 22, 2017
 *      Author: debashish.g
 */

#include "../includes/ParkingLotController.h"

#include "cute.h"
#include <iostream>

class ParkingLotControllerTest {
public:
    ParkingLotControllerTest() {};
    void operator()() {
        ParkingLotController pc(6);

        std::vector<int> allSlots = pc.getAvailableSlots();
        ASSERTM(" first available slot is correct" , allSlots[0] == 1);
        ASSERTM(" last  available slot is correct " , allSlots[5] == 6);

        ParkingLotController pc1(6);

        std::vector<int> slotsOccupiedByCarWithColor;
        //slotsOccupiedByCarWithColor = pc1.getSlotNumbersForCarsWithColor("White");
        //ASSERTM(" occupied slot is correct " , slotsOccupiedByCarWithColor[0] == 1);

        std::vector<std::string> registrationNumberForCarsWithColor;
        //registrationNumberForCarsWithColor = pc1.getRegistrationNumbersForCarsWithColor("White");
        //ASSERTM(" occupied registration number is " , registrationNumberForCarsWithColor[0].compare("KA-01-HH-9999") == 0);

        bool succ = false;

        succ = pc1.park("KA-01-HH-9969", "White");
        succ = pc1.park("KA-01-HH-9979", "Black");
        succ = pc1.park("KA-01-HH-9989", "Blue");
        succ = pc1.park("KA-01-HH-9994", "Red");
        succ = pc1.park("KA-01-HH-9991", "Blue");
        succ = pc1.park("KA-01-HH-9996", "Blue");

        succ = pc1.park("KA-01-HH-9926", "White");

        ASSERTM(" add successfully done " , succ == false);

        registrationNumberForCarsWithColor = pc1.getRegistrationNumbersForCarsWithColor("White");
        ASSERTM(" occupied registration number is " , registrationNumberForCarsWithColor[0].compare("KA-01-HH-9999") == 0);

        succ = pc1.releaseSlot(3);
        succ = pc1.releaseSlot(4);
        succ = pc1.releaseSlot(1);
        succ = pc1.releaseSlot(2);
        succ = pc1.releaseSlot(5);
        succ = pc1.releaseSlot(6);

        succ = pc1.releaseSlot(6);
        ASSERTM(" deletion successfully done ", succ == true);

        slotsOccupiedByCarWithColor = pc1.getSlotNumbersForCarsWithColor("Blue");
        int n = slotsOccupiedByCarWithColor.size();
        ASSERTM(" first occupied slot for color blue is correct " , slotsOccupiedByCarWithColor[0] == 4);
        ASSERTM(" last occupied slot for color blue is correct " , slotsOccupiedByCarWithColor[n-1] == 6);

        registrationNumberForCarsWithColor = pc1.getRegistrationNumbersForCarsWithColor("White");
        //ASSERTM(" first registration number car with color Black is " , registrationNumberForCarsWithColor[0].compare("KA-01-HH-9979") == 0);
        ASSERTM(" last registration number car with color White is " , registrationNumberForCarsWithColor[0].compare("KA-01-HH-9999") == 0);

    };
};
