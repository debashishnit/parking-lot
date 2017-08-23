
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

#endif
