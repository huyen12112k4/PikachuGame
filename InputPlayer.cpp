#include "inputPlayer.h"

Players inputPlayer() {
    color(RED);
    setFontSize(800, 36,36);

    string username;
    gotoxy(25, 8);
    cout << "_______________________";
    gotoxy(20, 8);
    cout << "Input Username: ";
    cin >> username;
    playSoundWhenPressKey();
    Players player(username);
    return player;
}
