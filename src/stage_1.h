#ifndef STAGE_1_H
#define STAGE_1_H
#include <string>
#include "dialog.h"

inline extern Dialog dialog_1_16 = create_npc_dialog("This is demo text 6", 4, 5, nullptr);
inline extern Dialog dialog_1_15 = create_npc_dialog("You selected an option previously", 1, 1, &dialog_1_16);

inline extern Dialog dialog_1_14 = create_npc_dialog("You clicked option 1", 1, 1, &dialog_1_15);
inline extern Dialog dialog_1_13 = create_npc_dialog("You clicked option 2", 1, 1, &dialog_1_15);
inline extern Dialog dialog_1_12 = create_npc_dialog("You clicked option 3", 1, 1, &dialog_1_15);
inline extern Dialog dialog_1_11 = create_npc_dialog("You clicked option 4", 1, 1, &dialog_1_15);

inline extern Choice choice_1_9_a = create_choice("Option 1", &dialog_1_14);
inline extern Choice choice_1_9_b = create_choice("Option 2", &dialog_1_13);
inline extern Choice choice_1_9_c = create_choice("Option 3", &dialog_1_12);
inline extern Choice choice_1_9_d = create_choice("Option 4", &dialog_1_11);

inline extern Dialog dialog_1_9 = create_dialog_choice("Pick an option", 1, 1, &choice_1_9_a, &choice_1_9_b, &choice_1_9_c, &choice_1_9_d);

inline extern Dialog dialog_1_8 = create_npc_dialog("This is demo text 9", 3, 3, &dialog_1_9);
inline extern Dialog dialog_1_7 = create_npc_dialog("This is demo text 8", 4, 2, &dialog_1_8);
inline extern Dialog dialog_1_6 = create_npc_dialog("This is demo text 7", 3, 7, &dialog_1_7);
inline extern Dialog dialog_1_5 = create_npc_dialog("This is demo text 6", 4, 5, &dialog_1_6);
inline extern Dialog dialog_1_4 = create_npc_dialog("This is demo text 5", 6, 3, &dialog_1_5);
inline extern Dialog dialog_1_3 = create_npc_dialog("This is demo text 4", 5, 1, &dialog_1_4);
inline extern Dialog dialog_1_2 = create_npc_dialog("This is demo text 3", 4, 1, &dialog_1_3);
inline extern Dialog dialog_1_1 = create_npc_dialog("This is demo text 2", 3, 2, &dialog_1_2);
inline extern Dialog stage_1_root = create_npc_dialog("This is demo text 1", 2, 1, &dialog_1_1);

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

inline extern string michael_neutral[] = {
    "I'm Michael, and I've known Elizabeth for some time now. We had a business arrangement regarding her farm.",
    "I was with Elizabeth in the Rose Garden, exploring the farm and discussing our business deal.",
    "I can't say I noticed anything specific. My mind was preoccupied with our conversation."
    "I knew her well enough through our business interactions. She seemed determined and focused on her farm.",
    "I'm not aware of any recent conflicts she may have had. Our discussions were mainly centered around the sale of her farm.",
    " I was with Elizabeth in the Rose Garden. She can confirm my presence there."
    "I was present at the time, but I didn't witness the actual crime. I heard some commotion, but I was too shocked to react immediately.",
    "I can't say for certain. Elizabeth seemed to have a lot of acquaintances due to her involvement in the community and her farm.",
    "I'm not sure about any peculiar habits, but she was passionate about her farm and dedicated a lot of time to its upkeep.",
    "Our recent conversations mainly revolved around the sale of her farm and the financial aspects surrounding it."};

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

inline extern string michael_aggressive[] = {
    "I-I was there to discuss the sale of Elizabeth's farm. We had arranged to meet, and I was hoping to finalize the details.",
    "N-No, I'm not hiding anything. Our relationship was primarily centered around the business deal, and I have nothing to hide.",
    "N-No, absolutely not! I had no motives or reasons to cause any harm to Elizabeth. I wanted the sale to go smoothly.",
    "I wasn't aware of any secrets Elizabeth might have had. Our discussions were focused on the farm sale, and I don't have any involvement in secrets.",
    "It's purely a coincidence. I-I didn't have any involvement or intentions regarding what happened to Elizabeth.",
    "I-I'm not sure. I was mostly focused on my conversation with Elizabeth, and I didn't pay much attention to others around us.",
    "N-No, I promise I'm not withholding anything important. I'm just trying to help as much as I can.",
    "No, I've never been involved in any criminal activities. I-I have no reason to cover up anything or hide any tracks.",
    "N-No, I don't have any history of violence or conflicts with Elizabeth or anyone else involved in this case. I've always tried to avoid such situations.",
    "Y-You can trust me, please. I had no reason to tamper with the crime scene or hide any evidence. I-I would never do something like that."};

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

inline extern string michael_friendly[] = {
    "I've known Elizabeth for a few months, but we weren't particularly close. I didn't have many personal interactions or memories with her.",
    "Our relationship was more on the acquaintance side. We interacted mainly regarding the potential sale of her farm.",
    "Elizabeth seemed determined and had a sense of integrity in her dealings. I admired her commitment to her farm.",
    "We didn't have many common hobbies or interests. Our interactions were primarily centered around the farm sale.",
    "I'm afraid I don't have any specific information about Elizabeth that could be relevant to the investigation.",
    "The loss of Elizabeth is indeed tragic, but I didn't have a strong personal connection with her, so it hasn't affected me as deeply.",
    "I don't recall any specific incidents, but I've heard that Elizabeth was known for her generosity and willingness to help others.",
    "Elizabeth's passion for farming seemed to inspire those around her. She had a positive impact on the community.",
    "I don't have any theories or ideas about who might have wanted to harm Elizabeth. I'm sorry, I wish I could be more helpful in that regard.",
    "I've shared what I know and remember. I don't have any additional information that could assist in solving the case."};

#endif // STAGE_1_H