#include "wave.h"

Wave::Wave()
{
    timer = 200;
    nivel = 1;
}

void Wave::update(Player &player){
    if (nivel<5) {timer--;}
    Text::write(400,20,"%d",timer);
    Text::write(400,40,"%d",nivel);
    if (timer <= 0 && nivel <=4){
        for(i=(nivel-1)*10;i<nivel*10;i++){
            zumbis[i].position(setPos(player));
            zumbis[i].activeBody();
            zumbis[i].visible(true);
        }
        nivel++;
        timer = 200;
    }
    for(i=0 ; i< (NUM_ZUMBIS-(NUM_ZUMBIS-nivel*10)) ; i++){
        if (zumbis[i].bodyBehavior() == Object::ACTIVE){
            if ((player.position() - zumbis[i].position()).length() < 3.0)
            {
                if (zumbis[i].graphic().getCurrentAnimation() != Animation::TAUNT02)
                {
                    //Força colisão repetida de ataque
                    Array tmp = (player.position() - zumbis[i].position()).normalize()*200.0;
                    tmp += Array(0,2000.0,0);
                    zumbis[i].body().force += tmp;
                    zumbis[i].tempAnimation(Animation::TAUNT02, Animation::WALK);
                }
            }
            else
            {
                zumbis[i].body().force += (player.position() - zumbis[i].position()).normalize()* VELOCIDADE_ZUMBI;
                zumbis[i].direction(zumbis[i].body().force);
            }
        }
    }
}

Zumbi* Wave::getZumbis(){
    return zumbis;
}

Array Wave::setPos(Player &player){
    Array pos;
    float rand,x,y,z;
    do{
        rand = random()*255;
        x = rand - (255/2);
        rand = random()*255;
        z = rand - (255/2);
        y = 20;
        pos.set(x,y,z);
        if ( player.position().dist(pos) > 30.0){
        return pos;
        }
    }while(true);
}

void Wave::insertCenario(Scenario &cenario){
    int i;
    for(i=0;i<NUM_ZUMBIS;i++){
        zumbis[i].insertCenario(cenario);
    }
}

void Wave::gameOver(){
    for(i=0 ; i< NUM_ZUMBIS ; i++){
        zumbis[i].disappear();
    }
}
