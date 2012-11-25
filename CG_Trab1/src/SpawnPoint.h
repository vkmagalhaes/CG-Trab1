#ifndef SPAWN_POINT_H
#define SPAWN_POINT_H
#include "bibliotecas.h"
#include "Constantes.h"
#include "Zumbi.h"

class SpawnPoint
{
    public:
        SpawnPoint(float x, float y, float z);
        void insertZombie(Zumbi &zombie);
    private:
        Array position;
        float maxDistance;
};

#endif // SPAWN_POINT_H

