#pragma once // serves the same purpose as include guards - Ref: https://www.wikiwand.com/en/Pragma_once
#ifndef _STARTING_H_
#define _STARTING_H_

#include<iostream>
#include<Windows.h>

#include "Assets.h"
#include "ConsoleSettings.h"
#include "inputPlayer.h"
#include "RoundOneWithUnchangeBoard.h"
#include "RoundTwoWithChangeLeft.h"
#include "Tutorials.h"
#include "Leaderboard.h"
#include "Setting.h"
#include "Models.h"
#include "sound.h"
using namespace std;

int countHorizontalSeperator(int maxWidth, int length);
void displayContentInBlock(string content, int width, int x, int y);
void printStartingHomeHeader();

#endif
