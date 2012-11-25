#ifndef SPAWN_POINT_H
#define SPAWN_POINT_H
#include "bibliotecas.h"
#include "Constantes.h"
#include "Zumbi.h"

class SpawnPoint
{
    public:
        SpawnPoint();
        void insertZombie(Zumbi &zombie);
        void setPosition(float x, float y, float z);
    private:
        Array position;
        float maxDistance;
};

#endif // SPAWN_POINT_H

