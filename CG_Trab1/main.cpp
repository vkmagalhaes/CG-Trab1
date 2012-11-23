#include<URGE/URGE.h>
#include "Municao.h"
#include <iostream>

USING_URGE;

#define LABEL_PLAYER    1
#define LABEL_MUNICAO   2
#define LABEL_ENEMY     3
#define NUM_BALAS       3
#define NUM_ZUMBIS      10

class Player:public FirstPersonCamera
{
public:
    int life;
    GuiSprite lifebar;
    GuiSprite lifebar_empty;
    Text texto;
    Sound sfx;

    Player(void)
    {
        life = 100;
        label(LABEL_PLAYER);
        linearSpeed(3.0);
        lifebar.load("media/sprites/lifebar.bmp");
        lifebar.scale(1.0,0.5);
        lifebar.position(10 + lifebar.width()/2,10 + lifebar.height()/2);

        lifebar_empty.load("media/sprites/lifebar_empty.bmp");
        lifebar_empty.scale(1.0,0.5);
        lifebar_empty.position(10 + lifebar_empty.width()/2,10 + lifebar_empty.height()/2);

        sfx.load("media/sfx/choir.wav");
        sfx.play();

    }

    int collide(Object &other)
    {
        if (other.label() == LABEL_ENEMY)
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
};


class Enemy:public Generic
{
public:
    int life;

    Enemy(void)
    {
        life = 100;
        label(LABEL_ENEMY);
        load("media/models/Knight/knight.md2");
        changeAnimation(Animation::WALK);
        graphic().setAnimationDelay(Animation::WALK,6);
        graphic().setAnimationDelay(Animation::TAUNT02,2);
        graphic().setAnimationDelay(Animation::HIT01,6);
        graphic().setAnimationDelay(Animation::DIE01,6);
        changeBoundingVolume(Solid::OBOX);
        animatedVolume();
        //scale(0.5);
        position(0.0,20.0,0);
    }

    int collide(Object &other)
    {
        if (other.label() == LABEL_MUNICAO)
        {
            if (life > 0)
            {
                life -= 100;
                tempAnimation(Animation::HIT02, Animation::WALK);
            }
            else
            {
                //tempAnimation(Animation::DIE01,Animation::NONE);
                visible(false);
                inactiveBody();
            }
        }
        return 1;
    }

};


URGE_BEGIN
{
    gimme_window(800,600, RENDER_QUALITY_PERFECT, DEFERRED_SHADING | WINDOWED | SHADER_LOG, "URGE TEST");

    Player player;
    Scenario scenario;
    Enemy zumbi[NUM_ZUMBIS];
    int i;
    Sky sky;
    Light light;
    Terrain terrain;
    Texture texturaDoTerreno;

    Municao municao;

   /* Ocean ocean;
    ocean.loadNormalMap("media/water/wave_n.png");
    ocean.loadTexture("media/water/water.jpg");
    ocean.position(0,10,0);
    ocean.color(5,60,120);
    ocean.transparency(0.5);
    ocean.scale(500);
    ocean.graphic().material().ambient(0.6);
    ocean.graphic().material().specular(2.0);
    ocean.waveSize(3.37);
    ocean.waveSpeed(1.0);
    scenario.insert(ocean);
     */

    player.activeBody();
    player.position(20,20,0);
    player.scale(1.7);
    player.changeKey("Forward", Input::Keyboard::UP);
    player.changeKey("Left", Input::Keyboard::LEFT);
    player.changeKey("Right", Input::Keyboard::RIGHT);
    player.changeKey("Back", Input::Keyboard::DOWN);

    terrain.load("media/terrain/heightmap6.jpg",0, 50, 255,255,"media/tex/dirt.jpg");
    /*if (texturaDoTerreno.loadTextur("media/tex/terrain.jpg" != TEXTURE_LOAD_SUCCESS);
	{
		printf("oh dear...\n");
        thanks_byebye();
		return 1;
	}
    terrain.load("media/terrain/heightmap3.jpg",1, 10, 255,255,texturaDoTerreno);
    */
    terrain.specular(0.3);
    terrain.ambient(0.4);
    terrain.texture().scale(30);

    light.directional();
    light.color(240,170,80);
    light.intensity(0.7);
    light.direction(-1,1,-1);


    if (sky.loadTexture("media/sky/cloudy") != TEXTURE_LOAD_SUCCESS)
	{
		printf("oh dear...\n");
        thanks_byebye();
		return 1;
	}


    // inserindo os objetos no cenario
    scenario.insert(player);
    scenario.insert(sky);
    for(i=0 ; i < NUM_ZUMBIS ; i++){
        scenario.insert(zumbi[i]);
        zumbi[i].position(i*20,20,i*20);
    }

    //scenario.insert(enemy2);
    scenario.insert(terrain);
    scenario.insert(light);
    scenario.insert(municao);
    scenario.insert(municao.p);
    scenario.insert(municao.light);
    scenario.insert(municao.spark);

    scenario.glowNullNormalSurfacesRatio(0.6);

    scenario.prepare();

    Display disp;

    disp.insert(player.lifebar_empty);
    disp.insert(player.lifebar);
    //disp.insert(player.texto);

    do
    {
        if (Keyboard::hit(Keyboard::ESC)) break;

        for(i=0 ; i< NUM_ZUMBIS ; i++){
            if (zumbi[i].bodyBehavior() == Object::ACTIVE){
                if ((player.position() - zumbi[i].position()).length() < 5.0)
                {
                    if (zumbi[i].graphic().getCurrentAnimation() != Animation::TAUNT02)
                    {
                        Array tmp = (player.position() - zumbi[i].position()).normalize()*400.0;
                        tmp += Array(0,2000,0);
                        zumbi[i].body().force += tmp;
                        zumbi[i].tempAnimation(Animation::TAUNT02, Animation::WALK);
                    }
                }
                else
                {
                    zumbi[i].body().force += (player.position() - zumbi[i].position()).normalize()*45.0;
                    zumbi[i].direction(zumbi[i].body().force);
                }
            }
        }
        if (Keyboard::hit(Keyboard::SPACE))
        {
            municao.appear();
            municao.position() = player.position();
            municao.velocity() = player.direction()*180.0;
        }

        scenario.update();
        disp.update();


        next_frame();

    }while(true);

    thanks_byebye();
}
URGE_END
