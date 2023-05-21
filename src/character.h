#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
using namespace std;

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
