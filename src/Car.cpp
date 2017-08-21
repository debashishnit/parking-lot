/*
 * Car.cpp
 *
 *  Created on: Aug 22, 2017
 *      Author: debashish.g
 */

#include "../includes/Car.h"

Car::Car(std::string registrationNumber, std::string color) {
    // TODO Auto-generated constructor stub
    this->color = color;
    this->registrationNumber = registrationNumber;
}

Car::~Car() {
    // TODO Auto-generated destructor stub
}

std::string Car::getColor() {
    return this->color;
}

std::string Car::getRegistrationNumber() {
    return this->registrationNumber;
}


