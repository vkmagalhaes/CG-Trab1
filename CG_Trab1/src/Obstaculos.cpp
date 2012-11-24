#include "obstaculos.h"

Obstaculos::Obstaculos()
{

    objeto.load("media/models/eagle/eagle.md2");
    objeto.staticBody();
    objeto.position(80,1,80);

    objeto2.load("media/models/plant/plant2.md2");
    objeto2.staticBody();
    objeto2.scale(2.0);
    objeto2.position(85,0.5,80);

    objeto4.load("media/models/plant/plant2.md2");
    objeto4.staticBody();
    objeto4.scale(2.0);
    objeto4.direction(1,1,1);
    objeto4.position(85,0.5,82);

    objeto5.load("media/models/plant/plant2.md2");
    objeto5.staticBody();
    objeto5.scale(2.0);
    objeto5.direction(1,1,0);
    objeto5.position(85,0.5,78);

    objeto6.load("media/models/arbusto/fern.md2");
    objeto6.staticBody();
    objeto6.enableLighting();
    objeto6.shininess(50.0);
    //objeto6.reflectivity(1.0);
    //objeto6.scale(2.0);
    objeto6.position(85,0.5,70);

    objeto3.load("media/models/jeep/jeep.obj");
    objeto3.staticBody();
    objeto3.position(80,1,90);

    objeto7.load("media/models/vegetation/grass/grass.c4d");
    objeto7.staticBody();
    objeto7.position(80,1,100);

}

void Obstaculos::insertCenario(Scenario &cenario){
    cenario.insert(objeto);
    cenario.insert(objeto2);
    cenario.insert(objeto3);
    cenario.insert(objeto4);
    cenario.insert(objeto5);
    cenario.insert(objeto6);
    cenario.insert(objeto7);
}
