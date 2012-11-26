#include "arvore.h"

Arvore::Arvore()
{
    load("media/models/Trees/trunk.md2");
    staticBody();
    scale(2.0);
    //position(83,2,80.3);

    folhas1.load("media/models/plant/plant2.md2");
    folhas1.staticBody();
    folhas1.scale(2.0);
    folhas1.direction(-0.5,-0.5,-1);


    folhas2.load("media/models/plant/plant2.md2");
    folhas2.staticBody();
    folhas2.scale(2.0);
    folhas2.direction(0,0.5,1);


}

void Arvore::insertCenario(Scenario &cenario){


    //folhas2.position(position.getx()-0.7,4.3,position.getz()-0.3);

    cenario.insert(*this);
    cenario.insert(folhas1);
    cenario.insert(folhas2);
}

void Arvore::setPosition(){
    float x, z;
    Array diff;
    float maxDistance = 250.0;
    x = random() * maxDistance;
    z = random() * maxDistance;
    position(x,2,  z);

    Array pos = position();
    pos.add(0.7,2.3,-0.3);
    folhas1.position(pos);
    pos.add(-1.4,0,0);
    folhas2.position(pos);
}
