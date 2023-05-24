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
Question *stage_2_questions[18] = {
    create_question("What was the amount of the signed cheque found on the table?",
                    {"$1,000,000", "$1,500,000", "$2,000,000", "$2,500,000"}, 2),
    create_question("Whose name was on the pen found next to the cheque?",
                    {"Elizabeth Killingsworth", "Marcus", "Vincent", "Detective Conan"}, 1),
    create_question("What kind of weapon was used in the murder?",
                    {"Silenced 9mm", "Silenced 10mm", "Revolver", "Knife"}, 1),
    create_question("Where was the murder believed to have taken place?",
                    {"Elizabeth's bedroom", "The study", "The basement", "The kitchen"}, 1),
    create_question("What was the condition of the gun cabinet on the wall?",
                    {"Broken open", "Smashed", "Intact but opened", "Missing "}, 2),
    create_question("What color was the strand of hair found near the body?",
                    {"Blonde", "Brown", "Red", "Black"}, 2),
    create_question("At what time did the murder occur?",
                    {"10 am", "11 am", "Between 12 pm - 1 pm", "1 pm"}, 2),
    create_question("What daily activity did Elizabeth usually engage in around the time of the murder?",
                    {"Exercise", "Meditation", "Phone calls", "Writing"}, 2),
    create_question("What was the condition of Elizabeth's body in terms of bruises?",
                    {"Multiple bruises", "One bruise on the arm", "No bruises", "Bruises on the face"}, 2),
    create_question("What object was missing from the crime scene?",
                    {"Elizabeth's necklace", "A valuable painting", "The murder weapon", "A stack of cash"}, 2),
    create_question("Who was Marcus in relation to Elizabeth Killingsworth?",
                    {"Her lawyer", "Her business partner", "Her secret lover", "Her financial advisor"}, 1),
    create_question("What was the state of the window at the crime scene?",
                    {"Wide open", "Closed but unlocked", "Broken", "Slightly ajar "}, 0),
    create_question("What was the murder weapon?",
                    {"Knife", "Poison", "Gun", "Rope"}, 2),
    create_question("Detective Conan found multiple bruises on Elizabeth's body.",
                    {"True", "False", "", ""}, 1),
    create_question("The gun cabinet on the wall was broken open.",
                    {"True", "False", "", ""}, 1),
    create_question("The murder weapon was a knife.",
                    {"True", "False", "", ""}, 1),
    create_question("The murder occurred at 2 pm.",
                    {"True", "False", "", ""}, 1),
    create_question("The strand of hair found near the body was blonde. ",
                    {"True", "False", "", ""}, 1)
};
