#ifndef FRAME_RATE_MONITOR_H
#define FRAME_RATE_MONITOR_H
#include "bibliotecas.h"
#include "Constantes.h"

class FrameRateMonitor
{
    public:
        FrameRateMonitor();
        double getDeltaTime();
        void updateLastFrameTime();
        void update();
    private:
        time_t lastFrameTime;
        int frames;
        double elapsedTime;
        float fps;

};

#endif // FRAME_RATE_MONITOR_H
