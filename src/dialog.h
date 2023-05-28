#ifndef DIALOG_H
#define DIALOG_H

#include <string>
using namespace std;

/*
  This file contains the definition of the dialog struct.
  A dialog is a piece of text that will be displayed on the screen.
  It can be a piece of text that a character says, or a question that the player must answer.
  This is indicated by the type field, which can be one of the following:
    DIALOG: A piece of text that a character says
    QUESTION: A question that the player must answer
    STAGE_END: A piece of text that is displayed at the end of a stage
    GAME_END: A piece of text that is displayed at the end of the game

  In the UI, the dialog is displayed in a box at the bottom of the screen.
  Based on the current dialog, the UI will display the following:
    - The text of the dialog
    - The character that is speaking
    - The background to display
    - The options to be made available to the player if this is a choice

  Clicks on the options are handled by the UI, which will then advance the pointer to the next dialog.
    - STAGE_END nodes will advance to the next stage
    - GAME_END nodes will advance to the main menu
    - QUESTION nodes will advance to the next question and adjust the score accordingly
    - DIALOG nodes will advance to the next dialog

    The dialog is implemented as a linked list, where each node points to the next node.
    This allows us to easily traverse the dialog tree.

    The original design for this was meant to be a tree, where each node points to its children,
    and based on the player's answer, we would traverse the tree to different branches.

    However, this was not implemented due to time constraints,
    and writing a coherent branching story is a lot of work.

 */

enum DialogType
{
    DIALOG,
    QUESTION,
    STAGE_END,
    GAME_END
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

    // the next dialog to be displayed
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
Dialog create_end_dialog(string text, int character, int bg);

#endif // DIALOG_H
