// Copyright (c) 2023 Vrund Patel

#include <iostream>
#include <string>

#include "../Core/IniFileParser.hpp"

int main()
{

    std::string filepath = "./test.ini";
    IniFileParser testfile(filepath);
    testfile.PrintData();

    return 0;

}