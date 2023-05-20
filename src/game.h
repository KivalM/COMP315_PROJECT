#ifndef GAME_H
#define GAME_H

#include "character.h"

class Game
{
public:
    Game();
    Game(int difficulty);

    ~Game(){};

    void set_difficulty(int difficulty);

private:
    // holds the player's character
    Character *player;

    // holds a list of all the characters in the game
    Character *characters;

    // holds the current stage
    int stage = 0;
    int difficulty = 0;
};

#endif // GAME_H
