// Copyright (c) 2023 Chirag Patel चिराग: Veejansh Inc.
//
#pragma once

#include <string>

#include <System/Lock.h>

/**
 * Service class comprising of multiple resources
*/
class Service
{
protected:
    // name of the service
    std::string mName;
    // resource lock
    Lock mLock;
    // service thread
    std::thread mThread;
};
