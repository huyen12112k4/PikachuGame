#include "Tutorials.h"

void printTutorial1(){

    ifstream ifs;
    int x = 25, y = 0;
    ifs.open("./image_game/tutorial_image/tutorial1.txt");
    if(!ifs.is_open()) {
        cout << "No opening file";
    } else {
        string tmp;

        color(LIGHTMAGENTA);
        while(!ifs.eof()){
            getline(ifs, tmp);
            gotoxy(x,y);
            cout << tmp;
            y++;
        }

    ifs.close();
    }
}
void printTutorial2(){
    ifstream in;
    int x = 25, y = 10;

    in.open("./image_game/tutorial_image/tutorial2.txt");
    string text;
   if(!in.is_open()) {
        cout << "No opening file";
    } else {
        string text;
        color(BROWN);
        while(!in.eof()){
            getline(in, text);
            gotoxy(x, y);
            cout << text;
            y++;
        }
    }
    in.close();

}

void TutorialsButtonIsSelected() {
    system("cls");
    printTutorial1();
    printTutorial2();

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


