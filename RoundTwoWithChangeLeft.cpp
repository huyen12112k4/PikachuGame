#include "RoundTwoWithChangeLeft.h"

void openRound2(Players &player) {
    int cntRound = 1, pairs = 0;
    while(cntRound < 4) {

        showTitleRound(player, cntRound);
        timeOff = false;
        finishGame = false;
        createTimerCount();
        initializeTheBoardLL(player, pairs);
        if(finishGame == false)
            break;
        ;
        gotoxy(0,0);
        color(YELLOW);
        cntRound++;
    }
    system("cls");
    gotoxy(0,0);
    setFontSize(800, 23,23);
    printThankYou();

    if (finishGame) {
        printBackroughFinish();
    }
    else {
        printYouLose();
    }
    printResult(player, pairs);
    printDesign();

    if(cntRound == 4) {
        player.updatePlayer(5, 2, player.getTime());
        updateLeaderBoard(player);
    }
    bool isExit = false;
    int keyArrow;

    while(!isExit) {
        if (kbhit()) {      //kbhit() is present in conio.h and used to determine if a key has been pressed or not.
            keyArrow = getMoveFromKeyboard();
            if (keyArrow == 3)
                isExit = true;
        }
    }
}

