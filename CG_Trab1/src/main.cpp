#include "bibliotecas.h"
#include <iostream>
#include "Constantes.h"
#include "Zumbi.h"
#include "municao.h"
#include "Player.h"
#include "wave.h"
#include "cartucho.h"

URGE_BEGIN
{
    gimme_window(LARGURA_TELA,ALTURA_TELA, RENDER_QUALITY_PERFECT, WINDOWED | NO_SHADER, "URGE TEST");

    //DECLARAÇÕES
    int gameOver = 0;
    Player player;
    Scenario cenario;
    Wave wave;
    Sky sky;
    Light light;
    Terrain terrain;
    Texture texturaDoTerreno;
    Cartucho cartucho;

    //CARREGANDO COISAS
    terrain.load("media/terrain/heightmap6.jpg",0, 50, 255,255,"media/tex/dirt.jpg");
    terrain.specular(0.3);
    terrain.ambient(0.4);
    terrain.texture().scale(30);

    light.directional();
    light.color(240,170,80);
    light.intensity(0.2);
    light.direction(0,100,0);

    if (sky.loadTexture("media/sky/cloudy") != TEXTURE_LOAD_SUCCESS)
	{
		printf("oh dear...\n");
        thanks_byebye();
		return 1;
	}

    // inserindo os objetos no cenario
    cenario.insert(sky);
    wave.insertCenario(cenario);
    cenario.insert(terrain);
    cenario.insert(light);
    cartucho.insertCenario(cenario);
    player.insertCenario(cenario);
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
