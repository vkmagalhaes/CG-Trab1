#include "wave.h"

//Wave::Wave(Scenario &cenario) : scenario(cenario)
Wave::Wave()
{
    nivel = 0;
    start = time(NULL); // Inicio do cronometro
    status = WAVE_OFF; // Wave Inicia com o Suspiro
    remainingSeconds = 0; // Segundos restantes para o inicio da Wave

    // Inicializa as posições das Waves
    spawnPoints[0].setPosition(200, 0, 20);
    spawnPoints[1].setPosition(150, 0, 20);
    spawnPoints[2].setPosition(50, 0, 20);
    // index que indica o próximo spawn de onde vai nascer um zumbi
    spawnPointIndex = 0;
}

//void Wave::update() {
void Wave::update(Player &player) {
    if (status == WAVE_OFF) {
        // calcula quantos segundos restam para a Wave trocar de status
        remainingSeconds = WAVE_INTERVAL - difftime( time(NULL), start );
        //arredonda os segundos
        remainingSeconds = ceil(remainingSeconds);

        // se for o nivel 0 muda a label
        if (nivel)
            Text::write(400,20,"Proxima Wave em %.0f", remainingSeconds);
        else
            Text::write(400,20,"Primeira Wave em %.0f", remainingSeconds);

        // muda o status da Wave se ja estiver chegado o tempo
        if ( remainingSeconds <= 0 ) turnOn();
    } else {
        // calcula quantos segundos restam para a Wave trocar de status
        remainingSeconds = WAVE_DURATION - difftime( time(NULL), start );
        remainingSeconds = ceil(remainingSeconds);

        Text::write(400,20,"Wave: %d", nivel);

        // muda o status da Wave se ja estiver chegado o tempo
        if ( remainingSeconds <= 0 ) turnOff();
    }

    tokensIt = enterTokens.begin();
    while(!enterTokens.empty()) {
        // como a lista está ordenada, se achou um token pra inserir
        // um zumbi, entao insere e deixa o loop prosseguir para ver se não
        // tem mais nenhum zumbi para inserir
        if ( difftime( time(NULL), (*tokensIt).enterTime) >= 0 ) {
            activateZombie();
            tokensIt = enterTokens.erase(tokensIt);
        } else {
            break;
        }
    }

    //Text::write(20,40,"Zumbis Ativos: %d", activeZombiesIndexes.size());
    //Text::write(20,60,"Zumbis Inativos: %d", inactiveZombiesIndexes.size());

    // loop para atualizar as posicoes dos zumbis ativos
    // e fazerem eles irem emdirecao ao player
    intIt = activeZombiesIndexes.begin();
    while(intIt != activeZombiesIndexes.end()){
        i = *intIt;
        if (zombies[i].bodyBehavior() == Object::ACTIVE) {
            if ((player.position() - zombies[i].position()).length() < 5.0) {
                if (zombies[i].graphic().getCurrentAnimation() != Animation::TAUNT02)
                {
                    //Forca colisao repetida de ataque
                    Array tmp = (player.position() - zombies[i].position()).normalize()*200.0;
                    tmp += Array(0,2000.0,0);
                    zombies[i].body().force += tmp;
                    zombies[i].tempAnimation(Animation::TAUNT02, Animation::WALK);
                }
            } else {
                zombies[i].body().force += (player.position() - zombies[i].position()).normalize()* VELOCIDADE_ZUMBI;
                zombies[i].direction(zombies[i].body().force);
            }
            intIt++;
        } else {
            // se o zumbi está inativo é pq ele foi morto
            // logo tira ele dos zumbis ativos e coloca como inativo
            inactiveZombiesIndexes.push_back(i);
            intIt = activeZombiesIndexes.erase(intIt);
        }
    }
}

// funcao para ordenar a lista de tokens
bool compare(enterToken first, enterToken second) {
    // se o tempo de entrar do primeiro for menor do que o do segundo
    // então siginifica que ele tem que entrar antes, logo ele tem que
    // estar nas primeiras posições da lista
    if ( difftime( second.enterTime, first.enterTime ) >= 0 ) return true;
    return false;
}

void Wave::turnOn() {
    int numZombies;

    status = WAVE_ON; // ativa a wave
    nivel++; // aumenta o nivel
    start = time(NULL); // atualiza o inicio do status wave
    remainingSeconds = 0.0; // zera o contador

    numZombies = 10 + 5 * nivel; // define quantos zumbis devem ser criados nesta wave

    // cria os tokens
    for(i=0; i < numZombies; i++) {
        enterToken newToken;
        newToken.enterTime = start + random() * WAVE_DURATION;
        newToken.zombieType = ZOMBIE_1;

        enterTokens.push_front(newToken);
    }
    // ordena a lista de tokens com a funcao compare
    enterTokens.sort(compare);
}

void Wave::turnOff() {
    status = WAVE_OFF;
    start = time(NULL);
    remainingSeconds = 0.0;
}

void Wave::insertZombies(Scenario &scenario) {
    // insere os zumbis no cenario e iniciliza a lista
    // de zumbis inativos com todos os zumbis
    // pois todos entram inativos
    for(i=0; i < NUM_ZUMBIS; i++) {
        inactiveZombiesIndexes.push_back(i);
        zombies[i].insertCenario(scenario);
    }
}

void Wave::activateZombie() {
    // se nao tem zumbi disponivel, ignora a chamada. MELHORAAAAR!
    if (inactiveZombiesIndexes.empty()) return;

    i = inactiveZombiesIndexes.front(); // pega o indice de um zumbi inativo

    // coloca ele na posicao de uma spawn
    spawnPoints[spawnPointIndex].insertZombie(zombies[i]);
    spawnPointIndex = (spawnPointIndex + 1) % NUM_SPAWN_POINTS; // atualiza para a proxima spawn

    zombies[i].activeBody(); // ativa o zumbi
    zombies[i].visible(true); // deixa ele ativo

    activeZombiesIndexes.push_back(i); // coloca o indice como ativo
    inactiveZombiesIndexes.pop_front(); // e remove dos inativos
}

void Wave::gameOver(){
    // some com todos os zumbis ativos
    enterTokens.clear();
    for(intIt=activeZombiesIndexes.begin(); intIt != activeZombiesIndexes.end(); intIt++){
        i = *intIt;
        zombies[i].disappear();
    }
}

void Wave::restart() {
    nivel = 0;
    start = time(NULL); // Inicio do cronometro
    status = WAVE_OFF; // Wave Inicia com o Suspiro
    remainingSeconds = 0; // Segundos restantes para o inicio da Wave
}
