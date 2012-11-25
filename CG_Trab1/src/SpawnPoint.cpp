#include "SpawnPoint.h"

SpawnPoint::SpawnPoint() {
    maxDistance = 20.0;
}

void SpawnPoint::setPosition(float x, float y, float z) {
    position.set(x, y , z);
}

void SpawnPoint::insertZombie(Zumbi &zombie) {
    float x, z;
    Array diff;

    x = random() * maxDistance;
    z = random() * maxDistance;
    diff.set(x, 0, z);

    zombie.position( position + diff );
}

