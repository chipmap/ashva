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
        std::string processMultiLine(std::ifstream& file , std::string& line);
        std::array<std::string, 2> processKeyValLine(std::ifstream& file, std::string& line);
        std::string toLower(std::string& s);

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

        // std::string GetValue(const std::string& section, const std::string& key, const std::string& defaultValue)
        // {
        //     std::string retValue = defaultValue;
        //     if (data_.find(section) && data_.find(key)) {
        //         retValue = data_.get();
        //     }

        //     return retValue;
        // }

};