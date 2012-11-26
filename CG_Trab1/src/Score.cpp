#include "score.h"

Score::Score() {
    // pega o tempo atual
    start = time(NULL);
    lastTimeScore = time(NULL);
    timeMultiplier = 1;
}

int Score::score = 0;
int Score::headShot = 0;
int Score::kills = 0;
int Score::comboKills = 0;
int Score::totalKills = 0;
int Score::maxComboKills = 0;
int Score::comboMultiplier = 1;
time_t Score::lastKill = time(NULL);

void Score::addKill() {
    score += SCORE_ZOMBIE_KILL * comboMultiplier;
    updateKills();
}

void Score::addHeadShot() {
    score += SCORE_ZOMBIE_HEADSHOT * comboMultiplier;
    headShot++;
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
    if ( lastKill != 0 && difftime( time(0), lastKill ) >= COMBO_DURATION ) {
        if (comboKills > maxComboKills) maxComboKills = comboKills;
        comboMultiplier = 1;
        lastKill = 0;
        kills = 0;
        comboKills = 0;
    }

    Text::write(COLUNA_DISPLAY ,LINHA1_DISPLAY + 20,"Score: %d",score);
    //Text::write(COLUNA_DISPLAY ,LINHA1_DISPLAY + 50,"HeadShot: %d",headShot);

    if (comboMultiplier > 1) {
        Text::write(COLUNA_DISPLAY ,LINHA1_DISPLAY + 30,"Multiplicador: %d",comboMultiplier);
    }
    if (comboKills > 1) {
        Text::write(COLUNA_DISPLAY ,LINHA1_DISPLAY + 40,"Combo: %d",comboKills);
    }
    Text::write(COLUNA_DISPLAY ,LINHA1_DISPLAY + 500,"Headshot: %d",headShot);
}

void Score::erase() {
    score = 0;
    headShot = 0;
    kills = 0;
    comboKills = 0;
    totalKills = 0;
    maxComboKills = 0;
    comboMultiplier = 1;
}

void Score::updateKills() {
    lastKill = time(NULL);
    kills++;
    comboKills++;
    totalKills++;

    if (kills >= 4 * comboMultiplier) {
        comboMultiplier++;
        kills = 0;
    }
}
