/*
 * ParkingQueryHelper.h
 *
 *  Created on: Aug 22, 2017
 *      Author: debashish.g
 */

#ifndef PARKINGQUERYHELPER_H_
#define PARKINGQUERYHELPER_H_

#include <unordered_map>
#include <vector>
#include <algorithm>

#include "Car.h"
#include "Slot.h"

class ParkingQueryHelper {
private:
    ParkingQueryHelper();
    virtual ~ParkingQueryHelper();

    static std::unordered_map<std::string, std::vector<std::string> > colorRegistrationNumberMap;
    static std::unordered_map<std::string, std::vector<int> > carColorSlotMap;
    static std::unordered_map<std::string, int> registrationNumberSlotNumberMap;
public:
    static std::vector<std::string> getRegistrationNumbersForCarsWithColor(std::string);
    static std::vector<int> getSlotNumbersForCarsWithColor(std::string);
    static int getSlotNumberForRegistrationNumber(std::string);

    static void addToCarColorSlotMap(Car, Slot);
    static void addToColorRegistrationNumberMap(Car);
    static void addToSlotNumberRegistrationNumberMap(Car, Slot);

    static void deleteFromCarColorSlotMap(Car, Slot);
    static void deleteFromColorRegistrationNumberMap(Car);
    static void deleteFromSlotNumberRegistrationNumberMap(Car);
};

#endif /* PARKINGQUERYHELPER_H_ */
