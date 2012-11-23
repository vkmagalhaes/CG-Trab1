#include "municao.h"

Municao::Municao()
{
    sphere();
    changeBoundingVolume(Solid::SPHERE);
    label(LABEL_MUNICAO);
    scale(1.0);
    //body().gravityScale(0.001);
    body().damping(0.0);

    light.color(255,180,60);
    light.intensity(5.0);
    light.attenuation(0.4);
    light.quadraticAttenuation(0.01);

    disappear();

    bala.generate(Particle::GLOW);
    bala.setAnimationType(Particle::FIRE);
    bala.color(130,70,20);
    bala.scale(1.25);

    spark.load("media/sprites/spark.tga");
    spark.setAnimationType(Particle::FOG);
    spark.color(200,100,40);
    spark.scale(1.0);
    spark.animationMotionOffset(3.5);
    spark.stop();
}

void Municao::act()
{
    bala.position() = position();
    light.position() = position();

    if (bala.isEmitting())
    {
        timer--;
        light.intensity(float(timer)*0.0715);
        if (timer <= 0)    disappear();
    }
}

int Municao::collide(Object &other)
{
    //if (other.label() == LABEL_ZUMBI)
    //{
        spark.start(10);
        spark.position() = position();
        disappear();
    //}
    return 1;
}

void Municao::disparar(Player &player)
{
    timer = 40;
    light.intensity(float(timer)*0.0715);
    bala.start();
    activeBody();
    position() = player.position();
    velocity() = player.direction()* VELOCIDADE_BALA;
}

void Municao::disappear()
{
    light.intensity(0.0);
    timer = 0;
    visible(false);
    inactiveBody();
    bala.stop();
}

void Municao::insertCenario(Scenario &cenario){

    cenario.insert(*this);
    cenario.insert(spark);
    cenario.insert(light);
    cenario.insert(bala);
}

