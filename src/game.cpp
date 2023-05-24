#include "game.h"

Game::Game()
{

    // initialize the player character
    // player = new Character("Detective Conan", 13);

    // initialize the characters
    characters = new Character[9];

    characters[0] = Character("Detective Conan", -1);
    characters[1] = Character("Narrator", -1);
    characters[2] = Character("Captain Clouseau", 2);
    characters[3] = Character("Heiji", 3);
    characters[4] = Character("Kazuha", 4);
    characters[5] = Character("Mouri", 5);
    characters[6] = Character("Ran", 6);
    characters[7] = Character("Kogoro", 7);

    characters[8] = Character("News Reporter", -1);

    // initialize the dialog tree
    current = stages[0];

    randomize_quiz();
}

void Game::set_difficulty(int difficulty)
{
    this->difficulty = difficulty;
}

void Game::operator++()

{
    if (stage == Stage::STAGE_5_QUIZ)
    {
        current = new Dialog(create_stage_end("You have completed the game!", 1, 0));
    }
    else
    {
        // increment the stage
        // stage = (Stage)((int)stage + 1);
        current_stage++;
        current = stages[current_stage];
    }
}

void Game::randomize_quiz()
{
    int quiz_len = 5;

    random_device rd;
    mt19937 rng(rd());

    int size = 17;

    std::shuffle(stage_1_questions, stage_1_questions + size, rng);
    // fill the question arrays
    for (int i = 0; i < quiz_len; i++)
    {
        Question *q = stage_1_questions[i];
        string choices[4] = {q->choices[0], q->choices[1], q->choices[2], q->choices[3]};
        quiz_one[i] = create_choice_mcq(q->question, nullptr, choices, q->answer_index);
    }
    // now point each question to the next
    for (int i = 0; i < quiz_len - 1; i++)
    {
        quiz_one[i].next = &quiz_one[i + 1];
    }
    // set the last question to point to the stage end
    quiz_one[quiz_len - 1].next = new Dialog(create_stage_end("You have completed the first stage quiz!", 1, 0));

    // int size = 0;
    // std::shuffle(stage_2_questions, stage_2_questions + size, rng);

    // int size = 0;
    // std::shuffle(stage_3_questions, stage_3_questions + size, rng);

    // int size = 17;
    // std::shuffle(stage_4_questions, stage_4_questions + size, rng);

    // int size = 17;
    // std::shuffle(stage_5_questions, stage_5_questions + size, rng);
}

bool Game::is_quiz()
{
    return stage == STAGE_1_QUIZ || stage == STAGE_2_QUIZ || stage == STAGE_3_QUIZ || stage == STAGE_4_QUIZ || stage == STAGE_5_QUIZ;
}