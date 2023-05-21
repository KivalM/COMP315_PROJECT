#ifndef GAME_H
#define GAME_H

#include "character.h"
#include "dialog.h"
#include "stage_1.h"

class Game
{
public:
    Game();
    ~Game(){};

    void set_difficulty(int difficulty);

    Dialog *current = &stage_1_root;

    // holds the player's character
    Character *player;

    // holds a list of all the characters in the game
    Character *characters;

private:
    // holds the current stage
    int stage = 0;
    int difficulty = 0;
};

#endif // GAME_H
