#ifndef PLAYER_H
#define PLAYER_H

#include "bibliotecas.h"
#include "Constantes.h"
#include <iostream>

class Player:public FirstPersonCamera
{
public:
    Player();
    void die();
    int collide(Object &other);
    int isDead();
    void update();
    GuiSprite* getLifeBar();
    GuiSprite* getLifeBarEmpty();
    void insertCenario(Scenario &cenario);
    void revive();
private:
    int life;
    Sound sfx;
    GuiSprite lifebar;
    GuiSprite lifebar_empty;
    Light lanterna;
    int lanternaLigada;
};


#endif // PLAYER_H
