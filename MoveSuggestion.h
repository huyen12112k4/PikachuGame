#pragma once // serves the same purpose as include guards - Ref: https://www.wikiwand.com/en/Pragma_once
#ifndef _MOVESUGGESTION_H_
#define _MOVESUGGESTION_H_

#include <iostream>
#include <stdlib.h>
#include "ConsoleSettings.h"
#include "Models.h"
#include  "BoardSettings.h"
#include  "Checking.h"

using namespace std;

void getHelp(Players &player);
bool findSuggestion(bool isMark);
void getHelpLL(Players &player);
bool findSuggestionLL(bool isMark);

#endif


