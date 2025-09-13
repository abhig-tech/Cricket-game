#include <team.h>
#include <specialization.h>
#include <iostream>

team::team(string n):name(n){
    playerList.resize(0);
    scores=0;
    wickets=0;
    overs=0;
}

string team::getName(){
    return name;
}

void team::updateList(player* ptr){
    playerList.push_back(ptr);
}

void team::delPlayers(){
    for(int i=0;i<playerList.size();i++){
        delete playerList[i];
    }
    playerList.resize(0);
}

void team::teamBuilder(team &t1, int nPlayers){
        for(int i=0;i<nPlayers;i++){
            cout<<endl<<"Enter Name of player without space"<<endl;
            string name;
            cin>>name;
            int pskill;
            int skill;
            player* ptr;
            while(1){
            cout<<endl<<"Choose primary skill"<<endl<<"1. Batting\n2. Bowling"<<endl;
            cin>>pskill;
            if(cin.fail()){
                cout<<"invalid selection try again";
                cin.clear();
                cin.ignore(1000, '\n');
            }
            else if(pskill==1||pskill==2){
                break;
            }else{
                cout<<"invalid selection try again";
            }
            }
            if(pskill==1){
                while(1){
                cout<<endl<<"Choose secondary skill"<<endl<<"1. Bowling\n2. Wicketkeeping\n3. Fielding"<<endl;
                cin>>skill;
                if(cin.fail()){
                cout<<"invalid selection try again";
                cin.clear();
                cin.ignore(1000, '\n');
                }
                else if(skill==1||skill==2||skill==3){
                    if(skill==1){
                        ptr=new AllRounder(name);
                    }else if(skill==2){
                        ptr=new Wbat(name);
                    }else{
                        ptr=new Batsman(name);
                    }
                    break;
                }else{
                    cout<<"Invalid Input try again";
                }
                }
            }else{
                while(1){
                cout<<endl<<"Choose secondary skill"<<endl<<"1. Batting \n2. Fielding"<<endl;
                cin>>skill;
                if(cin.fail()){
                cout<<"invalid selection try again";
                cin.clear();
                cin.ignore(1000, '\n');
                }
                else if(skill==1||skill==2){
                    if(skill==1){
                        ptr=new AllRounder(name);
                    }else{
                        ptr=new Bowler(name);
                    }
                    break;
                }else{
                    cout<<"Invalid selection try again"<<endl;
                }
                }
            }
            t1.updateList(ptr);
        }
}

void team::teamListDesigner(vector<team> &teamList, int nTeams){
    for(int i=0;i<nTeams;i++){
        cout<<endl<<"enter name of Team "<<i+1<<endl;
        string n;
        cin>>n;
        team t1(n);
        teamList.push_back(t1);
    }
}