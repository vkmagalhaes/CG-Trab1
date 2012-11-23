#ifndef ZUMBI_H
#define ZUMBI_H
#include "bibliotecas.h"
#include "Constantes.h"

class Zumbi:public Generic
{
public:
    int life;

    Zumbi();
    int collide(Object &other);
    void update();
    void insertCenario(Scenario &cenario);
};

#endif // ZUMBI_H
