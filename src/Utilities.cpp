
#include "../includes/Utilities.h"

enum Utilities::CommandValue Utilities::commandValue;

std::unordered_map<std::string, Utilities::CommandValue> Utilities::s_mapCommandValues;

Utilities::Utilities() {


}

Utilities::~Utilities() {

}

void Utilities::readData(std::istream & file) {
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

                int allotedSlot = pc.allocateSlot(registrationNumber, color);
                if(allotedSlot > 0)
                    std::cout << "Allocated slot number: " << allotedSlot << std::endl;
                else
                    std::cout << "Sorry, parking lot is full" << std::endl;
                break;
            }
            case cmdleave: {
                int slotNumber = std::stoi(args[0]);
                if(pc.releaseSlot(slotNumber))
                    std::cout << "Slot number " << slotNumber << " is free." << std::endl;
                break;
            }
            case cmdStatus: {
                pc.showStatus();
                break;
            }
            case cmdRegistrationNumbersForCarsWithColor: {
                std::vector<std::string> registrationNumberList;
                registrationNumberList = ParkingQueryHelper::getRegistrationNumbersForCarsWithColor(args[0]);
                std::string result = "";
                for(int i=0; i<registrationNumberList.size(); i++) {
                    if(result != "") result += ", ";

                    result += registrationNumberList[i];
                }
                std::cout << result << std::endl;
                break;
            }
            case cmdSlotNumbersForCarsWithColor: {
                std::vector<int> slotNumbers;
                slotNumbers = ParkingQueryHelper::getSlotNumbersForCarsWithColor(args[0]);
                std::string result = "";
                for(int i=0; i<slotNumbers.size(); i++) {
                    if(result != "") result += ", ";

                    result += std::to_string(slotNumbers[i]) ;
                }
                std::cout << result << std::endl;
                break;
            }
            case cmdSlotNumberForRegistrationNumber: {
                int slotNumber = -1;

                if((slotNumber = ParkingQueryHelper::getSlotNumberForRegistrationNumber(args[0])) > 0) {
                    std::cout << std::to_string(slotNumber) << std::endl;
                } else {
                    std::cout << "Not Found." << std::endl;
                }
                break;
            }
            default: {
                break;
            }
        }

    }

}

void Utilities::Initialize() {
    s_mapCommandValues["create_parking_lot"] = cmdCreateParkingLot;
    s_mapCommandValues["park"] = cmdPark;
    s_mapCommandValues["leave"] = cmdleave;
    s_mapCommandValues["status"] = cmdStatus;
    s_mapCommandValues["registration_numbers_for_cars_with_colour"] = cmdRegistrationNumbersForCarsWithColor;
    s_mapCommandValues["slot_numbers_for_cars_with_colour"] = cmdSlotNumbersForCarsWithColor;
    s_mapCommandValues["slot_number_for_registration_number"] = cmdSlotNumberForRegistrationNumber;
}

void Utilities::runAllTests(int argc, char const *argv[]){
    cute::suite s;
    //TODO add your test here
    s.push_back(SlotTest());
    s.push_back(CarTest());
    s.push_back(ParkingLotControllerTest());
    cute::xml_file_opener xmlfile(argc,argv);
    cute::xml_listener<cute::ide_listener<> >  lis(xmlfile.out);
    cute::makeRunner(lis,argc,argv)(s, "AllTests");
}

