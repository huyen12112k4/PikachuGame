#include "StartingHome.h"

void printTileGame() {
    gotoxy(0,0);
    color(BROWN);
    string title = R"(
                                                                              ,'\
                                                _.----.        ____         ,'  _\   ___    ___     ____
                                            _,-'       `.     |    |  /`.   \,-'    |   \  /   |   |    \  |`.   `;-.          ___,
                                            \      __    \    '-.  | /   `.  ___    |    \/    |   '-.   \ |  |   `.`\_...._/`.-"`
                                             \.    \ \   |  __  |  |/    ,','_  `.  |          | __  |    \|  |     \        /      ,
                                               \    \/   /,' _`.|      ,' / / / /   |          ,' _`.|     |  |     /()   () \    .' `-._
                                                \     ,-'/  /   \    ,'   | \/ / ,`.|         /  /   \  |     |    |)  .    ()\  /   _.'
                                                 \    \ |   \_/  |   `-.  \    `'  /|  |    ||   \_/  | |\    |    \  -'-     ,; '. <
                                                  \    \ \      /       `-.`.___,-' |  |\  /| \      /  | |   |     ;.__     ,;|   > \
                                                   \    \ `.__,'|  |`-._    `|      |__| \/ |  `.__,'|  | |   |    / ,    / ,  |.-'.-'
                                                    \_.-'       |__|    `-._ |              '-.|     '-.| |   |   (_/    (_/ ,;|.<`
                                                                            `'                            '-._|     \    ,     ;-`
                                                                                                                     >   \    /
                                                          ==========================================                (_,-'`> .'
                                                                                                                         (_,'
                                            )";

    cout << title;
}

void printClass() {
    color(CYAN); // set color text is Blue
    cout << R"(
                                                               ___     ___     ___     _       ___      __     ____
                                                              |_  )   |_  )   / __|   | |     / __|    /  \   |__ /
                                                               / /     / /   | (__    | |__  | (__    | () |   |_ \
                                                              /___|   /___|   \___|   |____|  \___|   _\__/   |___/
                                                            _|"""""|_|"""""|_|"""""|_|"""""|_|"""""|_|"""""|_|"""""|
                                                            "`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'


                                                                      ===========================================

                                           )";
}

void printStartingHomeHeader() {
    setFontSize(400, 16, 7);
    system("cls");
    printTileGame();
    printClass();
}

void startButtonIsSelected() {
    system("cls");
    Players player = inputPlayer();
    system("cls");
    if (modePlay == 0)
        openRound1(player);
    else openRound2(player);
}

// LEADERBOARD IS SELECTED
void leaderboardButtonIsSelected(){
    system("cls");
    printLeaderBoard();

}

// MENU


Menu::Menu() {

    _numberOfItem = 4;
    item = new string[_numberOfItem];

    item[0] = "START";

    item[1] = "SETTING";

    item[2] = "LEADERBOARD";

    item[3] = "TUTORIALS";

}

void Menu::printMenu(int X, int Y, int maxWidth, int posCursor) {
    for (int i = 0; i < _numberOfItem; i++) {
        if(i == posCursor) {
            color(LIGHTRED);
            gotoxy(X_CURSOR_MENU_VAL, Y_CURSOR_MENU_VAL + i * 3);
            cout << '>';
        }
        else {
            color(DEFAULT_COLOR);
            gotoxy(X_CURSOR_MENU_VAL, Y_CURSOR_MENU_VAL + i * 3);
            cout << ' ';
        }
        displayContentInBlock(item[i], maxWidth, X, Y);
        Y += 3;
        //Sleep(100); //Tạm dừng 100ms

    }


}

void Menu::deleteMenu(int X, int Y, int width) {

    for (int i = 0; i < _numberOfItem; i++) {
        //Sleep(100);
        for(int k = 0; i < 3; i++) {
            gotoxy(X, Y);
            for (int j = 0; j < width + 2; j++)
                cout << " "; // delete by ' ' character
            Y++;
        }
        Y++;
    }
}

void Menu::initializeMenuWithCursor(int X, int Y, int maxWidth) {

    int currentLine = 0; //Vị trí dòng của menu
    bool isExit = false;
    int keyArrow;
    printMenu(X, Y, maxWidth, currentLine);
    playSoundWhenStartingGame();
    while(!isExit) {
        if (kbhit()) {      //kbhit() is present in conio.h and used to determine if a key has been pressed or not.
            keyArrow = getMoveFromKeyboard();
            switch (keyArrow) {
                case 1:
                case 4:
                    {
                        currentLine++;
                        if (currentLine >= _numberOfItem) currentLine = 0;
                        break;
                    }
                case 2:
                case 3:
                    {
                        currentLine--;
                        if (currentLine < 0) currentLine = _numberOfItem - 1;
                        break;
                    }
                case 6:
                    {
                        if (currentLine == 0) {
                            startButtonIsSelected();
                            printStartingHomeHeader();
                            printMenu(X, Y, maxWidth, currentLine);
                        }
                        else
                        if (currentLine == 1) {
                            settingButtonIsSelected();
                            system("cls");
                            printStartingHomeHeader();
                            printMenu(X, Y, maxWidth, currentLine);

                        }
                        else
                        if  (currentLine == 2) {
                            leaderboardButtonIsSelected();
                            printStartingHomeHeader();
                            printMenu(X, Y, maxWidth, currentLine);
                        }
                        else
                        if (currentLine == 3) {
                            TutorialsButtonIsSelected();
                            system("cls");
                            printStartingHomeHeader();
                            printMenu(X, Y, maxWidth, currentLine);
                        }
                        else
                            cout << "selected other";
                        break;
                    }
                case 5:
                    isExit = true;
            }
            deleteMenu(X, Y, maxWidth);
            printMenu(X, Y, maxWidth, currentLine);
        }
    }
}
