#include "MoveSuggestion.h"

bool findSuggestion(bool isMark) {
    for(int i = 0; i < numBoxLength * numBoxWidth - 1; i++)
        if (board[i / numBoxWidth][i % numBoxWidth].isSelected == false) {

            for(int j = i + 1; j < numBoxLength * numBoxWidth; j++)
            if (board[j / numBoxWidth][j % numBoxWidth].isSelected == false) {
                board[i / numBoxWidth][i % numBoxWidth].isSelected = true;
                board[j / numBoxWidth][j % numBoxWidth].isSelected = true;
                Node checkNode1 = board[i / numBoxWidth][i % numBoxWidth], checkNode2 = board[j / numBoxWidth][j % numBoxWidth];
                checkNode1.x = i / numBoxWidth;
                checkNode1.y = i % numBoxWidth;
                checkNode2.x = j / numBoxWidth;
                checkNode2.y = j % numBoxWidth;
                //
                if (canConnect(checkNode1, checkNode2, 0)) {
                    if (isMark) {
                        checkNode1.isMarkedHighLight(board[checkNode1.x][checkNode1.y].x, board[checkNode1.x][checkNode1.y].y);
                        checkNode2.isMarkedHighLight(board[checkNode2.x][checkNode2.y].x, board[checkNode2.x][checkNode2.y].y);
                    }
                    board[i / numBoxWidth][i % numBoxWidth].isSelected = false;
                    board[j / numBoxWidth][j % numBoxWidth].isSelected = false;
                    return true;
                }
                board[i / numBoxWidth][i % numBoxWidth].isSelected = false;
                board[j / numBoxWidth][j % numBoxWidth].isSelected = false;

            }
    }
    return false;

}

void getHelp(Players &player) {
    if (player.getHint() < 0) {
        gotoxy(20, 1);
        color(RED);
        cout << "Out of help, keep it up!!";
        return;
    }
    int newHint = player.getHint() - 1;
    player.updateHint(newHint);
    findSuggestion(true);
}

bool findSuggestionLL(bool isMark) {
   for(int i = 0; i < numBoxLength * numBoxWidth - 1; i++)
        if (boardLL[i / numBoxWidth][i % numBoxWidth].content != '\0') {
            for(int j = i + 1; j < numBoxLength * numBoxWidth; j++)
                if (boardLL[j / numBoxWidth][j % numBoxWidth].content != '\0') {
                    NodeLL *node1 = &boardLL[i / numBoxWidth][i % numBoxWidth], *node2 = &boardLL[j / numBoxWidth][j % numBoxWidth];
                    if (canConnectLL(node1, node2, 0)) {
                        if (isMark) {
                            node1 -> isMarkHighLight(node1 -> x, node1 -> y);
                            node2 -> isMarkHighLight(node2 -> x, node2 -> y);
                        }
                        return true;
                    }
                }
        }

    return false;

}

void getHelpLL(Players &player) {
    if (player.getHint() < 0) {
        gotoxy(20, 1);
        color(RED);
        cout << "Out of help, keep it up!!";
        return;
    }
    int newHint = player.getHint() - 1;
    player.updateHint(newHint);
    findSuggestionLL(true);
}
