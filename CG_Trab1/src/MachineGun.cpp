#include "machineGun.h"

MachineGun::MachineGun()
{
    //ctor
}

void MachineGun::setCaracteristicas(){
    int i;
    for(i=0;i<NUM_BALAS;i++){
        //balas[i].
        balas[i].scale(0.6);
        balas[i].body().gravityScale(0.05);
        balas[i].bala.color(0,0,255);
        balas[i].setVelocidade(VELOCIDADE_BALA_2);
    }
}
