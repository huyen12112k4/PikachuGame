

#pragma once // serves the same purpose as include guards - Ref: https://www.wikiwand.com/en/Pragma_once
#ifndef _CHECKING_H_
#define _CHECKING_H_

#include<iostream>

#include "ConsoleSettings.h"
#include "Models.h"
#include "Background.h"

using namespace std;

bool canConnect(Node node1, Node node2, int isDelete);
bool canConnectLL(NodeLL *node1, NodeLL *node2, int isDelete);
#endif
