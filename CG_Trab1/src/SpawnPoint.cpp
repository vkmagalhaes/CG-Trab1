#include "SpawnPoint.h"

SpawnPoint::SpawnPoint() {
    maxDistance = 20.0;
}

void SpawnPoint::setPosition(float x, float y, float z) {
    position.set(x, y , z);
}

void SpawnPoint::insertZombie(Zumbi &zombie) {
    float x, y;
    Array diff;

    x = random() * maxDistance;
    y = random() * maxDistance;
    diff.set(x, y, 20);

    zombie.position( position + diff );
}

