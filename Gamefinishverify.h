#pragma once
#ifndef _GAMEFINISH_H_
#define _GAMEFINISH_H_

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>


#include "Leaderboard.h"
#include "Models.h"
#include "BoardSettings.h"
#include "Timing.h"

using namespace std;

void printThankYou();
void printBackroughFinish();
void printYouLose();
void printResult(Players player, int &pairs);
void printDesign();
void updateLeaderBoard(Players player);

#endif
