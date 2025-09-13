#pragma once
#include <player.h>
using namespace std;

class Batsman:public player{
    public:
    Batsman(string n);
    void printStats();
};
class Bowler:public player{
    public:
    Bowler(string n);
    void printStats();
};
class AllRounder:public player{
    public:
    AllRounder(string n);
    void printStats();
};
class Wbat:public player{
    public:
    Wbat(string n);
    void printStats();
};
