// Copyright (c) 2023 Vrund Patel

#include <iostream>
#include <string>

#include "../Core/IniFileParser.hpp"

int main(int argc, char* argv[])
{

    if (argc > 1) {

        IniFileParser testFile(argv[1]);
        testFile.PrintData();

    } else {

        std::cout << "Provide file name with path\n";
        
    }
    return 0;

}