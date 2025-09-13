#include <iostream>
#include <scoreboard.h>

void scoreboard::player_stats(player*){

}

void scoreboard::match_Starts(team &t1, team &t2, umpire &ump){
    cout<<endl<<t1.name<<" vs "<<t2.name<<endl<<t1.name<<" Batting first"<<endl;
    cout<<"*******************************************************************************"<<endl;
    ump.action();
    cout<<endl<<"*******************************************************************************"<<endl;
    cout<<t1.name<<" Player Stats"<<endl;
    for(int i=0;i<t1.playerList.size();i++){
        cout<<t1.playerList[i]->getName()<<" ";
        t1.playerList[i]->printStats();
        cout<<endl;
    }
    cout<<"*******************************************************************************"<<endl;
    cout<<t2.name<<" Player Stats"<<endl;
    for(int i=0;i<t2.playerList.size();i++){
        cout<<t2.playerList[i]->getName()<<" ";
        t2.playerList[i]->printStats();
        cout<<endl;
    }
    cout<<"*******************************************************************************"<<endl;
}

void scoreboard::LiveScore(team &t1, string batting){
    cout<<"*******************************************************************************"<<endl;
    cout<<"Team -> "<<t1.name<<"|| Score/Wicket -> " <<t1.scores <<"/"<<t1.wickets<<"|| Batting -> "<< batting<<"|| Overs -> "<<t1.overs;
    cout<<endl<<"*******************************************************************************"<<endl;
}

void scoreboard::innings_finished(team &t1,team &t2){
    cout<<"*******************************************************************************"<<endl;
    cout<<"*******************Innings Finished********************************************"<<endl;
    cout<<"*******************************************************************************"<<endl;
    cout<<"********************ScoreBoard*************************************************"<<endl;
    for(auto i:t1.playerList){
        cout<<i->getName()<<" = "<<i->runs<<endl;
    }
    cout<<endl<<"Total = "<<t1.scores<<" Wickets = "<<t1.wickets<<endl;
    cout<<"*******************************************************************************"<<endl<<t2.name<<" Batting now"<<endl;
}

void scoreboard::match_finished(team &t1, team&t2){
    if(t1.scores>t2.scores){
        cout<<"*******************************************************************************"<<endl;
        cout<<t1.name<<" won the match"<<endl;
        cout<<"*******************************************************************************"<<endl;
    }else if(t1.scores==t2.scores){
        cout<<"*******************************************************************************"<<endl;
        cout<<"Match Tied"<<endl;
        cout<<"*******************************************************************************"<<endl;
    }
    else{
        cout<<"*******************************************************************************"<<endl;
        cout<<t2.name<<" won the match"<<endl;
        cout<<"*******************************************************************************"<<endl;
    }
    cout<<t1.name<<" ScoreBoard"<<endl;
    for(auto i:t1.playerList){
        cout<<i->getName()<<" = "<<i->runs<<endl;
    }
    cout<<endl<<"Total = "<<t1.scores<<" Wickets = "<<t1.wickets;
    cout<<endl<<"*******************************************************************************"<<endl;
    cout<<t2.name<<" ScoreBoard"<<endl;
    for(auto i:t2.playerList){
        cout<<i->getName()<<" = "<<i->runs<<endl;
    }
    cout<<endl<<"Total = "<<t2.scores<<" Wickets = "<<t2.wickets;
    cout<<endl<<"*******************************************************************************"<<endl;
}
