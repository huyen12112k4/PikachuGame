#include "ConsoleSettings.h"
#include "header.h"

bool timeOff;
bool finishGame;
int numBoxWidth;
int numBoxLength;
int modePlay;
Background bg[30][66];


int main() {
    initWindow(WIDTH, LENGTH);
    Menu menu;
    timeOff = false;
    finishGame = false;
    modePlay = 0;       // default is normal mode

    numBoxLength = 4;   // 4 rows as default
    numBoxWidth = 8;    // 8 columns as default
    srand(time(NULL));

    printStartingHomeHeader();
    menu.printMenu(X_MENU_VAL, Y_MENU_VAL, MAXWIDTH, 0);
    menu.initializeMenuWithCursor(X_MENU_VAL, Y_MENU_VAL, MAXWIDTH);


    return 0;

}

