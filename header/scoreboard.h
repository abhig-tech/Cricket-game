#pragma once
#include <specialization.h>
#include <umpire.h>
#include <team.h>
#include <unordered_map>

class scoreboard{
    public:
    static void player_stats(player*);
    static void match_Starts(team &t1, team &t2, umpire &ump);
    static void LiveScore(team &t1, string batting);
    static void innings_finished(team &t1,team &t2);
    static void match_finished(team &t1, team&t2);
};
