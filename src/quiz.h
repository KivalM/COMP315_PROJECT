#ifndef QUIZ_H
#define QUIZ_H

#include <string>
#include <map>
#include <array>
using namespace std;

struct Question
{
    string question;
    array<std::string, 4> choices;
    int answer_index;
};

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