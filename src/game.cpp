#include "game.h"

Game::Game()
{

    // initialize the player character
    // player = new Character("Detective Conan", 13);

    // initialize the characters
    characters = new Character[9];

    characters[0] = Character("Detective Conan", -1);
    characters[1] = Character("Narrator", -1);
    characters[2] = Character("Sonoko", 2);
    characters[3] = Character("Heiji", 3);
    characters[4] = Character("Kazuha", 4);
    characters[5] = Character("Mouri", 5);
    characters[6] = Character("Ran", 6);
    characters[7] = Character("Kogoro", 7);

    characters[8] = Character("News Reporter", -1);

    // initialize the dialog tree
    current = &stage_0_root;
}

void Game::set_difficulty(int difficulty)
{
    this->difficulty = difficulty;
}
