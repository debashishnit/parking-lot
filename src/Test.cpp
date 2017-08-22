#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"

#include <iostream>

#include "Slot_test.cpp"
#include "Car_test.cpp"
#include "ParkingLotController_test.cpp"

void thisIsATest() {
    int sum = 2;
	ASSERTM("new msg", (sum == 2));

}

void runAllTests(int argc, char const *argv[]){
	cute::suite s;
	//TODO add your test here
	s.push_back(SlotTest());
	s.push_back(CarTest());
	s.push_back(ParkingLotControllerTest());
	cute::xml_file_opener xmlfile(argc,argv);
	cute::xml_listener<cute::ide_listener<> >  lis(xmlfile.out);
	cute::makeRunner(lis,argc,argv)(s, "AllTests");
}

int main(int argc, char const *argv[]){

    /*ParkingLotController p(6);

    p.park("KA-01-HH-1234", "White");
    p.park("KA-01-HH-9999", "White");
    p.park("KA-01-BB-0001", "Black");
    p.park("KA-01-HH-7777", "Red");
    p.park("KA-01-HH-2701", "Blue");
    p.park("KA-01-HH-3141", "Black");

    p.releaseSlot(3);
    p.releaseSlot(4);
    p.park("KA-01-HH-3143", "Lilac");
    p.status();

    p.releaseSlot(3);
    p.status();
    std::vector<int> reg = p.getSlotNumbersForCarsWithColor("Lilac");
    for(int i=0; i<reg.size();i++)
        std::cout << reg[i] << std::endl;

    p.park("KA-01-HH-2709", "White");
    p.park("KA-01-HH-2799", "White");

    std::vector<int> slots = p.getSlotNumbersForCarsWithColor("White");
    for(int i=0; i<slots.size(); i++)
        std::cout << slots[i] << std::endl;

    std::vector<std::string> reg1 = p.getRegistrationNumbersForCarsWithColor("White");
        for(int i=0; i<reg1.size(); i++)
            std::cout << reg1[i] << std::endl;*/
    runAllTests(argc,argv);
    return 0;
}



