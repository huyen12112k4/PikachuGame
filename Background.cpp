#include "Background.h"
void getBackground(int cntRound) {
    ifstream fin;
    if (cntRound == 1)
        fin.open("./background/v1.txt", ios::in);
    if (cntRound == 2)
        fin.open("./background/v2.txt", ios::in);
    if (cntRound == 3)
        fin.open("./background/v3.txt", ios::in);
    if (fin) {
        for (int i = 2; i < 22; i++)
        {
            for (int j = 2; j < 67; j++)
            {
                bg[i][j].content = fin.get();
                bg[i][j].x = j;
                bg[i][j].y = i;
                //gotoxy(bg[i][j].x, bg[i][j].y);
                //cout << bg[i][j].content;
            }
            fin.ignore();
        }
        fin.close();
    }
}

void printBGNode(int x, int y, Node node1) {
    color(DEFAULT_COLOR);
    int xTmp = x, yTmp = y, width = 3, length = 7;
    if (x == bg[2][2].x  && y == bg[2][2].y ) { //Board[0][0]
         for (int i = y; i <= y + width; i++) {
            for (int j = x; j <= x + length; j++) {
                gotoxy(j, i);
                cout << bg[i][j].content;
            }
        }
        return;
    } else if (x < bg[2][10].x - 2 && y >= bg[6][2].y - 2) { //
        if (board[node1.x - 1][node1.y].isSelected == false) {
            yTmp++;
            width--;
            for (int i = yTmp; i <= yTmp + width; i++) {
                for (int j = xTmp; j <= xTmp + length; j++) {
                    gotoxy(j, i);
                    cout << bg[i][j].content;

                }
            }
            return;
        } else {
            for (int i = yTmp; i <= yTmp + width; i++) {
                for (int j = xTmp; j <= xTmp + length; j++) {
                    gotoxy(j, i);
                    cout << bg[i][j].content;
                }
            }
            return;
        }
    } else if (x >= bg[2][10].x - 2 && y < bg[6][2].y - 2) { // Board[0][j] j khác 0
        if(board[node1.x][node1.y - 1].isSelected == false) {
            xTmp++;
            length--;
            for (int i = yTmp; i <= yTmp + width; i++) {
                for (int j = xTmp; j <= xTmp + length; j++) {
                    gotoxy(j, i);
                    cout << bg[i][j].content;

                }
            }
            return;
        } else {
            for (int i = yTmp; i <= yTmp + width; i++) {
                for (int j = xTmp; j <= xTmp + length; j++) {
                    gotoxy(j, i);
                    cout << bg[i][j].content;
                }
            }
            return;
        }
    } else if (x >= bg[2][10].x - 2 && y >= bg[6][2].y - 2) { // Cac ô còn lại
        if(board[node1.x][node1.y - 1].isSelected == false ) {
            xTmp++;
            length--;
        }
        if(board[node1.x - 1][node1.y].isSelected == false) {
                yTmp++;
                width--;
        }
        for (int i = yTmp; i <= yTmp + width; i++) {
                for (int j = xTmp; j <= xTmp + length; j++) {

                    gotoxy(j, i);
                    cout << bg[i][j].content;
            }
        }
        if(board[node1.x - 1][node1.y - 1].isSelected == false) {
            gotoxy(x, y);
            color(YELLOW);
            cout << 'o';
        }
        return;
    }
}
