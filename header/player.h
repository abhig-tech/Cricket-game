#pragma once
#include <person.h>
class match;
class player:public person{
    friend class match;
    friend class scoreboard;
    int runs;
    public:
    player(string n);
    virtual void printStats()=0;
    virtual ~player();
};