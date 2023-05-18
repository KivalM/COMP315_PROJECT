#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
using namespace std;

class Character
{
public:
    string name = "Default";
    int suspicion = 0;
    int trust = 0;

    Character(string name);
    ~Character();
};

#endif // CHARACTER
