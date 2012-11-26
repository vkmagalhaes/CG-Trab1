#include "bibliotecas.h"
#include <iostream>
#include "Constantes.h"
#include "Zumbi.h"
#include "municao.h"
#include "Player.h"
#include "wave.h"
#include "cartucho.h"
#include "score.h"
#include "obstaculos.h"

URGE_BEGIN
{
    gimme_window(LARGURA_TELA,ALTURA_TELA, RENDER_QUALITY_PERFECT, DEFERRED_SHADING | WINDOWED | SHADER_LOG, "URGE TEST");

    //DECLARAÇÕES
    int gameOver = 0;
    Player player;
    Scenario cenario;
    Sky sky;
    Light light;
    Terrain terrain;
    Cartucho cartucho;
    Score score;
    //Wave wave(cenario);
    Wave wave;

    //FrameRateMonitor frameMonitor;

    Obstaculos obstaculos;

    //CARREGANDO COISAS
    terrain.load("media/terrain/heightmap7Fechado.jpg",0, 100,LARGURA_TERRENO,COMPRIMENTO_TERRENO,"media/tex/grass.jpg");
    terrain.specular(0.3);
    terrain.ambient(0.4);
    terrain.texture().scale(50);

    light.directional();
    light.color(240,170,80);
    light.intensity(1.6);
    light.direction(20,50,0);

    if (sky.loadTexture("media/sky/cloudy") != TEXTURE_LOAD_SUCCESS)
	{
		printf("oh dear...\n");
        thanks_byebye();
		return 1;
	}

    // inserindo os objetos no cenario
    cenario.insert(sky);
    cenario.insert(terrain);
    cenario.insert(light);
    cartucho.insertCenario(cenario);
    player.insertCenario(cenario);
    obstaculos.insertCenario(cenario);
    wave.insertZombies(cenario);

    cenario.glowNullNormalSurfacesRatio(0.6);
    cenario.prepare();
    Display disp;
    disp.insert(*player.getLifeBarEmpty() );
    disp.insert(*player.getLifeBar() );

    //LOOP DO JOGO
    do
    {
        if (Keyboard::hit(Keyboard::ESC)) break;

        if (gameOver){
            Text::write((LARGURA_TELA/2)-20,(ALTURA_TELA/2)-5,"%s","GAME OVER");
        }else{
            Text::write((LARGURA_TELA/2)-3,(ALTURA_TELA/2)-5,"%s","+");

            player.update();
            wave.update(player);
            cartucho.update(player);
            if (Keyboard::hit(Keyboard::J)) wave.activateZombie();
            if (Keyboard::hit(Keyboard::M)) wave.turnOn();
            score.update();
            if ( player.isDead() ){
                gameOver = 1;
                wave.gameOver();
            }
        }
        cenario.update();
        disp.update();
        next_frame();

    }while(true);

    thanks_byebye();
}
URGE_END
