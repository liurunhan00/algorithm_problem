#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <mutex>

using namespace std;

class RWLock {
public:
    RWLock() : rcnt(0){}
    ~RWLock(){}

    void rlock()
    {
        std::lock_guard<mutex> l_g(rmtx);
        if(++rcnt == 1)
        {
            wmtx.lock();
        }
    }

    void runlock()
    {
        std::lock_guard<mutex> l_g(rmtx);
        if(--rcnt == 0)
        {
            wmtx.unlock();
        }
    }

    void wlock()
    {
        wmtx.lock();
    }

    void wunlock()
    {
        wmtx.unlock();
    }

private:
    mutex rmtx;
    mutex wmtx;
    int rcnt;
};

volatile int var = 10;
RWLock rwLock;
mutex showLock;

void Write()
{
    rwLock.wlock();
    var += 10;
    std::unique_lock<mutex> u_l(showLock);
    cout << "write var: " << var << endl;
    rwLock.wunlock();
}

void Read()
{
    rwLock.rlock();
    std::unique_lock<mutex> u_l(showLock);
    cout << "read var: " << var << endl;
    rwLock.runlock();
}


