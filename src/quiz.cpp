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

Question *stage_1_questions[17] = {
    create_question("What was the name of the case that brought Detective Conan fame?",
                    {"Midnight Mirage", "Crimson Crown", "Pink Panther", "Diamond Deception"}, 2),
    create_question("The Pink Panther case involved the murder of a king for a pink diamond.",
                    {"True", "False", "", ""}, 1),
    create_question("How long has it been since the Pink Panther case?",
                    {"2 years", "3 years", "5 years", "7 years"}, 2),
    create_question("What was the occupation of the murder suspect in the Pink Panther case?",
                    {"Antique dealer", "Art forger", "Black market museum owner", "Jewelry store owner"}, 2),
    create_question("Why is Detective Conan under pressure to solve the current case?",
                    {"The department is short-staffed", "He wants to become a captain", "The department is in a financial crisis", "He wants to impress Captain Clouseau"}, 2),
    create_question("Who specifically requested Detective Conan to investigate Elizabeth Killingsworth's murder?",
                    {"The police chief", "The mayor of the city", "The board of investors", "Elizabeth Killingsworth herself"}, 2),
    create_question("What is Elizabeth Killingsworth's profession?",
                    {"Business magnate", "Famous actress", "Renowned lawyer", "Notable politician"}, 0),
    create_question("Where does Elizabeth Killingsworth spend most of her time?",
                    {"Her private island", "Her mansion", "Luxury hotels", "Her office building"}, 1),
    create_question("Who surrounds Elizabeth Killingsworth in her mansion?",
                    {"Her loyal bodyguards", "Her trusted family members", "Her personal assistants", "Her closest friends and advisors"}, 3),
    create_question("What will happen if Detective Conan fails to solve the current case?",
                    {"He will be demoted", "He will receive a pay cut", "He will lose his job", "He will be assigned to a different department"}, 2),
    create_question(" If Detective Conan fails to solve the current case, he will be replaced by Detective Trevor Nightingale.",
                    {"True", "False", "", ""}, 0),
    create_question("What is Detective Conan's main goal in the current case?",
                    {"To catch a notorious serial killer", "To clear his name from past mistakes", "To become the head of the department", "To regain his lost reputation"}, 3),
    create_question("What is the atmosphere in Captain Clouseau's office during the conversation?",
                    {"Brightly lit with natural light", "Filled with suspense and shadows", "Lively and bustling with activity", "Cluttered and chaotic"}, 1),
    create_question("How does Captain Clouseau emphasize the importance of the case to Detective Conan?",
                    {"By offering a promotion", "By threatening to demote him", "By mentioning the department's financial crisis", "By promising a substantial reward"}, 2),
    create_question("How does Detective Conan express his determination to Captain Clouseau?",
                    {"By mentioning his past successes", "By promising to outshine his rivals", "By assuring he won't let him down", "By requesting additional resources"}, 2),
    create_question("Does Captain Clouseau personally want to fire Detective Conan?",
                    {"Yes", "No", "", ""}, 1),
    create_question(" Detective Conan has been struggling to find leads in recent cases.",
                    {"True", "False", "", ""}, 0),
};