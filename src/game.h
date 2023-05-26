#ifndef GAME_H
#define GAME_H

#include "character.h"
#include "dialog.h"
#include "stage_0.h"
#include "stage_1.h"
#include "stage_2.h"
#include "stage_3.h"

#include "quiz.h"

#include <thread>
#include <chrono>
#include <algorithm>
#include <random>

// Enum for the current stage of the game
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
    // constructor
    Game();
    ~Game(){};

    void set_difficulty(int difficulty);

    // the current dialog node
    Dialog *current;

    // holds the player's character
    Character *player;

    // holds a list of all the characters in the game
    Character *characters;

    // holds the current stage
    Stage stage = STAGE_1;

    // getters for the game's score
    int get_score()
    {
        return score;
    }

    // function to be called when the player answers a question incorrectly
    void incorrect_answer();

    // function to be called when the player answers a question correctly
    void correct_answer();

    // function to be called to progress to the next stage
    void next_stage()
    {
        stage = (Stage)((int)stage + 1);
        current_stage++;
        current = stages[current_stage];
    };

    // pulls the question pool, randomizes the content, and builds a dialog tree
    void randomize_quiz();

    // is the current stage a quiz?
    bool is_quiz();

    int current_act()
    {
        return current_stage / 2;
    }

private:
    // the player's score
    int score = 75;

    // the games difficulty
    int difficulty = 0;

    // pointers to quiz questions
    Dialog quiz_one[8];
    Dialog quiz_two[8];
    Dialog quiz_three[8];
    Dialog quiz_four[8];
    Dialog quiz_five[8];

    // pointers to dialog roots
    Dialog *stages[8] = {
        &stage_1_root,
        quiz_one,
        &stage_2_root,
        quiz_two,
        &stage_3_root,
        quiz_three,
        &stage_4_root,
        quiz_four,
    };

    // the current stage of the above `stages` array
    int current_stage = 0;
};

#endif // GAME_H
