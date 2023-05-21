#include "game.h"

Game::Game()
{

    // initialize the player character
    player = new Character("Detective Conan", 13);

    // initialize the characters
    characters = new Character[7];
    characters[0] = Character("Narrator", 0);
    characters[1] = Character("Kogoro", 7);
    characters[2] = Character("Sonoko", 2);
    characters[3] = Character("Heiji", 3);
    characters[4] = Character("Kazuha", 4);
    characters[5] = Character("Mouri", 5);
    characters[6] = Character("Ran", 6);

    // initialize the dialog tree
    current = &stage_1_root;
}

void Game::set_difficulty(int difficulty)
{
    this->difficulty = difficulty;
}
