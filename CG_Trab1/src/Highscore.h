#ifndef HIGHSCORE_H
#define HIGHSCORE_H
#include "bibliotecas.h"
#include "Constantes.h"
#include "score.h"
#include <iostream>
#include <fstream>

using namespace std;

struct highscore_t {
    int score;
    int comboKills;
    int totalKills;
};

class Highscore
{
    public:
        Highscore();
        void update();
        bool isHighscore();
        void addHighscore();
        void loadFromFile();
        void saveToFile();
    private:
        fstream file;
        highscore_t highscores[HIGHSCORES_CAPACITY];
};

#endif // HIGHSCORE_H


