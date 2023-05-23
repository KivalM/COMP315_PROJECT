#include "quiz.h"

Question *create_question(string question, array<string, 4> choices, int answer_index)
{
    Question *q = new Question;
    q->question = question;
    for (int i = 0; i < 4; i++)
    {
        q->choices[i] = choices[i];
    }
    q->answer_index = answer_index;
    return q;
}

Question *stage_1_questions[15] = {
    create_question("What is the name of the main character?",
                    {"John", "Jack", "James", "Jill"}, 2),
    create_question("What is the name of the main character's wife?",
                    {"Jill", "Jane", "Jenny", "Judy"}, 0),
    create_question("What is the name of the main character's son?",
                    {"Jimmy", "Jack", "John", "Jill"}, 0),
};
