#include "score.h"

Score::Score() {
    // pega o tempo atual
    start = time(NULL);
    lastTimeScore = time(NULL);
    score = 0;
    kills = 0;
    comboKills = 0;
    comboMultiplier = 1;
    timeMultiplier = 1;
    lastKill = time(NULL);
}

void Score::addKill() {
    score += SCORE_ZOMBIE_KILL * comboMultiplier;
    updateKills();
}

void Score::addHeadShot() {
    score += SCORE_ZOMBIE_HEADSHOT * comboMultiplier;
    updateKills();
}

void Score::addTimeScore() {
    score += SCORE_PER_SEC * timeMultiplier;
    lastTimeScore = time(NULL);
}

void Score::plusTimeMultiplier() {
    timeMultiplier++;
}

void Score::update() {
    if ( difftime( time(NULL), lastTimeScore ) >= 1 ) {
        addTimeScore();
    }
    if ( lastKill != NULL && difftime( time(NULL), lastKill ) >= COMBO_DURATION ) {
        comboMultiplier = 1;
        lastKill = NULL;
        kills = 0;
        comboKills = 0;
    }

    Text::write(COLUNA_DISPLAY -100,LINHA1_DISPLAY + 20,"Score: %d",score);

    if (comboMultiplier > 1) {
        Text::write(COLUNA_DISPLAY -100,LINHA1_DISPLAY + 30,"Multiplicador: %d",comboMultiplier);
    }
    if (comboKills > 1) {
        Text::write(COLUNA_DISPLAY -100,LINHA1_DISPLAY + 40,"Combo: %d",comboKills);
    }
}

void Score::updateKills() {
    lastKill = time(NULL);
    kills++;
    comboKills++;

    if (kills >= 4 * comboMultiplier) {
        comboMultiplier++;
        kills = 0;
    }
}
