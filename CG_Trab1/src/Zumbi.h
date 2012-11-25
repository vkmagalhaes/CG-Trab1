#ifndef ZUMBI_H
#define ZUMBI_H
#include "bibliotecas.h"
#include "Constantes.h"
#include "score.h"
#include "municao.h"

class Zumbi:public Generic
{
public:
    int life;

    Zumbi();
    int collide(Object &other);
    void update();
    void insertCenario(Scenario &cenario);
    void disappear();
    void die(Object &other);
};

#endif // ZUMBI_H
