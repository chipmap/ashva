// Copyright (c) 2023 Chirag Patel चिराग: Veejansh Inc.
//
// Parent class for all services
#pragma once

#include <string>
#include <mutex>

class Service
{
protected:
    // name of the service
    std::string mName;
    // resource lock
    std::mutex mLock;
    // service thread
    std::thread mThread;
};
