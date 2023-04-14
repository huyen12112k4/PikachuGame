#pragma once
#ifndef _LEADERBOARD_H_
#define _LEADERBOARD_H_


#include <fstream>
#include <string>
#include <sstream>

#include "ConsoleSettings.h"
using namespace std;

struct TopPlayers{
    int id;
    string name;
    int time;
};

string checkRanking(int time);
void readLeaderBoard(TopPlayers top[]);
void printLeaderBoard();

#endif

