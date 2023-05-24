#ifndef STAGE_2_H
#define STAGE_2_H

#include <string>
#include "dialog.h"
#include "stage_1.h"

// Narrator introduction
inline extern Dialog dialog_0_18 = create_npc_dialog("I hope you mean it, Conan. The department's future rests in your hands. Don't let us down.", 2, 14, &stage_1_root);
inline extern Dialog dialog_0_17 = create_npc_dialog("You won't be disappointed, Captain. I'll give it my all. This is my shot at redemption, and I won't let it slip away.", 0, 14, &dialog_0_18);
inline extern Dialog dialog_0_16 = create_npc_dialog("That's the spirit, Conan. Prove to me that you still have that fire. Solve this case, find the truth, and make sure justice is served. We're counting on you.", 2, 14, &dialog_0_17);
inline extern Dialog dialog_0_15 = create_npc_dialog("Nightingale? The rising star? I won't let him steal my chance at redemption.", 0, 14, &dialog_0_16);
inline extern Dialog dialog_0_14 = create_npc_dialog("Damn right it would be. We can't afford any slip-ups. Trevor Nightingale is waiting in the wings, ready to take your place if you falter.", 2, 14, &dialog_0_15);
inline extern Dialog dialog_0_13 = create_npc_dialog("I understand the gravity of the situation, Captain. Losing this opportunity would be disastrous for both of us.", 0, 14, &dialog_0_14);
inline extern Dialog dialog_0_12 = create_npc_dialog("You've got it. She's surrounded herself with trusted individuals, hidden away in that mansion of hers. We're putting our last hope in you, Conan. Fail, and it's the end of the line.", 2, 14, &dialog_0_13);
inline extern Dialog dialog_0_11 = create_npc_dialog("Elizabeth Killingsworth, the reclusive magnate? The stakes are high, I see.", 0, 14, &dialog_0_12);
inline extern Dialog dialog_0_10 = create_npc_dialog("We're in a financial crisis, Conan. The department's on the edge. We need a breakthrough, a high-profile case that will restore our reputation. The investors from Elizabeth Killingsworth's companies specifically requested you.", 2, 14, &dialog_0_11);
inline extern Dialog dialog_0_9 = create_npc_dialog("I know, Captain. I've hit a rough patch. But what's this all about?", 0, 14, &dialog_0_10);
inline extern Dialog dialog_0_8 = create_npc_dialog("Exactly. That case put you in the spotlight, but it's been years since then. And lately, you've been struggling to find leads. You need something big to reclaim your former glory.", 2, 14, &dialog_0_9);
inline extern Dialog dialog_0_7 = create_npc_dialog("Yeah, it feels like a lifetime ago. A queen murdered for a pink diamond, and the culprit running a black market museum.", 0, 14, &dialog_0_8);
inline extern Dialog dialog_0_6 = create_npc_dialog("You remember the Pink Panther case, don't you? The one that shot you to fame?", 2, 14, &dialog_0_7);
inline extern Dialog dialog_0_5 = create_npc_dialog("What's on your mind, Captain?", 0, 14, &dialog_0_6);
inline extern Dialog dialog_0_4 = create_npc_dialog("Take a seat, Conan. We need to have a serious talk.", 2, 14, &dialog_0_5);
inline extern Dialog dialog_0_3 = create_npc_dialog("Detective Conan entered Captain Clouseau's dimly lit office, the faint glow of a desk lamp casting shadows on the worn-out wooden furniture.", 1, 14, &dialog_0_4);
inline extern Dialog dialog_0_2 = create_npc_dialog("The game will now begin", 1, 14, &dialog_0_3);
inline extern Dialog dialog_0_1 = create_npc_dialog("We hope you have read the `How to play` section in the main menu before starting this. Otherwise gameplay elements will seem a bit foreign.", 1, 14, &dialog_0_2);
inline extern Dialog stage_2_root = create_npc_dialog("Welcome to Mystery Noir: Shadows of Redemption", 1, 14, &dialog_0_1);

#endif // STAGE_2\_H