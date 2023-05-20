#include "dialog.h"

Dialog create_dialog(string text, string character, string bg, Dialog *next)
{
    Dialog d;
    d.text = text;
    d.char_img = character;
    d.bg_img = bg;
    d.type = DIALOG;
    d.next = next;
    return d;
}