
#include "../includes/Car.h"

Car::Car(std::string registrationNumber, std::string color) {

    this->color = color;
    this->registrationNumber = registrationNumber;
}

Car::~Car() {

}

std::string Car::getColor() {
    return this->color;
}

std::string Car::getRegistrationNumber() {
    return this->registrationNumber;
}


