#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "gameInfo.h"
#include "hud.h"

int boss1(gameInfo);
int bossBattle(int bossSelection, gameInfo _battleInfo) {
    int success = 0;
    switch (bossSelection) {
        case 0: {
            success = boss1(_battleInfo);
            break;
        }
        default: {
            _battleInfo.errorCode = 4;
            break;
        }
    }
    return success;
}

int boss1(gameInfo _battleInfo) {
    //Setting Battle Info
    unsigned int action = 0;
    int battleOutcome = 0, bossSuccess = 0, playerSuccess = 0;
    bossStruct boss;
    playerStruct player;
    srand((unsigned int)time(NULL));
    int success = 1;

    //Setting Player Info
    player.damage = _battleInfo.interestPoints[2] * 3;
    player.health = 100;
    player.maxHealth = 100;

    //Selecting Boss Atrributes
    boss.damage = 10;
    boss.health = 75;
    boss.maxHealth = 100;
    boss.skill = 50;
    boss.name = "Boss 1";

    //Splash Screen
    getReadyScreen();
    clear();
    refresh();

    //Main Battle Loop;
    while (boss.health > 0 && player.health > 0) {
        //Creating Windows
        int hudHeight = 5;
        WINDOW *enemyHudWindow;
        WINDOW *playerHudWindow;
        WINDOW *contentWindow;
        optionReturn optionWindow;

        int lines = 1;
        char *line[1];
        line[0] = "It tries to attack you";

        int options = 3;
        char *option[options];
        option[0] = "Fight";
        option[1] = "Evade";
        option[2] = "Taunt";

        enemyHudWindow = createEnemyHud(boss, hudHeight);
        contentWindow = createContentHud(hudHeight, line, lines);
        playerHudWindow = createPlayerHud(player, hudHeight);
        optionWindow = createOptionHud(hudHeight, option, options);

        lines = 1;
        line[0] = "You dealt 20 damage";
        boss.health -= 20;
        enemyHudWindow = createEnemyHud(boss, hudHeight);
        contentWindow = createContentHud(hudHeight, line, lines);

        options = 1;
        option[0] = "Next ";
        optionWindow = createOptionHud(hudHeight, option, options);
        //optionWindow.choice ==
        // option[0] = "Fight";
        // option[1] = "Evade";
        // option[2] = "Taunt";
    }

    return success;
}