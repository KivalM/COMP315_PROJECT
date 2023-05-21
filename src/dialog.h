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

    // the index of the background to display
    int bg = 0;

    // the id of the character to display
    int character = 0;

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

Dialog create_dialog(string text, int character, int bg, Dialog *next);

#endif // DIALOG_H
