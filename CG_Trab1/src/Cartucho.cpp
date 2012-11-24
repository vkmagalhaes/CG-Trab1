#include "cartucho.h"

Cartucho::Cartucho()
{
    proximaBala = 0;
}

Municao* Cartucho::getBalas(){
    return balas;
}

void Cartucho::update(Player &player){
    if ((Mouse::hit(Mouse::LEFT)|| Keyboard::hit(Keyboard::SPACE))&&(proximaBala < NUM_BALAS)){
        balas[proximaBala].disparar(player);
        proximaBala++;
    }

    if (Keyboard::hit(Keyboard::R)){
        recarregar();
    }

    Text::write(COLUNA_DISPLAY,LINHA1_DISPLAY,"%s %d","Balas: ",(NUM_BALAS - proximaBala));
}


void Cartucho::recarregar(){
    proximaBala = 0;
}

void Cartucho::insertCenario(Scenario &cenario){
    int i;
    for(i=0;i<NUM_BALAS;i++){
        balas[i].insertCenario(cenario);
    }
}

