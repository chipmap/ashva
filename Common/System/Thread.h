// Copyright (c) 2023 Chirag Patel चिराग: Veejansh Inc.
//
#pragma once

#include <string>
#include <thread>

#include <Helper/Type.h>

/**
 * Thread wrapper class
*/
class Thread
{
private:
    // default ctor
    Thread() = delete;
    // copy ctor
    Thread(const Thread&) = delete;
    // assignment otor
    Thread& operator = (const Thread&) = delete;

protected:
    // C++ thread object
    std::thread mThread;
    // User specified name of the thread
    std::string mName;

public:
    // Sleep for milliseconds
    static void SleepMillis(au32 millis)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(millis));
    }
};
