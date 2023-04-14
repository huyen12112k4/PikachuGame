#include "Models.h"

int Players::next_id = 0;

void Players::updatePlayer(int newLife, int newHint, int newTime) {
    life = newLife;
    hint = newHint;
    time = newTime;   // UPDATE
}

void Node::printNode(int x, int y) {            // the function print the Node at the coordination (x; y)
    for(int i = 0; i < 5; i++) {
        gotoxy(x, y + i);
        for(int j = 0; j < 10; j++)
            cout << box[i][j];
        cout << endl;
    }
    gotoxy(x + 4, y + 2);
    cout << content;
}

void Node::IsCurrentCursor(int x, int y) {      // the function set the Node at (x; y) is selected by cursor
    gotoxy(x + 1, y + 1);
    color(YELLOW);
    for(int i = 0; i < 3; i++) {
        gotoxy(x + 1, y + 1 + i);
        for(int j = 0; j < 7; j++)
            cout << (char) 219;
    }
    if(content != '\0') {
        gotoxy(x + 4, y + 2);
        cout << content;
    }
}

void Node::IsCurrentCursorUnselected(int x, int y) {    // the function unselected the Node at (x; y)
    gotoxy(x + 1, y + 1);
    color(0);
    for(int i = 0; i < 3; i++) {
        gotoxy(x + 1, y + 1 + i);
        for(int j = 0; j < 7; j++)
            cout << (char) 219;
    }
    color(YELLOW);
    gotoxy(x + 4, y + 2);
    cout << content;
}

void Node::isMarked(int x, int y) {
    gotoxy(x + 1, y + 1);
    color(GREEN);
    for(int i = 0; i < 3; i++) {
        gotoxy(x + 1, y + 1 + i);
        for(int j = 0; j < 7; j++)
            cout << (char) 219;
    }
    if(content != '\0') {
        gotoxy(x + 4, y + 2);
        cout << content;
    }
}

void Node::isMarkedHighLight(int x, int y) {
    gotoxy(x + 1, y + 1);
    color(LIGHTCYAN);
    for(int i = 0; i < 3; i++) {
        gotoxy(x + 1, y + 1 + i);
        for(int j = 0; j < 7; j++)
            cout << (char) 219;
    }
    if(content != '\0') {
        gotoxy(x + 4, y + 2);
        cout << content;
    }
}

void Node::isError(int x, int y) {      // the function set the Node at (x; y) is selected by cursor
    gotoxy(x + 1, y + 1);
    color(RED);
    for(int i = 0; i < 3; i++) {
        gotoxy(x + 1, y + 1 + i);
        for(int j = 0; j < 7; j++)
            cout << (char) 219;
    }
    if(content != '\0') {
        gotoxy(x + 4, y + 2);
        cout << content;
    }
}

void Node::deleteNode(int x, int y, int i, int j) {         // the function delete the Node when it satisfied of the condition
    content = '\0';
    int length = 3, width = 7, xTmp = x, yTmp = y;
    x++; y++;
    if (j == 0 || board[i][j - 1].isSelected == true) {     // check to delete the left border
        x--; width++;
    }
    if(i == 0 || board[i - 1][j].isSelected == true) {      // check to delete the top border
        y--; length++;
    }
    if(j == 7 || board[i][j + 1].isSelected == true)        // check to delete the right border
        width++;
    if(i == 3 || board[i + 1][j].isSelected == true)        // check to delete the bottom border
        length++;

    // delete the content in the Node that must be deleted
    gotoxy(x, y);
    color(0);
    for(int i = 0; i < length; i++) {
        gotoxy(x, y + i);
        for(int j = 0; j < width; j++)
            cout << (char) 219;
    }

    // check the corner is existed to rewrite the linked character at the corner
    color(YELLOW);

    if(i != 3 && j != 7 && board[i + 1][j + 1].isSelected == false) {
        gotoxy(xTmp + 8, yTmp + 4);
        cout << 'o';
    }
    if(i != 0 && j != 7 && board[i - 1][j + 1].isSelected == false) {
        gotoxy(xTmp + 8, yTmp);
        cout << 'o';
    }
    if(i != 0 && j != 0 && board[i - 1][j - 1].isSelected == false) {
        gotoxy(xTmp, yTmp);
        cout << 'o';
    }
    if(i != 3 && j != 0 && board[i + 1][j - 1].isSelected == false) {
        gotoxy(xTmp, yTmp + 4);
        cout << 'o';
     }

}

// Node LINKED LIST

void printNodeLL(NodeLL *head, int x, int y) {

    for(int i = 0; i < 5; i++) {
        gotoxy(x, y + i);
        for(int j = 0; j < 9; j++)
            if(i == 2 && j == 4)
                cout << head -> content;
            else
            cout << head -> box[i][j];
        if(i != 4)
                cout << endl;
    }
}

void printNodeLLNull(NodeLL *node, int x, int y) {
    color(BLACK);
    gotoxy(x + 4, y + 2);
    cout << " ";

    for(int i = 1; i < 4; i++) {
        gotoxy(x + 8, y + i);
        cout << " ";
    }

    if (node -> up == NULL || abs(node -> up -> y - node -> y) > 4) {
        gotoxy(x + 1, y);
        for(int i = 0; i < 8; i++)
            cout << " ";
    }
    if (node -> down == NULL || abs(node -> down -> y - node -> y) > 4) {
        gotoxy(x + 1, y + 4);
        for(int i = 0; i < 8; i++)
            cout << " ";
    }

    if (node -> left == NULL) {
        for(int i = 1; i < 4; i++) {
            gotoxy(x, y + i);
            cout << " ";
        }
    }
    if (node -> x == 2) {
        if (node -> up == NULL || node -> y - node -> up -> y > 4) {
            gotoxy(node -> x, node -> y);
            cout << " ";
        }
        if (node -> down == NULL || node -> down -> y - node -> y > 4) {
            gotoxy(node -> x, node -> y + 4);
            cout << " ";
        }
    }

}

void NodeLL::isCurrentCursorLL(int x, int y) {      // the function set the Node at (x; y) is selected by cursor
    gotoxy(x + 1, y + 1);
    color(YELLOW);
    for(int i = 0; i < 3; i++) {
        gotoxy(x + 1, y + 1 + i);
        for(int j = 0; j < 7; j++)
            cout << (char) 219;
    }
    if(content != '\0') {
        gotoxy(x + 4, y + 2);
        cout << content;
    }
}

void NodeLL::isCurrentCursorUnselectedLL(int x, int y) {    // the function unselected the Node at (x; y)
    gotoxy(x + 1, y + 1);
    color(0);
    for(int i = 0; i < 3; i++) {
        gotoxy(x + 1, y + 1 + i);
        for(int j = 0; j < 7; j++)
            cout << (char) 219;
    }
    color(YELLOW);
    gotoxy(x + 4, y + 2);
    cout << content;
}

void NodeLL::isMark(int x, int y) {      // the function set the Node at (x; y) is selected by cursor
    gotoxy(x + 1, y + 1);
    color(GREEN);
    for(int i = 0; i < 3; i++) {
        gotoxy(x + 1, y + 1 + i);
        for(int j = 0; j < 7; j++)
            cout << (char) 219;
    }
    if(content != '\0') {
        gotoxy(x + 4, y + 2);
        cout << content;
    }
}


void NodeLL::isMarkHighLight(int x, int y) {      // the function set the Node at (x; y) is selected by cursor
    gotoxy(x + 1, y + 1);
    color(LIGHTCYAN);
    for(int i = 0; i < 3; i++) {
        gotoxy(x + 1, y + 1 + i);
        for(int j = 0; j < 7; j++)
            cout << (char) 219;
    }
    if(content != '\0') {
        gotoxy(x + 4, y + 2);
        cout << content;
    }
}

void NodeLL::isError(int x, int y) {      // the function set the Node at (x; y) is selected by cursor
    gotoxy(x + 1, y + 1);
    color(RED);
    for(int i = 0; i < 3; i++) {
        gotoxy(x + 1, y + 1 + i);
        for(int j = 0; j < 7; j++)
            cout << (char) 219;
    }
    if(content != '\0') {
        gotoxy(x + 4, y + 2);
        cout << content;
    }
}

