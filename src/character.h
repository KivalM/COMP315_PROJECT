#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
using namespace std;

/*
    This file provides a struct for representing a character in the game.

    A character has a name, an image, and a type.
    The name indicates the name of the character.
    This is used to identify the character when they are speaking.

    The image is the index of the image to use for the character.
    This is used to display the character on the screen.

    The type is used to determine how the character responds to the player.
    We did not implement this in the game, but was a major part of the design.
    The original plan was to have 3 types of characters:
        Timid: These characters are scared of the player
        Normal: These characters are neutral to the player
        Aggressive: These characters are hostile to the player

    The type of character determines how they respond to the player, outlined below.

    The original idea was to have the non-player characters react to the way the player
    speaks to them. If the player is aggressive, the timid characters will be scared etc.

    This was deemed too complicated to implement in the time we had, so we did not implement it.
*/

enum CharacterType
{
    /*
    TIMID:
    How they respond to:
        Aggressive: They will get scared and provide a response
        Neutral: Will likely not provide much of a response
        Friendly: Will likely not provide much of a response
    */
    Timid,

    /*
    Aggressive:
    How they respond to:
        Aggressive: They will not do much and not provide a response
        Neutral: Will provide much of a response
        Friendly: Will provide much of a response
    */
    Normal,

    /*
    Aggressive:
    How they respond to:
        Aggressive: They will likely get hostile and not provide a response
        Neutral: Will likely not provide much of a response
        Friendly: Will provide much of a response
    */
    Aggressive
};

class Character
{
public:
    // The name of the character
    string name = "";

    // The image id of the character
    int image = 0;

    Character();
    Character(string name, int img_idx);

private:
    // The type of character
    CharacterType type = Normal;

    // How likely they to give the player information
    // if this gets too high, they will not talk to the player
    int mistrust = 0;
};

#endif // CHARACTER
