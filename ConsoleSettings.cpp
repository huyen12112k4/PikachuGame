#include "ConsoleSettings.h"

// WINDOW SETTINGS
void color(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

//Ref: https://superuser.com/questions/1496322/how-do-i-remove-hide-the-cursor-the-blinking-underscore-character-in-cmd-exe
void setCursorVisible() {
    HANDLE hStdOut = NULL;
    CONSOLE_CURSOR_INFO curInfo;

    hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleCursorInfo(hStdOut, &curInfo);    // retrieve information about cursor
    curInfo.bVisible = false;                   // disables the cursor visibility by settings bVisible boolean
    SetConsoleCursorInfo(hStdOut, &curInfo);    // reset the configuration for the specified console screen buffer.
}

//  Ref: https://github.com/PhVanMin/Pikachuuu.git
void resizeWindow(int x, int y) {
    HWND console = GetConsoleWindow();          // get a handle to the console window
    RECT r;
    GetWindowRect(console, &r);                 // retrieves the dimensions of the bounding rectangle of the specified window.
    MoveWindow(console, r.left, r.top, x, y, TRUE); // Changes the position and dimensions of the specified window
}

void hideScrollBar() {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screenBufferInfo;
    GetConsoleScreenBufferInfo(console, &screenBufferInfo); // retrieve information screen buffer

    COORD new_screen_buffer_size;

    // set the new size of screen buffer equal the size of screen Window
    new_screen_buffer_size.X = screenBufferInfo.srWindow.Right - screenBufferInfo.srWindow.Left + 1;
    new_screen_buffer_size.Y = screenBufferInfo.srWindow.Bottom - screenBufferInfo.srWindow.Top + 1;

    SetConsoleScreenBufferSize(console, new_screen_buffer_size);    // reset the new configuration
}

// Customize font size
void setFontSize(int weight, int height, int width) {

    static CONSOLE_FONT_INFOEX  fontex;
    fontex.cbSize = sizeof(CONSOLE_FONT_INFOEX);
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetCurrentConsoleFontEx(hOut, 0, &fontex);
    fontex.FontWeight = weight;
    fontex.dwFontSize.X = width;
    fontex.dwFontSize.Y = height;
    SetCurrentConsoleFontEx(hOut, NULL, &fontex);

}

// initialize window setting
void initWindow(int width, int length) {
    resizeWindow(width, length);
    hideScrollBar();
    setCursorVisible();
    setFontSize(400, 16, 7);
}

// GAME SETTINGS

// Ref: http://vualaptrinh.blogspot.com/2015/10/tao-mot-menu-truc-quan-sinh-ong-bang-cc.html
void gotoxy(int x, int y) {    // go to location with coordinates (column, line)
    COORD coord;

    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}

int getMoveFromKeyboard() {

    char c = getch();

    if ((int) c == -32)
        c = getch();
    Beep(400, 90);
    switch ((int) c) {

        case 80:
            return 1; // down

        case 72:
            return 2; // up

        case 77:
            return 3; // right

        case 75:
            return 4; // left

        case 27:
            return 5; // esc

        case 13:
            return 6; // enter

        case 104:
            return 7; // h character

        default:
            return 0;

    }

}

void *timerCout(void * arg) {

    int cnt = 0, i = 1;
    while(i <= TIME_PER_ROUND) {
        if (finishGame == true)
            return NULL;
        Sleep(1000);
         if(i % (12) == 0) {
            gotoxy(72, 8 + cnt);
            cout << " ";
            cnt++;
        }
        i++;
    }
    timeOff = true;
    return NULL;
}

void createTimerCount() {
    pthread_t timer;
    int i = 10, rc;
    rc = pthread_create(&timer, NULL, &timerCout, NULL);        // https://www.bogotobogo.com/cplusplus/multithreading_pthread.php

    if (rc) {
         cout << "Error:unable to create thread," << rc << endl;
         exit(-1);
    }

}

