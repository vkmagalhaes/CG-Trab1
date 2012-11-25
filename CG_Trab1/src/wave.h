#ifndef WAVE_H
#define WAVE_H
#include "bibliotecas.h"
#include "Constantes.h"
#include "Zumbi.h"
#include "SpawnPoint.h"
#include "Player.h"

using namespace std;

// estrutura que representará quando um zumbi tem que nascer
// o enterTime indica em que momento o zumbi deve nascer
// e o zombieType representa qual o tipo de zombie vai nascer
struct enterToken {
    time_t enterTime;
    int zombieType;
};

// TODOOOO: para finalizar a wave, falta colocar um zumbi como inativo ao ele ser morto
class Wave
{
    public:
        Wave();
        void update(Player &player); // atualiza a wave, as posicoes dos zumbis, ...
        void turnOn(); // liga a wave, e faz aumentar o nivel
        void turnOff(); // desliga para um suspiro
        void insertZombies(Scenario &cenario); // insere os zumbis no cenario
        void activateZombie(); // faz nascer um zumbi
        void gameOver(); // remove os zumbis da tela
    private:
        Zumbi zombies[NUM_ZUMBIS]; // array de zumbis
        list<int> inactiveZombiesIndexes; // lista com os indices dos zumbis que estão inativos
        list<int> activeZombiesIndexes; // lista com os indices dos zumbis que estão ativos
        list<int>::iterator intIt; // iterator das listas de indices
        SpawnPoint spawnPoints[NUM_SPAWN_POINTS]; // array com os spawn points
        time_t start; // variavel que guarda o inicio do status da wave
        list<enterToken> enterTokens; // lista com os tokens ordenados pela ordem de entrada
        list<enterToken>::iterator tokensIt; // iterator dos tokens
        int i; // variavel usada nos loops
        int nivel; // int indicando em qual nivel encontra-se a wave
        int status; // guarda o status da wave, se ela está em andamento, ou se esta em pausa para o suspiro
        int spawnPointIndex; // indica qual a proxima spawnpoint que ira nascer um zumbi
        double remainingSeconds; // variavel para armazenar os segundos restastes para a wave mudar de status
};

#endif // WAVE_H
