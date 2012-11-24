#include "obstaculos.h"

Obstaculos::Obstaculos()
{

    objeto.load("media/models/eagle/eagle.md2");
    objeto.staticBody();
    objeto.position(80,1,80);

    objeto2.load("media/models/Trees/leaves.md2");
    objeto2.staticBody();
    //objeto2.scale(2.0);
    objeto2.position(85,3,80);
    //objeto2.loadTexture("media/models/door/door.png");

}

void Obstaculos::insertCenario(Scenario &cenario){
    cenario.insert(objeto);
    cenario.insert(objeto2);
}
