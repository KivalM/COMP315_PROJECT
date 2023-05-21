#ifndef STAGE_1_H
#define STAGE_1_H

#include "dialog.h"

inline extern Dialog dialog_1_16 = create_dialog("This is demo text 6", 4, 5, nullptr);
inline extern Dialog dialog_1_15 = create_dialog("You selected an option previously", 1, 1, &dialog_1_16);

inline extern Dialog dialog_1_14 = create_dialog("You clicked option 1", 1, 1, &dialog_1_15);
inline extern Dialog dialog_1_13 = create_dialog("You clicked option 2", 1, 1, &dialog_1_15);
inline extern Dialog dialog_1_12 = create_dialog("You clicked option 3", 1, 1, &dialog_1_15);
inline extern Dialog dialog_1_11 = create_dialog("You clicked option 4", 1, 1, &dialog_1_15);

inline extern Choice choice_1_9_a = create_choice("Option 1", &dialog_1_14);
inline extern Choice choice_1_9_b = create_choice("Option 2", &dialog_1_13);
inline extern Choice choice_1_9_c = create_choice("Option 3", &dialog_1_12);
inline extern Choice choice_1_9_d = create_choice("Option 4", &dialog_1_11);

inline extern Dialog dialog_1_9 = create_dialog_choice("Pick an option", 1, 1, &choice_1_9_a, &choice_1_9_b, &choice_1_9_c, &choice_1_9_d);

inline extern Dialog dialog_1_8 = create_dialog("This is demo text 9", 5, 3, &dialog_1_9);
inline extern Dialog dialog_1_7 = create_dialog("This is demo text 8", 5, 2, &dialog_1_8);
inline extern Dialog dialog_1_6 = create_dialog("This is demo text 7", 6, 7, &dialog_1_7);
inline extern Dialog dialog_1_5 = create_dialog("This is demo text 6", 4, 5, &dialog_1_6);
inline extern Dialog dialog_1_4 = create_dialog("This is demo text 5", 2, 3, &dialog_1_5);
inline extern Dialog dialog_1_3 = create_dialog("This is demo text 4", 1, 1, &dialog_1_4);
inline extern Dialog dialog_1_2 = create_dialog("This is demo text 3", 1, 1, &dialog_1_3);
inline extern Dialog dialog_1_1 = create_dialog("This is demo text 2", 1, 2, &dialog_1_2);
inline extern Dialog stage_1_root = create_dialog("This is demo text 1", 1, 1, &dialog_1_1);

#endif // STAGE_1_H