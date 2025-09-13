#include<iostream>
#include <umpire.h>

umpire::umpire(string n):person(n){}
void umpire::action(){
    cout<<getName()<<" is umpiring";
}