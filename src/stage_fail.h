#ifndef STAGE_FAIL_H
#define STAGE_FAIL_H

#include <string>
#include "dialog.h"

// Narrator introduction

inline extern Dialog dialog_fail_13 = create_stage_end("With a heavy heart, Conan rose from his seat, his resolve unyielding. The room grew darker as he stepped into the unknown, leaving behind a void that only he could fill. The city's secrets awaited, and it was time to prove that even in defeat, a detective's spirit could not be extinguished.", 1, 0);
inline extern Dialog dialog_fail_12 = create_npc_dialog("I won't let this setback define me, Captain. I'll continue to search for the truth, even if it means working from the shadows. The city needs justice, and I won't rest until it's served.", 0, 0, &dialog_fail_13);
inline extern Dialog dialog_fail_11 = create_npc_dialog("Conan's gaze met Clouseau's, a glimmer of determination shining through the disappointment.", 1, 0, &dialog_fail_12);
inline extern Dialog dialog_fail_10 = create_npc_dialog("I know, Conan. I've seen you at your best, piercing through the haze of mystery. But even the brightest stars can fade. It's time for a new chapter, a fresh perspective. Nightingale may surprise us all.", 2, 0, &dialog_fail_11);
inline extern Dialog dialog_fail_9 = create_npc_dialog("Clouseau sighed, his voice carrying a tinge of regret.", 1, 0, &dialog_fail_10);
inline extern Dialog dialog_fail_8 = create_npc_dialog("Nightingale may have the edge, but he lacks the knowledge and intuition that comes with being immersed in the dark underbelly of this city. I've seen the face of evil, Captain. I won't let it triumph.", 0, 0, &dialog_fail_9);
inline extern Dialog dialog_fail_7 = create_npc_dialog("Conan clenched his fists, a flicker of defiance sparking in his eyes.", 1, 0, &dialog_fail_8);
inline extern Dialog dialog_fail_6 = create_npc_dialog("I know your passion, Conan, but the powers that be have chosen a replacement. Trevor Nightingale. They believe he has the edge, the instinct that's been lacking in your recent performance.", 2, 0, &dialog_fail_7);
inline extern Dialog dialog_fail_5 = create_npc_dialog("Taken off the case? But Captain, this investigation is my life. I won't let it end like this. There's more to uncover, I can feel it.", 0, 0, &dialog_fail_6);
inline extern Dialog dialog_fail_4 = create_npc_dialog("Conan's face grew dark, his eyes clouded with a mixture of frustration and disbelief.", 1, 0, &dialog_fail_5);
inline extern Dialog dialog_fail_3 = create_npc_dialog("I understand your dedication, Conan, but the higher-ups have made their decision. You're being taken off the case.", 2, 0, &dialog_fail_4);
inline extern Dialog dialog_fail_2 = create_npc_dialog("Captain, I assure you, I've been relentless in my pursuit of the truth. I may have hit a roadblock, but I am close to uncovering the real culprit.", 0, 0, &dialog_fail_3);
inline extern Dialog dialog_fail_1 = create_npc_dialog("Conan, we need to talk. The brass has lost confidence in your abilities. Your track record, once shining bright, has dimmed with this latest case.", 2, 0, &dialog_fail_2);
inline extern Dialog stage_fail_root = create_npc_dialog("Detective Conan sat in a dimly lit room, the weight of failure heavy on his shoulders. Captain Clouseau entered, his presence exuding an air of disappointment and frustration. The room was filled with the smoke of disappointment, swirling in the shadows.", 1, 0, &dialog_fail_1);

#endif // STAGE_FAIL_H