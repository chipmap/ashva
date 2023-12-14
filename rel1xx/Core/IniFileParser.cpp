// Copyright (c) 2023 Vrund Patel

#include <iostream>
#include <fstream>
#include <string>
#include <map>

#include "IniFileParser.hpp"

#define whitespace " \t\n\r"

typedef std::pair<std::string, KvMap> IniPair;
typedef std::pair<std::string, std::string> KvPair;

IniFileParser::~IniFileParser()
{

    std::cout << "\n";

}

/**
 * Prints data contained in entire .ini file after parsing
*/
void IniFileParser::PrintData()
{

    for (const IniPair& section : data_) {

        std::cout << "\n[" << section.first << "]\n";

        for (const KvPair& kv : section.second) {

            std::cout << kv.first << " = " << kv.second << "\n";

        }
        
    }

}

// reads and stores .ini file content
IniMap IniFileParser::parseFile(const std::string& filepath)
{

    IniMap data;

    std::ifstream file(filepath);

    if (!file.is_open()) {

        std::cerr << "Cannot read file.\n"; 

    } else {

        std::string line;
        std::string section;

        while (std::getline(file, line)) {

            line = processLine(line);

            if (line.empty()) {

                continue;
                
            } else if (multiLineEmpty_ == true) {

                multiLineEmpty_ = false;
                continue;

            } else if (line[0] == '[') {

                if (line.find(']') != std::string::npos) {

                    int endIdx = line.find(']');
                    section = line.substr(1, endIdx - 1);
                    section = processLine(section);

                } else {

                    if (line.back() == '\\') {

                        section = line.substr(1);
                        section = processMultiLine(file, section);

                        if (multiLineEmpty_ == true) {

                            multiLineEmpty_ = false;
                            std::cout << "Input .ini file has improper section header.\n";
                            exit(-1);

                        }

                        section.pop_back(); // remove extra ]
                        section = processLine(section);

                    } else {

                        std::cout << "Input .ini file has improper section header.\n";
                        exit(-1);

                    }

                }

            } else {

                std::array<std::string, 2> keyval = processKeyValLine(file, line);

                if (section == "") {

                    data["unspecified"][keyval[0]] = keyval[1];

                } else {
                    
                    data[section][keyval[0]] = keyval[1];

                }

            }

        }   

    }

    return data;

}

// processes line by removing whitespaces (leading and trailing) and comments
std::string IniFileParser::processLine(std::string& line) 
{

    line.erase(0, line.find_first_not_of(whitespace));
    line.erase(line.find_last_not_of(whitespace) + 1);

    if (line.find(';') != std::string::npos) {
        
        int scIdx = line.find(';');
        line.erase(scIdx);
        line = processLine(line);

    } else if (line.find('#') != std::string::npos) {

        int hashIdx = line.find('#');
        line.erase(hashIdx);
        line = processLine(line);

    }

    line = toLower(line);

    return line;

}

// processes multiple lines
std::string IniFileParser::processMultiLine(std::ifstream& file, std::string& line)
{

    while (line.back() == '\\') {

        line.pop_back();
        std::string newline;
        if(std::getline(file, newline)) {

            newline = processLine(newline);
            if (newline.empty()) {

                multiLineEmpty_ = true;
                break;

            }

            // newline = processLine(newline);
            line += newline;

        } else {

            break;

        }

    }

    return line;

}

// processes line(s) by storing key and value
std::array<std::string, 2> IniFileParser::processKeyValLine(std::ifstream& file , std::string& line)
{

    int equalIdx = line.find('=');

    std::string key = line.substr(0, equalIdx);
    key = processLine(key);

    std::string val = line.substr(equalIdx + 1);
    val = processLine(val);
    if (val.back() == '\\') {
        val = processMultiLine(file, val);
    }

    return {key, val};

}

// converts whole string to all lowercase
std::string IniFileParser::toLower(std::string& s)
{

    for (char& c : s) {

        c = std::tolower(c);
        
    }

    return s;

}

int main()
{

    std::string filepath = "./test.ini";
    IniFileParser testfile(filepath);
    testfile.PrintData();

    return 0;

}