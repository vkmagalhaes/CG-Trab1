#include "kamehameha.h"

Kamehameha::Kamehameha()
{
    //ctor
}
//metodo que configura as particularidades da bala
void Kamehameha::setCaracteristicas(){
    int i;
    for(i=0;i<NUM_BALAS;i++){
        balas[i].scale(2.25);
        balas[i].body().gravityScale(0.05);
        balas[i].bala.color(0,0,255);
        balas[i].setVelocidade(VELOCIDADE_BALA_1);
        //balas[i].
        //balas[i].

    }
}
