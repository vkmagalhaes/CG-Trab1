#ifndef CARTUCHO_H
#define CARTUCHO_H

#include "bibliotecas.h"
#include "Constantes.h"
#include "Player.h"
#include "municao.h"
#include "score.h"

class Cartucho
{
    public:
        Cartucho();
        void update(Player &player);
        void disparar(Player &player);
        void startCharge();
        Municao* getBalas();
        void finishCharge();
        void insertCenario(Scenario &cenario);
        virtual void setCaracteristicas();
        Municao balas[NUM_BALAS];
    private:

        int proximaBala;
        time_t chargeStart;
        int status;
};

#endif // CARTUCHO_H
