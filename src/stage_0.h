#ifndef STAGE_0_H
#define STAGE_0_H
#include <string>
#include "dialog.h"

// inline extern Dialog dialog_0_16 = create_npc_dialog("This is demo text 6", 4, 5, nullptr);
// inline extern Dialog dialog_0_15 = create_npc_dialog("You selected an option previously", 1, 1, &dialog_0_16);

// inline extern Dialog dialog_0_14 = create_npc_dialog("You clicked option 1", 1, 1, &dialog_0_15);
// inline extern Dialog dialog_0_13 = create_npc_dialog("You clicked option 2", 1, 1, &dialog_0_15);
// inline extern Dialog dialog_0_12 = create_npc_dialog("You clicked option 3", 1, 1, &dialog_0_15);
// inline extern Dialog dialog_0_11 = create_npc_dialog("You clicked option 4", 1, 1, &dialog_0_15);

// inline extern Choice choice_0_9_a = create_choice("Option 1", &dialog_0_14);
// inline extern Choice choice_0_9_b = create_choice("Option 2", &dialog_0_13);
// inline extern Choice choice_0_9_c = create_choice("Option 3", &dialog_0_12);
// inline extern Choice choice_0_9_d = create_choice("Option 4", &dialog_0_11);

// inline extern Dialog dialog_0_9 = create_dialog_choice("Pick an option", 1, 1, &choice_0_9_a, &choice_0_9_b, &choice_0_9_c, &choice_0_9_d);

inline extern Dialog dialog_0_20 = create_npc_dialog("Prepare yourself, Detective Conan, for the path to redemption will be fraught with challenges and deception. The fate of your career rests upon your shoulders as you step into the world of Elizabeth Killingsworth's murder, determined to solve the mystery and emerge victorious once again.", 1, 1, nullptr);
inline extern Dialog dialog_0_19 = create_npc_dialog(" As the clock ticks, the stakes grow higher. Failure is not an option. In this race against time, will Detective Conan rise from the ashes, or be forever consumed by the shadows that threaten to engulf him?", 1, 1, &dialog_0_20);
inline extern Dialog dialog_0_18 = create_npc_dialog(" To save his career, to reclaim his tarnished name, Detective Conan must unravel the truth behind Elizabeth's murder and expose the darkness lurking beneath the surface.", 1, 1, &dialog_0_19);

inline extern Dialog dialog_0_17 = create_npc_dialog("Scene: Conan looks at a photo of Elizabeth Killingsworth, determination etched on his face.", 1, 1, &dialog_0_18);

inline extern Dialog dialog_0_16 = create_npc_dialog("With every eye upon him, Conan must navigate the treacherous labyrinth of the elite, where lies intertwine with ambition, and every whisper hides a secret.", 1, 1, &dialog_0_17);

inline extern Dialog dialog_0_15 = create_npc_dialog("Scene: Conan walks through the doors of the department, greeted by skeptical glances from his colleagues.", 1, 1, &dialog_0_16);

inline extern Dialog dialog_0_14 = create_npc_dialog("But the department's trust is fragile, and Conan knows that one misstep, one sign of incompetence, will shatter his last chance at redemption.", 1, 1, &dialog_0_15);

inline extern Dialog dialog_0_13 = create_npc_dialog("Scene: Conan stands in front of a mirror, adjusting his tie, ready to embark on his quest for redemption.", 1, 1, &dialog_0_14);

inline extern Dialog dialog_0_12 = create_npc_dialog("It is within this darkness that an opportunity for redemption presents itself. The department, seeking to salvage their reputation, places Conan at the center of a high-stakes investigation – the murder of Elizabeth Killingsworth.", 1, 1, &dialog_0_13);

inline extern Dialog dialog_0_11 = create_npc_dialog("Scene: Conan glances at the news report, a spark of determination igniting in his eyes.", 1, 1, &dialog_0_12);

inline extern Dialog dialog_0_10 = create_npc_dialog(" In a shocking turn of events, the prominent socialite and business magnate, Elizabeth Killingsworth, has been found dead under mysterious circumstances.", 8, 1, &dialog_0_11);
inline extern Dialog dialog_0_9 = create_npc_dialog("Scene: A news report plays on a television, highlighting the murder of Elizabeth Killingsworth.", 1, 1, &dialog_0_10);

inline extern Dialog dialog_0_8 = create_npc_dialog("Now, haunted by the weight of his past glory, Conan finds himself standing at the precipice of ruin. The once-esteemed detective has become a mere shadow of his former self, relegated to a forgotten corner of the department.", 1, 1, &dialog_0_9);
inline extern Dialog dialog_0_7 = create_npc_dialog("Scene: Conan's office, where his desk is adorned with framed newspaper clippings of past successes.", 1, 1, &dialog_0_8);

inline extern Dialog dialog_0_6 = create_npc_dialog("The world celebrated his triumph, as he unraveled the enigma of the Pink Panther, a case that had confounded countless investigators. But since that fateful day, Conan's achievements have vanished like smoke in the wind.", 1, 1, &dialog_0_7);

inline extern Dialog dialog_0_5 = create_npc_dialog("Flashback to a newspaper headline reading \"The Pink Panther Mystery Solved!\"", 1, 1, &dialog_0_6);
inline extern Dialog dialog_0_4 = create_npc_dialog("In the heart of a bustling city, where shadows conceal untold secrets, resides a detective known by a single name: Conan. Once hailed as a prodigious solver of mysteries, his reputation now hangs by a thread.", 1, 1, &dialog_0_5);
inline extern Dialog dialog_0_3 = create_npc_dialog("A dimly lit room with a desk cluttered with case files. Detective Conan, a seasoned investigator, sits with a pensive expression.", 1, 1, &dialog_0_4);

// Narrator introduction
inline extern Dialog dialog_0_2 = create_npc_dialog("The game will now begin", 1, 1, &dialog_0_3);
inline extern Dialog dialog_0_1 = create_npc_dialog("We hope you have read the How to play section in the main menu before starting this. Otherwise gameplay elements will seem a bit foreign.", 1, 1, &dialog_0_2);
inline extern Dialog stage_0_root = create_npc_dialog("Welcome to Deception's Echo: A Detective's Tale", 1, 1, &dialog_0_1);

#endif // STAGE_0_H