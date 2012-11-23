#ifndef CARTUCHO_H
#define CARTUCHO_H

#include "bibliotecas.h"
#include "Constantes.h"
#include "Player.h"
#include "municao.h"

class Cartucho
{
    public:
        Cartucho();
        void update(Player &player);
        Municao* getBalas();
        void recarregar();
        void insertCenario(Scenario &cenario);
    private:
        Municao balas[NUM_BALAS];
        int proximaBala;
};

#endif // CARTUCHO_H
