#include "machineGun.h"

MachineGun::MachineGun()
{
    //ctor
}

void MachineGun::setCaracteristicas(){
    int i;
    for(i=0;i<NUM_BALAS;i++){
        balas[i].scale(2.0);
        balas[i].body().gravityScale(0.0);
        balas[i].bala.color(130,70,20);
        balas[i].setVelocidade(VELOCIDADE_BALA_2);
        //balas[i].

    }
}
