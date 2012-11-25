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
}

int Zumbi::collide(Object &other)
{
    if (other.label() == LABEL_MUNICAO){ die( other );}
    return 1;
}

void Zumbi::insertCenario(Scenario &cenario){
    cenario.insert(*this);
}

void Zumbi::disappear(){
    visible(false);
    inactiveBody();
}

void Zumbi::die(Object &other){
    disappear();
    Municao* municao;
    municao = (Municao*)&other;
    if( (*municao).position().y() > 1.3){
        Score::addHeadShot();
    }
    else{
        Score::addKill();
    }
}
