#include "Background.h"
void getBackground(int cntRound) { // read background from folder background
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
            }
            fin.ignore();
        }
        fin.close();
    }
}

void printBGNode(int x, int y, Node node1) { // print background when delete node
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
    } else if (x < bg[2][10].x - 2 && y >= bg[6][2].y - 2) { // Board[i][0] not include board[0][0]
        if (board[node1.x - 1][node1.y].isSelected == false) { // Check board on the top of current board
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
    } else if (x >= bg[2][10].x - 2 && y < bg[6][2].y - 2) { // board[0][j] not include board[0][0]
        if(board[node1.x][node1.y - 1].isSelected == false) { // check board on the right of current board
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
    } else if (x >= bg[2][10].x - 2 && y >= bg[6][2].y - 2) { // other board
        if(board[node1.x][node1.y - 1].isSelected == false ) { // check board on the right of current board
            xTmp++;
            length--;
        }
        if(board[node1.x - 1][node1.y].isSelected == false) { // check board on the top of current board
                yTmp++;
                width--;
        }
        for (int i = yTmp; i <= yTmp + width; i++) {
                for (int j = xTmp; j <= xTmp + length; j++) {

                    gotoxy(j, i);
                    cout << bg[i][j].content;
            }
        }
        if(board[node1.x - 1][node1.y - 1].isSelected == false) { // check board cross with current board
            gotoxy(x, y);
            color(YELLOW);
            cout << 'o';
        }
        return;
    }
}
