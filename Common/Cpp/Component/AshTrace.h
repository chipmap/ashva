// Copyright (c) 2023 Chirag Patel चिराग: Veejansh Inc.
//
#pragma once

#include <string>
#include <chrono>

#include <System/AshLock.h>
#include <System/AshTime.h>

// Log level enumeration
enum AshLogLevel
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
    AshTime createTime;
    AshTime logTime;
};

/**
 * Trace wrapper
*/
class AshTrace
{
private:
    // Name of the trace object
    std::string mName;
    // Default log level
    AshLogLevel mDefaultLogLevel;
    // Shared resource lock
    AshLock mLock;

    // Default ctor
    AshTrace() = delete;
    // Copy ctor
    AshTrace(const AshTrace&) = delete;
    // Assignment otor
    AshTrace& operator = (const AshTrace&) = delete;

public:
    // ctor
    AshTrace(std::string name, LogLevel defaultLevel);
    // dtor
    virtual ~AshTrace();

    // Changes current default log level
    void SetDefaultLogLevel(AshLogLevel newLevel)
    {
        AshLockGuard guard(mLock);
        mDefaultLogLevel = newLevel;
    }

    // Gets current default log level
    AshLogLevel GetDefaultLogLevel() { return mDefaultLogLevel; }

};
