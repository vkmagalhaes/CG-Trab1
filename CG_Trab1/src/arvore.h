#ifndef ARVORE_H
#define ARVORE_H
#include "bibliotecas.h"
#include "Constantes.h"


class Arvore:public Generic
{
    public:
        Arvore();
        void insertCenario(Scenario &cenario);
        void setPosition();
    protected:
    private:
        Generic folhas1;
        Generic folhas2;
};

#endif // ARVORE_H
