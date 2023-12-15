// Copyright (c) 2023 Vrund Patel

#pragma once

#include <string>
#include <map>

typedef std::map<std::string, std::string> KvMap;
typedef std::map<std::string, KvMap> IniMap;

class IniFileParser
{

    private:

        std::string filepath_;
        IniMap data_;
        bool multiLineEmpty_ = false;

    private:

        IniMap parseFile(const std::string& filepath);
        std::string processLine(std::string& line);
        std::string processMultiLine(std::ifstream& file, std::string& line);
        std::array<std::string, 2> processKeyValLine(std::ifstream& file, std::string& line);
        void trace(const char* format, ...);

        // converts whole string to all lowercase
        std::string toLower(std::string& s)
        {

            for (char& c : s) {

                c = std::tolower(c);
                
            }

            return s;

        }

        // checks if value exists in parsed data and returns it
        bool findValue(const std::string& section, const std::string& key, std::string& retValue)
        {

            bool found = false;

            IniMap::iterator ini = data_.find(section);
            if (ini != data_.end()) {

                KvMap::iterator kvi = ini->second.find(key);
                if (kvi != ini->second.end()) {

                    retValue = kvi->second;
                    found = true;

                }

            }

            return found;

        }

    public:

        IniFileParser() = delete;
        IniFileParser(const IniFileParser&) = delete;
        IniFileParser& operator = (const IniFileParser&) = delete;

        IniFileParser(std::string filepath)
        {

            filepath_ = filepath;
            data_ = parseFile(filepath_);

        }

        virtual ~IniFileParser();

        void PrintData();

        std::string GetValue(const std::string& section, const std::string& key, const std::string& defaultValue)
        {

            std::string retValue = defaultValue;
            findValue(section, key, retValue);
            return retValue;

        }

        int GetValue(const std::string& section, const std::string& key, const int defaultValue)
        {

            int retValue = defaultValue;
            std::string tempVal;
            if (findValue(section, key, tempVal)) {

                retValue = std::stoi(tempVal);

            }

            return retValue;

        }

        double GetValue(const std::string& section, const std::string& key, const double defaultValue)
        {

            double retValue = defaultValue;
            std::string tempVal;
            if (findValue(section, key, tempVal)) {

                retValue = std::stod(tempVal);

            }

            return retValue;

        }

        float GetValue(const std::string& section, const std::string& key, const float defaultValue)
        {

            float retValue = defaultValue;
            std::string tempVal;
            if (findValue(section, key, tempVal)) {

                retValue = std::stof(tempVal);
                
            }

            return retValue;

        }

        long GetValue(const std::string& section, const std::string& key, const long defaultValue)
        {

            long retValue = defaultValue;
            std::string tempVal;
            if (findValue(section, key, tempVal)) {

                retValue = std::stol(tempVal);
                
            }

            return retValue;

        }

};