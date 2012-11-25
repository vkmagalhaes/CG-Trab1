#ifndef SCORE_H
#define SCORE_H
#include "bibliotecas.h"
#include "Constantes.h"

class Score
{

    public:
        Score();
        //virtual void zumbiKilled();
        static void addKill();
        static void addHeadShot();
        void plusTimeMultiplier();
        void update();
        void addTimeScore();

        static int score;
        static int kills;
        static int comboKills;
        static int comboMultiplier;
        static time_t lastKill;
        static int headShot;

    private:


        static void updateKills();
        time_t start;
        time_t lastTimeScore;
        int timeMultiplier;
};

#endif // SCORE_H

