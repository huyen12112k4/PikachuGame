#include "sound.h"
// https://learn.microsoft.com/en-us/previous-versions/dd743680(v=vs.85)
void playSoundWhenStartingGame() {
    PlaySound(TEXT("./Sound/StartingHome.wav"), NULL, SND_ASYNC);
}
void playSoundWhenPressKey() {
    PlaySound(TEXT("./Sound/PressKey.wav"), NULL, SND_ASYNC);
}
void playSoundWhenSelectRight(){
    PlaySound(TEXT("./Sound/Selectright.wav"), NULL, SND_ASYNC);
}
void playSoundWhenSelectWrong() {
    PlaySound(TEXT("./Sound/Select_false.wav"), NULL, SND_ASYNC);
}

void playSoundYouWin(){
    PlaySound(TEXT("./Sound/YouWin.wav"), NULL, SND_ASYNC);
}

void playSoundYouLose(){
    PlaySound(TEXT("./Sound/YouLose.wav"), NULL, SND_ASYNC);
}

