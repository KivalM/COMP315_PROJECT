#ifndef STAGE_4_H
#define STAGE_4_H

#include <string>
#include "dialog.h"
#include "stage_3.h"

/*
    This file represents the final stage of the game.
    It contains the dialog nodes for the final stage.

    Each dialog node is represented by a Dialog struct.
    The pointer to the next dialog node is stored in the next field.
*/

inline extern Dialog dialog_4_12 = create_stage_end("They exchanged a nod, their paths intertwining once again as they prepared for the next enigma to unravel. The room fell into silence, echoing the shadows that danced within the hearts of men. The detective and the captain, two figures bound by their pursuit of justice, disappeared into the night, leaving behind a tale of murder and intrigue.", 1, 0);
inline extern Dialog dialog_4_11 = create_npc_dialog("Indeed, Captain. The web has been unraveled, and the truth shines forth. But remember, in the realm of darkness, another mystery awaits, lurking in the depths of the city's underbelly.", 0, 0, &dialog_4_12);
inline extern Dialog dialog_4_10 = create_npc_dialog("Truly, you are a master of deduction, Conan. With Vincent unmasked, justice can be served. The game is afoot no more.", 2, 0, &dialog_4_11);
inline extern Dialog dialog_4_9 = create_npc_dialog("His words were crafted carefully, Captain, but his lies could not escape my scrutiny. His suspicion towards Marcus, his knowledge of Thomas's surveillance mishap. They were breadcrumbs he left behind, attempting to divert attention. But in the world of shadows, every move leaves a trace.", 0, 0, &dialog_4_10);
inline extern Dialog dialog_4_8 = create_npc_dialog("Formidable, Conan! And what say you to Vincent's defense?", 2, 0, &dialog_4_9);
inline extern Dialog dialog_4_7 = create_npc_dialog("The signs were there, Captain. Vincent's feigned shock and loyalty, his intricate knowledge of Elizabeth's inner circle, and his financial motives. He orchestrated the arrival of Marcus, creating the perfect alibi while removing his competition. The pieces of the puzzle aligned with meticulous precision.", 0, 0, &dialog_4_8);
inline extern Dialog dialog_4_6 = create_npc_dialog("Ah, c'est incroyable! But what led you to this conclusion, Conan?", 2, 0, &dialog_4_7);
inline extern Dialog dialog_4_5 = create_npc_dialog("Indeed, Captain. The truth has been revealed, and the darkness has come to light. Vincent Delacroix, the man who walked in shadows, was the puppet master behind this tragedy.", 0, 0, &dialog_4_6);
inline extern Dialog dialog_4_4 = create_npc_dialog("Well, well, Conan. Have you cracked the case? Enlighten me, mon ami.", 2, 0, &dialog_4_5);
inline extern Dialog dialog_4_3 = create_npc_dialog("Captain Clouseau entered the room, his trench coat trailing behind him as he approached Detective Conan. The room was filled with a haze of cigarette smoke, adding to the air of mystery.", 1, 2, &dialog_4_4);
inline extern Dialog dialog_4_2 = create_npc_dialog("He paced the room, his mind weaving through the evidence. The motive, the means, and the opportunity all pointed to Vincent. The man who stood by Elizabeth's side, her confidant and close companion. Conan drew in a deep breath, ready to unravel the tangled web.", 1, 2, &dialog_4_3);
inline extern Dialog dialog_4_1 = create_npc_dialog("'As the pieces fall into place, the web of deception becomes clear,' Conan muttered in a low, gravelly voice. 'Vincent, you played your part well, concealing your true nature behind a veil of shock and loyalty. But the shadow of guilt cannot escape the keen eyes of a detective.'", 1, 2, &dialog_4_2);
inline extern Dialog stage_5_root = create_npc_dialog("Detective Conan stood in the dimly lit room, the faint glow of a cigarette illuminating his face. The pieces of the puzzle were scattered before him, and his mind raced to connect them. The time had come to unveil the truth behind Elizabeth's murder.", 1, 2, &dialog_4_1);

#endif // STAGE_4_H