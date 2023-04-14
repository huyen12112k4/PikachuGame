#pragma once // serves the same purpose as include guards - Ref: https://www.wikiwand.com/en/Pragma_once
#ifndef _SETTING_H_
#define _SETTING_H_

#include<iostream>
#include<Windows.h>

#include "Assets.h"
#include "ConsoleSettings.h"

using namespace std;

void settingButtonIsSelected();
int countHorizontalSeperator(int maxWidth, int length);
void displayContentInBlock(string content, int width, int x, int y);
#endif
