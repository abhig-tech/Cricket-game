#pragma once
#include <scoreboard.h>

class match{
    double overs;
    team *T1;
    team *T2;
    umpire *ump;
    public:
    match(team &t1, team &t2, double ov, umpire &umpi);
    void match_starts();
    static void match_details(int n,vector <team> &teamList);
    static int teamCount();
    static int matchCount();
};