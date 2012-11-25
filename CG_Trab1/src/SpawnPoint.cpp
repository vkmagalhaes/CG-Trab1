#include "SpawnPoint.h""

SpawnPoint::SpawnPoint(float x, float y, float z) {
    position.set(x, y , z);
    maxDistance = 10.0;
}

void SpawnPoint::insertZombie(Zumbi &zombie) {
    float x, y;
    Array diff;

    x = random() * maxDistance;
    y = random() * maxDistance;
    diff.set(x, y, 20);

    zombie.position( position + diff );
}

