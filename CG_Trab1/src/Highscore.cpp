#include "Highscore.h"

Highscore::Highscore() {
    for(int i=0; i < HIGHSCORES_CAPACITY; i++) {
        highscores[i].score = 0;
        highscores[i].comboKills = 0;
        highscores[i].totalKills = 0;
    }
}

void Highscore::update() {
    Text::write(200,100,"Posicao");
    Text::write(350,100,"Maior Combo");
    Text::write(500,100,"Zumbis Mortos");
    for(int i=0; i < HIGHSCORES_CAPACITY; i++) {
        Text::write(200,120+i*20,"%d",highscores[i].score);
        Text::write(350,120+i*20,"%d",highscores[i].comboKills);
        Text::write(500,120+i*20,"%d",highscores[i].totalKills);
    }
}

bool Highscore::isHighscore() {
    for(int i=0; i < HIGHSCORES_CAPACITY; i++) {
        if (Score::score > highscores[i].score)
            return true;
        else if (Score::score == highscores[i].score && i < HIGHSCORES_CAPACITY-1)
            return true;
    }
    return false;
}

void Highscore::addHighscore() {
    highscore_t newHighscore, temp;

    newHighscore.score = Score::score;
    newHighscore.comboKills = Score::maxComboKills;
    newHighscore.totalKills = Score::totalKills;

    for(int i=0; i < HIGHSCORES_CAPACITY; i++) {
        if (Score::score >= highscores[i].score) {
            temp = highscores[i];
            highscores[i] = newHighscore;
            newHighscore = temp;
        }
    }
}

void Highscore::loadFromFile() {
    int i = 0, score, comboKills, totalKills;
    file.open("highscores.txt");

    //if (file.is_open()) {
        while(file.good() && i < HIGHSCORES_CAPACITY) {
            file >> score >> comboKills >> totalKills;

            highscores[i].score = score;
            highscores[i].comboKills = comboKills;
            highscores[i].totalKills = totalKills;

            i++;
        }
    //} else {
     //   printf("Erro ao carregar highscores!\n");
    //}

    file.close();
}

void Highscore::saveToFile() {
    //file.open("highscores.txt");

    FILE * pFile;

    pFile = fopen("highscores.txt", "w");

    //if (file.is_open()) {
        for(int i=0; i < HIGHSCORES_CAPACITY; i++) {
            fprintf(pFile, "%d %d %d\n", highscores[i].score, highscores[i].comboKills, highscores[i].totalKills);
        }
    //} else {
    //    printf("Erro ao salvar highscores!\n");
    //}

    //file.close();
    fclose(pFile);
}
