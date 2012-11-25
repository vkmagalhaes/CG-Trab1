#include "cartucho.h"

Cartucho::Cartucho()
{
    proximaBala = 0;
    status = CARTUCHO_PRONTO;
}

Municao* Cartucho::getBalas(){
    return balas;
}

void Cartucho::update(Player &player){
    if (status == CARTUCHO_PRONTO) {
        if ((Mouse::hit(Mouse::LEFT)|| Keyboard::hit(Keyboard::SPACE))&&(proximaBala < NUM_BALAS)){
            disparar(player);
        }

        if (Keyboard::hit(Keyboard::R)){
            startCharge();
        }

        Text::write(COLUNA_DISPLAY,LINHA1_DISPLAY,"%s %d","Balas: ",(NUM_BALAS - proximaBala));
    } else {
        Text::write(COLUNA_DISPLAY,LINHA1_DISPLAY,"Carregando...");

        if (difftime(time(NULL), chargeStart) >= CHARGING_TIME) recarregar();
    }
}

void Cartucho::disparar(Player &player) {
    balas[proximaBala].disparar(player);
    proximaBala++;

    if (proximaBala >= NUM_BALAS) startCharge();
}

void Cartucho::startCharge() {
    status = CARTUCHO_CARREGANDO;
    chargeStart = time(NULL);
}

void Cartucho::recarregar(){
    status = CARTUCHO_PRONTO;
    proximaBala = 0;
}

void Cartucho::insertCenario(Scenario &cenario){
    int i;
    for(i=0;i<NUM_BALAS;i++){
        balas[i].insertCenario(cenario);
    }
}

