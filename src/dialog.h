#ifndef DIALOG_H
#define DIALOG_H

#include <string>
using namespace std;

struct Dialog;

struct Choice
{
    string text;
    Dialog *next;
};

enum DialogType
{
    DIALOG,
    CHOICE,
    STAGE_END,
    END
};

struct Dialog
{
    // A piece of text that the character says
    string text;

    string bg_img = "default.png";
    string char_img = "default.png";

    // The type of dialog
    DialogType type = DIALOG;

    // the next dialog to be displayed if this is a dialog
    Dialog *next = nullptr;

    // The options to be made available to the player if this is a choice
    Choice *option1 = nullptr;
    Choice *option2 = nullptr;
    Choice *option3 = nullptr;
    Choice *option4 = nullptr;
};

Dialog create_dialog(string text, string character, string bg, Dialog *next);

#endif // DIALOG_H
