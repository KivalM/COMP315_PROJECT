#ifndef GAME_H
#define GAME_H

#include "character.h"
#include "dialog.h"
#include "stage_0.h"
#include "stage_1.h"
#include "quiz.h"

#include <thread>
#include <chrono>
#include <algorithm>
#include <random>

enum Stage
{

    STAGE_1,
    STAGE_1_QUIZ,
    STAGE_2,
    STAGE_2_QUIZ,
    STAGE_3,
    STAGE_3_QUIZ,
    STAGE_4,
    STAGE_4_QUIZ,
    STAGE_5_QUIZ,

};

class Game
{
public:
    Game();
    ~Game(){};

    void set_difficulty(int difficulty);

    Dialog *current;

    // holds the player's character
    Character *player;

    // holds a list of all the characters in the game
    Character *characters;

    // holds the current stage
    Stage stage = STAGE_1;

    void operator++();
    void randomize_quiz();
    bool is_quiz();
    void next_stage()
    {
        stage = (Stage)((int)stage + 1);
        current_stage++;
        current = stages[current_stage];
    };

private:
    int difficulty = 0;

    // pointers to quiz questions
    Dialog quiz_one[5];
    Dialog quiz_two[5];
    Dialog quiz_three[5];
    Dialog quiz_four[5];
    Dialog quiz_five[5];

    // pointers to dialog roots
    Dialog *stages[2] = {&stage_1_root, quiz_one};

    int current_stage = 0;
};

#endif // GAME_H
