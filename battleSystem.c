#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "gameInfo.h"
#include "hud.h"

int bossBattle(int bossSelection, gameInfo _battleInfo) {
    //Setting Battle Info
    unsigned int action = 0;
    int battleOutcome = 0, bossSuccess = 0, playerSuccess = 0;
    bossStruct boss;
    playerStruct player;
    srand((unsigned int)time(NULL));
    int success = 1;

    //Setting Player Info
    player.damage = 10;  //_battleInfo.interestPoints[2] * 3;
    player.health = 100;
    player.maxHealth = 100;

    //Selecting Boss Atrributes
    boss.damage = 10;
    boss.health = 75;
    boss.maxHealth = 100;
    boss.skill = 50;

    switch (bossSelection) {
        case 0: {
            boss.name = "Boss 1";
        }
    }

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

        // Generates random boss move
        boss.move = rand() % 3;

        // Calculates success rate
        bossSuccess = rand() % 100;
        playerSuccess = rand() % 100;

        int lines = 1;
        char *line[lines];
        line[0] = "What do you want to do?";

        int options = 3;
        char *option[options];
        option[0] = "Fight";
        option[1] = "Evade";
        option[2] = "Taunt";

        enemyHudWindow = createEnemyHud(boss, hudHeight);
        contentWindow = createContentHud(hudHeight, line, lines);
        playerHudWindow = createPlayerHud(player, hudHeight);
        optionWindow = createOptionHud(hudHeight, option, options);
        // If boss attacks
        if (boss.move == 0) {
            lines = 1;
            line[0] = "He tries to attack you.";
            contentWindow = createContentHud(hudHeight, line, lines);

            options = 1;
            option[0] = "Next ";
            createOptionHud(hudHeight, option, options);
            // If attack succeeds
            if (bossSuccess >= boss.skill) {
                // If player chose to attack
                if (optionWindow.choice == 0) {
                    lines = 1;
                    line[0] = "It hit!";
                    player.health -= boss.damage;
                    playerHudWindow = createEnemyHud(boss, hudHeight);
                    contentWindow = createContentHud(hudHeight, line, lines);

                    options = 1;
                    option[0] = "Next ";
                    createOptionHud(hudHeight, option, options);

                    // If player attack succeeds
                    if (playerSuccess >= 30) {
                        lines = 1;
                        line[0] = "You manage to land a hit yourself!";
                        boss.health -= player.damage;
                        enemyHudWindow = createEnemyHud(boss, hudHeight);
                        contentWindow = createContentHud(hudHeight, line, lines);
                    } else {
                        lines = 1;
                        line[0] = "You missed!";
                        contentWindow = createContentHud(hudHeight, line, lines);
                    }

                    options = 1;
                    option[0] = "Next ";
                    createOptionHud(hudHeight, option, options);
                }

                // If player chose to evade
                else if (optionWindow.choice == 1) {
                    // If player evade succeeds
                    if (playerSuccess >= 30) {
                        lines = 1;
                        line[0] = "You manage to dodge his attack!";
                        contentWindow = createContentHud(hudHeight, line, lines);
                    } else {
                        lines = 1;
                        player.health -= boss.damage;
                        playerHudWindow = createEnemyHud(boss, hudHeight);
                        contentWindow = createContentHud(hudHeight, line, lines);
                    }

                    options = 1;
                    option[0] = "Next ";
                    createOptionHud(hudHeight, option, options);
                }

                // If player chose to taunt
                else if (optionWindow.choice == 2) {
                    // If player taunt succeeds
                    if (playerSuccess >= 20) {
                        lines = 2;
                        line[0] = "You successfully taunt your opponent!";
                        line[1] = "Increasing your attack power by 5.";
                        player.damage += 5;
                        contentWindow = createContentHud(hudHeight, line, lines);

                    } else {
                        lines = 1;
                        line[0] = "You try to taunt but it doesn't phase him at all!";
                        contentWindow = createContentHud(hudHeight, line, lines);
                    }

                    options = 1;
                    option[0] = "Next ";
                    createOptionHud(hudHeight, option, options);
                }

                // If boss attack fails
            } else {
                lines = 1;
                line[0] = "He missed!";
                contentWindow = createContentHud(hudHeight, line, lines);

                options = 1;
                option[0] = "Next ";
                createOptionHud(hudHeight, option, options);

                // If player chose to attack
                if (optionWindow.choice == 0) {
                    // If player attack succeeds
                    if (playerSuccess >= 30) {
                        lines = 1;
                        line[0] = "You take the opportunity and hit them hard!";
                        boss.health -= player.damage;
                        enemyHudWindow = createEnemyHud(boss, hudHeight);
                        contentWindow = createContentHud(hudHeight, line, lines);
                    } else {
                        lines = 1;
                        line[0] = "You missed!";
                        contentWindow = createContentHud(hudHeight, line, lines);
                    }

                    options = 1;
                    option[0] = "Next ";
                    createOptionHud(hudHeight, option, options);
                }

                // If player chose to evade
                else if (optionWindow.choice == 1) {
                    lines = 1;
                    line[0] = "You managed to dodge his attack";
                    contentWindow = createContentHud(hudHeight, line, lines);

                    options = 1;
                    option[0] = "Next ";
                    createOptionHud(hudHeight, option, options);
                }

                // If player chose to taunt
                else if (optionWindow.choice == 2) {
                    // If player taunt succeeds
                    if (playerSuccess >= 20) {
                        lines = 2;
                        line[0] = "You mock his weak attempt of an attack";
                        line[1] = "Increasing your attack power by 5.";
                        player.damage += 5;
                        contentWindow = createContentHud(hudHeight, line, lines);

                    } else {
                        lines = 1;
                        line[0] = "You try and mock his missed attack but choke on your own spit instead";
                        contentWindow = createContentHud(hudHeight, line, lines);
                    }

                    options = 1;
                    option[0] = "Next ";
                    createOptionHud(hudHeight, option, options);
                }
            }
        }

        // If boss evades
        if (boss.move == 1) {
            lines = 1;
            line[0] = "He tries to get away from you";
            contentWindow = createContentHud(hudHeight, line, lines);

            options = 1;
            option[0] = "Next ";
            createOptionHud(hudHeight, option, options);

            // If evade succeeds
            if (bossSuccess >= boss.skill) {
                // If player chose to attack
                if (optionWindow.choice == 0) {
                    lines = 1;
                    line[0] = "You miss!";
                    contentWindow = createContentHud(hudHeight, line, lines);

                    options = 1;
                    option[0] = "Next ";
                    createOptionHud(hudHeight, option, options);
                }

                // If player chose to evade
                else if (optionWindow.choice == 1) {
                    lines = 1;
                    line[0] = "Both of you try to get away from each other";
                    contentWindow = createContentHud(hudHeight, line, lines);

                    options = 1;
                    option[0] = "Next ";
                    createOptionHud(hudHeight, option, options);
                }

                // If player chose to taunt
                else if (optionWindow.choice == 2) {
                    // If player taunt succeeds
                    if (playerSuccess >= 20) {
                        lines = 2;
                        line[0] = "You successfully taunt your opponent!";
                        line[1] = "Increasing your attack power by 5.";
                        player.damage += 5;
                        contentWindow = createContentHud(hudHeight, line, lines);

                    } else {
                        lines = 1;
                        line[0] = "You went the wrong way and got hit by his attack instead!";
                        player.health -= boss.damage;
                        playerHudWindow = createEnemyHud(boss, hudHeight);
                        contentWindow = createContentHud(hudHeight, line, lines);
                    }

                    options = 1;
                    option[0] = "Next ";
                    createOptionHud(hudHeight, option, options);
                }

                // If boss evade fails
            } else {
                // If player chose to attack
                if (optionWindow.choice == 0) {
                    // If player attack succeeds
                    if (playerSuccess >= 30) {
                        lines = 1;
                        line[0] = "He moved the wrong way and you managed to hit him!";
                        boss.health -= player.damage;
                        enemyHudWindow = createEnemyHud(boss, hudHeight);
                        contentWindow = createContentHud(hudHeight, line, lines);
                    } else {
                        lines = 1;
                        line[0] = "You missed!";
                        contentWindow = createContentHud(hudHeight, line, lines);
                    }

                    options = 1;
                    option[0] = "Next ";
                    createOptionHud(hudHeight, option, options);
                }

                // If player chose to evade
                else if (optionWindow.choice == 1) {
                    lines = 1;
                    line[0] = "Both of you get away from each other";
                    contentWindow = createContentHud(hudHeight, line, lines);

                    options = 1;
                    option[0] = "Next ";
                    createOptionHud(hudHeight, option, options);
                }

                // If player chose to taunt
                else if (optionWindow.choice == 2) {
                    // If player taunt succeeds
                    if (playerSuccess >= 20) {
                        lines = 2;
                        line[0] = "You successfully taunt your opponent";
                        line[1] = "Increasing your attack power by 5.";
                        player.damage += 5;
                        contentWindow = createContentHud(hudHeight, line, lines);

                    } else {
                        lines = 1;
                        line[0] = "You try and insult him but choke on your own spit instead";
                        contentWindow = createContentHud(hudHeight, line, lines);
                    }

                    options = 1;
                    option[0] = "Next ";
                    createOptionHud(hudHeight, option, options);
                }
            }
        }

        // If boss taunts
        if (boss.move == 2) {
            lines = 1;
            line[0] = "He tries insulting you";
            contentWindow = createContentHud(hudHeight, line, lines);

            options = 1;
            option[0] = "Next ";
            createOptionHud(hudHeight, option, options);

            // If taunt succeeds
            if (bossSuccess >= boss.skill) {
                lines = 1;
                line[0] = "He manages to hurt your feelings and increase his attack power at the same time";
                boss.damage += 5;
                contentWindow = createContentHud(hudHeight, line, lines);

                options = 1;
                option[0] = "Next ";
                createOptionHud(hudHeight, option, options);

                // If player chose to attack
                if (optionWindow.choice == 0) {
                    // If player attack succeeds
                    if (playerSuccess >= 30) {
                        lines = 1;
                        line[0] = "You take the opportunity and land a hit!";
                        boss.health -= player.damage;
                        enemyHudWindow = createEnemyHud(boss, hudHeight);
                        contentWindow = createContentHud(hudHeight, line, lines);
                    } else {
                        lines = 1;
                        line[0] = "You tried to hit him but badly missed";
                        contentWindow = createContentHud(hudHeight, line, lines);
                    }

                    options = 1;
                    option[0] = "Next ";
                    createOptionHud(hudHeight, option, options);
                }

                // If player chose to evade
                else if (optionWindow.choice == 1) {
                    lines = 1;
                    line[0] = "You roll away from him";
                    contentWindow = createContentHud(hudHeight, line, lines);

                    options = 1;
                    option[0] = "Next ";
                    createOptionHud(hudHeight, option, options);
                }

                // If player chose to taunt
                else if (optionWindow.choice == 2) {
                    // If player taunt succeeds
                    if (playerSuccess >= 20) {
                        lines = 2;
                        line[0] = "You give him a mouthful of insults as well!";
                        line[1] = "Increasing your attack power by 5.";
                        player.damage += 5;
                        contentWindow = createContentHud(hudHeight, line, lines);

                    } else {
                        lines = 1;
                        line[0] = "Stunned by what he just said, you just skipped your turn";
                        contentWindow = createContentHud(hudHeight, line, lines);
                    }

                    options = 1;
                    option[0] = "Next ";
                    createOptionHud(hudHeight, option, options);
                }

                // If boss taunt fails
            } else {
                lines = 1;
                line[0] = "He stutters and fails to hurt your feelings";
                contentWindow = createContentHud(hudHeight, line, lines);

                options = 1;
                option[0] = "Next ";
                createOptionHud(hudHeight, option, options);

                // If player chose to attack
                if (optionWindow.choice == 0) {
                    // If player attack succeeds
                    if (playerSuccess >= 30) {
                        lines = 1;
                        line[0] = "You take the opportunity and hit them hard!";
                        boss.health -= player.damage;
                        enemyHudWindow = createEnemyHud(boss, hudHeight);
                        contentWindow = createContentHud(hudHeight, line, lines);
                    } else {
                        lines = 1;
                        line[0] = "You take a swing at him but miss!";
                        contentWindow = createContentHud(hudHeight, line, lines);
                    }

                    options = 1;
                    option[0] = "Next ";
                    createOptionHud(hudHeight, option, options);
                }

                // If player chose to evade
                else if (optionWindow.choice == 1) {
                    lines = 1;
                    line[0] = "You roll away from him";
                    contentWindow = createContentHud(hudHeight, line, lines);

                    options = 1;
                    option[0] = "Next ";
                    createOptionHud(hudHeight, option, options);
                }

                // If player chose to taunt
                else if (optionWindow.choice == 2) {
                    // If player taunt succeeds
                    if (playerSuccess >= 20) {
                        lines = 2;
                        line[0] = "You laugh at his attempt to insult you";
                        line[1] = "Increasing your attack power by 10.";
                        player.damage += 10;
                        contentWindow = createContentHud(hudHeight, line, lines);

                    } else {
                        lines = 1;
                        line[0] = "You try and insult him as well but choke on your own spit instead";
                        contentWindow = createContentHud(hudHeight, line, lines);
                    }

                    options = 1;
                    option[0] = "Next ";
                    createOptionHud(hudHeight, option, options);
                }
            }
        }
    }

    if (boss.health <= 0) {
        success = 1;
    }

    return success;
}