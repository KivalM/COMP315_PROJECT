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
    QUESTION,
    STAGE_END,
    // END
};

struct Dialog
{
    // A piece of text that the character says
    string text;

    // the index of the background to display
    int bg = 0;

    // the id of the character to display
    int speaking = 0;

    // the id of the character to display
    int char_to_draw = 0;

    // The type of dialog
    DialogType type = DIALOG;

    // the next dialog to be displayed if this is a dialog
    Dialog *next = nullptr;

    // The options to be made available to the player if this is a choice
    string options[4];
    int correct_option = 0;
};

// Helper functions for creating dialogs
Dialog create_npc_dialog(string text, int character, int bg, Dialog *next);
Dialog create_player_dialog(string text, int character, int bg, Dialog *next);
Dialog create_stage_end(string text, int character, int bg);
Dialog create_choice_mcq(string text, Dialog *next, string options[4], int correct_option);

#endif // DIALOG_H
