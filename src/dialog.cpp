#include "dialog.h"

Dialog create_choice_mcq(string text, Dialog *next, string options[4], int correct_option)
{
    Dialog d;
    d.text = text;
    d.type = QUESTION;
    d.next = next;
    d.options[0] = options[0];
    d.options[1] = options[1];
    d.options[2] = options[2];
    d.options[3] = options[3];
    d.correct_option = correct_option;
    return d;
}

Dialog create_npc_dialog(string text, int character, int bg, Dialog *next)
{
    Dialog d;
    d.text = text;
    d.speaking = character;
    d.char_to_draw = character;
    d.bg = bg;
    d.type = DIALOG;
    d.next = next;
    return d;
}
Dialog create_player_dialog(string text, int character, int bg, Dialog *next)
{
    Dialog d;
    d.text = text;
    d.speaking = 0;
    d.char_to_draw = character;
    d.bg = bg;
    d.type = DIALOG;
    d.next = next;
    return d;
}

Dialog create_stage_end(string text, int character, int bg)
{
    Dialog d;
    d.text = text;
    d.char_to_draw = character;
    d.bg = bg;
    d.type = STAGE_END;
    return d;
}

Dialog create_end_dialog(string text, int character, int bg)
{
    Dialog d;
    d.text = text;
    d.char_to_draw = character;
    d.bg = bg;
    d.type = GAME_END;
    return d;
}