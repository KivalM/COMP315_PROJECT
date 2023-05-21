#ifndef STAGE_1_H
#define STAGE_1_H

#include "dialog.h"

inline extern Dialog dialog_1_8 = create_dialog("This is demo text 9", 5, 3, nullptr);
inline extern Dialog dialog_1_7 = create_dialog("This is demo text 8", 8, 2, &dialog_1_8);
inline extern Dialog dialog_1_6 = create_dialog("This is demo text 7", 6, 7, &dialog_1_7);
inline extern Dialog dialog_1_5 = create_dialog("This is demo text 6", 4, 5, &dialog_1_6);
inline extern Dialog dialog_1_4 = create_dialog("This is demo text 5", 2, 3, &dialog_1_5);
inline extern Dialog dialog_1_3 = create_dialog("This is demo text 4", 1, 1, &dialog_1_4);
inline extern Dialog dialog_1_2 = create_dialog("This is demo text 3", 1, 1, &dialog_1_3);
inline extern Dialog dialog_1_1 = create_dialog("This is demo text 2", 1, 2, &dialog_1_2);
inline extern Dialog stage_1_root = create_dialog("This is demo text 1", 1, 1, &dialog_1_1);

#endif // STAGE_1_H