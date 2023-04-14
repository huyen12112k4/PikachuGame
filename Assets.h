#pragma once
#ifndef _ASSETS_H_
#define _ASSETS_H_

#include <conio.h>

#define BLUE 1
#define GREEN 2
#define CYAN	3
#define RED	4
#define MAGENTA	5
#define BROWN	6
#define DEFAULT_COLOR	7
#define DARKGRAY	8
#define LIGHTBLUE	9
#define LIGHTGREEN	10
#define LIGHTCYAN	11
#define LIGHTRED	12
#define LIGHTMAGENTA	13
#define YELLOW	14
#define BLACK	0

#define X_MENU_VAL 80
#define Y_MENU_VAL 27
#define X_CURSOR_MENU_VAL 78
#define Y_CURSOR_MENU_VAL 28
#define MAXWIDTH 21

#define WIDTH 1920
#define LENGTH 1080
#define WIDTH_CHAR 180
#define LENGTH_CHAR 100

#define MAX_NUMBER_PLAYERS 100
#define TIME_PER_ROUND 120 // 120 secs = 2 mins
using namespace std;

extern bool timeOff;
extern bool finishGame;
extern int numBoxWidth;
extern int numBoxLength;
extern int modePlay;

#endif
