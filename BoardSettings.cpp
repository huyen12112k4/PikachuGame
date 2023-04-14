#include "BoardSettings.h"
Node board[10][10];
Node tmpBoard[10][10];
NodeLL **boardLL;

void showTimeBar() {
    color(YELLOW);
    for(int i = 0; i < 10; i++) {
        gotoxy(72, 8 + i);
        if(i > 1 && i < 4)
            color(YELLOW);
        else if(i > 3 && i < 6)
            color(LIGHTRED);
        else if(i > 5 && i < 8)
            color(LIGHTRED);
        else if (i > 7)
            color(RED);
        cout << (char)219;
    }
    color(YELLOW);
}

// show the information of the current round play
void printHint(Players player) {
    // erasing old hint value
    color(BLACK);
    gotoxy(60, 0);
    cout << "       ";

    color(RED);
    gotoxy(55, 0);
    cout << "Hint: " << player.getHint() << " ?";
}

void printLife(Players player) {
    // erasing old hint value
    color(BLACK);
    gotoxy(40, 0);
    cout << "       ";

    color(RED);
    gotoxy(35, 0);
    cout << "Life: " << player.getLife() << " " << (char) 3;
}


void showTitleRound(Players player, int numRound) {
    // display player infomation
    color(RED);
    gotoxy(10,0);
    cout << "username: " << player.getUsername();
    printLife(player);
    printHint(player);

    // display round play information
    gotoxy(70,5);
    color(YELLOW);
    cout << "ROUND";
    gotoxy(72,6);
    cout << numRound;
    cout << endl;
    showTimeBar();

}

void resetTheBoard() {
    for(int i = 0; i < numBoxLength; i++)
    for(int j = 0; j < numBoxWidth; j++) {
        board[i][j].content = '#';
        board[i][j].isSelected = false;
    }

    int numPairs = numBoxLength * numBoxWidth / 2;
    while (numPairs) {
        int index, time = 2;
        char c = 65 + rand() % 26;

        while (time) { // gan 1 ky tu cho 2 o
            index = rand() % (numBoxLength * numBoxWidth); // vitri bat ki
            if (board[index / numBoxWidth][index % numBoxWidth].content == '#') { //
                board[index / numBoxWidth][index % numBoxWidth].content = c;
                board[index / numBoxWidth][index % numBoxWidth].x = 2 + (index % numBoxWidth) * 8;
                board[index / numBoxWidth][index % numBoxWidth].y = 2 + (index / numBoxWidth) * 4;
                time--;
            }
        }
        numPairs--;
    }

}

void showTheBoard() {
    color(YELLOW);
    for(int i = 0; i < numBoxLength; i++)
    for(int j = 0; j < numBoxWidth; j++)
        if (board[i][j].isSelected == false)
            board[i][j].printNode(board[i][j].x, board[i][j].y);
}

// find the next position for the cursor when it is deleted
void findNearestIsUnSelected(int &currentI, int &currentJ) {

    for(int j = currentJ + 1; j < numBoxWidth; j++)
        if(board[currentI][j].isSelected == false) {
                    currentJ = j;
                    return;
        }
    for(int i = currentI; i < numBoxLength; i++)
        for(int j = 0; j < numBoxWidth; j++)
            if(board[i][j].isSelected == false) {
                    currentI = i;
                    currentJ = j;
                    return;
            }
    for(int i = 0; i < numBoxLength; i++)
        for(int j = 0; j < numBoxWidth; j++)
            if(board[i][j].isSelected == false) {
                    currentI = i;
                    currentJ = j;
                    return;
            }
}
void findNearestIsUnSelectedDown(int &currentI, int &currentJ) {
    for(int i = currentI + 1; i < numBoxLength; i++)
        if (board[i][currentJ].isSelected == false) {
            currentI = i;
            return;
        }

    findNearestIsUnSelected(currentI, currentJ);
    return;
}

void findNearestIsUnSelectedUp(int &currentI, int &currentJ) {
    for(int i = currentI - 1; i >= 0; i--)
        if (board[i][currentJ].isSelected == false) {
            currentI = i;
            return;
        }

    findNearestIsUnSelected(currentI, currentJ);
    return;
}

void findNearestIsUnSelectedRight(int &currentI, int &currentJ) {
    for(int j = currentJ + 1; j < numBoxWidth; j++)
        if (board[currentI][j].isSelected == false) {
            currentJ = j;
            return;
        }

    findNearestIsUnSelected(currentI, currentJ);
    return;
}

void findNearestIsUnSelectedLeft(int &currentI, int &currentJ) {
    for(int j = currentJ - 1; j >= 0; j--)
        if (board[currentI][j].isSelected == false) {
            currentJ = j;
            return;
        }

    findNearestIsUnSelected(currentI, currentJ);
    return;
}

void shuffle() {
    int numPairs = 0;
    for(int i = 0; i < numBoxLength; i++)
    for(int j = 0; j < numBoxWidth; j++)
        if (board[i][j].isSelected == false) {
            board[i][j].content = '#';
            numPairs++;
        }

    while (numPairs) {
        int index, time = 2;
        char c = 65 + rand() % 26;

        while (time) { // gan 1 ky tu cho 2 o
            index = rand() % (numBoxLength * numBoxWidth); // vitri bat ki
            if (board[index / numBoxWidth][index % numBoxWidth].content == '#' && board[index / numBoxWidth][index % numBoxWidth].isSelected == false) { //
                board[index / numBoxWidth][index % numBoxWidth].content = c;
                time--;
            }
        }
        numPairs -= 2;
    }
}

void setCursorForBoard(Players player, int &pairs) {
    int currentI = 0, currentJ = 0, cntNumberOfSelectedNode = 0, cntNumDeleted = 0;
    Node node1, node2;
    node1.x = -1;   node1.y = -1;  // initialize the first ceil
    node2.x = -1;   node2.y = -1;  // initialize the second ceil is not
    board[currentI][currentJ].IsCurrentCursor(board[currentI][currentJ].x, board[currentI][currentJ].y);
    bool isExit = false;
    int keyArrow;
    if(timeOff == true)
        return;
    while(!isExit) {
        if(timeOff == true)
            return;


        if (kbhit()) {      //kbhit() is present in conio.h and used to determine if a key has been pressed or not.
            if(keyArrow != 6 && board[currentI][currentJ].isSelected == false)
                board[currentI][currentJ].IsCurrentCursorUnselected(board[currentI][currentJ].x, board[currentI][currentJ].y);
                 if(timeOff == true)
                return;
            keyArrow = getMoveFromKeyboard();
                if(timeOff == true)
                return;
            switch (keyArrow) {
            case 1:     // down
                    if(currentI < numBoxLength - 1)
                        currentI++;
                    else currentI = 0;
                    if(board[currentI][currentJ].isSelected == true) {
                        findNearestIsUnSelectedDown(currentI, currentJ);
                    }
                    break;

                case 2:     // up

                    if(currentI > 0)
                        currentI--;
                    else currentI = numBoxLength - 1;
                    if(board[currentI][currentJ].isSelected == true)
                        findNearestIsUnSelectedUp(currentI, currentJ);
                    break;


                case 3:     // right
                    if(currentJ < numBoxWidth - 1)
                        currentJ++;
                    else currentJ = 0;
                    if(board[currentI][currentJ].isSelected == true)
                        findNearestIsUnSelectedRight(currentI, currentJ);
                    break;

                case 4:     // left
                    if(currentJ > 0)
                        currentJ--;
                    else currentJ = numBoxWidth - 1;
                    if(board[currentI][currentJ].isSelected == true)
                        findNearestIsUnSelectedLeft(currentI, currentJ);
                    break;

                case 5:
                    isExit = true;
                    break;

                case 6:
                    if(node1.x == currentI && node1.y == currentJ)
                        break;

                    board[currentI][currentJ].isSelected = true;
                    board[currentI][currentJ].IsCurrentCursor(board[currentI][currentJ].x, board[currentI][currentJ].y);
                    cntNumberOfSelectedNode += 1;

                    if(cntNumberOfSelectedNode == 1) {
                        node1 = board[currentI][currentJ];
                        node1.x = currentI;
                        node1.y = currentJ;
                    } else {
                        node2 = board[currentI][currentJ];
                        node2.x = currentI;
                        node2.y = currentJ;
                        if(canConnect(node1, node2, 1)) { // checking to delete
                            playSoundWhenSelectRight();
                            cntNumDeleted += 2;
                            pairs++;
                            if (cntNumDeleted == 8 * 4) {
                                finishGame = true;
                                return;
                            }
                             int isCannotMatch = false;
                            while(!findSuggestion(false)) {
                                shuffle();
                                isCannotMatch = true;
                            }
                            if (isCannotMatch)
                                showTheBoard();

                        } else {
                            playSoundWhenSelectWrong();
                            board[node1.x][node1.y].isError(board[node1.x][node1.y].x, board[node1.x][node1.y].y);
                            board[node2.x][node2.y].isError(board[node2.x][node2.y].x, board[node2.x][node2.y].y);
                            Sleep(400);
                            int newLife = player.getLife() - 1;
                            player.updateLife(newLife);

                            if(newLife == 0)
                                return;
                            else
                                printLife(player);

                            board[node1.x][node1.y].isSelected = false;
                            board[node2.x][node2.y].isSelected = false;
                            board[node1.x][node1.y].IsCurrentCursorUnselected(board[node1.x][node1.y].x, board[node1.x][node1.y].y);
                            board[node2.x][node2.y].IsCurrentCursorUnselected(board[node2.x][node2.y].x, board[node2.x][node2.y].y);
                        }
                    }
                    break;


                case 7: // need a help
                    getHelp(player);
                    printHint(player);
                    break;
            }
            if(cntNumberOfSelectedNode != 2)
                board[currentI][currentJ].IsCurrentCursor(board[currentI][currentJ].x, board[currentI][currentJ].y);
            else {
                cntNumberOfSelectedNode = 0;
                findNearestIsUnSelected(currentI, currentJ);
                board[currentI][currentJ].IsCurrentCursor(board[currentI][currentJ].x, board[currentI][currentJ].y);
                gotoxy(40, 0);
                keyArrow = -1;
            }
        }

    }
}
void initializeTheBoard(Players &player, int &pairs, int cntRound) {
    getBackground(cntRound);
    // ref: https://www.programiz.com/cpp-programming/library-function/ctime/difftime
    time_t start1, finish1; // count time per round
    resetTheBoard();
    while (!findSuggestion(false)) {
        shuffle();
    }
    showTheBoard();
    time(&start1);
    setCursorForBoard(player, pairs);
    time(&finish1);
    int time = difftime(finish1, start1);
    countTime(time, player);
    gotoxy(0,0);
    color(YELLOW);
}

// BOARD USING LINKED LIST

void allocTheBoardLL() {
    boardLL = new NodeLL*[numBoxLength];
    for(int i = 0; i < numBoxLength; i++)
        boardLL[i] = new NodeLL[numBoxWidth];

    // Supported By Teacher Phan Thi Phuong Uyen
    for(int i = 0; i < numBoxLength; i++)
        for(int j = 0; j < numBoxWidth - 1; j++) {
            boardLL[i][j].right = &boardLL[i][j + 1];
            boardLL[i][j + 1].left = &boardLL[i][j];
        }
    for(int i = 0; i < numBoxLength - 1; i++)
        for(int j = 0; j < numBoxWidth; j++) {
            boardLL[i][j].down = &boardLL[i + 1][j];
            boardLL[i + 1][j].up = &boardLL[i][j];
        }
}

void setTheBoardLL() {
    for(int i = 0; i < numBoxLength; i++)
        for(int j = 0; j < numBoxWidth; j++)
            boardLL[i][j].content = '#';
    int numPairs = 16;
    while (numPairs) {
        int index, time = 2;
        char c = 65 + rand() % 26;

        while (time) { // gan 1 ky tu cho 2 o
            index = rand() % 32; // vitri bat ki
            if (boardLL[index / 8][index % 8].content == '#') { //
                boardLL[index / 8][index % 8].content = c;
                boardLL[index / 8][index % 8].x = 2 + (index % 8) * 8;
                boardLL[index / 8][index % 8].y = 2 + (index / 8) * 4;
                time--;
            }
        }
        numPairs--;
    }

    //boardLL[1][2 - 1].next = boardLL[1][2].next;
}

void showTheBoardLL(NodeLL *current) {
    NodeLL *right_ptr = current, *down_ptr = current;
    int i = 0;
    color(YELLOW);
    while(down_ptr) {
        right_ptr = down_ptr;
        while(right_ptr) {
            printNodeLL(right_ptr, (right_ptr) -> x, (right_ptr) ->y);
            right_ptr = right_ptr -> right;
        }
        down_ptr = down_ptr -> down;
    }
}

NodeLL *findTheMostRight(NodeLL * delNode, int &distant) {
    distant = 0;
    while(delNode -> right) {
        delNode = delNode -> right;
        distant++;
    }
    return delNode;
}

void updateNode(NodeLL * delNode) {
    int distant;
    NodeLL *mostRight = findTheMostRight(delNode, distant);
    // Add a link btw up-node & down-node of the mostRight
    if (mostRight -> up)
        mostRight -> up -> down = mostRight -> down;
    if (mostRight -> down)
        mostRight -> down -> up = mostRight -> up;

    mostRight -> isCurrentCursorUnselectedLL(mostRight -> x, mostRight -> y);
    printNodeLLNull(mostRight, mostRight -> x, mostRight -> y);

    int cnt = 0;
    // update the new link up & down in the right sequence of the delNode
    while(distant--) {
        if (mostRight -> left) {
            mostRight -> up = mostRight -> left -> up;
            if (mostRight -> left -> up)
                mostRight -> left -> up -> down = mostRight;
            mostRight -> down = mostRight -> left -> down;
            if (mostRight -> left -> down)
                mostRight -> left -> down -> up = mostRight;
        }
        else {
            mostRight -> up = NULL;
            mostRight ->down = NULL;
        }
        mostRight -> x -=8;
        mostRight = mostRight -> left;
    }

    // update the link btw the left-delNode & the right-delNode
    if (delNode -> left != NULL)
        (delNode -> left) -> right = delNode -> right; // sure
    if (delNode -> right != NULL)
        delNode -> right -> left = delNode -> left;
}

void deleteTheNodeLL(NodeLL *delNode) {
    updateNode(delNode);
    showTheBoardLL(delNode -> right);
}

void shuffleLL() {
    int numPairs = 0;
    for(int i = 0; i < numBoxLength; i++)
        for(int j = 0; j < numBoxWidth; j++)
            if (boardLL[i][j].content != '\0') {
                boardLL[i][j].content = '#';
                numPairs++;
        }

    while (numPairs) {
        int index, time = 2;
        char c = 65 + rand() % 26;

        while (time) { // gan 1 ky tu cho 2 o
            index = rand() % 32; // vitri bat ki
            if (boardLL[index / 8][index % 8].content == '#') { //
                boardLL[index / 8][index % 8].content = c;
                time--;
            }
        }
        numPairs-= 2;
    }
}

void setCursorForBoardLL(Players &player, int &pair) {
    int currentI = 0, currentJ = 0, cntNumberOfSelectedNode = 0, cntNumDeleted = 0;
    NodeLL **node1 = NULL, **node2 = NULL;
    NodeLL **currentNode = boardLL;
    (**currentNode).isCurrentCursorLL((**currentNode).x, (**currentNode).y);
    bool isExit = false;
    int keyArrow;
    if(timeOff == true)
        return;
    while(!isExit) {
        if(timeOff == true)
            return;

        if (kbhit()) {      //kbhit() is present in conio.h and used to determine if a key has been pressed or not.
            if (node1 == NULL || (node1 != NULL && *currentNode != *node1))
                (**currentNode).isCurrentCursorUnselectedLL((**currentNode).x, (**currentNode).y);

            keyArrow = getMoveFromKeyboard();
            switch (keyArrow) {
                case 1:

                    // Support by teacher Phan Thi Phuong Uyen
                    if((**currentNode).down != NULL)
                        currentNode = &(**currentNode).down;
                    else
                        while((**currentNode).up != NULL)
                            currentNode = &(**currentNode).up;


                    //if((boardLL[currentI] + currentJ) == NULL || boardLL[currentI][currentJ].isSelected == true)
                        //findNearestIsUnSelected(currentI, currentJ, numBoxLength, numBoxWidth);
                    break;

                case 2:
                    if((**currentNode).up != NULL)
                        currentNode = &(**currentNode).up;
                    else
                        while((**currentNode).down != NULL)
                            currentNode = &(**currentNode).down;
                    //if(board[currentI][currentJ].isSelected == true)
                      //  findNearestIsUnSelected(currentI, currentJ, numBoxLength, numBoxWidth);
                    break;
                case 3:
                    if((**currentNode).right != NULL)
                        currentNode = &(**currentNode).right;
                    else
                        while((**currentNode).left != NULL)
                            currentNode = &(**currentNode).left;
                    //if(board[currentI][currentJ].isSelected == true)
                      //  findNearestIsUnSelected(currentI, currentJ, numBoxLength, numBoxWidth);
                    break;
                case 4:
                    if((**currentNode).left != NULL)
                        currentNode = &(**currentNode).left;
                    else
                        while((**currentNode).right != NULL)
                            currentNode = &(**currentNode).right;
                    //if(board[currentI][currentJ].isSelected == true)
                      //  findNearestIsUnSelected(currentI, currentJ, numBoxLength, numBoxWidth);
                    break;

                case 5:
                    isExit = true;
                    break;
                case 6:
                    if(cntNumberOfSelectedNode == 0) {
                        node1 = currentNode;
                        gotoxy(0, 1);
                        color(YELLOW);
                        cntNumberOfSelectedNode++;
                    }
                    else {
                        if (*node1 == *currentNode)
                            break;
                        cntNumberOfSelectedNode = 0;
                        node2 = currentNode;
                        if (canConnectLL(*node1, *node2, 1)) {

                            (*node1) -> content = '\0';
                            (*node2) -> content = '\0';


                            deleteTheNodeLL(*node1);

                            if ((*node2) -> right)
                            currentNode = &((*node2) ->right);
                            else
                            if ((*node2) -> left)
                                currentNode = &((*node2) -> left);
                            else
                            if ((*node2) -> up)
                                currentNode = &((*node2) -> up);
                            else
                            if ((*node2) -> down)
                                currentNode = &((*node2) -> down);
                            else
                                currentNode = NULL;

                            deleteTheNodeLL(*node2);
                            cntNumDeleted += 2;

                            if (cntNumDeleted == 32) {
                                finishGame = true;
                                return;
                            }
                            bool isShuffle = false;
                            while(!findSuggestionLL(false)) {
                                shuffleLL();
                                isShuffle = true;
                            }
                            if (isShuffle) {
                                showTheBoardLL(*boardLL);
                            }

                        } else {

                            (*node1) -> isError((*node1) -> x, (*node1) -> y);
                            (*node2) -> isError((*node2) -> x, (*node2) -> y);
                            int newLife = player.getLife() - 1;
                            player.updateLife(newLife);

                            if(newLife == 0)
                                return;
                            else
                                printLife(player);
                            Sleep(300);
                            (*node1) -> isCurrentCursorUnselectedLL((*node1) -> x, (*node1) -> y);
                            (*node2) -> isCurrentCursorUnselectedLL((*node2) -> x, (*node2) -> y);

                        }
                        node1 = node2 = NULL;
                    }
                    break;
                case 7:
                    getHelpLL(player);
                    printHint(player);
                    break;
            }
            gotoxy(0, 0);
            color(YELLOW);
            (**currentNode).isCurrentCursorLL((**currentNode).x, (**currentNode).y);
        }
    }
}


void initializeTheBoardLL(Players &player, int &pairs) {
    time_t start2, finish2;
    allocTheBoardLL();
    setTheBoardLL();
    while(!findSuggestionLL(false))
        shuffleLL();

    showTheBoardLL(boardLL[0]);
    time(&start2);
    setCursorForBoardLL(player , pairs);
    time(&finish2);
    int time = difftime(finish2, start2);
    countTime(time, player);
}
