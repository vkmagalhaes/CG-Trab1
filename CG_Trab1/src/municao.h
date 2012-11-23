#ifndef MUNICAO_H
#define MUNICAO_H

#include "bibliotecas.h"
#include "Constantes.h"
#include "Player.h"


class Municao : public Generic
{
    public:
        ParticleEmitter bala;
        ParticleEmitter spark;
        int timer;
        Light light;

        Municao();
        void act();
        int collide(Object &other);
        void disparar(Player &player);
        void disappear();
        void insertCenario(Scenario &cenario);
};

#endif // MUNICAO_H
