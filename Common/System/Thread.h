// Copyright (c) 2023 Chirag Patel चिराग: Veejansh Inc.
//
#pragma once

#include <string>
#include <thread>

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

public:
    static void Sleep()
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
};
