#include "dialog.h"

Choice create_choice(string text, Dialog *next)
{
    Choice c;
    c.text = text;
    c.next = next;
    return c;
}

Dialog create_dialog(string text, int character, int bg, Dialog *next)
{
    Dialog d;
    d.text = text;
    d.character = character;
    d.bg = bg;
    d.type = DIALOG;
    d.next = next;
    return d;
}

Dialog create_dialog_choice(string text, int character, int bg, Choice *option1, Choice *option2, Choice *option3, Choice *option4)
{
    Dialog d;
    d.text = text;
    d.character = character;
    d.bg = bg;
    d.type = CHOICE;
    d.option1 = option1;
    d.option2 = option2;
    d.option3 = option3;
    d.option4 = option4;
    return d;
}

Dialog create_stage_end(string text, int character, int bg)
{
    Dialog d;
    d.text = text;
    d.character = character;
    d.bg = bg;
    d.type = STAGE_END;
    return d;
}

Dialog create_end(string text, int character, int bg)
{
    Dialog d;
    d.text = text;
    d.character = character;
    d.bg = bg;
    d.type = END;
    return d;
}