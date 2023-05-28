#include "game.h"

Game::Game()
{

    // initialize the characters
    characters = new Character[9];

    characters[0] = Character("Detective Conan", -1);
    characters[1] = Character("Narrator", -1);
    characters[2] = Character("Captain Clouseau", 0);
    characters[3] = Character("Marcus", 1);
    characters[4] = Character("Thomas", 2);
    characters[5] = Character("Amelia", 3);
    characters[6] = Character("Olivia", 4);
    characters[7] = Character("Vincent", 5);
    characters[8] = Character("News Reporter", -1);

    // initialize the dialog tree
    current = stages[0];

    // initialize the score
    score = 75;

    // call the function to randomize the quiz
    // as well as build the quiz linked list
    randomize_quiz();
}

Game::~Game()
{
    delete[] characters;

    // delete the data at the additional questions
    delete quiz_one[7].next;
    delete quiz_two[7].next;
    delete quiz_three[7].next;
    delete quiz_four[7].next;
}

void Game::set_difficulty(int difficulty)
{
    this->difficulty = difficulty;
}

void Game::randomize_quiz()
{
    // variable to choose the number of questions
    int quiz_len = 8;

    // shuffle the questions
    std::random_device rd;
    std::mt19937 rng(rd());

    // the size of stage 1 questions
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

    size = 18;
    std::shuffle(stage_2_questions, stage_2_questions + size, rng);
    // fill the question arrays
    for (int i = 0; i < quiz_len; i++)
    {
        Question *q = stage_2_questions[i];
        string choices[4] = {q->choices[0], q->choices[1], q->choices[2], q->choices[3]};
        quiz_two[i] = create_choice_mcq(q->question, nullptr, choices, q->answer_index);
        quiz_two[i].bg = 2;
    }
    // now point each question to the next
    for (int i = 0; i < quiz_len - 1; i++)
    {
        quiz_two[i].next = &quiz_two[i + 1];
    }

    // set the last question to point to the stage end
    quiz_two[quiz_len - 1].next = new Dialog(create_stage_end("You have completed the second stage quiz!", 2, 0));

    size = 29;
    std::shuffle(stage_3_questions, stage_3_questions + size, rng);
    // fill the question arrays
    for (int i = 0; i < quiz_len; i++)
    {
        Question *q = stage_3_questions[i];
        string choices[4] = {q->choices[0], q->choices[1], q->choices[2], q->choices[3]};
        quiz_three[i] = create_choice_mcq(q->question, nullptr, choices, q->answer_index);
        quiz_three[i].bg = 3;
    }

    // now point each question to the next
    for (int i = 0; i < quiz_len - 1; i++)
    {
        quiz_three[i].next = &quiz_three[i + 1];
    }

    // set the last question to point to the stage end
    quiz_three[quiz_len - 1].next = new Dialog(create_stage_end("You have completed the third stage quiz!", 3, 0));

    size = 20;
    std::shuffle(stage_4_questions, stage_4_questions + size, rng);
    // fill the question arrays
    for (int i = 0; i < quiz_len; i++)
    {
        Question *q = stage_4_questions[i];
        string choices[4] = {q->choices[0], q->choices[1], q->choices[2], q->choices[3]};
        quiz_four[i] = create_choice_mcq(q->question, nullptr, choices, q->answer_index);
        quiz_four[i].bg = 3;
    }

    // now point each question to the next
    for (int i = 0; i < quiz_len - 1; i++)
    {
        quiz_four[i].next = &quiz_four[i + 1];
    }

    // set the last question to point to the stage end
    quiz_four[quiz_len - 1].next = new Dialog(create_stage_end("You have completed the fourth stage quiz!", 4, 0));
}

bool Game::is_quiz()
{
    return stage == STAGE_1_QUIZ || stage == STAGE_2_QUIZ || stage == STAGE_3_QUIZ || stage == STAGE_4_QUIZ;
}

bool Game::is_memory()
{
    return stage == MATCHING;
}

// overload ++ and -- to call correct_answer() and incorrect_answer()
void Game::operator++()
{
    correct_answer();
}

void Game::operator--()
{
    incorrect_answer();
}

void Game::correct_answer()
{

    if (score == 100)
        return;

    // we will only increase the score if the difficulty is standard
    switch (difficulty)
    {
    case 1:
        score += 5;
        break;
    default:
        break;
    }
}
void Game::incorrect_answer()
{

    // we will only decrease the score if the difficulty is standard or hard
    switch (difficulty)
    {
    case 1:
        score -= 5;
        break;
    case 2:
        score -= 5;
        break;
    default:
        break;
    }

    if (score == 0)
    {
        // game over
        // we will point the current node to the game over node
        stage = STAGE_FAIL;
        current = &stage_fail_root;
        current_stage = 12;
        return;
    }
}

int Game::current_act()
{
    if (stage == STAGE_1 || stage == STAGE_1_QUIZ)
    {
        return 1;
    }
    else if (stage == STAGE_2 || stage == STAGE_2_QUIZ)
    {
        return 2;
    }
    else if (stage == STAGE_3 || stage == STAGE_3_QUIZ)
    {
        return 3;
    }
    else if (stage == STAGE_4 || stage == STAGE_4_QUIZ)
    {
        return 4;
    }
    else if (stage == MATCHING)
    {
        return 5;
    }
    else if (stage == STAGE_5)
    {
        return 6;
    }
    else if (stage == GOODBYE)
    {
        return 6;
    }
    else if (stage == END)
    {
        return 6;
    }
    else
    {
        return 0;
    }
}

void Game::next_stage()
{

    stage = (Stage)((int)stage + 1);
    current_stage++;
    current = stages[current_stage];
};