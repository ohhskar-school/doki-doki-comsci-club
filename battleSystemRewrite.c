#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
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
    player.maxHealth = 100;

    //Selecting Boss Atrributes
    switch (bossSelection) {
        case 0:
            boss.damage = 10;
            boss.health = 75;
            boss.maxHealth = 100;
            boss.skill = 50;
            boss.name = "Maam Alota";
            break;
        default:
            _battleInfo.errorCode = 3;
            break;
    }

    //Main Battle Loop;
    while (boss.health > 0 && player.health > 0) {
        //Splash Screen
        getReadyScreen();
        clear();
        refresh();
        //Creating Windows
        int hudHeight = 5;
        WINDOW *enemyHudWindow;
        WINDOW *playerHudWindow;
        WINDOW *contentWindow;

        enemyHudWindow = createEnemyHud(boss, hudHeight);
        sleep(2);
    }
}