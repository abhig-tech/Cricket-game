#include <iostream>
#include <match.h>
using namespace std;

int main(){
    vector <team> teamList;
    team::teamListDesigner(teamList, match::teamCount());
    match::match_details(match::matchCount(), teamList);
}


 