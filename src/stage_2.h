#ifndef STAGE_2_H
#define STAGE_2_H

#include <string>
#include "dialog.h"

/*
    This file represents the second stage of the game.
    It contains the dialog nodes for the third stage.

    Each dialog node is represented by a Dialog struct.
    The pointer to the next dialog node is stored in the next field.
*/

inline extern Dialog dialog_2_44 = create_stage_end("Their conversation ended, both Detective Conan and Thomas Reynolds understood the weight of their task. The path to uncovering the truth would be treacherous, but they were determined to bring justice to the shadows that surrounded them.", 1, 3);
inline extern Dialog dialog_2_43 = create_npc_dialog("I couldn't agree more, Mr. Reynolds. Together, we shall shed light on the shadows and reveal the hidden truths that lie within.", 0, 3, &dialog_2_44);
inline extern Dialog dialog_2_42 = create_npc_dialog("(Nods, a glimmer of determination in his eyes) That it is, Detective. Elizabeth deserves justice, and we must uncover the darkness lurking within these walls.", 4, 3, &dialog_2_43);
inline extern Dialog dialog_2_41 = create_npc_dialog("Your caution is duly noted, Mr. Reynolds. A thorough investigation is indeed necessary to unravel the truth behind this intricate web of secrets.", 0, 3, &dialog_2_42);
inline extern Dialog dialog_2_40 = create_npc_dialog("(Pauses, choosing his words carefully) Detective, in my line of work, one learns to suspect everyone until proven otherwise. While I can't point fingers directly, it's clear that anyone within Elizabeth's inner circle could have had motives of their own. We must approach this investigation with utmost caution.", 4, 3, &dialog_2_41);
inline extern Dialog dialog_2_39 = create_npc_dialog("And what about the other suspects? Any thoughts on their potential involvement?", 0, 3, &dialog_2_40);
inline extern Dialog dialog_2_38 = create_npc_dialog("(Nods gravely) It wouldn't be far-fetched to assume so. Marcus and Elizabeth have had their fair share of conflicts in the past. There's always been an air of rivalry between them, driven by their ambitions and the competition they shared.", 4, 3, &dialog_2_39);
inline extern Dialog dialog_2_37 = create_npc_dialog("Intriguing. Your concerns about Marcus are evident. Do you believe he had a motive to harm Elizabeth?", 0, 3, &dialog_2_38);
inline extern Dialog dialog_2_36 = create_npc_dialog("Regrettably, I lost sight of Marcus at a crucial moment. It was then that he vanished from my sight, slipping away like a wisp of smoke. Next thing I knew, he was in Elizabeth's office, lurking in the shadows.", 4, 3, &dialog_2_37);
inline extern Dialog dialog_2_35 = create_npc_dialog("Did you witness anything unusual during your surveillance?", 0, 3, &dialog_2_36);
inline extern Dialog dialog_2_34 = create_npc_dialog("I was diligently carrying out my duty, watching over Marcus Hawthorne as Elizabeth instructed me. He seemed rather jumpy, moving about the mansion in a suspicious manner.", 4, 3, &dialog_2_35);
inline extern Dialog dialog_2_33 = create_npc_dialog("Thank you for your concern, Mr. Reynolds. Now, tell me, where were you at the time of the murder?", 0, 3, &dialog_2_34);
inline extern Dialog dialog_2_32 = create_npc_dialog("(Relaxes slightly) Detective, you may proceed, but mind your step. This place is full of shadows.", 4, 3, &dialog_2_33);
inline extern Dialog dialog_2_31 = create_npc_dialog("Detective Conan, at your service. I'm here to shed light on the unfortunate events that have taken place.", 0, 3, &dialog_2_32);
inline extern Dialog dialog_2_30 = create_npc_dialog("(Gazes at Conan with suspicion) Who's asking?", 4, 3, &dialog_2_31);
inline extern Dialog dialog_2_29 = create_npc_dialog("Mr. Reynolds, a moment of your time, if you please.", 0, 3, &dialog_2_30);
inline extern Dialog dialog_2_28 = create_npc_dialog("Detective Conan encountered Thomas Reynolds, Elizabeth's loyal bodyguard, in the dimly lit hallway of the mansion. Thomas's stern expression and alert posture hinted at his years of experience in protecting his clients.", 1, 3, &dialog_2_29);
inline extern Dialog dialog_2_27 = create_npc_dialog("With that, Detective Conan left Amelia in the dimly lit hallway, her eyes filled with a mix of grief, resentment, and a glimmer of hope that the truth would ultimately be revealed.", 1, 3, &dialog_2_28);
inline extern Dialog dialog_2_26 = create_npc_dialog("I'll do my best, Ms. Bennett. Trust that justice will prevail.", 0, 3, &dialog_2_27);
inline extern Dialog dialog_2_25 = create_npc_dialog("(Nods, a mix of grief and resentment in her eyes) Please find the truth, Detective. The secrets that haunt this mansion must be unraveled.", 5, 3, &dialog_2_26);
inline extern Dialog dialog_2_24 = create_npc_dialog("Thank you for your cooperation, Ms. Bennett. I'll be sure to consider your insights while investigating this unfortunate case.", 0, 3, &dialog_2_25);
inline extern Dialog dialog_2_23 = create_npc_dialog("(Her voice firm) No, Detective. I want nothing to do with it. My sister's success was never mine to inherit, and I have no desire to continue what she built. My interests lie elsewhere.", 5, 3, &dialog_2_24);
inline extern Dialog dialog_2_22 = create_npc_dialog("(Raises an eyebrow) Vincent Delacroix, you say? An interesting lead indeed. But what about you, Ms. Bennett? Do you have any interest in running the business?", 0, 3, &dialog_2_23);
inline extern Dialog dialog_2_21 = create_npc_dialog("Vincent Delacroix, that conniving snake. He had everything to gain financially by harming Elizabeth. I've always suspected his ulterior motives, aiming to seize control of her business empire. He's not to be trusted.", 5, 3, &dialog_2_22);
inline extern Dialog dialog_2_20 = create_npc_dialog("(Nods understandingly) And what are your thoughts on the other suspects? Any suspicions?", 0, 3, &dialog_2_21);
inline extern Dialog dialog_2_19 = create_npc_dialog("(Her voice tinged with bitterness) Oh, Detective, our relationship was strained, to say the least. She reveled in her triumphs while I lived in the shadows. I can't say I paid much attention to her actions, but I could feel the weight of her success crushing me.", 5, 3, &dialog_2_20);
inline extern Dialog dialog_2_18 = create_npc_dialog("Interesting. Have you noticed anything peculiar about Elizabeth leading up to her demise?", 0, 3, &dialog_2_19);
inline extern Dialog dialog_2_17 = create_npc_dialog("(Pauses for a moment) It's nothing significant, really. Just a way to distract myself from the shadow Elizabeth cast over my life. I've always felt overshadowed by her success.", 5, 3, &dialog_2_18);
inline extern Dialog dialog_2_16 = create_npc_dialog("A personal project, you say? Anything you'd like to share about it?", 0, 3, &dialog_2_17);
inline extern Dialog dialog_2_15 = create_npc_dialog("I was in my room the entire evening, immersed in a personal project. I hardly interacted with Elizabeth. Our relationship had become distant, you see.", 5, 3, &dialog_2_16);
inline extern Dialog dialog_2_14 = create_npc_dialog("Tell me, where were you when the unfortunate incident occurred?", 0, 3, &dialog_2_15);
inline extern Dialog dialog_2_13 = create_npc_dialog("(A hint of sadness lingers in her voice) Thank you, Detective. It's a difficult time for our family. What do you need to know?", 5, 3, &dialog_2_14);
inline extern Dialog dialog_2_12 = create_npc_dialog("Ms. Bennett, isn't it? My deepest condolences for your loss. Mind if we have a little chat?", 0, 3, &dialog_2_13);
inline extern Dialog dialog_2_11 = create_npc_dialog("Detective Conan bumped into Amelia Bennett in a dimly lit hallway of the mansion. He couldn't help but notice the tension in her eyes, hinting at a troubled past. The detective approached her cautiously, ready to delve into the depths of her strained relationship with Elizabeth.", 1, 3, &dialog_2_12);
inline extern Dialog dialog_2_10 = create_npc_dialog("Conan's gaze intensified, probing for any hidden truths or inconsistencies. Satisfied for the moment, he moved on to the next suspect, leaving Marcus to contemplate the shadows that danced around him, threatening to reveal his darkest secrets.", 1, 3, &dialog_2_11);
inline extern Dialog dialog_2_9 = create_npc_dialog("(Defensively) I assure you, Detective, I had no knowledge of her tragic fate until I stumbled upon the scene. The shock of the discovery still lingers within me.", 3, 3, &dialog_2_10);
inline extern Dialog dialog_2_8 = create_npc_dialog("(With a hint of curiosity) Interesting. Your ignorance of Elizabeth's demise until you arrived at the crime scene piques my interest. A fortunate coincidence, or perhaps something more?", 0, 3, &dialog_2_9);
inline extern Dialog dialog_2_7 = create_npc_dialog("(Reluctantly) I heard Elizabeth's voice, engaged in a conversation with someone down the hall. The words were muffled, making it impossible to discern their true nature.", 3, 3, &dialog_2_8);
inline extern Dialog dialog_2_6 = create_npc_dialog("(Leaning in, voice lowered) And, pray tell, what did you overhear in that clandestine exchange?", 0, 3, &dialog_2_7);
inline extern Dialog dialog_2_5 = create_npc_dialog("Conan's eyes narrowed as he listened to Marcus's account, the subtle hints of suspicion lingering in the air.", 1, 3, &dialog_2_6);
inline extern Dialog dialog_2_4 = create_npc_dialog("(Slightly taken aback) I was exploring the depths of this mansion, losing myself in the allure of these captivating masterpieces. But fate had other plans, for I found myself inadvertently in Elizabeth's office, overhearing a conversation that made me flee through the window, fearing discovery.", 3, 3, &dialog_2_5);
inline extern Dialog dialog_2_3 = create_npc_dialog("Merely seeking answers, my good sir, in this web of darkness that has befallen us. Pray tell, where were you when the nefarious act took place?", 0, 3, &dialog_2_4);
inline extern Dialog dialog_2_2 = create_npc_dialog("(Startled, turning to face Conan) Detective Conan, a stranger in this somber labyrinth. What brings you to my secluded haven?", 3, 3, &dialog_2_3);
inline extern Dialog dialog_2_1 = create_npc_dialog("Well, well, Marcus Hawthorne, a man of refined taste, surrounded by the enigmatic allure of art. May I disturb your contemplation for a moment?", 0, 3, &dialog_2_2);
inline extern Dialog stage_3_root = create_npc_dialog("The gloomy library cast long shadows as Detective Conan made his way through the dimly lit room. He approached Marcus Hawthorne, the elusive businessman, who was engrossed in admiring an antique painting.", 1, 3, &dialog_2_1);

#endif // STAGE_2\_H