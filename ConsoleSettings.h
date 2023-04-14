#pragma once // serves the same purpose as include guards - Ref: https://www.wikiwand.com/en/Pragma_once
#ifndef _CONSOLE_H_
#define _CONSOLE_H_

#include<Windows.h>
#include<iostream>
#include <pthread.h>
#include <iomanip>
#include "Assets.h"



using namespace std;

void setCursorVisible(bool visible);
void resizeWindow(int x, int y);
void setFrameLine(int width, int length);
void hideScrollBar();
void initWindow(int width, int length);
void gotoxy(int column, int line);
void color(int color);
void setFrameLine(int width, int length);
int getMoveFromKeyboard();
void clearScreen (int width, int length);
void setFontSize(int weight, int height, int width);
void createTimerCount();
#endif

