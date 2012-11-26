#ifndef MACHINEGUN_H
#define MACHINEGUN_H


#include "bibliotecas.h"
#include "Constantes.h"
#include "cartucho.h"

class MachineGun: public Cartucho
{
    public:
        MachineGun();
        void setCaracteristicas();
    protected:
    private:
};

#endif // MACHINEGUN_H
