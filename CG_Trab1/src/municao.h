#ifndef MUNICAO_H
#define MUNICAO_H

#include "bibliotecas.h"
#include "Constantes.h"
#include "Player.h"
#include "score.h"


class Municao : public Generic
{
    public:
        ParticleEmitter bala;
        ParticleEmitter spark;
        int timer;
        Light light;
        void setVelocidade(float speed);
        Municao();
        void act();
        int collide(Object &other);
        void disparar(Player &player);
        void disappear();
        void insertCenario(Scenario &cenario);
    private:
        float velocidade;
};

#endif // MUNICAO_H
