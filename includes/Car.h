/*
 * Car.h
 *
 *  Created on: Aug 22, 2017
 *      Author: debashish.g
 */


#ifndef CAR_H_
#define CAR_H_

#include <string>
#include <algorithm>

class Car {
private:
    std::string color;
    std::string registrationNumber;
public:
    Car(std::string, std::string);
    virtual ~Car();

    std::string getColor();
    std::string getRegistrationNumber();
};

#endif /* CAR_H_ */
