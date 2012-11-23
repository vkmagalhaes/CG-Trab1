#include "Zumbi.h"

Zumbi::Zumbi(){
    life = 100;
    label(LABEL_ZUMBI);
    load("media/models/Knight/knight.md2");
    changeAnimation(Animation::WALK);
    graphic().setAnimationDelay(Animation::WALK,8);
    graphic().setAnimationDelay(Animation::TAUNT02,3);
    graphic().setAnimationDelay(Animation::HIT01,6);
    graphic().setAnimationDelay(Animation::DIE01,6);
    changeBoundingVolume(Solid::OBOX);
    animatedVolume();
    inactiveBody();
    visible(false);
    //scale(0.5);
    position(0.0,20.0,0.0);
}

int Zumbi::collide(Object &other)
{
    if (other.label() == LABEL_MUNICAO)
    {
        visible(false);
        inactiveBody();
    }
    return 1;
}

void Zumbi::insertCenario(Scenario &cenario){
    cenario.insert(*this);
}
