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
    scale(1.0);
    changeKey("Forward", Input::Keyboard::UP);
    changeKey("Left", Input::Keyboard::LEFT);
    changeKey("Right", Input::Keyboard::RIGHT);
    changeKey("Back", Input::Keyboard::DOWN);

    label(LABEL_PLAYER);
    linearSpeed(2.0);

    sfx.load("media/sfx/choir.wav");
    sfx.play();

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
                control().disableAll();
                disableMouse();
            }
        }
    }
    return 1;
}

void Player::die(){
    control().disableAll();
    disableMouse();
}

void Player::update(){

};
int Player::isDead()
{
    if (life<=0)
        return 1;
    return 0;
}

