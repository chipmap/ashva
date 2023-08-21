// Copyright (c) 2023 Chirag Patel चिराग: Veejansh Inc.
//
// All trace and logging sub-system utility class
#pragma once

#include <string>
#include <chrono>

// Log level enumeration
enum LogLevel
{
    Off = 0,
    Debug = 1,
    Info = 2,
    Warning = 3
};

// Header used by every trace entry
struct TraceHeader
{
    std::string name;
    LogLevel level;
    std::chrono::time_point createTime;
    std::chrono::time_point logTime;
};

/**
 * Trace wrapper
*/
class Trace
{

};
