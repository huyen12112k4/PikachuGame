#include "Gamefinishverify.h"

void printThankYou() {
    ifstream ifs;
    ifs.open("./image_game/image_finish/Thanks.txt");

    if(!ifs.is_open()) {
        cout << "No opening file";
    } else {
        string tmp;
        gotoxy(0,0);
        color(RED);
        while(!ifs.eof()){
            getline(ifs, tmp);
            cout << tmp;
            cout << endl;
        }
    }

}
void printDesign() {
    ifstream ifs;
    ifs.open("./image_game/image_finish/Star.txt");

    if(!ifs.is_open()) {
        cout << "No opening file";
    } else {
        string tmp;
        gotoxy(8,18);
        color(BROWN);
        while(!ifs.eof()){
            getline(ifs, tmp);
            cout << tmp;
            cout << endl;
        }
    }

}

void printBackroughFinish(){
    ifstream ifs;
    ifs.open("./image_game/image_finish/YouWin.txt");

    if(!ifs.is_open()) {
        cout << "No opening file";
    } else {
        string tmp;
        gotoxy(6,2);
        color(BLUE);
        while(!ifs.eof()){
            getline(ifs, tmp);
            cout << tmp;
            cout << endl;
        }
    }
    ifs.close();

}

void printYouLose(){
    ifstream ifs;
    ifs.open("./image_game/image_finish/YouLose.txt");

    if(!ifs.is_open()) {
        cout << "No opening file";
    } else {
        string tmp;
        gotoxy(80,2);
        color(DARKGRAY);
        while(!ifs.eof()){
            getline(ifs, tmp);
            cout << tmp;
            cout << endl;
        }
    }
    ifs.close();

}


void printResult(Players player, int &pairs){
    gotoxy(37,16);
    color(RED);
    cout << "USERNAME: " << player.getUsername();
    gotoxy(70, 16);
    cout << "     TIME: " << player.getTime();
    gotoxy(56,19);
    cout << 48 - pairs;
    gotoxy(91,19);
    cout << pairs;

}
void updateLeaderBoard(Players player){
    TopPlayers update[5];
    int pos = 0; // position of current player

    // Read file leaderboard.txt and pass to update[5]
    readLeaderBoard(update);

    // Compare point and name of current player from top[0] -> top[4]
    for(int i = 0; i <= 4; i++) {

        if(player.getTime() > update[i].time ){
                pos++;
        } else if(player.getTime() == update[i].time) {

            if(player.getUsername() < update[i].name)
                pos++;
        }

    }
    // update position's player
    if(pos > 4) return;

    else {
        for(int i = 4; i > pos; i--){

            update[i] = update[i - 1];
            update[i].id += 1;
        }

    update[pos].time = player.getTime();

    update[pos].name = player.getUsername();

    update[pos].id = pos + 1;

    }
    // update leaderboard.txt

    ofstream ofs;
    ofs.open("leaderboard.txt");
    for(int i = 0 ; i < 5; i++){
        ofs << update[i].id << " " << update[i].name << " " << update[i].time << endl;
    }
    ofs.close();
}

/*
//
void findPositionOfPlayer(Players player) {
    int pos = 0;
    for(int i = 0; i < next_id - 1; i++){
        if(point < Players.point[i] - 1)
                pos++;
    }
}
void checkLeaderBoard(Players player){
    int pos = findPositionOfPlayer(player);
    if(pos <= 5){
        for (int i = 4; i >= pos ; i--)
            topPlayers[i] = topPlayers[i - 1];
        topPlayer[i] = Players[length - 1];
    } else
        return;
}

*/



