#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"

#include <iostream>
#include <unordered_map>
#include <algorithm>

#include "Slot_test.cpp"
#include "Car_test.cpp"
#include "ParkingLotController_test.cpp"

enum CommandValue { cmdNotDefined,
                           cmdCreateParkingLot,
                           cmdPark,
                           cmdleave,
                           cmdStatus,
                           cmdRegistrationNumbersForCarsWithColor,
                           cmdSlotNumbersForCarsWithColor,
                           cmdSlotNumberForRegistrationNumber,
                           cmdEnd
                        };

std::unordered_map<std::string, CommandValue> s_mapCommandValues;

void readData(std::istream & file) {
    ParkingLotController pc;

    std::string line;
    while(getline(file, line)) {
        std::string cmd, token;
        std::vector<char *> args;
        std::istringstream iss(line);

        if(iss >> cmd){
            while(iss >> token) {
                char *arg = new char[token.size() + 1];
                copy(token.begin(), token.end(), arg);
                arg[token.size()] = '\0';
                args.push_back(arg);
            }
        }

        std::cout << cmd << std::endl;
        switch (s_mapCommandValues[cmd]) {
            case cmdCreateParkingLot: {
                int n = std::stoi(args[0]);
                pc = ParkingLotController(n);
                std::cout << "Created a parking lot with " << n << " slots." << std::endl;
                break;
            }
            case cmdPark: {
                std::string registrationNumber = args[0];
                std::string color = args[1];
                std::cout << registrationNumber << " " << color << std::endl;
                int allotedSlot = pc.park(registrationNumber, color);
                if(allotedSlot > 0)
                    std::cout << "Allocated slot number: " << allotedSlot << std::endl;
                else
                    std::cout << "Sorry, parking lot is full" << std::endl;
                break;
            }
            default:
                break;
        }

    }

}

void Initialize() {
    s_mapCommandValues["create_parking_lot"] = cmdCreateParkingLot;
    s_mapCommandValues["park"] = cmdPark;
    s_mapCommandValues["leave"] = cmdleave;
    s_mapCommandValues["status"] = cmdStatus;
    s_mapCommandValues["registration_numbers_for_cars_with_colour"] = cmdRegistrationNumbersForCarsWithColor;
    s_mapCommandValues["slot_numbers_for_cars_with_colour"] = cmdSlotNumbersForCarsWithColor;
    s_mapCommandValues["slot_number_for_registration_number"] = cmdSlotNumberForRegistrationNumber;
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

    Initialize();

    runAllTests(argc,argv);

    if ( argc > 1 )
    {
        std::ifstream the_file ( argv[1] );
        if ( !the_file.is_open() )
             std::cout<<"Could not open file\n";
        else {
         readData( the_file );
       }
    }
    else
    {
        // No input file has been passed in the command line.
        // Read the data from stdin (std::cin).
        readData(std::cin);
    }

    return 0;
}



