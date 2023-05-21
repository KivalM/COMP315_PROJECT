#ifndef STAGE_1_H
#define STAGE_1_H
#include <string>
#include "dialog.h"

// inline extern Dialog dialog_1_16 = create_dialog("This is demo text 6", 4, 5, nullptr);
// inline extern Dialog dialog_1_15 = create_dialog("You selected an option previously", 1, 1, &dialog_1_16);

// inline extern Dialog dialog_1_14 = create_dialog("You clicked option 1", 1, 1, &dialog_1_15);
// inline extern Dialog dialog_1_13 = create_dialog("You clicked option 2", 1, 1, &dialog_1_15);
// inline extern Dialog dialog_1_12 = create_dialog("You clicked option 3", 1, 1, &dialog_1_15);
// inline extern Dialog dialog_1_11 = create_dialog("You clicked option 4", 1, 1, &dialog_1_15);

// inline extern Choice choice_1_9_a = create_choice("Option 1", &dialog_1_14);
// inline extern Choice choice_1_9_b = create_choice("Option 2", &dialog_1_13);
// inline extern Choice choice_1_9_c = create_choice("Option 3", &dialog_1_12);
// inline extern Choice choice_1_9_d = create_choice("Option 4", &dialog_1_11);

// inline extern Dialog dialog_1_9 = create_dialog_choice("Pick an option", 1, 1, &choice_1_9_a, &choice_1_9_b, &choice_1_9_c, &choice_1_9_d);

// inline extern Dialog dialog_1_8 = create_dialog("This is demo text 9", 5, 3, &dialog_1_9);
// inline extern Dialog dialog_1_7 = create_dialog("This is demo text 8", 5, 2, &dialog_1_8);
// inline extern Dialog dialog_1_6 = create_dialog("This is demo text 7", 6, 7, &dialog_1_7);
// inline extern Dialog dialog_1_5 = create_dialog("This is demo text 6", 4, 5, &dialog_1_6);
// inline extern Dialog dialog_1_4 = create_dialog("This is demo text 5", 2, 3, &dialog_1_5);
// inline extern Dialog dialog_1_3 = create_dialog("This is demo text 4", 1, 1, &dialog_1_4);
// inline extern Dialog dialog_1_2 = create_dialog("This is demo text 3", 1, 1, &dialog_1_3);
// inline extern Dialog dialog_1_1 = create_dialog("This is demo text 2", 1, 2, &dialog_1_2);
// inline extern Dialog stage_1_root = create_dialog("This is demo text 1", 1, 1, &dialog_1_1);

// array of neutral questions
inline extern string q_neutral[] = {
    "Can you please introduce yourself and tell me your relationship with Elizabeth Killingsworth?",
    "What were you doing at the time of the murder?",
    "Did you notice anything unusual or suspicious leading up to the incident?",
    "How well did you know Elizabeth? Can you describe her personality?",
    "Are you aware of any conflicts or disagreements Elizabeth had with anyone recently?",
    "Can you provide an alibi for your whereabouts during the time of the murder?",
    "Were you present when the crime occurred? If so, can you describe what you saw or heard?",
    "Do you have any knowledge of anyone who might have wanted to harm Elizabeth?",
    "Are there any peculiar habits or routines that Elizabeth had that you can share?",
    "Can you recall any recent interactions or conversations you had with Elizabeth?"};
inline extern string q_aggressive[] = {
    "Why were you at the scene of the crime? What were you planning to do?",
    "Are you hiding anything about your relationship with Elizabeth that might be relevant to the investigation?",
    "Did you have any motives or reasons to harm Elizabeth Killingsworth?",
    "Were you aware of any secrets Elizabeth was keeping? Did you have any involvement in those secrets?",
    "Is it just a coincidence that you were present during the murder, or were you deliberately involved?",
    "Did you notice anyone else acting suspiciously around the time of the murder?",
    "Are you intentionally withholding information that could be crucial to solving this case?",
    "Have you ever been involved in any criminal activities in the past? Are you trying to cover up your own tracks?",
    "Do you have a history of violence or conflicts with Elizabeth or anyone else related to this case?",
    "How can we be sure that you didn't tamper with the crime scene or hide any evidence?"};

inline extern string q_friendly[] = {
    "How long have you known Elizabeth? Can you tell me about your fondest memory of her?",
    "What can you tell me about your relationship with Elizabeth? Were you close friends or acquaintances?",
    "Can you share any positive qualities or traits that you admired in Elizabeth?",
    "Are there any hobbies or interests that you and Elizabeth had in common?",
    "Is there anything you would like to tell me about Elizabeth that might help in the investigation?",
    "How are you coping with the loss of Elizabeth? It must be tough for you as well.",
    "Can you recall any specific incidents where Elizabeth showed kindness or helped someone in need?",
    "What do you think was the most significant impact Elizabeth had on the people around her?",
    "Do you have any theories or ideas about who might have wanted to harm Elizabeth?",
    "Is there anything else you would like to share with me that could assist in solving this case?"};

#endif // STAGE_1_H