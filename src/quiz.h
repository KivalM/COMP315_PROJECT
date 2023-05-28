#ifndef QUIZ_H
#define QUIZ_H

#include <string>
#include <map>
#include <array>
using namespace std;

/*
    This struct represents a question in the quiz
    before it is processed into a dialog node.

    It represents a question with 4 choices, and the index of the correct answer.

    The benefit of creating questions this way over directly creating dialog nodes
    is that we can randomize the order of the questions.

    The shuffled array of questions can then be passed to the dialog node creator functions
    where we select the first X questions to be used in the quiz.
*/

struct Question
{
    // The question to be asked
    string question;

    // The 4 choices to be displayed
    // empty strings are ignored
    array<std::string, 4> choices;

    // The index of the correct answer in the choices array
    int answer_index;
};

// Helper function to create a question
Question *create_question(string question, array<string, 4> choices, int answer_index);

// STAGE 1 QUESTIONS
extern Question *stage_1_questions[];

// STAGE 2 QUESTIONS
extern Question *stage_2_questions[];

// STAGE 3 QUESTIONS
extern Question *stage_3_questions[];

// STAGE 4 QUESTIONS
extern Question *stage_4_questions[];

// STAGE 5 QUESTIONS
extern Question *stage_5_questions[];

// STAGE 6 QUESTIONS
extern Question *stage_6_questions[];

#endif // QUIZ_H