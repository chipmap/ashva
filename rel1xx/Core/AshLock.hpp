// Copyright (c) 2023 Chirag Patel चिराग: Veejansh Inc.
//
#pragma once

#include <string>
#include <mutex>

/**
 * Lock wrapper class
*/
class AshLock
{
private:
    // mutex object
    std::mutex mMutex;

    // copy ctor
    AshLock(const AshLock&) = delete;
    // assignment otor
    AshLock& operator = (const AshLock&) = delete;

public:
    // default ctor
    AshLock()
    {
    }

    // dtor
    ~AshLock()
    {
    }
};

/**
 * Lock guard wrapper class
*/
class AshLockGuard
{
private:
    // guard object
    AshLock* mLock;

    // default ctor
    AshLockGuard() = delete;
    // copy ctor
    AshLockGuard(const AshLockGuard&) = delete;
    // assignment otor
    AshLockGuard& operator = (const AshLockGuard&) = delete;

public:
    // ctor
    AshLockGuard(AshLock* lock)
    : mLock(lock)
    {
    }

    // dtor
    ~AshLockGuard()
    {
    }
};
