#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
using namespace std;

class Character
{
public:
    // The name of the character
    string name = "";

    // The image id of the character
    int img_id = 0;

    Character(string name){};
    ~Character(){};
};

#endif // CHARACTER
