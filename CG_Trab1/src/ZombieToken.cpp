#include "ZombieToken.h"

ZombieToken::ZombieToken(float secs, Zumbi &zumbi) {
    zombie = zumbi;
    enterTime = time(NULL) + secs;
}

bool ZombieToken::enter() {
    if ( difftime( time(NULL), enterTime ) >= 0 ) return true;
    return false;
}

bool ZombieToken::compare(ZombieToken first, ZombieToken second) {
    // se o tempo de entrar fo primeiro for menor do que o do segundo
    // ent�o siginifica que ele tem que entrar antes, logo ele tem que
    // estar nas primeira posi��es da lista
    if ( diffTime( second.enterTime, first.enterTime ) >= 0 ) return true;
    return false;
}


