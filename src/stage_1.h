#ifndef STAGE_1_H
#define STAGE_1_H
#include <string>
#include "dialog.h"
#include "stage_2.h"

inline extern Dialog dialog_1_15 = create_stage_end("This is end of stage 2.", 1, 14);
inline extern Dialog dialog_1_14 = create_npc_dialog("In this perilous stage, Detective Conan had uncovered vital clues. The blood-soaked cheque, Marcus's pen, the missing weapon, the redhead hair strand, and the meticulous timing all formed pieces of a dark puzzle. With each deduction, he moved closer to unraveling the truth behind Elizabeth Killingsworth's murder.", 1, 2, &dialog_1_15);
inline extern Dialog dialog_1_13 = create_npc_dialog("(firmly): The window, a potential portal for the perpetrator. An avenue for intrusion or a means of evasion.", 0, 2, &dialog_1_14);
inline extern Dialog dialog_1_12 = create_npc_dialog("His piercing gaze shifted towards the open window, a gateway for both escape and entry.", 1, 2, &dialog_1_13);
inline extern Dialog dialog_1_11 = create_npc_dialog("(with a determined tone): The killer struck precisely, exploiting Elizabeth's moment of solitude. A calculated move, a predator stalking its prey.", 0, 2, &dialog_1_12);
inline extern Dialog dialog_1_10 = create_npc_dialog("He pondered the timeline, knowing that the murder occurred between 12 and 1 pm, Elizabeth's regular meditation hour. The precise timing added a layer of meticulous planning to the heinous act.", 1, 2, &dialog_1_11);
inline extern Dialog dialog_1_9 = create_npc_dialog("(with a touch of intrigue): A fiery strand, a clue to the enigma. The mystery of the killer's appearance deepens.", 0, 2, &dialog_1_10);
inline extern Dialog dialog_1_8 = create_npc_dialog("As he meticulously examined the crime scene, a single strand of vibrant redhead hair caught his attention. It lay near the body, a possible trace of the killer's identity.", 1, 2, &dialog_1_9);
inline extern Dialog dialog_1_7 = create_npc_dialog("(whispering): Vincent, my old acquaintance. You played your part well. Elizabeth never stood a chance.", 0, 2, &dialog_1_8);
inline extern Dialog dialog_1_6 = create_npc_dialog("His eyes then darted to the gun cabinet on the wall, still intact but left open. A key remained in the lock, suggesting that Elizabeth may have retrieved the weapon for defense. However, Conan's instincts told him otherwise.", 1, 2, &dialog_1_7);
inline extern Dialog dialog_1_5 = create_npc_dialog("(muttering): A silenced 10mm. A professional's weapon of choice. Deadly and discreet", 0, 2, &dialog_1_6);
inline extern Dialog dialog_1_4 = create_npc_dialog("His attention shifted to the gunshot wound on Elizabeth's head, a swift and lethal execution. The absence of any defensive wounds hinted at a sudden and unsuspecting attack.", 1, 2, &dialog_1_5);
inline extern Dialog dialog_1_3 = create_npc_dialog("(thoughtfully): A generous payment, tainted by blood. Marcus's involvement demands closer scrutiny. But where is he now?", 0, 2, &dialog_1_4);
inline extern Dialog dialog_1_2 = create_npc_dialog("He carefully examined the scene, his keen eyes scanning every detail. His gaze fell upon a blood-soaked table, where a signed cheque for Marcus, worth a staggering $2,000,000, lay abandoned. A pen bearing Marcus's name rested nearby, a potential link to the suspect.", 1, 2, &dialog_1_3);
inline extern Dialog dialog_1_1 = create_npc_dialog("(in a low, gravelly voice): Another soul lost to the darkness. No bruises, no signs of struggle. The killer moved swiftly and silently, catching Elizabeth off guard.", 0, 2, &dialog_1_2);
inline extern Dialog stage_2_root = create_npc_dialog("Detective Conan stood in the dimly lit office, a cloud of tension hanging in the air. The lifeless body of Elizabeth Killingsworth lay before him, a gruesome reminder of the high stakes he now faced.", 1, 2, &dialog_1_1);

#endif // STAGE_1_H