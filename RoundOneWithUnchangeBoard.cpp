#include "RoundOneWithUnchangeBoard.h"

void openRound1(Players &player) {
    int cntRound = 1; int pairs = 0;
    while(cntRound < 4) {
        time_t start1, finish1;
        showTitleRound(player, cntRound);
        timeOff = false;
        finishGame = false;
        createTimerCount();
        time(&start1);
        initializeTheBoard(player, pairs, cntRound);
        time(&finish1);
        int time = difftime(finish1, start1);
        countTime(time, player);
        if(finishGame == false)
            break;
        Sleep(1000);
        cntRound++;

    }
    system("cls");
    gotoxy(0,0);
    setFontSize(800, 23,23);
    printThankYou();
    if (finishGame) {
        playSoundYouWin();
        printBackroughFinish();
    }
    else {
        playSoundYouLose();
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






