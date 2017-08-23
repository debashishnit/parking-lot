#include <iostream>
#include <sstream>
#include <unordered_map>
#include <algorithm>

#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include "../includes/ParkingLotController.h"

#include "../src/Slot_test.cpp"
#include "../src/Car_test.cpp"
#include "../src/ParkingLotController_test.cpp"

#ifndef SRC_UTILITIES_H_
#define SRC_UTILITIES_H_

class Utilities {
private:
public:
    enum CommandValue{ cmdNotDefined,
                       cmdCreateParkingLot,
                       cmdPark,
                       cmdleave,
                       cmdStatus,
                       cmdRegistrationNumbersForCarsWithColor,
                       cmdSlotNumbersForCarsWithColor,
                       cmdSlotNumberForRegistrationNumber,
                       cmdEnd
                     };
    static enum CommandValue commandValue;
    static std::unordered_map<std::string, CommandValue> s_mapCommandValues;

    Utilities();
    virtual ~Utilities();

    static void Initialize();
    static void readData(std::istream &);
    static void runAllTests(int, char const **);

};

#endif
