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

Question *stage_3_questions[29] = {
    create_question("Where was Thomas Reynolds during the murder?",
                    {"In Elizabeth's office", "Patrolling the mansion grounds", "Observing Marcus Hawthorne", "In his room"}, 2),
    create_question("What did Thomas Reynolds notice about Marcus Hawthorne's behavior?",
                    {"He was calm and composed", "He was acting suspiciously", "He was constantly talking on the phone", "He seemed disinterested in the events"}, 1),
    create_question("Who did Thomas Reynolds lose sight of during his surveillance?",
                    {"Vincent Delacroix", "Detective Conan", "Amelia Bennett", "Marcus Hawthorne"}, 3),
    create_question("Where did Marcus Hawthorne go after Thomas lost sight of him?",
                    {"Elizabeth's office", "The mansion's garden", "The library", "Elizabeth's office"}, 0),
    create_question("What does Thomas Reynolds imply about Marcus Hawthorne's motives?",
                    {"He had no motive to harm Elizabeth", "He was motivated by financial gain", "He had a personal vendetta against Elizabeth", "His motives were unknown"}, 2),
    create_question("How does Thomas Reynolds describe the relationship between Marcus and Elizabeth?",
                    {"Friendly and supportive", "Full of admiration and respect", "Competitive and conflicted", "Indifferent and distant"}, 2),
    create_question("What does Thomas Reynolds believe about the other suspects?",
                    {"He suspects Vincent Delacroix the most", "He believes Amelia Bennett is the murderer", "He thinks anyone within Elizabeth's inner circle could be the murderer", "He has no suspicions about the other suspects"}, 2),
    create_question("How does Thomas Reynolds emphasize the need for the investigation?",
                    {"By expressing his own suspicions", "By urging Detective Conan to be careful", "By highlighting the rivalry between Marcus and Elizabeth", "By emphasizing the importance of justice for Elizabeth"}, 3),
    create_question("Thomas Reynolds was present in Elizabeth's office during the murder.",
                    {"True", "False", "", ""}, 1),
    create_question("Thomas Reynolds believes that Amelia Bennett is the prime suspect.",
                    {"True", "False", "", ""}, 1),
    create_question("Where was Amelia when the murder occurred?",
                    {"In Elizabeth's office", "In her room", "In the mansion's library", "In the garden"}, 1),
    create_question("How would you describe Amelia's relationship with Elizabeth?",
                    {"Harmonious and supportive", "Strained and overshadowed", "Indifferent and distant", "Competitive and resentful"}, 1),
    create_question("What was Amelia working on in her room?",
                    {"A personal project", "A business proposal", "A family photograph album", "A painting"}, 0),
    create_question("How did Amelia feel about Elizabeth's success?",
                    {"Proud and inspired", "Jealous and resentful", "Indifferent and uninterested", "Supportive and encouraging"}, 1),
    create_question("Whom does Amelia suspect of having financial motives to harm Elizabeth?",
                    {"Marcus Hawthorne", "Thomas Reynolds", "Olivia Montgomery", "Vincent Delacroix"}, 3),
    create_question("Does Amelia have any interest in running Elizabeth's business?",
                    {"Yes, she wants to take over", "No, she has no interest", "She's unsure at the moment", "She's considering it as an option"}, 1),
    create_question("Did Amelia have direct interactions with Elizabeth before her death?",
                    {"Yes, they frequently interacted", "No, they rarely spoke to each other", "Only during family gatherings", "Only during business meetings"}, 1),
    create_question("Amelia witnessed Elizabeth's murder.",
                    {"True", "False", "", ""}, 1),
    create_question("What does Amelia hope Detective Conan will uncover?",
                    {"The hidden family secrets", "Elizabeth's secret will", "The mansion's history", "The truth behind the murder"}, 3),
    create_question("What emotions can be seen in Amelia's eyes during the conversation?",
                    {"Grief, resentment, and hope", "Happiness, curiosity, and relief", "Anger, confusion, and despair", "Indifference, suspicion, and determination"}, 0),
    create_question("Where was Marcus Hawthorne when the murder took place?",
                    {"Exploring the mansion", "In the library admiring art", "In Elizabeth's office overhearing a conversation", "Fleeing through the window"}, 1),
    create_question("What did Marcus overhear in Elizabeth's office?",
                    {"Elizabeth talking to someone down the hall", "Elizabeth's voice engaged in a heated argument", "Indistinct murmurs of a conversation", "The sound of footsteps approaching the office"}, 3),
    create_question("How did Marcus find out about Elizabeth's murder?",
                    {"He was informed by Detective Conan", "He discovered the crime scene himself", "He heard about it from Olivia Montgomery", "He read about it in the newspaper"}, 2),
    create_question("Did Marcus have any specific insights about the other suspects?",
                    {"Yes, he believed Thomas Reynolds had a motive to harm Elizabeth", "No, he did not provide any opinions on the other suspects", "Yes, he suspected Amelia Bennett of being involved in the murder", "No, he remained silent about the other suspects' involvement"}, 1),
    create_question("Marcus claims he was completely unaware of Elizabeth's murder until he arrived at the crime scene.",
                    {"True", "False", "", ""}, 0),
    create_question("Marcus states that he heard Elizabeth arguing with someone in her office before he fled through the window.",
                    {"True", "False", "", ""}, 1),
    create_question("According to Marcus, where was he exploring in the mansion?",
                    {"The library", "The ballroom", "The study", "The kitchen"}, 0),
    create_question("Did Marcus notice anything strange about Elizabeth?",
                    {"Yes, she was behaving unusually before the murder", "No, she appeared completely normal to him", "Yes, she seemed anxious and worried", "No, he did not interact with her prior to the murder"}, 1),
    create_question("Marcus expresses concern about Thomas Reynolds' behavior and implies that he might have had a motive to harm Elizabeth.",
                    {"True", "False", "", ""}, 1)
};
Question *stage_4_questions[20] = {
    create_question("According to Vincent, how does he feel about Elizabeth's death?",
                    {"Indifferent", "Stunned and shaken to his core", "Relieved", "Suspicious"}, 1),
    create_question("What bond does Vincent claim to have with Elizabeth?",
                    {"A bond of trust and loyalty", "A business partnership", "A distant acquaintance", "An adversarial relationship"}, 0),
    create_question("How does Conan view the connection between Vincent and Olivia?",
                    {"They are likely involved in Elizabeth's demise", "They have a deep and evident connection", "They are distant colleagues", "Their bond is irrelevant to the investigation"}, 1),
    create_question("Vincent admits to being involved in the murder.",
                    {"True", "False", "", ""}, 1),
    create_question("Who does Vincent express suspicion towards?",
                    {"Marcus Hawthorne", "Olivia Montgomery", "Thomas Reynolds", "Amelia Summers"}, 0),
    create_question("What behavior of Marcus raises Vincent's suspicions?",
                    {"His nosy and peculiar actions", "His distant and uninterested demeanor", "His close friendship with Elizabeth", "His absence during the murder"}, 0),
    create_question("What strikes Vincent as odd regarding Thomas Reynolds?",
                    {"Thomas' close surveillance of Marcus", "Thomas' prompt response to the murder", "Thomas' involvement with Elizabeth", "Thomas losing track of Marcus during surveillance"}, 3),
    create_question("Vincent believes Olivia and he are innocent.",
                    {"True", "False", "", ""}, 0),
    create_question("How does Vincent describe himself in the investigation?",
                    {"A key suspect", "A mere observer in a twisted game of shadows", "A conspirator in Elizabeth's demise", "A victim of circumstance"}, 1),
    create_question("What is Conan's perspective on Vincent's involvement?",
                    {"He suspects Vincent's guilt", "He believes Vincent is innocent", "He is unsure about Vincent's role", "He thinks Vincent is hiding something"}, 2),
    create_question("What was Olivia doing in her office when Vincent dropped off the papers?",
                    {"Writing a report", "Organizing files", "Making phone calls", "Busy with paperwork"}, 3),
    create_question("How did Olivia react when she heard about Elizabeth's murder?",
                    {"She screamed in horror", "She broke down in tears", "She expressed shock and disbelief", "She remained calm and composed"}, 2),
    create_question("Whom did Olivia express mistrust towards?",
                    {"Marcus Hawthorne", "Vincent Delacroix", "Amelia Summers", "The bodyguard"}, 0),
    create_question("What is the nature of Olivia's relationship with Elizabeth?",
                    {"Employer and employee", "Friends and confidantes", "Siblings", "Rivals"}, 1),
    create_question("What did Olivia mention about her level of trust towards the suspects?",
                    {"She trusts all of them completely", "She has a deep mistrust towards all of them", "She is unsure about some of them", "She believes they are all innocent"}, 2),
    create_question("Who dropped off the papers for Olivia?",
                    {"Conan", "Marcus Hawthorne", "Vincent Delacroix", "Amelia Summers"}, 2),
    create_question("How does Olivia describe her relationship with Marcus Hawthorne?",
                    {"Close friendship", "Business associates", "Distant acquaintances", "Fierce rivals"}, 0),
    create_question("What did Olivia hint about the relationship between Amelia and Elizabeth?",
                    {"They were always at odds with each other", "They were best friends", "There were underlying tensions or conflicts", "They had a deep bond of trust"}, 2),
    create_question("Olivia admits to being involved in Elizabeth's murder.",
                    {"True", "False", "", ""}, 1),
    create_question("Olivia believes that all the suspects are innocent.",
                    {"True", "False", "", ""}, 1)
};

