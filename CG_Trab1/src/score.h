#ifndef SCORE_H
#define SCORE_H
#include "bibliotecas.h"
#include "Constantes.h"

class Score
{
    public:
        Score();
        void addKill();
        void addHeadShot();
        void plusTimeMultiplier();
        void update();
    private:
        void addTimeScore();
        void updateKills();
        time_t start;
        time_t lastTimeScore;
        int score;
        int kills;
        int comboKills;
        int comboMultiplier;
        int timeMultiplier;
        time_t lastKill;
};

#endif // SCORE_H

