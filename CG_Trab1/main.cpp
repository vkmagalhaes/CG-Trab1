#include <URGE/URGE.h>
#include <iostream>

#include "Fireball2.h"


USING_URGE;

class Player :public FirstPersonCamera
{
public:
    GuiSprite lifebar;
    Sound sfx;

    Player(void) : FirstPersonCamera()
    {
        linearSpeed(3.0);

        lifebar.load("media/sprites/lifebar.bmp");
        lifebar.scale(1.0, 0.5);
        lifebar.position(10 + lifebar.width() / 2, 10 + lifebar.height() / 2);

        sfx.load("media/sfx/choir.wav");
        sfx.play();

        activeBody();
        position(0,20,0);
        scale(1.7);
    }

    int collide(Object& other)
    {
        // DO SOMETHING AT COLLISION!
        // ...
        return true;
    }

    void act(void)
    {
        // DO SOMETHING EVERY FRAME!
        // ...
    }
};

class FireBall : public Generic
{
public:
    ParticleEmitter particle;
    ParticleEmitter spark;
    Light light;

    FireBall(void)
    {
        sphere();
        changeBoundingVolume(Solid::SPHERE);
        scale(2.0);
        staticBody();

        light.color(255,180,60);
        light.intensity(5.0);
        light.attenuation(0.4);
        light.quadraticAttenuation(0.01);

        particle.generate(Particle::GLOW);
        particle.setAnimationType(Particle::FIRE);
        particle.color(130,70,20);
        particle.scale(3.25);

        spark.load("media/sprites/spark.tga");
        spark.setAnimationType(Particle::FOG);
        spark.color(200,100,40);
        spark.scale(3.5);
        spark.animationMotionOffset(3.5);
    }

    void act(void)
    {
        particle.position() = position();
        spark.position() = position();
        light.position() = position();
    }
};

URGE_BEGIN
{
    //new window:RX, RY, RENDER QUALITY LEVEL, PARAMS,  WINDOW TITTLE,
    gimme_window(800, 600, RENDER_QUALITY_PERFECT, WINDOWED, "URGE - Teste Complementar");

    Scenario scenario;
    Display display;

    // Setup
    Player player;
    FireBall fireball;
    Fireball2 fire2;

    Sky sky;
    Light light;
    Terrain terrain;
    // Ocean ocean;

    // Init
    fireball.position() = player.position() - Array(0.0, 0.0, 20.0);

    sky.loadTexture("media/sky/cloudy");

    light.directional();
    light.color(240,170,80);
    light.intensity(0.7);
    light.direction(-1,1,-1);

    terrain.load("media/terrain/heightmap2.jpg",1, 20, 255,255,"media/tex/dirt.jpg");
    terrain.specular(0.3);
    terrain.ambient(0.4);
    terrain.texture().scale(30);

    /* ocean.loadNormalMap("media/water/wave_n.png");
    ocean.loadTexture("media/water/water.jpg");
    ocean.position(0,14,0);
    ocean.color(5,60,120);
    ocean.transparency(0.5);
    ocean.scale(500);
    ocean.graphic().material().ambient(0.6);
    ocean.graphic().material().specular(2.0);
    ocean.waveSize(0.37);
    ocean.waveSpeed(1.0); */

    // Insert
    scenario.insert(player);
    display.insert(player.lifebar);

    scenario.insert(fireball);
    scenario.insert(fireball.light);
    scenario.insert(fireball.particle);
    scenario.insert(fireball.spark);

    scenario.insert(fire2);

    scenario.insert(sky);
    scenario.insert(terrain);
    scenario.insert(light);
    // scenario.insert(ocean);

    scenario.glowNullNormalSurfacesRatio(0.6);

    scenario.prepare();

    do
    {
        if (Keyboard::hit(Keyboard::ESC))  break;

        scenario.update();
        display.update();

        next_frame();
    } while(true);

    thanks_byebye();
}
URGE_END
