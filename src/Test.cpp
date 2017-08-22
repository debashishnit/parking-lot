#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"

#include <iostream>

#include "Slot_test.cpp"
#include "Car_test.cpp"
#include "ParkingLotController_test.cpp"


void readData(std::istream & file) {
    std::string line;
    while(getline(file, line)) {
        std::string cmd, token;
        std::vector<char *> args;
        std::istringstream iss(cmd);

        while(iss >> token) {
            char *arg = new char[token.size() + 1];
            copy(token.begin(), token.end(), arg);
            arg[token.size()] = '\0';
            args.push_back(arg);
        }

        ParkingLotController pc;

        switch (cmd) {
            case 'create_parking_lot':

                break;
            default:
                break;
        }

    }

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



