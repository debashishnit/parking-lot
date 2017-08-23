
#include <iostream>

#include "../includes/Utilities.h"


int main(int argc, char const *argv[]){

    Utilities::Initialize();

    const char* * argV = nullptr;
    Utilities::runAllTests(0,argV);

    if ( argc > 1 )
    {
        std::ifstream the_file ( argv[1] );
        if ( !the_file.is_open() )
             std::cout<<"Could not open file\n";
        else {
         Utilities::readData( the_file );
       }
    }
    else
    {
        Utilities::readData(std::cin);
    }

    return 0;
}



