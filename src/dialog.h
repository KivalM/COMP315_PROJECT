#ifndef DIALOG_H
#define DIALOG_H

#include <string>
using namespace std;

struct Dialog
{
    // A piece of text that the character says
    string text;

    // The next dialog options
    Dialog *option1 = nullptr;
    Dialog *option2 = nullptr;
    Dialog *option3 = nullptr;
    Dialog *option4 = nullptr;
};

void build_dialog_tree(Dialog *root){};

#endif // DIALOG_H
