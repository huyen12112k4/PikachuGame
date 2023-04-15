#include "Checking.h"

// PATH I
void drawPathI(Node node1, Node node2, int direction, int colorSet) {
    int coorXNode1 = board[node1.x][node1.y].x, coorYNode1 = board[node1.x][node1.y].y, coorXNode2 = board[node2.x][node2.y].x, coorYNode2 = board[node2.x][node2.y].y;
    color(colorSet);
    // Draw horizontal line
    if(direction == 0) {

        gotoxy(min(coorXNode1, coorXNode2) + 5, coorYNode1 + 2);
        cout << (char) 17;
        for(int i = min(coorXNode1, coorXNode2); i < max(coorXNode1, coorXNode2) - 3; i++)
            cout << (char) 250;
        cout << (char) 16;
    } else {    // Draw vertical line
        gotoxy(coorXNode1 + 4, min(coorYNode1, coorYNode2) + 3);
        cout << (char) 30;
        int i;
        for(i = 1; i <= max(coorYNode1, coorYNode2) - min(coorYNode1, coorYNode2) - 3; i++) {
            gotoxy(coorXNode1 + 4, min(coorYNode1, coorYNode2) + 3 + i);
            cout << (char) 250;

        }
        gotoxy(coorXNode1 + 4, min(coorYNode1, coorYNode2) + 3 + i);
        cout << (char) 31;
    }

    if (colorSet != BLACK)
        Sleep(400); // pause 0.4s
}


// CHECK I MATCHING
bool checkPathI(Node node1, Node node2, int isDelete) {
    if (node1.x == node2.x) {   // check whether 2 ceil have the same line
        for(int j = min(node1.y, node2.y); j <= max(node1.y, node2.y); j++)
            if (board[node1.x][j].isSelected == false)
                return false;
        if (isDelete) {

            board[node1.x][node1.y].isMarked(board[node1.x][node1.y].x, board[node1.x][node1.y].y);
            board[node2.x][node2.y].isMarked(board[node2.x][node2.y].x, board[node2.x][node2.y].y);
            drawPathI(node1, node2, 0, LIGHTRED);
            drawPathI(node1, node2, 0, BLACK);
        }

        return true;
    } else

    if (node1.y == node2.y) {   // check whether 2 ceil have the same column
        for(int i = min(node1.x, node2.x); i <= max(node1.x, node2.x); i++)
            if (board[i][node1.y].isSelected == false)
                return false;
        if (isDelete) {
            board[node1.x][node1.y].isMarked(board[node1.x][node1.y].x, board[node1.x][node1.y].y);
            board[node2.x][node2.y].isMarked(board[node2.x][node2.y].x, board[node2.x][node2.y].y);
            drawPathI(node1, node2, 1, LIGHTRED);
            drawPathI(node1, node2, 1, BLACK);
        }
        return true;
    } else
        return false;
}

// PATH Z
void drawPathZ(Node node1, Node node2, int middle, int direction, int colorSet) {
    int coorNode1XMiddle = board[node1.x][node1.y].x + 4, coorNode1YMiddle = board[node1.x][node1.y].y + 2;
    int coorNode2XMiddle = board[node2.x][node2.y].x + 4, coorNode2YMiddle = board[node2.x][node2.y].y + 2;
    color(colorSet);
    if(direction == 1) { // Horizontal Draw
        // starting draw at node1 position
        int currentX = coorNode1XMiddle + 1, currentY = coorNode1YMiddle;   // starting the linked line next to the content
        gotoxy(currentX, currentY);
        cout << (char) 17;
        for(int i = 0; i < abs(middle - node1.y) * 8 - 2; i++)
            cout << (char) 250;

            // draw the middle line
        // starting draw the top to the bottom of the middle line
        int topMiddleX = board[node1.x][middle].x + 4;
        int topMiddleY = min(board[node1.x][middle].y, board[node2.x][middle].y) + 2;
        int bottomMiddleX = topMiddleX;
        int bottomMiddleY = max(board[node1.x][middle].y, board[node2.x][middle].y) + 2;

        currentX = topMiddleX, currentY = topMiddleY;
        gotoxy(currentX, currentY);
        cout << 'o';
        for(int i = topMiddleY; i <= bottomMiddleY - 2; i++) {
            currentY++;
            gotoxy(currentX, currentY);
            cout << (char) 250;
        }
        currentY++;
        gotoxy(currentX, currentY);
        cout << 'o';

            // draw the horizontal to node2
        currentY = coorNode2YMiddle;
        gotoxy(currentX, currentY);
        for(int i = 0; i < abs(middle - node2.y) * 8 - 1; i++)
            cout << (char) 250;
        cout << (char) 16;

    } else {             // Vertical Draw
        // starting draw at node1 position
        int currentX = coorNode1XMiddle, currentY = coorNode1YMiddle + 1;   // starting the linked line next to the content
        gotoxy(currentX, currentY);
        cout << (char) 30;
        for(int i = 0; i < abs(middle - node1.x) * 4 - 2; i++) {
            currentY++;
            gotoxy(currentX, currentY);
            cout << (char) 250;
        }

            // Draw the middle line
        // starting draw the left to the right of the middle line
        int leftMiddleX = min(board[middle][node1.y].x, board[middle][node2.y].x) + 4;
        int rightMiddleX = max(board[middle][node1.y].x, board[middle][node2.y].x) + 4;
        currentX = leftMiddleX;
        currentY++;
        gotoxy(currentX, currentY);
        cout << 'o';
        for(int i = leftMiddleX; i <= rightMiddleX - 2; i++)
            cout << (char) 250;
        cout << 'o';

        // Draw the vertical to node2
        currentX = coorNode2XMiddle;
        for(int i = 0; i < abs(middle - node2.x) * 4 - 2; i++) {
            currentY++;
            gotoxy(currentX, currentY);
            cout << (char) 250;
        }
        currentY++;
        gotoxy(currentX, currentY);
        cout << (char) 31;
    }

    if(colorSet != BLACK)
        Sleep(400);
}

// CHECKING Z MATCHING
bool checkPathZ(Node node1, Node node2, int isDelete) {
    // check Z path starting with horizontal
    if (node1.y > node2.y)
        swap(node1, node2);
    int right = node1.y;
    while(board[node1.x][right + 1].isSelected == true && right < node2.y)
        right++;
    int left = node2.y;
    while(board[node2.x][left - 1].isSelected == true && left > node1.y)
        left--;
    bool check = true;
    for(int j =left; j <= right; j++) {
        bool check = true;
        for(int i = min(node1.x, node2.x); i <= max(node1.x, node2.x); i++)
            if(board[i][j].isSelected == false) {
                check = false;
                break;
            }
        if(check == true) {
            if (isDelete) {
                board[node1.x][node1.y].isMarked(board[node1.x][node1.y].x, board[node1.x][node1.y].y);
                board[node2.x][node2.y].isMarked(board[node2.x][node2.y].x, board[node2.x][node2.y].y);
                drawPathZ(node1, node2, j, 1, LIGHTRED);
                drawPathZ(node1, node2, j, 1, BLACK);
            }
            return check;
        }
    }

    // check Z path starting vertical
    if (node1.x > node2.x)
        swap(node1, node2);
    int bottom = node1.x;
    while(board[bottom + 1][node1.y].isSelected == true && bottom < node2.x)
        bottom++;
    int top = node2.x;
    while(board[top - 1][node2.y].isSelected == true && top > node1.x)
        top--;
    check = true;

    for(int i = top; i <= bottom; i++) {
        bool check = true;
        for(int j = min(node1.y, node2.y); j <= max(node1.y, node2.y); j++)
            if(board[i][j].isSelected == false) {
                check = false;
                break;
            }
        if(check == true) {
            if (isDelete) {
                board[node1.x][node1.y].isMarked(board[node1.x][node1.y].x, board[node1.x][node1.y].y);
                board[node2.x][node2.y].isMarked(board[node2.x][node2.y].x, board[node2.x][node2.y].y);
                drawPathZ(node1, node2, i, 0, LIGHTRED);
                drawPathZ(node1, node2, i, 0, BLACK);
            }
            return check;
        }
    }
    return false;
}

// PATH L

void drawPathL(Node node1, Node node2, int middle, int direction, int colorSet) {
    int coorNode1XMiddle = board[node1.x][node1.y].x + 4, coorNode1YMiddle = board[node1.x][node1.y].y + 2;
    int coorNode2XMiddle = board[node2.x][node2.y].x + 4, coorNode2YMiddle = board[node2.x][node2.y].y + 2;
    color(colorSet);
    if(direction == 1) { // Horizontal Draw

        // starting draw at Node1 position
        int currentX = coorNode1XMiddle + 1, currentY = coorNode1YMiddle;   // starting the linked line next to the content
        gotoxy(currentX, currentY);
        cout << (char) 17;
        for(int i = 0; i < abs(middle - node1.y) * 8 - 2; i++)
            cout << (char) 250;

            // draw the middle line
        // starting draw the top to the bottom of the middle second line
        int topMiddleX = board[node1.x][middle].x + 4;
        int topMiddleY = board[node1.x][middle].y + 2;
        int bottomMiddleX = topMiddleX;
        int bottomMiddleY = board[node2.x][middle].y + 2;

        currentX = topMiddleX, currentY = topMiddleY;
        gotoxy(currentX, currentY);
        cout << 'o';

        if (node2.x > node1.x) {
            for(int i = 1; i <= abs(bottomMiddleY - topMiddleY) - 2; i++) {
                currentY++;
                gotoxy(currentX, currentY);
                cout << (char) 250;
            }
        currentY++;
        gotoxy(currentX, currentY);
        cout << (char) 31;
        } else {
            for(int i = 1; i <= abs(bottomMiddleY - topMiddleY) - 2; i++) {
                currentY--;
                gotoxy(currentX, currentY);
                cout << (char) 250;
            }
        currentY--;
        gotoxy(currentX, currentY);
        cout << (char) 30;
        }


    } else {
        int currentX = coorNode1XMiddle, currentY = coorNode1YMiddle;
        // starting draw at Node1 position
        if (node1.x > node2.x) {
            currentY--;   // starting the linked line next to the content
            gotoxy(currentX, currentY);
            cout << (char) 31;
            for(int i = 0; i < abs(node2.x - node1.x) * 4 - 2; i++) {
                currentY--;
                gotoxy(currentX, currentY);
                cout << (char) 250;
            }
            currentY--;
            gotoxy(currentX, currentY);
            cout << 'o';
        } else {
            currentY++;// starting the linked line next to the content
            gotoxy(currentX, currentY);
            cout << (char) 30;
            for(int i = 0; i < abs(node2.x - node1.x) * 4 - 2; i++) {
                currentY++;
                gotoxy(currentX, currentY);
                cout << (char) 250;
            }
            currentY++;
            gotoxy(currentX, currentY);
            cout << 'o';
        }
        int leftMiddleX = board[node2.x][node1.y].x + 4;
        int rightMiddleX = board[node2.x][node2.y].x + 4;
        currentX = leftMiddleX + 1;
        gotoxy(currentX, currentY);
        for(int i = leftMiddleX; i <= rightMiddleX - 3; i++)
            cout << (char) 250;
        cout << (char) 16;
    }

    if (colorSet != BLACK)
        Sleep(400);

}

// ref : https://nguyenvanquan7826.wordpress.com/2014/03/25/thuat-toan-game-pokemon-pikachu/
bool checkPathL(Node node1, Node node2, int isDelete) {
    // make sure Node1 is always on the left of Node2
    if (node1.y > node2.y)
        swap(node1, node2);

    bool check = true;
    // horizontal then vertical
    for(int j = node1.y; j <= node2.y; j++)
        if(board[node1.x][j].isSelected == false)
           check = false;
    if (check) {
        for (int i = min(node1.x, node2.x); i <= max(node1.x, node2.x); i++)
            if (board[i][node2.y].isSelected == false)
                check = false;
    }
    if (check) {
        if (isDelete) {
            board[node1.x][node1.y].isMarked(board[node1.x][node1.y].x, board[node1.x][node1.y].y);
            board[node2.x][node2.y].isMarked(board[node2.x][node2.y].x, board[node2.x][node2.y].y);
            drawPathL(node1, node2, node2.y, 1, LIGHTRED);
            drawPathL(node1, node2, node2.y, 1, BLACK);
        }
        return true;
    }
    check = true;
    // vertical then horizontal
    for (int i = min(node1.x, node2.x); i <= max(node1.x, node2.x); i++) {
            if (board[i][node1.y].isSelected == false)
                return false;
    }
    if (check) {
        for(int j = node1.y; j <= node2.y; j++)
            if(board[node2.x][j].isSelected == false)
                return false;
    }
    if (check) {
        if (isDelete) {
            board[node1.x][node1.y].isMarked(board[node1.x][node1.y].x, board[node1.x][node1.y].y);
            board[node2.x][node2.y].isMarked(board[node2.x][node2.y].x, board[node2.x][node2.y].y);
            drawPathL(node1, node2, node2.y, 0, LIGHTRED);
            drawPathL(node1, node2, node2.y, 0, BLACK);
        }
    return true;
    }
}

// PATH U

void drawPathU(Node node1, Node node2, int middle, int direction, int colorSet) {
    int coorNode1XMiddle = board[node1.x][node1.y].x + 4, coorNode1YMiddle = board[node1.x][node1.y].y + 2;
    int coorNode2XMiddle = board[node2.x][node2.y].x + 4, coorNode2YMiddle = board[node2.x][node2.y].y + 2;
    color(colorSet);
    if (direction == 0) {
        int topMiddleX, topMiddleY, bottomMiddleX, bottomMiddleY;
        int horizontalNode1, horizontalNode2;

        if (middle != 8) {
            horizontalNode1 = abs(middle - node1.y) * 8 - 2;
            horizontalNode2 = abs(middle - node2.y) * 8 - 2;
            topMiddleX = board[node1.x][middle].x + 4;
            topMiddleY = min(board[node1.x][middle].y, board[node2.x][middle].y) + 2;
            bottomMiddleX = topMiddleX;
            bottomMiddleY = max(board[node1.x][middle].y, board[node2.x][middle].y) + 2;
        }
        else {
            horizontalNode1 = abs(middle - node1.y) * 8 - 4;
            horizontalNode2 = abs(middle - node2.y) * 8 - 4;
            topMiddleX = board[node1.x][7].x + 10;
            topMiddleY = min(board[node1.x][node1.y].y, board[node2.x][node2.y].y) + 2;
            bottomMiddleX = topMiddleX;
            bottomMiddleY = max(board[node1.x][node1.y].y, board[node2.x][node2.y].y) + 2;
        }

        int currentX = coorNode1XMiddle + 1, currentY = coorNode1YMiddle;   // starting the linked line next to the content
        gotoxy(currentX, currentY);
        cout << (char) 17;
        for(int i = 0; i < horizontalNode1; i++)
            cout << (char) 250;
        cout << 'o';
            // draw the middle line
        // starting draw the top to the bottom of the middle line
        currentX = topMiddleX, currentY = topMiddleY;

        for(int i = topMiddleY; i <= bottomMiddleY - 2; i++) {
            currentY++;
            gotoxy(currentX, currentY);
            cout << (char) 250;
        }

            // draw the horizontal to node2
        currentX = coorNode2XMiddle + 1;
        currentY = coorNode2YMiddle;
        gotoxy(currentX, currentY);
        cout << (char) 17;
        for(int i = 0; i < horizontalNode2; i++)
            cout << (char) 250;
        cout << 'o';
    } else
    if (direction == 1) {
        int topMiddleX, topMiddleY, bottomMiddleX, bottomMiddleY;
        int horizontalNode1, horizontalNode2;

        if (middle != -1) {
            horizontalNode1 = abs(middle - node1.y) * 8 - 2;
            horizontalNode2 = abs(middle - node2.y) * 8 - 2;

            topMiddleX = board[node1.x][middle].x + 4;
            topMiddleY = min(board[node1.x][middle].y, board[node2.x][middle].y) + 2;
            bottomMiddleX = topMiddleX;
            bottomMiddleY = max(board[node1.x][middle].y, board[node2.x][middle].y) + 2;

        } else
        {
            horizontalNode1 = abs(middle - node1.y) * 8 - 4;
            horizontalNode2 = abs(middle - node2.y) * 8 - 4;
            topMiddleX = board[node1.x][0].x - 2;
            topMiddleY = min(coorNode1YMiddle, coorNode2YMiddle);
            bottomMiddleX = topMiddleX;
            bottomMiddleY = max(coorNode1YMiddle, coorNode2YMiddle);;

        }

        int currentX = coorNode1XMiddle - 1, currentY = coorNode1YMiddle;   // starting the linked line next to the content
        gotoxy(currentX, currentY);
        cout << (char) 16;
        for(int i = 0; i < horizontalNode1; i++) {
            currentX--;
            gotoxy(currentX, currentY);
            cout << (char) 250;
        }
        currentX--;
        gotoxy(currentX, currentY);
        cout << 'o';

            // draw the middle line
        // starting draw the top to the bottom of the middle line

        currentX = topMiddleX, currentY = topMiddleY;
        gotoxy(currentX, currentY);
        for(int i = topMiddleY; i <= bottomMiddleY - 2; i++) {
            currentY++;
            gotoxy(currentX, currentY);
            cout << (char) 250;
        }
        //Sleep(1000);
            // draw the horizontal to node2
        currentX = coorNode2XMiddle - 1, currentY = coorNode2YMiddle;   // starting the linked line next to the content
        gotoxy(currentX, currentY);
        cout << (char) 16;
        for(int i = 0; i < horizontalNode2; i++) {
            currentX--;
            gotoxy(currentX, currentY);
            cout << (char) 250;
        }
        currentX--;
        gotoxy(currentX, currentY);
        cout << 'o';

    } else
    if (direction == 2) {   // draw down, then draw to right, then draw up
        int leftMiddleX, leftMiddleY, rightMiddleX, rightMiddleY;
        int verticalNode1, verticalNode2;

        if (middle != 4) {
            verticalNode1 = abs(middle - node1.x) * 4 - 2;
            verticalNode2 = abs(middle - node2.x) * 4 - 2;
            leftMiddleX = min(board[middle][node1.y].x, board[middle][node2.y].x) + 4;
            leftMiddleY = board[middle][node1.y].y + 2;
            rightMiddleX = max(board[middle][node1.y].x, board[middle][node2.y].x) + 4;
            rightMiddleY = leftMiddleY;

        } else {
            verticalNode1 = abs(middle - node1.x) * 4 - 3;
            verticalNode2 = abs(middle - node2.x) * 4 - 3;
            leftMiddleX = min(coorNode1XMiddle, coorNode2XMiddle);
            leftMiddleY = board[3][node1.y].y + 4 + 1;
            rightMiddleX = min(coorNode1XMiddle, coorNode2XMiddle);
            rightMiddleY = leftMiddleY;
        }

        int currentX = coorNode1XMiddle, currentY = coorNode1YMiddle + 1;   // starting the linked line next to the content
        gotoxy(currentX, currentY);
        cout << (char) 30;
        for(int i = 0; i < verticalNode1; i++) {
            currentY++;
            gotoxy(currentX, currentY);
            cout << (char) 250;
        }
        currentY++;
        gotoxy(currentX, currentY);
        cout << 'o';
            // draw the middle line

        currentX = leftMiddleX + 1; currentY = leftMiddleY;
        gotoxy(currentX, currentY);
        for(int i = 0; i <= abs(node1.y - node2.y)* 8 - 2; i++)
            cout << (char) 250;
        cout << 'o';

        // draw the vertical to node2
        currentX = coorNode2XMiddle; currentY = coorNode2YMiddle + 1;
        gotoxy(currentX, currentY);
        cout << (char) 30;
        for(int i = 0; i < verticalNode2; i++) {
            currentY++;
            gotoxy(currentX, currentY);
            cout << (char) 250;
        }
    } else {
        int leftMiddleX, leftMiddleY, rightMiddleX, rightMiddleY;
        int verticalNode1, verticalNode2;

        if (middle != -1) {
            verticalNode1 = abs(middle - node1.x) * 4 - 2;
            verticalNode2 = abs(middle - node2.x) * 4 - 2;
            leftMiddleX = min(coorNode1XMiddle, coorNode2XMiddle);
            leftMiddleY = board[middle][node1.y].y + 2;
            rightMiddleX = min(coorNode1XMiddle, coorNode2XMiddle);
            rightMiddleY = leftMiddleY;

        } else {
            verticalNode1 = abs(middle - node1.x) * 4 - 3;
            verticalNode2 = abs(middle - node2.x) * 4 - 3;
            leftMiddleX = min(coorNode1XMiddle, coorNode2XMiddle);
            leftMiddleY = board[0][node1.y].y - 1;
            rightMiddleX = max(coorNode1XMiddle, coorNode2XMiddle);
            rightMiddleY = leftMiddleY;
        }
        int currentX = coorNode1XMiddle, currentY = coorNode1YMiddle - 1;   // starting the linked line next to the content
        gotoxy(currentX, currentY);
        cout << (char) 31;
        for(int i = 0; i < verticalNode1; i++) {
            currentY--;
            gotoxy(currentX, currentY);
            cout << (char) 250;
        }
        currentY--;
        gotoxy(currentX, currentY);
        cout << 'o';
            // draw the middle line

        currentX = leftMiddleX + 1; currentY = leftMiddleY;
        gotoxy(currentX, currentY);
        for(int i = 0; i <= abs(node1.y - node2.y)* 8 - 2; i++)
            cout << (char) 250;
        cout << 'o';

        // draw the vertical to node2
        currentX = coorNode2XMiddle; currentY = coorNode2YMiddle - 1;
        gotoxy(currentX, currentY);
        cout << (char) 31;
        for(int i = 0; i < verticalNode2; i++) {
            currentY--;
            gotoxy(currentX, currentY);
            cout << (char) 250;
        }
    }
    if(colorSet != BLACK)
        Sleep(400);
}

bool checkPathU(Node node1, Node node2, int isDelete) {

    if (node1.y > node2.y)
        swap(node1, node2);

    int right = node1.y;
    while(board[node1.x][right + 1].isSelected == true && right < 8) // qua phải dần
        right++;
    int left = node2.y;
    while(board[node2.x][left - 1].isSelected == true && left >= 0) // qua trái dần
        left--;
    if (right == 7)
        right++;
    if (left == 0)
        left--;


    bool check, checkForBorder = true;
    // check the middle line on the right
    for(int j = node2.y; j <= min(right, 7); j++) { // xét từ node2 -> right
        check = true;
        if (board[node2.x][j].isSelected == false) {
            checkForBorder = false;
            break;
        }
        for(int i = min(node1.x, node2.x); i <= max(node1.x, node2.x); i++)
            if(board[i][j].isSelected == false) {
                check = false;
                break;
            }
        if (board[node2.x][j].isSelected == false)
            checkForBorder = false;
        if(check == true) {
            if (isDelete) {
                board[node1.x][node1.y].isMarked(board[node1.x][node1.y].x, board[node1.x][node1.y].y);
                board[node2.x][node2.y].isMarked(board[node2.x][node2.y].x, board[node2.x][node2.y].y);
                drawPathU(node1, node2, j, 0, LIGHTRED);
                drawPathU(node1, node2, j, 0, BLACK);
            }
            return check;
        }
    }
    if (right == 8 && checkForBorder) {
        if (isDelete) {
            board[node1.x][node1.y].isMarked(board[node1.x][node1.y].x, board[node1.x][node1.y].y);
            board[node2.x][node2.y].isMarked(board[node2.x][node2.y].x, board[node2.x][node2.y].y);
            drawPathU(node1, node2, 8, 0, LIGHTRED);
            drawPathU(node1, node2, 8, 0, BLACK);
        }
        return true;
    }

    checkForBorder = true;
    for(int j = node1.y; j >= max(left, 0); j--) {
        check = true;
        if (board[node1.x][j].isSelected == false) {
            checkForBorder = false;
            break;
        }
        for(int i = min(node1.x, node2.x); i <= max(node1.x, node2.x); i++)
            if(board[i][j].isSelected == false) {
                check = false;
                break;
            }
        if (board[node1.x][j].isSelected == false)
            checkForBorder = false;
        if(check == true) {
            if (isDelete) {
                board[node1.x][node1.y].isMarked(board[node1.x][node1.y].x, board[node1.x][node1.y].y);
                board[node2.x][node2.y].isMarked(board[node2.x][node2.y].x, board[node2.x][node2.y].y);
                drawPathU(node1, node2, j, 1, LIGHTRED);
                drawPathU(node1, node2, j, 1, BLACK);
            }
            return check;
        }
    }
    if (left == -1 && checkForBorder) {
        if (isDelete) {
            board[node1.x][node1.y].isMarked(board[node1.x][node1.y].x, board[node1.x][node1.y].y);
            board[node2.x][node2.y].isMarked(board[node2.x][node2.y].x, board[node2.x][node2.y].y);
            drawPathU(node1, node2, -1, 1, LIGHTRED);
            drawPathU(node1, node2, -1, 1, BLACK);
        }
        return true;
    }

    if (node1.x > node2.x)
        swap(node1, node2);

    int bottom = node1.x;
    while(board[bottom + 1][node1.y].isSelected == true && bottom < 4)
        bottom++;
    int top = node2.x;
    while(board[top - 1][node2.y].isSelected == true && top >= 0)
        top--;
    if (bottom == 3)
        bottom++;
    if (top == 0)
        top--;

    checkForBorder = true;
    for(int i = node2.x; i <= min(bottom, 3); i++) {
        check = true;
        if (board[i][node2.y].isSelected == false) {
            checkForBorder = false;
            break;
        }
        for(int j = min(node1.y, node2.y); j <= max(node1.y, node2.y); j++)
            if(board[i][j].isSelected == false) {
                check = false;
                break;
            }
        if (board[i][node2.y].isSelected == false)
            checkForBorder = false;

        if(check == true) {
            if (isDelete) {
                board[node1.x][node1.y].isMarked(board[node1.x][node1.y].x, board[node1.x][node1.y].y);
                board[node2.x][node2.y].isMarked(board[node2.x][node2.y].x, board[node2.x][node2.y].y);
                drawPathU(node1, node2, i, 2, LIGHTRED);
                drawPathU(node1, node2, i, 2, BLACK);
            }
            return check;
        }
    }
    if (bottom == 4 && checkForBorder) {
        if (isDelete) {
            board[node1.x][node1.y].isMarked(board[node1.x][node1.y].x, board[node1.x][node1.y].y);
            board[node2.x][node2.y].isMarked(board[node2.x][node2.y].x, board[node2.x][node2.y].y);
            drawPathU(node1, node2, 4, 2, LIGHTRED);
            drawPathU(node1, node2, 4, 2, BLACK);
        }
        return true;
    }

    checkForBorder = true;
    for(int i = node1.x; i >= max(top, 0); i--) {
        check = true;
        if (board[i][node1.y].isSelected == false) {
            checkForBorder = false;
            break;
        }
        for(int j = min(node1.y, node2.y); j <= max(node1.y, node2.y); j++)
            if(board[i][j].isSelected == false) {
                check = false;
                break;
            }
        if (board[i][node1.y].isSelected == false)
            checkForBorder = false;
        if(check == true) {
            if (isDelete) {
                board[node1.x][node1.y].isMarked(board[node1.x][node1.y].x, board[node1.x][node1.y].y);
                board[node2.x][node2.y].isMarked(board[node2.x][node2.y].x, board[node2.x][node2.y].y);
                drawPathU(node1, node2, i, 3, LIGHTRED);
                drawPathU(node1, node2, i, 3, BLACK);
            }
            return check;
        }
    }
    if (top == -1 && checkForBorder) {
        if (isDelete) {
            board[node1.x][node1.y].isMarked(board[node1.x][node1.y].x, board[node1.x][node1.y].y);
            board[node2.x][node2.y].isMarked(board[node2.x][node2.y].x, board[node2.x][node2.y].y);
            drawPathU(node1, node2, -1, 3, LIGHTRED);
            drawPathU(node1, node2, -1, 3, BLACK);
        }
        return true;
    }
    return false;
}



bool canConnect(Node node1, Node node2, int isDelete) {
    if(node1.content != node2.content)
        return false;
    if(checkPathI(node1, node2, isDelete) || checkPathL(node1, node2, isDelete) || checkPathU(node1, node2, isDelete) || checkPathZ(node1, node2, isDelete)) {
        if (isDelete) {
            board[node1.x][node1.y].deleteNode(board[node1.x][node1.y].x, board[node1.x][node1.y].y, node1.x, node1.y);
            board[node2.x][node2.y].deleteNode(board[node2.x][node2.y].x, board[node2.x][node2.y].y, node2.x, node2.y);
            if (node1.y < 8)
            printBGNode(board[node1.x][node1.y].x, board[node1.x][node1.y].y, node1);
            if (node2.y < 8)
            printBGNode(board[node2.x][node2.y].x, board[node2.x][node2.y].y, node2);
       }
        return true;
    }
    return false;
}

// BOARD LINKED LIST CHECKING

// CHECK I MATCHING
// BOARD LINKED LIST CHECKING

// CHECK I MATCHING
void drawPathILL(NodeLL * node1, NodeLL *node2, int direction, int colorSet) {
    color(colorSet);
    int coorNode1XMiddle = node1 -> x + 4, coorNode1YMiddle = node1 -> y + 2;
    int coorNode2XMiddle = node2 -> x + 4, coorNode2YMiddle = node2 -> y + 2;

    if (direction == 0) {   // draw down
        int currentX = coorNode1XMiddle, currentY = coorNode1YMiddle + 1;
        gotoxy(currentX, currentY);
        cout << (char) 30;
        int i = 0;
        for(i = coorNode1YMiddle + 2; i <= coorNode2YMiddle - 2; i++) {
            currentY = i;
            gotoxy(currentX, currentY);
            cout << (char) 250;
        }
        currentY = i;
        gotoxy(currentX, currentY);
        cout << (char) 31;
    } else {
        int currentX = coorNode1XMiddle + 1, currentY = coorNode1YMiddle;
        gotoxy(currentX, currentY);
        cout << (char) 17;
        for(int i = coorNode1XMiddle + 2; i <= coorNode2XMiddle - 2; i++)
            cout << (char) 250;
        cout << (char) 16;
    }

    if (colorSet != BLACK)
        Sleep(400);
}

bool checkPathILL(NodeLL *node1, NodeLL *node2, int isDelete) {
    if (node1 -> x != node2 -> x && node1 -> y != node2 -> y)
        return false;

    if (node1 -> x == node2 -> x) {
        if (node1 -> y > node2 -> y)
            swap(node1, node2);

        if (node1 -> down == node2) {
            if (isDelete) {
                node1 -> isMark(node1 -> x, node1 -> y);
                node2 -> isMark(node2 -> x, node2 -> y);
                drawPathILL(node1, node2, 0, LIGHTRED);
                drawPathILL(node1, node2, 0, BLACK);
            }
            return true;
        }
    } else
    if (node1 -> y == node2 -> y) {
        if (node1 -> x > node2 -> x)
            swap(node1, node2);

        if (node1 -> right == node2) {
            if (isDelete) {
                node1 -> isMark(node1 -> x, node1 -> y);
                node2 -> isMark(node2 -> x, node2 -> y);
                drawPathILL(node1, node2, 1, LIGHTRED);
                drawPathILL(node1, node2, 1, BLACK);
            }
            return true;
        }
    }
    return false;
}

// CHECK Z MATCHING

void drawPathZLL(NodeLL *node1, NodeLL *node2, int direction, int colorSet) {
    color(colorSet);
    int coorNode1XMiddle = node1 -> x + 4, coorNode1YMiddle = node1 -> y + 2;
    int coorNode2XMiddle = node2 -> x + 4, coorNode2YMiddle = node2 -> y + 2;

    if (direction == 0) {
        int currentX = coorNode1XMiddle, currentY = coorNode1YMiddle + 1;
        gotoxy(currentX, currentY);
        cout << (char) 30;
        int i = 0;
        for(i = coorNode1YMiddle + 2; i < coorNode2YMiddle - 4; i++) {
            currentY = i;
            gotoxy(currentX, currentY);
            cout << (char) 250;
        }
        currentY = i;
        // draw the middle
        currentX = min(coorNode1XMiddle, coorNode2XMiddle);
        gotoxy(currentX, currentY);
        cout << 'o';
        for(int i = min(coorNode1XMiddle, coorNode2XMiddle) + 1; i <= max(coorNode1XMiddle, coorNode2XMiddle) - 1; i++) {
            currentX = i;
            gotoxy(currentX, currentY);
            cout << (char) 250;
        }
        currentX = max(coorNode1XMiddle, coorNode2XMiddle);
        gotoxy(currentX, currentY);
        cout << 'o';

        // draw vertical to node2
        currentX = coorNode2XMiddle;
        currentY = coorNode2YMiddle - 1;
        gotoxy(currentX, currentY);
        cout << (char) 31;

        for(int i = 0; i < 2; i++) {
            currentY--;
            gotoxy(currentX, currentY);
            cout << (char) 250;
        }

    } else {
        int currentX = coorNode1XMiddle, currentY = coorNode1YMiddle + 1;
        gotoxy(currentX, currentY);
        cout << (char) 30;
        for(int i = 0; i < 2; i++) {
            currentY++;
            gotoxy(currentX, currentY);
            cout << (char) 250;
        }
        currentY++;
        // draw the middle line
        currentX = min(coorNode1XMiddle, coorNode2XMiddle);
        gotoxy(currentX, currentY);
        cout << 'o';
        for(int i = min(coorNode1XMiddle, coorNode2XMiddle) + 1; i <= max(coorNode1XMiddle, coorNode2XMiddle) - 1; i++) {
            currentX = i;
            gotoxy(currentX, currentY);
            cout << (char) 250;
        }
        currentX = max(coorNode1XMiddle, coorNode2XMiddle);
        gotoxy(currentX, currentY);
        cout << 'o';

        // draw vertical to node2
        currentX = coorNode2XMiddle; currentY = coorNode2YMiddle - 1;
        gotoxy(currentX, currentY);
        cout << (char) 31;
        for(int i = coorNode2YMiddle - 2; i >= coorNode1YMiddle + 5; i--) {
            currentY = i;
            gotoxy(currentX, currentY);
            cout << (char) 250;
        }
    }

    if (colorSet != BLACK)
        Sleep(400);
}

bool checkPathZLL(NodeLL *node1, NodeLL *node2, int isDelete) {
    if(node1 -> y > node2 -> y)
        swap(node1, node2);

    // checking btw node1 and node2 has any line or not
    if (!(abs(node1 -> y - node2 -> y) > 4))
        return false;

    if (node1 -> down != NULL)
        if (!(abs(node1 -> down -> y - node1 -> y) > 4))
            return false;
    if (node2 -> up != NULL)
        if (!(abs(node2 -> up -> y - node2 -> y) > 4))
            return false;

    if (node1 -> down != NULL && node2 -> up != NULL) {
        if (node1 -> down -> y >= node2 -> y) {
            if (isDelete) {
                node1 -> isMark(node1 -> x, node1 -> y);
                node2 -> isMark(node2 -> x, node2 -> y);
                drawPathZLL(node1, node2, 0, LIGHTRED);
                drawPathZLL(node1, node2, 0, BLACK);
            }
            return true;
        }
        else
        if (node2 -> up -> y <= node1 -> y) {
            if (isDelete) {
                node1 -> isMark(node1 -> x, node1 -> y);
                node2 -> isMark(node2 -> x, node2 -> y);
                drawPathZLL(node1, node2, 1, LIGHTRED);
                drawPathZLL(node1, node2, 1, BLACK);
            }
            return true;
        }
    } else
    if (node1 -> down == NULL) {
        if (isDelete) {
            node1 -> isMark(node1 -> x, node1 -> y);
            node2 -> isMark(node2 -> x, node2 -> y);
            drawPathZLL(node1, node2, 0, LIGHTRED);
            drawPathZLL(node1, node2, 0, BLACK);
        }
        return true;
    } else
    if (node2 -> up == NULL) {
        if (isDelete) {
            node1 -> isMark(node1 -> x, node1 -> y);
            node2 -> isMark(node2 -> x, node2 -> y);
            drawPathZLL(node1, node2, 1, LIGHTRED);
            drawPathZLL(node1, node2, 1, BLACK);
        }
        return true;
    }
    return false;
}

// CHECK L MATCHING

void drawPathLLL(NodeLL *node1, NodeLL *node2, int direction, int colorSet) {
    color(colorSet);
    int coorNode1XMiddle = node1 -> x + 4, coorNode1YMiddle = node1 -> y + 2;
    int coorNode2XMiddle = node2 -> x + 4, coorNode2YMiddle = node2 -> y + 2;

    if (direction == 0) {   // draw horizontal from node1 then draw vertical to node2
        int horizontalNode1 = abs(coorNode1XMiddle - coorNode2XMiddle) - 2, verticalNode2 = abs(coorNode1YMiddle - coorNode2YMiddle) - 2;
        int currentX = coorNode1XMiddle + 1, currentY = coorNode1YMiddle;
        // draw horizontal from node1
        gotoxy(currentX, currentY);
        cout << (char) 17;
        for(int i = 0; i < horizontalNode1; i++)
            cout << (char) 250;
        cout << 'o';
        // draw vertical to node2
        currentX = coorNode2XMiddle; currentY = coorNode2YMiddle + 1;
        gotoxy(currentX, currentY);
        cout << (char) 30;
        for(int i = 0; i < verticalNode2; i++) {
            currentY++;
            gotoxy(currentX, currentY);
            cout << (char) 250;
        }
    } else {
        int horizontalNode1 = abs(coorNode1XMiddle - coorNode2XMiddle) - 2, verticalNode2 = abs(coorNode1YMiddle - coorNode2YMiddle) - 2;
        int currentX = coorNode1XMiddle + 1, currentY = coorNode1YMiddle;
        // draw horizontal from node1
        gotoxy(currentX, currentY);
        cout << (char) 17;
        for(int i = 0; i < horizontalNode1; i++)
            cout << (char) 250;
        cout << 'o';
        // draw vertical to node2
        currentX = coorNode2XMiddle; currentY = coorNode2YMiddle - 1;
        gotoxy(currentX, currentY);
        cout << (char) 31;
        for(int i = 0; i < verticalNode2; i++) {
            currentY--;
            gotoxy(currentX, currentY);
            cout << (char) 250;
        }
    }
    if (colorSet !=BLACK)
        Sleep(400);
}

bool checkPathLLL(NodeLL *node1, NodeLL *node2, int isDelete) {

    if (node1 -> x > node2 -> x)
        swap(node1, node2);

    if (node1-> right != NULL)
        return false;
    if(node1 -> y > node2 -> y) { // node1 is under node2
        if (node2 -> down != NULL && node2 -> down -> y <= node1 -> y)
            return false;

    } else
    if(node1 -> y < node2 -> y) { // node2 is under node1
        if (node2 -> up != NULL && node2 -> up -> y >= node1 -> y)
            return false;
    }

    if (isDelete) {
        node1 -> isMark(node1 -> x, node1 -> y);
        node2 -> isMark(node2 -> x, node2 -> y);
        drawPathLLL(node1, node2, node1 -> y < node2 -> y, LIGHTRED);
        drawPathLLL(node1, node2, node1 -> y < node2 -> y, BLACK);
    }
    return true;
}

void drawPathULL(NodeLL *node1, NodeLL *node2, int direction, int colorSet) {
    color(colorSet);
    int coorNode1XMiddle = node1 -> x + 4, coorNode1YMiddle = node1 -> y + 2;
    int coorNode2XMiddle = node2 -> x + 4, coorNode2YMiddle = node2 -> y + 2;

    if (direction == 0) {   // draw down first
        int verticalNode1, verticalNode2, middleLine;
        verticalNode1 = 1;
        verticalNode2 = abs(node2 -> y - node1 -> y) + 1;

        middleLine = abs(coorNode1XMiddle - coorNode2XMiddle) - 1;
        int currentX = coorNode1XMiddle, currentY = coorNode1YMiddle + 1;
        gotoxy(currentX, currentY);
        cout << (char) 30;
        for(int i = 0; i < verticalNode1; i++) {
            currentY++;
            gotoxy(currentX, currentY);
            cout << (char) 250;
        }
        currentY++;
        gotoxy(currentX, currentY);
        cout << 'o';

        // draw the middle line
        for(int i = 0; i < middleLine; i++)
            cout << (char) 250;
        cout << 'o';
        currentX = coorNode2XMiddle; currentY = coorNode2YMiddle + 1;
        gotoxy(currentX, currentY);
        cout << (char) 30;
        for(int i = 0; i < verticalNode2; i++) {
            currentY++;
            gotoxy(currentX, currentY);
            cout << (char) 250;
        }
    } else
    if (direction == 1) {
        int verticalNode1, verticalNode2, middleLine;
        verticalNode1 = 1;
        verticalNode2 = abs(node2 -> y - node1 -> y) + 1;
        middleLine = abs(coorNode1XMiddle - coorNode2XMiddle) - 1;
        int currentX = coorNode1XMiddle, currentY = coorNode1YMiddle - 1;
        gotoxy(currentX, currentY);
        cout << (char) 31;
        for(int i = 0; i < verticalNode1; i++) {
            currentY--;
            gotoxy(currentX, currentY);
            cout << (char) 250;
        }
        currentY--;
        gotoxy(currentX, currentY);
        cout << 'o';

        // draw the middle line
        for(int i = 0; i < middleLine; i++)
            cout << (char) 250;
        cout << 'o';
        currentX = coorNode2XMiddle; currentY = coorNode2YMiddle - 1;
        gotoxy(currentX, currentY);
        cout << (char) 31;
        for(int i = 0; i < verticalNode2; i++) {
            currentY--;
            gotoxy(currentX, currentY);
            cout << (char) 250;
        }
    } else
    if (direction == 2) {
        int horizontalNode1, horizontalNode2, middleLine;
        int coorRightBorder = 66;
        horizontalNode1 = coorRightBorder - coorNode1XMiddle;
        horizontalNode2 = coorRightBorder - coorNode2XMiddle;
        middleLine = abs(coorNode1YMiddle - coorNode2YMiddle) - 1;
        int currentX = coorNode1XMiddle + 1, currentY = coorNode1YMiddle;
        gotoxy(currentX, currentY);
        cout << (char) 17;
        for(int i = 0; i < horizontalNode1; i++) {
            currentX++;
            cout << (char) 250;
        }
        cout << 'o';

        // draw the middle line
        currentX++;
        for(int i = 0; i < middleLine; i++) {
            currentY++;
            gotoxy(currentX, currentY);
            cout << (char) 250;
        }

        //
        currentX = coorNode2XMiddle + 1; currentY =coorNode2YMiddle;
        gotoxy(currentX, currentY);
        cout << (char) 17;
        for(int i = 0; i < horizontalNode2; i++)
            cout << (char) 250;
        cout << 'o';
    } else {
        int horizontalNode1, horizontalNode2, middleLine;
        int coorLeftBorder = 2;
        horizontalNode1 = coorNode1XMiddle - coorLeftBorder;
        horizontalNode2 = coorNode1XMiddle - coorLeftBorder;
        middleLine = abs(coorNode1YMiddle - coorNode2YMiddle) - 1;
        int currentX = coorNode1XMiddle - 1, currentY = coorNode1YMiddle;
        gotoxy(currentX, currentY);
        cout << (char) 16;

        for(int i = 0; i < horizontalNode1; i++) {
            currentX--;
            gotoxy(currentX, currentY);
            cout << (char) 250;
        }
        currentX--;
        gotoxy(currentX, currentY);
        cout << 'o';

        // draw the middle line

        for(int i = 0; i < middleLine; i++) {
            currentY++;
            gotoxy(currentX, currentY);
            cout << (char) 250;
        }

        //
        currentX = coorNode2XMiddle - 1; currentY =coorNode2YMiddle;
        gotoxy(currentX, currentY);
        cout << (char) 16;
        for(int i = 0; i < horizontalNode2; i++) {
            currentX--;
            gotoxy(currentX, currentY);
            cout << (char) 250;
        }
        currentX--;
        gotoxy(currentX, currentY);
        cout << 'o';
    }

    if (colorSet != BLACK)
        Sleep(400);
}

bool checkPathULL(NodeLL *node1, NodeLL *node2, int isDelete) {
    if (node1 -> x > node2 -> x)
        swap(node1, node2);

    if (node1 -> down == NULL && node2 -> down == NULL) {
        if (isDelete) {
            node1 -> isMark(node1 -> x, node1 -> y);
            node2 -> isMark(node2 -> x, node2 -> y);
            drawPathULL(node1, node2, 0, LIGHTRED);
            drawPathULL(node1, node2, 0, BLACK);
        }
        return true;
    }
    else
    if (node1 -> down != NULL && abs(node1 -> down -> y - node1 -> y) > 4 && (node2 -> up == NULL || abs(node2 -> up -> y - node2 -> y) > 4)) {
        if (isDelete) {
            node1 -> isMark(node1 -> x, node1 -> y);
            node2 -> isMark(node2 -> x, node2 -> y);
            drawPathULL(node1, node2, 0, LIGHTRED);
            drawPathULL(node1, node2, 0, BLACK);
        }
        return true;
    }

    if (node1 -> up == NULL && node2 -> up == NULL) {
        if (isDelete) {
            node1 -> isMark(node1 -> x, node1 -> y);
            node2 -> isMark(node2 -> x, node2 -> y);
            drawPathULL(node1, node2, 1, LIGHTRED);
            drawPathULL(node1, node2, 1, BLACK);
        }
        return true;
    }
    else
    if (node1 -> up != NULL && abs(node1 -> up -> y - node1 -> y) > 4) {
        if (isDelete) {
            node1 -> isMark(node1 -> x, node1 -> y);
            node2 -> isMark(node2 -> x, node2 -> y);
            drawPathULL(node1, node2, 1, LIGHTRED);
            drawPathULL(node1, node2, 1, BLACK);
        }
        return true;
    }
    if (node1 -> y > node2 -> y)
        swap(node1, node2);

    if (node1 -> right == NULL && node2 -> right == NULL) {
        if (isDelete) {
            node1 -> isMark(node1 -> x, node1 -> y);
            node2 -> isMark(node2 -> x, node2 -> y);
            drawPathULL(node1, node2, 2, LIGHTRED);
            drawPathULL(node1, node2, 2, BLACK);
        }
        return true;
    }

    if (node1 -> left == NULL && node2 -> left == NULL) {
        if (isDelete) {
            node1 -> isMark(node1 -> x, node1 -> y);
            node2 -> isMark(node2 -> x, node2 -> y);
            drawPathULL(node1, node2, 3, LIGHTRED);
            drawPathULL(node1, node2, 3, BLACK);
        }
        return true;
    }

    return false;
}

bool canConnectLL(NodeLL *node1, NodeLL *node2, int isDelete) {

    if(node1 -> content != node2 -> content)
        return false;
    if(checkPathILL(node1, node2, isDelete) || checkPathLLL(node1, node2, isDelete) || checkPathULL(node1, node2, isDelete) || checkPathZLL(node1, node2, isDelete))
        return true;

    return false;
}
