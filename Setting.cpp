#include "Setting.h"

int countHorizontalSeperator(int maxWidth, int length) {
    return (maxWidth - length) / 2;
}

void displayContentInBlock(string content, int width, int x, int y) {
    string block = "";
    // the top of the block
    gotoxy(x, y);
    cout << (char) 201; // the top left corner
    for(int i = 0; i < width; i++)
        cout << (char) 205; // the middle of block
    cout << (char) 187; // the top right corner

    //the middle of the block
    gotoxy(x, y + 1);
    cout << (char) 186;     // the left border
    int space = countHorizontalSeperator(width, content.length());
    for(int i = 0; i < space; i++)
        cout << " ";        // print space horizontal
    cout << content;        // the content that contained in block
    for(int i = 0; i < space; i++)
        cout << " ";        // print space horizontal
    cout << (char) 186;     // the right border

    // the bottom of the block
    gotoxy(x, y + 2);
    cout << (char) 200; // the bottom left corner
    for(int i = 0; i < width; i++)
        cout << (char) 205; // the middle of block
    cout << (char) 188; // the bottom right corner

}


void settingButtonIsSelected() {
    system("cls");
    setFontSize(800, 36,36);
    int color1 = RED, color2 = DEFAULT_COLOR;
    if (modePlay == 1)
        swap(color1, color2);

    color(color1);
    displayContentInBlock(" Normal", MAXWIDTH, 27, 5);
    color(color2);
    displayContentInBlock("Difficult", MAXWIDTH, 27, 10);
    bool isExit = false;
    int keyArrow;
    while(!isExit) {
        if (kbhit()) {      //kbhit() is present in conio.h and used to determine if a key has been pressed or not.
            keyArrow = getMoveFromKeyboard();
            switch (keyArrow) {
                case 1:
                case 4:
                    {
                        modePlay++;
                        if (modePlay > 1) modePlay = 0;
                        break;
                    }
                case 2:
                case 3:
                    {
                        modePlay--;
                        if (modePlay < 0) modePlay = 1;
                        break;
                    }
                case 6:
                        return;
                case 5:
                    isExit = true;
            }
        swap(color1, color2);
        color(color1);
        displayContentInBlock(" Normal", MAXWIDTH, 27, 5);
        color(color2);
        displayContentInBlock("Difficult", MAXWIDTH, 27, 10);
        }
    }
}

