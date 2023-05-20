#include "game.h"

Game::Game()
{
    // // load the player's character
    // this->player = new Character("player", "player", "player", 0, 0, 0, 0, 0, 0, 0, 0, 0);

    // // load the characters
    // this->characters = new Character[3];
    // this->characters[0] = Character("character1", "character1", "character1", 0, 0, 0, 0, 0, 0, 0, 0, 0);
    // this->characters[1] = Character("character2", "character2", "character2", 0, 0, 0, 0, 0, 0, 0, 0, 0);
    // this->characters[2] = Character("character3", "character3", "character3", 0, 0, 0, 0, 0, 0, 0, 0, 0);
}

Game::Game(int difficulty)
{
    // call default constructor
    Game();

    // override the difficulty
    this->difficulty = difficulty;
}

void Game::set_difficulty(int difficulty)
{
    this->difficulty = difficulty;
}
