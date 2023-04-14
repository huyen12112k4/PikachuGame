#pragma once // serves the same purpose as include guards - Ref: https://www.wikiwand.com/en/Pragma_once
#ifndef _MODELS_H_
#define _MODELS_H_

#include<iostream>
#include<Windows.h>

#include "Assets.h"
#include "ConsoleSettings.h"

using namespace std;

class Menu {

    public:

        Menu();

    ~Menu() {}

    void printMenu(int X, int Y, int maxWidth, int posCursor);

    void deleteMenu(int X, int Y, int width); //Xóa menu khi kết thúc chương trình bằng cách viết đè kí tự trắng

    void initializeMenuWithCursor(int X, int Y, int maxWidth);

    int numberOfItem() {
        return _numberOfItem;
    }

    string * getItem() {
        return item;
    }

    private:

        string * item; //Mảng lưu tên của các menu

    int _numberOfItem; //Số lượng menu

};

class Players {
private:
    static int next_id;
    int id;
    string username;
    int life;
    int hint;
    int time; // UPDATE
public:
    // a reference to a string object whose contents will not be changed
    Players(const string& username) : id(++next_id), username(username), life(10), hint(10), time(0) {} // UPDATE

    int getId() const {
        return id;
    }

    void updatePlayer(int newLife, int newHint, int newTime); // UPDATE

    void updateHint(int newHint) {
        hint = newHint;
    }
    void updateTime(int newTime) { // UPDATE
        time = newTime;
    }
    void updateLife(int newLife) {
        life = newLife;
    }
    string getUsername() {
        return username;
    }
    int getLife() {
        return life;
    }
    int getHint() {
        return hint;
    }
    int getTime() {                 // UPDATE
        return time;
    }
};



struct Node {
    char box[5][12] = {{"o-------o"},
                       {"|       |"},
                       {"|       |"},
                       {"|       |"},
                       {"o-------o"}
                      };
    bool isSelected = true;
    char content = '#';
    int x;
    int y;
    void printNode(int x, int y);
    void IsCurrentCursor(int x, int y);
    void IsCurrentCursorUnselected(int x, int y);
    void isMarked(int x, int y);
    void isMarkedHighLight(int x, int y);
    void isError(int x, int y);
    void deleteNode(int x, int y, int i, int j);
};
struct NodeLL {
    char content = '#';
    char box[5][12] = {{"o-------o"},
                       {"|       |"},
                       {"|       |"},
                       {"|       |"},
                       {"o-------o"}};
    bool isSelected = false;
    int x;
    int y;
    // Supported by teacher Phan Thi Phuong Uyen
    NodeLL *right = NULL, *left = NULL, *up = NULL, *down = NULL;

    NodeLL *deleteNode(NodeLL *head, int x, int y);
    void isCurrentCursorLL(int x, int y);
    void isCurrentCursorUnselectedLL(int x, int y);
    void isMark(int x, int y);
    void isMarkHighLight(int x, int y);
    void isError(int x, int y);

};

NodeLL *createBoardLL(Node board[][10], int i, int j, int m, int n);
void printNodeLL(NodeLL *head, int x, int y);
void printNodeLLNull(NodeLL *node, int x, int y);

extern Node board[10][10];
extern Node tmpBoard[10][10];
extern NodeLL **boardLL;

struct Background{
    char content;
    int x;
    int y;

};
extern Background bg[30][66];

#endif
