#ifndef CHARACTER_H
#define CHARACTER_H

#include "role.h"

/*
 * The character class is empty because all the functions of player(main role) are
 * in "player.h", "player.cpp" and "role.h". All the functions of NPCs are in "view.h"
 * and "view.cpp"
 */


class Character : public Role {
public:
    Character() {}
    ~Character() {}
};

#endif // CHARACTER_H
