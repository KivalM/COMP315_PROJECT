#include "game.h"

Game::Game()
{

    // initialize the player character
    player = new Character("Detective Conan");

    // initialize the characters
    characters = new Character[7];
    characters[0] = Character("Narrator");
    characters[1] = Character("Kogoro");
    characters[2] = Character("Sonoko");
    characters[3] = Character("Heiji");
    characters[4] = Character("Kazuha");
    characters[5] = Character("Mouri");
    characters[6] = Character("Ran");

    // initialize the dialog tree
    current = &stage_1_root;
}

void Game::set_difficulty(int difficulty)
{
    this->difficulty = difficulty;
}
