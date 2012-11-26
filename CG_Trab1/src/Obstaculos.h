#ifndef OBSTACULOS_H
#define OBSTACULOS_H
#include "bibliotecas.h"
#include "Constantes.h"
#include "caixote.h"
#include "arvore.h"

class Obstaculos
{
    public:
        Obstaculos();
        void insertCenario(Scenario &cenario);

    private:
        Arvore arvores[NUM_ARVORES];
        Caixote caixote1;
        Caixote caixote2;
};

#endif // OBSTACULOS_H
