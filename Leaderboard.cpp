#include "leaderboard.h"


string checkRanking(int time) {
    string s;
    if (300 <= time){
        s = "NEWBIE";
    } else if (200 <= time && time < 300){
            s =  "APPPRENTICE";
    } else if (120 <= time && time < 200 ){
            s = "EXPERT";
    } else if (time <= 120) {
            s = "MASTER";
    }
    return s;
}

void readLeaderBoard(TopPlayers top[]) {
    // read Leaderboard from leaderboard.txt
    ifstream ifs;
    ifs.open("leaderboard.txt");
    string s;
    string tmp;
    int cnt = 0;
    while(!ifs.eof()){
        getline(ifs, s);
        if(s == "")
            break;
        stringstream ss(s);

        getline(ss, tmp, ' ');
        top[cnt].id = stoi(tmp);
        getline(ss, tmp, ' ');
        top[cnt].name = tmp;
        getline(ss, tmp, ' ');
        top[cnt].time = stoi(tmp);

        cnt++;

    }
    ifs.close();

}

void printLeaderBoard() {
    gotoxy(0,0);
    TopPlayers top[5];
    ifstream ifs;
    ifs.open("LBDesign.txt");
    if(!ifs.is_open()) {
        cout << "No opening file";
    } else {
        string text;
        color(YELLOW);
        while(!ifs.eof()){
            getline(ifs, text);
            cout << text;
            cout << endl;
        }
    }
    ifs.close();
    readLeaderBoard(top);
    string s;
    color(LIGHTCYAN);
    int distance = 0;
    for(int i = 0; i < 5; i++) {
       gotoxy(28, i + 14 + distance);
       cout << top[i].name;
       gotoxy(66, i + 14 + distance);
       cout << top[i].time << "s";
       gotoxy(96, i +14 + distance);
       cout << checkRanking(top[i].time);
       distance += 1;
    }
    gotoxy(50,27);
    cout << "Press ENTER to exit ";
    while(getMoveFromKeyboard() != 6){
        printLeaderBoard();
    }
    system("cls");

}



