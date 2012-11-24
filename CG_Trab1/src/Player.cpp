#include "Player.h"

Player::Player()
{
    life = 100;
    lifebar.load("media/sprites/lifebar.bmp");
    lifebar.scale(1.0, 0.5);
    lifebar.position(10 + lifebar.width() / 2, 10 + lifebar.height() / 2);
    lifebar_empty.load("media/sprites/lifebar_empty.bmp");
    lifebar_empty.scale(1.0,0.5);
    lifebar_empty.position(10 + lifebar_empty.width()/2,10 + lifebar_empty.height()/2);
    activeBody();
    position(100,0,80);
    scale(1.4);
    changeKey("Forward", Input::Keyboard::UP);
    changeKey("Left", Input::Keyboard::LEFT);
    changeKey("Right", Input::Keyboard::RIGHT);
    changeKey("Back", Input::Keyboard::DOWN);

    label(LABEL_PLAYER);
    linearSpeed(2.0);
    //limita a visao do player a esse angulo
    humanView(70.0);
    mouseSensibility(0.6);

    lanterna.color(240,170,80);
    lanterna.intensity(5.0);
    lanterna.spot();
    lanterna.spotAngle(70);
    lanterna.attenuation(0.2);
    lanterna.quadraticAttenuation(0.05);
    lanterna.spotAttenuation(8);
    //sfx.load("media/sfx/choir.wav");
    //sfx.play();

}

int Player::collide(Object &other)
{
    if (other.label() == LABEL_ZUMBI)
    {
        if (life > 0)
        {
            life--;
            lifebar.scale(life/100.0,0.5);
            lifebar.position(10 + lifebar.width()/2,10 + lifebar.height()/2);

            if (life <= 0)
            {
                die();
            }
        }
    }
    return 1;
}

void Player::die(){
    control().disableAll();
    disableMouse();
    lanterna.intensity(0.0);
}

void Player::update(){
    lanterna.position() = position();
    lanterna.direction() = direction();
};
int Player::isDead()
{
    if (life<=0)
        return 1;
    return 0;
}

GuiSprite* Player::getLifeBar(){
    return &lifebar;
}
GuiSprite* Player::getLifeBarEmpty(){
    return &lifebar_empty;
}

void Player::insertCenario(Scenario &cenario){
    cenario.insert(*this);
    cenario.insert(lanterna);
}
