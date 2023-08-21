// Copyright (c) 2023 Chirag Patel चिराग: Veejansh Inc.
//
#pragma once

#include <string>
#include <chrono>

#include <System/Lock.h>

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
private:
    // Name of the trace object
    std::string mName;
    // Default log level
    LogLevel mDefaultLogLevel;
    // Shared resource lock
    Lock mLock;

    // Default ctor
    Trace() = delete;
    // Copy ctor
    Trace(const Trace&) = delete;
    // Assignment otor
    Trace& operator = (const Trace&) = delete;

public:
    // ctor
    Trace(std::string name, LogLevel defaultLevel);
    // dtor
    ~Trace();

    // Changes current default log level
    void SetDefaultLogLevel(LogLevel newLevel)
    {
        LockGuard guard(mLock);
        mDefaultLogLevel = newLevel;
    }

    // Gets current default log level
    LogLevel GetDefaultLogLevel() { return mDefaultLogLevel; }

};
