#include "obstaculos.h"

Obstaculos::Obstaculos()
{

    objeto.load("media/models/eagle/eagle.md2");
    objeto.staticBody();
    objeto.position(80,1,80);

    objeto2.load("media/models/plant/plant2.md2");
    objeto2.staticBody();
    objeto2.scale(2.0);
    objeto2.graphic().rotate(30,0,0,1);
    //objeto2.direction(0,0,1);
    objeto2.position(86,1,81);

    objeto4.load("media/models/plant/plant2.md2");
    objeto4.staticBody();
    objeto4.scale(2.0);
    objeto4.graphic().rotate(60,0,0,1);
    //objeto4.direction(0,0,1);
    objeto4.position(84,1,79);

    objeto5.load("media/models/plant/plant2.md2");
    objeto5.staticBody();
    objeto5.scale(2.0);
    objeto5.direction(0,0,1);
    objeto5.position(85,1,80);

    objeto6.load("media/models/arbusto/fern.md2");
    objeto6.staticBody();
    objeto6.enableLighting();
    objeto6.shininess(50.0);
    objeto6.reflectivity(1.0);
    //objeto6.scale(2.0);
    objeto6.position(85,0.5,70);

    objeto3.load("media/models/jeep/jeep.obj");
    objeto3.staticBody();
    objeto3.position(80,1,90);

    objeto7.load("media/models/Trees/trunk.md2");
    objeto7.staticBody();
    objeto7.scale(4.0);
    objeto7.position(85,4,80);

}

void Obstaculos::insertCenario(Scenario &cenario){
    cenario.insert(objeto);
    cenario.insert(objeto2);
    cenario.insert(objeto3);
    cenario.insert(objeto4);
    cenario.insert(objeto5);
    cenario.insert(objeto6);
    //cenario.insert(objeto7);
}
