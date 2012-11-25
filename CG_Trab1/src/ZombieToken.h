#ifndef ZOMBIE_TOKEN_H
#define ZOMBIE_TOKEN_H
#include "bibliotecas.h"
#include "Constantes.h"

class ZombieToken
{
    public:
        ZombieToken(float secs, Zumbi &zumbi);
        bool enter();
        static bool comparte(ZombieToken first, ZombieToken second);
        Zumbi zombie;
        time_t enterTime;
};

#endif // ZOMBIE_TOKEN_H

