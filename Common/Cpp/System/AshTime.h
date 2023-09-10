// Copyright (c) 2023 Chirag Patel चिराग: Veejansh Inc.
//
// Wrapper class for system time/clock/calendar
#pragma once

#include <chrono>
#include <ctime>

typedef std::chrono::time_point TimePoint;
typedef std::chrono::system_clock SystemClock;

// Main class
class SystemTime
{
private:
    // time object
    TimePoint mTimePoint;

    // copy ctor
    SystemTime(const SystemTime&) = delete;
    // assignment operator
    SystemTime& operator = (const SystemTime&) = delete;

public:
    // converts internal time object to time_t structure
    static std::time_t ToTimeT(const SystemTime& systemTime)
    {
        return SystemClock::to_time_t(systemTime.mTimePoint);
    }

    // returns difference in nanoseconds between two times A - B
    static TimePoint Diff(const SystemTime& systemTimeA, const SystemTime& systemTimeB)
    {
        return systemTimeA.mTimePoint - systemTimeB.mTimePoint;
    }

    // returns formatted string from time
    static std::string ToString(const SystemTime& systemTime)
    {
        std::time_t tmt = SystemTime::ToTimeT(systemTime);
        std::tm tm = *std::localtime(&tmt);
        // 2023 Aug 06 Sun 20:14:01
        return std::string(std::put_time(&tm, "%Y %b %d %a %H:%M:%S"));
    }

    // default ctor, sets current time right away
    SystemTime()
    {
        mTimePoint = SystemClock::now();
    }

    // ctor that takes time point object
    SystemTime(const TimePoint& timePoint)
    : mTimePoint(timePoint)
    {
    }

    // ctor that takes time_t structure to set internal timer object
    SystemTime(const std::time_t tm)
    {
        mTimePoint = SystemClock::from_time_t(tm);
    }

    // Set time to now again
    void Now()
    {
        mTimePoint = SystemClock::now();
    }

};
