#include "frameRateMonitor.h"

FrameRateMonitor::FrameRateMonitor() {
    // pega o tempo atual
    lastFrameTime = time(NULL);
    frames = 0;
    elapsedTime = 0;
    fps = 0.0f;
}

double FrameRateMonitor::getDeltaTime(){
    // retorna a diferenca em float entre o tempo atual e o tempo do último frame
    float deltaTime = difftime(time(NULL), lastFrameTime);
    frames++;
    elapsedTime += deltaTime;
    return deltaTime;
}

void FrameRateMonitor::updateLastFrameTime() {
    // atualiza o lastFrameTime para o tempo atual
    lastFrameTime = time(NULL);
}

void FrameRateMonitor::update() {
    if (elapsedTime > 3) {
        fps = frames / 3.0;
        frames = 0;
        elapsedTime = 0.0;
    }
    Text::write(COLUNA_DISPLAY -100,LINHA1_DISPLAY + 20,"%s %f","FPS: ",fps);
}
