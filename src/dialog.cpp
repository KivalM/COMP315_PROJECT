#include "dialog.h"

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