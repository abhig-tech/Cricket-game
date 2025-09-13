#include <match.h>
#include <iostream>

match::match (team &t1, team &t2, double ov, umpire &umpi){
    T1=&t1;
    T2=&t2;
    ump=&umpi;
    t1.scores=0;
    t1.overs=0;
    t1.wickets=0;
    t2.scores=0;
    t2.overs=0;
    t2.wickets=0;
    overs=ov;
}

void match::match_starts(){
    scoreboard::match_Starts(*T1, *T2, *ump);
    int totalBalls=overs*6;
    int currBalls=0;
    int currWickets=0;
    int outcome=0;
    //unordered_map<string, int> battingT1;
    int BattingNumber=0;
    T1->playerList[BattingNumber]->runs=0;
    while(currBalls<totalBalls&&currWickets<T1->playerList.size()){
        cout<< "Choose the outcome from given options"<<endl<<"-1 -> Out"<<endl<<"-2 -> Wide/No Ball"<<endl<<"-3 -> Wide/No Ball+runs"<<endl<<"+v numbers for runs"<<endl;
        while(1){
        cin>>outcome;
        if(cin.fail()){
            cout<<"Invalid Input! Enter again"<<endl;
            cin.clear();
            cin.ignore(1000,'\n');
        }else{
            break;
        }
        }
        cout<<endl;
        if(outcome>=0){
            T1->scores+=outcome;
            T1->playerList[BattingNumber]->runs+=outcome;
            currBalls++;
            int over=currBalls/6;
            double b=currBalls%6;
            b=b/10;
            T1->overs=over+b;
            scoreboard::LiveScore(*T1, T1->playerList[BattingNumber]->getName());
        }else if(outcome==-1){
            T1->wickets+=1;
            //battingT1[T1->playerList[BattingNumber]->getName()]=T1->playerList[BattingNumber]->runs;
            BattingNumber++;
            currWickets++;
            currBalls++;
            int over=currBalls/6;
            double b=currBalls%6;
            b=b/10;
            T1->overs=over+b;
            if(currWickets==T1->playerList.size()){
                break;
            }
            T1->playerList[BattingNumber]->runs=0;
            scoreboard::LiveScore(*T1, T1->playerList[BattingNumber]->getName());
        }else if(outcome==-2){
            T1->scores++;
            scoreboard::LiveScore(*T1, T1->playerList[BattingNumber]->getName());
        }else if(outcome==-3){
            cout<<endl<<"Enter total runs including wide/No ball runs"<<endl;
            cin>>outcome;
            cout<<endl;
            T1->scores+=outcome;
            scoreboard::LiveScore(*T1, T1->playerList[BattingNumber]->getName());
        }else{
            cout<<"Invalid input enter again";
        }
    }
    // if(currWickets<T1->playerList.size()){
    // battingT1[T1->playerList[BattingNumber]->getName()]=T1->playerList[BattingNumber]->runs;
    // }
    scoreboard::innings_finished(*T1,*T2);
    currBalls=0;
    currWickets=0;
    //unordered_map<string, int> battingT2;
    BattingNumber=0;
    T2->playerList[BattingNumber]->runs=0;
    while(currBalls<totalBalls&&currWickets<T2->playerList.size()){
        cout<< "Choose the outcome from given options"<<endl<<"-1 -> Out"<<endl<<"-2 -> Wide/No Ball"<<endl<<"-3 -> Wide/No Ball+runs"<<endl<<"+v numbers for runs"<<endl;
        while(1){
        cin>>outcome;
        if(cin.fail()){
            cout<<"Invalid Input! Enter again"<<endl;
            cin.clear();
            cin.ignore(1000,'\n');
        }else{
            break;
        }
        }
        cout<<endl;
        if(outcome>=0){
            T2->scores+=outcome;
            T2->playerList[BattingNumber]->runs+=outcome;
            currBalls++;
            int over=currBalls/6;
            double b=currBalls%6;
            b=b/10;
            T2->overs=over+b;
            scoreboard::LiveScore(*T2, T2->playerList[BattingNumber]->getName());
        }else if(outcome==-1){
            T2->wickets+=1;
            //battingT2[T2->playerList[BattingNumber]->getName()]=T2->playerList[BattingNumber]->runs;
            BattingNumber++;
            currWickets++;
            currBalls++;
            int over=currBalls/6;
            double b=currBalls%6;
            b=b/10;
            T2->overs=over+b;
            if(currWickets==T2->playerList.size()){
                break;
            }
            T2->playerList[BattingNumber]->runs=0;
            scoreboard::LiveScore(*T2, T2->playerList[BattingNumber]->getName());
        }else if(outcome==-2){
            T2->scores++;
            scoreboard::LiveScore(*T2, T2->playerList[BattingNumber]->getName());
        }else if(outcome==-3){
            cout<<endl<<"Enter total runs including wide/No ball runs"<<endl;
            cin>>outcome;
            cout<<endl;
            T2->scores+=outcome;
            scoreboard::LiveScore(*T2, T2->playerList[BattingNumber]->getName());
        }else{
            cout<<"Invalid input enter again"<<endl;
        }
        if(T2->scores>T1->scores){
            break;
        }
    }
    // if(currWickets<T2->playerList.size()){
    // battingT2[T2->playerList[BattingNumber]->getName()]=T2->playerList[BattingNumber]->runs;
    // }
    scoreboard::match_finished(*T1, *T2);
    }

void match::match_details(int nMatches, vector <team> &teamList){
    int nTeams=teamList.size();
    while(nMatches>0){
        cout<<"Total Players required per team for the match"<<endl;
        int nPlayers;
        while(1){
            cin>>nPlayers;
            if(cin.fail()){
                cout<<"Invalid Input Try Again"<<endl;
                cin.clear();
                cin.ignore(1000,'\n');
            }else if(nPlayers<=0){
                cout<<"Invalid Input Try Again"<<endl;
            }else{
                break;
            }
        }
        int teamNum;
        cout<<endl<<"Choose the first team"<<endl;
        while(1){
        for(int i=0;i<nTeams;i++){
            cout<<i<<" = "<<teamList[i].getName()<<endl;
        }
        cin>>teamNum;
        if(cin.fail()){
                cout<<"Invalid Input Try Again"<<endl;
                cin.clear();
                cin.ignore(1000,'\n');
        }
        else if(teamNum>=0&&teamNum<nTeams){
            break;
        }else{
            cout<<"Invalid Input Try Again"<<endl;
        }
        }
        team::teamBuilder(teamList[teamNum], nPlayers);
        int teamNum2;
        while(1){
        cout<<endl<<"Choose the second team"<<endl;
        for(int i=0;i<nTeams;i++){
            if(i==teamNum){
                continue;
            }
            cout<<i<<" = "<<teamList[i].getName()<<endl;
        }
        cin>>teamNum2;
        if(cin.fail()){
                cout<<"Invalid Input Try Again"<<endl;
                cin.clear();
                cin.ignore(1000,'\n');
        }
        else if(teamNum2>=0&&teamNum2<nTeams&&teamNum2!=teamNum){
            break;
        }else{
            cout<<"Invalid Input Try Again"<<endl;
        }
        }
        team::teamBuilder(teamList[teamNum2], nPlayers);
        int overs;
        cout<<endl<<"Enter number of overs";
        while(1){
        cin>>overs;
        if(cin.fail()){
                cout<<"Invalid Input Try Again"<<endl;
                cin.clear();
                cin.ignore(1000,'\n');
        }else{
            break;
        }
        }
        cout<<endl;
        cout<<"Enter the name of Umpire"<<endl;
        string Ump;
        cin>>Ump;
        umpire Umpi(Ump);
        match M1(teamList[teamNum], teamList[teamNum2], overs, Umpi);
        M1.match_starts();
        teamList[teamNum].delPlayers();
        teamList[teamNum2].delPlayers();
        nMatches--;
    }

}

int match::teamCount(){
    cout<<"Enter total Teams"<<endl;
    int nTeams;
    while(1){
    cin>>nTeams;
    if(cin.fail()){
        cout<<"Invalid Input Enter Again"<<endl;
        cin.clear();
        cin.ignore(1000, '\n');
    }else{
        break;
    }
    }
    return nTeams;
}

int match::matchCount(){
    cout<<"Enter total Matches"<<endl;
    int nMatches;
    while(1){
    cin>>nMatches;
    if(cin.fail()){
        cout<<"Invalid Input Enter Again"<<endl;
        cin.clear();
        cin.ignore(1000, '\n');
    }else{
        break;
    }
    }
    return nMatches;
}

