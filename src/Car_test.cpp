
#include "cute.h"
#include "../includes/Car.h"

class CarTest {
public:
    CarTest() {};
    void operator()() {
        Car car("abdefgh", "black");

        ASSERTM("wrong constructor color", car.getColor().compare("black") == 0);
        ASSERTM("wrong constructor registration", car.getRegistrationNumber().compare("abdefgh") == 0);
    };
};

