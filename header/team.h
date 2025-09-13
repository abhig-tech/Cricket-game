#pragma once
#include <vector>
#include<player.h>

class match;
class scoreboard;
class team{
    friend class match;
    friend class scoreboard;
    string name;
    vector <player*> playerList;
    int scores;
    int wickets;
    double overs;
    public:
    team(string name);
    string getName();
    void updateList(player*);
    void delPlayers();
    static void teamBuilder(team& obj, int n);
    static void teamListDesigner(vector<team> &teamList, int nTeams);
};