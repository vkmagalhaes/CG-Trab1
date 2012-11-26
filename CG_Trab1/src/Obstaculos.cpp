#include "obstaculos.h"

Obstaculos::Obstaculos()
{

}

void Obstaculos::insertCenario(Scenario &cenario){
    int i;

    for(i=0;i<NUM_ARVORES;i++){
        arvores[i].insertCenario(cenario);
        arvores[i].setPosition();
    }
    caixote1.insertCenario(cenario);
    caixote2.insertCenario(cenario);
    caixote1.scale(3.0);
    caixote2.scale(2.0);
    Array pos = caixote1.position();
    pos.add(2,-1,0);
    caixote2.position(pos);

}
