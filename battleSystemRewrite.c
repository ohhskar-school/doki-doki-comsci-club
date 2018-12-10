#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "gameInfo.h"
#include "hud.h"

void bossBattle(int bossSelection, gameInfo _battleInfo, int questGiver) {
    //Setting Battle Info
    unsigned int action = 0;
    int battleOutcome = 0, bossSuccess = 0, playerSuccess = 0;
    bossStruct boss;
    playerStruct player;
    srand((unsigned int)time(NULL));

    //Setting Player Info
    player.damage = _battleInfo.interestPoints[questGiver] * 3;
    player.health = 100;

    //Selecting Boss Atrributes
    switch (bossSelection) {
        case 0:
            boss.damage = 10;
            boss.health = 30;
            boss.skill = 50;
            boss.name = "Maam Alota";
            break;
        default:
            _battleInfo.errorCode = 3;
            break;
    }

    while (boss.health > 0 && player.health > 0) {
        getReadyScreen();
    }
}