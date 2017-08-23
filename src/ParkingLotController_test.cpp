
#include "../includes/ParkingLotController.h"

#include "cute.h"
#include <iostream>

class ParkingLotControllerTest {
public:
    ParkingLotControllerTest() {};
    void operator()() {

        ParkingLotController pc1(6);

        std::vector<int> slotsOccupiedByCarWithColor;
        //slotsOccupiedByCarWithColor = pc1.getSlotNumbersForCarsWithColor("White");
        //ASSERTM(" occupied slot is correct " , slotsOccupiedByCarWithColor[0] == 1);

        std::vector<std::string> registrationNumberForCarsWithColor;
        //registrationNumberForCarsWithColor = pc1.getRegistrationNumbersForCarsWithColor("White");
        //ASSERTM(" occupied registration number is " , registrationNumberForCarsWithColor[0].compare("KA-01-HH-9999") == 0);

        int succ = 0;

        succ = pc1.allocateSlot("KA-01-HH-9969", "White");
        succ = pc1.allocateSlot("KA-01-HH-9979", "Black");
        succ = pc1.allocateSlot("KA-01-HH-9989", "Blue");
        succ = pc1.allocateSlot("KA-01-HH-9994", "Red");
        succ = pc1.allocateSlot("KA-01-HH-9991", "Blue");
        succ = pc1.allocateSlot("KA-01-HH-9996", "Blue");

        succ = pc1.allocateSlot("KA-01-HH-9926", "White");

        ASSERTM(" add successfully done " , succ == -1);

        registrationNumberForCarsWithColor = ParkingQueryHelper::getRegistrationNumbersForCarsWithColor("White");
        ASSERTM(" occupied registration number is " , registrationNumberForCarsWithColor[0].compare("KA-01-HH-9969") == 0);

        ASSERTM(" slot occupied by car with registration number KA-01-HH-9991 is correct" , ParkingQueryHelper::getSlotNumberForRegistrationNumber("KA-01-HH-9991") == 5);

        slotsOccupiedByCarWithColor = ParkingQueryHelper::getSlotNumbersForCarsWithColor("Blue");
        int n = slotsOccupiedByCarWithColor.size();
        ASSERTM(" first occupied slot for color blue is correct " , slotsOccupiedByCarWithColor[0] == 3);
        ASSERTM(" last occupied slot for color blue is correct " , slotsOccupiedByCarWithColor[n-1] == 6);

        registrationNumberForCarsWithColor = ParkingQueryHelper::getRegistrationNumbersForCarsWithColor("White");
        //ASSERTM(" first registration number car with color White is " , registrationNumberForCarsWithColor[0].compare("KA-01-HH-9979") == 0);
        ASSERTM(" last registration number car with color White is " , registrationNumberForCarsWithColor[0].compare("KA-01-HH-9969") == 0);

        registrationNumberForCarsWithColor = ParkingQueryHelper::getRegistrationNumbersForCarsWithColor("Blue");
        ASSERTM(" first registration number car with color Blue is " , registrationNumberForCarsWithColor[0].compare("KA-01-HH-9989") == 0);

        succ = pc1.releaseSlot(3);
        succ = pc1.releaseSlot(4);
        succ = pc1.releaseSlot(1);
        succ = pc1.releaseSlot(2);
        succ = pc1.releaseSlot(5);
        succ = pc1.releaseSlot(6);

        succ = pc1.releaseSlot(6);
        ASSERTM(" deletion successfully done ", succ == false);

    };
};
