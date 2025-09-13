#include <specialization.h>
#include <iostream>
using namespace std;

Batsman::Batsman(string n):player(n){}

void Batsman::printStats(){
    cout<<"Batsman & Fielder";
}

Bowler::Bowler(string n):player(n){}

void Bowler::printStats(){
    cout<<"Bowler & Fielder";
}

AllRounder::AllRounder(string n):player(n){}

void AllRounder::printStats(){
    cout<<"AllRounder";
}

Wbat::Wbat(string n):player(n){}

void Wbat::printStats(){
    cout<<"WicketKeeper Batsman";
}
