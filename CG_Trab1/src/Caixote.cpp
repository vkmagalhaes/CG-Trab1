#include "caixote.h"

Caixote::Caixote()
{
    box();
    changeBoundingVolume(Solid::BOX);
    position(100,2,80);
    scale(3.0);
    loadTexture("media/tex/caixote_textura.png");
    loadNormalMap("media/tex/caixote_normal.png");
    texture().scale(1);
}

void Caixote::insertCenario(Scenario &cenario){

    cenario.insert(*this);
}
