
#pragma once // serves the same purpose as include guards - Ref: https://www.wikiwand.com/en/Pragma_once
#ifndef _BOARD_H_
#define _BOARD_H_

#include<iostream>
#include<Windows.h>
#include<time.h>

#include "Assets.h"
#include "ConsoleSettings.h"
#include "Models.h"
#include "Timing.h"
#include "Checking.h"
#include "MoveSuggestion.h"
#include "Background.h"
#include "Sound.h"
using namespace std;


void showBoxWithContent(char content, int x, int y);
void showTheBoard();
void showTitleRound(Players player, int numRound);
void initializeTheBoard(Players &player, int &pairs, int cntRound);
void initializeTheBoardLL(Players &player, int &pairs);
#endif
