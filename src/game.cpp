#include "game.h"

Game::Game()
{
    current = &stage_1_root;
}

void Game::set_difficulty(int difficulty)
{
    this->difficulty = difficulty;
}
