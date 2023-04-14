#include "Timing.h"

void countTime(int time, Players &player) {
    int newTime = player.getTime() + time - 1;
    player.updateTime(newTime);
}
