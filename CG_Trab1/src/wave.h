#ifndef WAVE_H
#define WAVE_H
#include "bibliotecas.h"
#include "Constantes.h"
#include "Zumbi.h"
#include "Player.h"

class Wave
{
    public:
        Wave();
        void update(Player &player);
        Zumbi* getZumbis();
        Array setPos(Player &player);
        void insertCenario(Scenario &cenario);
    private:
        Zumbi zumbis[NUM_ZUMBIS];
        int i;
        int timer;
        int nivel;
};

#endif // WAVE_H
