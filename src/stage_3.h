#ifndef STAGE_3_H
#define STAGE_3_H

#include <string>
#include "dialog.h"
#include "stage_2.h"

// Narrator introduction
inline extern Dialog dialog_3_44 = create_stage_end("Their conversation ended, both Detective Conan and Thomas Reynolds understood the weight of their task. The path to uncovering the truth would be treacherous, but they were determined to bring justice to the shadows that surrounded them.", 1, 14);
inline extern Dialog dialog_3_43 = create_npc_dialog("I couldn't agree more, Mr. Reynolds. Together, we shall shed light on the shadows and reveal the hidden truths that lie within.", 0, 14, &dialog_3_44);
inline extern Dialog dialog_3_42 = create_npc_dialog("(Nods, a glimmer of determination in his eyes) That it is, Detective. Elizabeth deserves justice, and we must uncover the darkness lurking within these walls.", 4, 14, &dialog_3_43);
inline extern Dialog dialog_3_41 = create_npc_dialog("Your caution is duly noted, Mr. Reynolds. A thorough investigation is indeed necessary to unravel the truth behind this intricate web of secrets.", 0, 14, &dialog_3_42);
inline extern Dialog dialog_3_40 = create_npc_dialog("(Pauses, choosing his words carefully) Detective, in my line of work, one learns to suspect everyone until proven otherwise. While I can't point fingers directly, it's clear that anyone within Elizabeth's inner circle could have had motives of their own. We must approach this investigation with utmost caution.", 4, 14, &dialog_3_41);
inline extern Dialog dialog_3_39 = create_npc_dialog("And what about the other suspects? Any thoughts on their potential involvement?", 0, 14, &dialog_3_40);
inline extern Dialog dialog_3_38 = create_npc_dialog("(Nods gravely) It wouldn't be far-fetched to assume so. Marcus and Elizabeth have had their fair share of conflicts in the past. There's always been an air of rivalry between them, driven by their ambitions and the competition they shared.", 4, 14, &dialog_3_39);
inline extern Dialog dialog_3_37 = create_npc_dialog("Intriguing. Your concerns about Marcus are evident. Do you believe he had a motive to harm Elizabeth?", 0, 14, &dialog_3_38);
inline extern Dialog dialog_3_36 = create_npc_dialog("Regrettably, I lost sight of Marcus at a crucial moment. It was then that he vanished from my sight, slipping away like a wisp of smoke. Next thing I knew, he was in Elizabeth's office, lurking in the shadows.", 4, 14, &dialog_3_37);
inline extern Dialog dialog_3_35 = create_npc_dialog("Did you witness anything unusual during your surveillance?", 0, 14, &dialog_3_36);
inline extern Dialog dialog_3_34 = create_npc_dialog("I was diligently carrying out my duty, watching over Marcus Hawthorne as Elizabeth instructed me. He seemed rather jumpy, moving about the mansion in a suspicious manner.", 4, 14, &dialog_3_35);
inline extern Dialog dialog_3_33 = create_npc_dialog("Thank you for your concern, Mr. Reynolds. Now, tell me, where were you at the time of the murder?", 0, 14, &dialog_3_34);
inline extern Dialog dialog_3_32 = create_npc_dialog("(Relaxes slightly) Detective, you may proceed, but mind your step. This place is full of shadows.", 4, 14, &dialog_3_33);
inline extern Dialog dialog_3_31 = create_npc_dialog("Detective Conan, at your service. I'm here to shed light on the unfortunate events that have taken place.", 0, 14, &dialog_3_32);
inline extern Dialog dialog_3_30 = create_npc_dialog("(Gazes at Conan with suspicion) Who's asking?", 4, 14, &dialog_3_31);
inline extern Dialog dialog_3_29 = create_npc_dialog("Mr. Reynolds, a moment of your time, if you please.", 0, 14, &dialog_3_30);
inline extern Dialog dialog_3_28 = create_npc_dialog("Detective Conan encountered Thomas Reynolds, Elizabeth's loyal bodyguard, in the dimly lit hallway of the mansion. Thomas's stern expression and alert posture hinted at his years of experience in protecting his clients.", 1, 14, &dialog_3_29);

inline extern Dialog dialog_3_27 = create_npc_dialog("With that, Detective Conan left Amelia in the dimly lit hallway, her eyes filled with a mix of grief, resentment, and a glimmer of hope that the truth would ultimately be revealed.", 1, 14, &dialog_3_28);
inline extern Dialog dialog_3_26 = create_npc_dialog("I'll do my best, Ms. Bennett. Trust that justice will prevail.", 0, 14, &dialog_3_27);
inline extern Dialog dialog_3_25 = create_npc_dialog("(Nods, a mix of grief and resentment in her eyes) Please find the truth, Detective. The secrets that haunt this mansion must be unraveled.", 5, 14, &dialog_3_26);
inline extern Dialog dialog_3_24 = create_npc_dialog("Thank you for your cooperation, Ms. Bennett. I'll be sure to consider your insights while investigating this unfortunate case.", 0, 14, &dialog_3_25);
inline extern Dialog dialog_3_23 = create_npc_dialog("(Her voice firm) No, Detective. I want nothing to do with it. My sister's success was never mine to inherit, and I have no desire to continue what she built. My interests lie elsewhere.", 5, 14, &dialog_3_24);
inline extern Dialog dialog_3_22 = create_npc_dialog("(Raises an eyebrow) Vincent Delacroix, you say? An interesting lead indeed. But what about you, Ms. Bennett? Do you have any interest in running the business?", 0, 14, &dialog_3_23);
inline extern Dialog dialog_3_21 = create_npc_dialog("Vincent Delacroix, that conniving snake. He had everything to gain financially by harming Elizabeth. I've always suspected his ulterior motives, aiming to seize control of her business empire. He's not to be trusted.", 5, 14, &dialog_3_22);
inline extern Dialog dialog_3_20 = create_npc_dialog("(Nods understandingly) And what are your thoughts on the other suspects? Any suspicions?", 0, 14, &dialog_3_21);
inline extern Dialog dialog_3_19 = create_npc_dialog("(Her voice tinged with bitterness) Oh, Detective, our relationship was strained, to say the least. She reveled in her triumphs while I lived in the shadows. I can't say I paid much attention to her actions, but I could feel the weight of her success crushing me.", 5, 14, &dialog_3_20);
inline extern Dialog dialog_3_18 = create_npc_dialog("Interesting. Have you noticed anything peculiar about Elizabeth leading up to her demise?", 0, 14, &dialog_3_19);
inline extern Dialog dialog_3_17 = create_npc_dialog("(Pauses for a moment) It's nothing significant, really. Just a way to distract myself from the shadow Elizabeth cast over my life. I've always felt overshadowed by her success.", 5, 14, &dialog_3_18);
inline extern Dialog dialog_3_16 = create_npc_dialog("A personal project, you say? Anything you'd like to share about it?", 0, 14, &dialog_3_17);
inline extern Dialog dialog_3_15 = create_npc_dialog("I was in my room the entire evening, immersed in a personal project. I hardly interacted with Elizabeth. Our relationship had become distant, you see.", 5, 14, &dialog_3_16);
inline extern Dialog dialog_3_14 = create_npc_dialog("Tell me, where were you when the unfortunate incident occurred?", 0, 14, &dialog_3_15);
inline extern Dialog dialog_3_13 = create_npc_dialog("(A hint of sadness lingers in her voice) Thank you, Detective. It's a difficult time for our family. What do you need to know?", 5, 14, &dialog_3_14);
inline extern Dialog dialog_3_12 = create_npc_dialog("Ms. Bennett, isn't it? My deepest condolences for your loss. Mind if we have a little chat?", 0, 14, &dialog_3_13);

inline extern Dialog dialog_3_11 = create_npc_dialog("(straightening his fedora, determination etched on his face) The shadows are my playground, Olivia. And the truth... it shall be revealed, one clue at a time.", 0, 14, &dialog_3_12);
inline extern Dialog dialog_3_10 = create_npc_dialog("(leaning closer, a glimmer of hope in her eyes) Find that truth, Detective. Bring justice to Elizabeth's memory. But tread carefully, for the shadows hold their secrets close, and danger lurks in the alleys of the unknown.", 6, 14, &dialog_3_11);
inline extern Dialog dialog_3_9 = create_npc_dialog("(smirking) Indeed, trust is a fragile currency in these labyrinthine corridors of suspicion. But fear not, Miss Montgomery. I have a knack for unraveling the tangled threads of deceit. And with your guidance, we shall uncover the truth that lurks beneath the surface.", 0, 14, &dialog_3_10);
inline extern Dialog dialog_3_8 = create_npc_dialog("(pausing, her voice tinged with caution) Ah, Amelia. Sisters, bound by blood and secrets. There's always been an undercurrent of tension, a dance of hidden conflicts between them. Yet, it's hard to imagine her capable of such darkness. Still, in this noir tale, trust becomes a fleeting luxury.", 6, 14, &dialog_3_9);
inline extern Dialog dialog_3_7 = create_npc_dialog("(leaning back, his eyes glinting with intrigue) Loyalty can be a double-edged blade, Olivia. And what about Amelia Summers? Elizabeth's sister. Any unease there?", 0, 14, &dialog_3_8);
inline extern Dialog dialog_3_6 = create_npc_dialog("(meeting his gaze, her tone filled with conviction) Access, yes. But involvement? Never. I may have known Elizabeth's innermost workings, but I swear on the shadowed alleys of this city, I had no hand in her demise. (Her eyes flickered with a mix of frustration and concern.) I know these suspects well, Detective. They're like family. Marcus Hawthorne, though... there's something amiss about him. His actions have raised my suspicions, and my loyalty to the others fuels my doubts.", 6, 14, &dialog_3_7);
inline extern Dialog dialog_3_5 = create_npc_dialog("(leaning in, his voice low and intense) You've had an intimate view into her world, Olivia. Her routines, her secrets. Some might say you had unparalleled access.", 0, 14, &dialog_3_6);
inline extern Dialog dialog_3_4 = create_npc_dialog("(nodding, her expression grave) Caught up indeed. The winds of tragedy blew through these halls, and we found ourselves in its merciless grip. (She paused, her eyes narrowing.) Elizabeth... she was more than just an employer to me. We were confidantes, allies. I find it unfathomable that someone close to her would be capable of such a heinous act.", 6, 14, &dialog_3_5);
inline extern Dialog dialog_3_3 = create_npc_dialog("(smirking) Secrets have a way of surfacing, even in the darkest corners. I hear you and Mr. Delacroix were caught up in the storm tonight.", 0, 14, &dialog_3_4);
inline extern Dialog dialog_3_2 = create_npc_dialog("(with a hint of weariness in her voice) Longer than I anticipated, Mr. Detective. The night took an unexpected turn, and here we are, surrounded by secrets and shadows.", 6, 14, &dialog_3_3);
inline extern Dialog dialog_3_1 = create_npc_dialog("(leaning against the door frame, his trench coat draped over his shoulders) Long night, Miss Montgomery?", 0, 14, &dialog_3_2);
inline extern Dialog stage_3_root = create_npc_dialog("The dimly lit office was cloaked in an air of mystery as Conan entered, his sharp gaze fixed on Olivia Montgomery, Elizabeth's enigmatic personal assistant. Olivia, her eyes darting between the stacks of papers on her desk, looked up with a mix of surprise and curiosity as Conan approached.", 1, 14, &dialog_3_1);

#endif // STAGE_3\_H