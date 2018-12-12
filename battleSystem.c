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
    int success = 0;

    //Setting Player Info
    player.damage = _battleInfo.interestPoints[2]/10;
    player.health = 100;
    player.maxHealth = 100;

    //Selecting Boss Attributes
    switch  (bossSelection) {
        case 1:
            boss.damage = 10;
            boss.health = 75;
            boss.maxHealth = 100;
            boss.skill = 50;
            boss.name = "Math Ghost";
            break;

        case 2:
            boss.damage = 10;
            boss.health = 75;
            boss.maxHealth = 100;
            boss.skill = 50;
            boss.name = "Club Recruiter Horde";
            break;
        case 3:
            boss.damage = 20;
            boss.health = 750;
            boss.maxHealth = 1000;
            boss.skill = 50;
            boss.name = "Jeff's TECKEN Character";
            break;
        case 4:
            boss.damage = 10;
            boss.health = 75;
            boss.maxHealth = 100;
            boss.skill = 50;
            boss.name = "CMSC 11 Assignment";
            break;
        case 5:
            boss.damage = 10;
            boss.health = 75;
            boss.maxHealth = 100;
            boss.skill = 50;
            boss.name = "Mr. K's Pop Quiz";
            break;
        case 6:
            boss.damage = 1000000;
            boss.health = 75;
            boss.maxHealth = 100;
            boss.skill = 50;
            boss.name = "Mr. K";
            break;
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

        switch(bossSelection) {
            case 1:
                option[0] = "Guess";
                option[1] = "Ignore";
                option[2] = "Study";
                break;
            case 2:
                option[0] = "Say NO";
                option[1] = "Ignore";
                option[2] = "Sidestep";
                break;
            case 3:
                option[0] = "Attack";
                option[1] = "Evade";
                option[2] = "Taunt";
                break;
            case 4:
                option[0] = "Answer";
                option[1] = "Skip";
                option[2] = "Research";
                break;
            case 5:
                option[0] = "Answer";
                option[1] = "Skip";
                option[2] = "Pray";
                break;
            case 6:
                option[0] = "Cry";
                option[1] = "Cry";
                option[2] = "Cry";
                break;
        }

        enemyHudWindow = createEnemyHud(boss, hudHeight);
        contentWindow = createContentHud(hudHeight, line, lines);
        playerHudWindow = createPlayerHud(player, hudHeight);
        optionWindow = createOptionHud(hudHeight, option, options);


        // If boss attacks
        if (boss.move == 0) {
            
            lines = 1;
            switch(bossSelection) {
                case 1:
                    line[0] = "Math Ghost hits you with a math problem!";
                    break;
                case 2:
                    lines = 1;
                    line[0] = "They ask you to join their club!";
                    break;
                case 3:
                    lines = 1;
                    line[0] = "Jeff's character tries to attack!";
                    break;
                case 4:
                    lines = 1;
                    line[0] = "You encounter a difficult question!";
                    break;
                case 5:
                    lines = 1;
                    line[0] = "You encounter a difficult question!";
                    break;
            }
            contentWindow = createContentHud(hudHeight, line, lines);

            options = 1;
            option[0] = "Next";
            createOptionHud(hudHeight, option, options);
            // If attack succeeds
            if (bossSuccess >= boss.skill) {

                // If player chose to attack
                if (optionWindow.choice == 0) {
                    lines = 1;
                    switch(bossSelection) {
                        case 1:
                            line[0] = "You get confused! Hurting your brain in the process";
                            break;
                        case 2:
                            line[0] = "They try to swarm you! Hurting you in the process";
                            break;
                        case 3:
                            line[0] = "Jeff's character tries to attack!";
                            break;
                        case 4:
                            line[0] = "You encounter a difficult question!";
                            break;
                        case 5:
                            line[0] = "You encounter a difficult question!";
                            break;
                    }
                    player.health -= boss.damage;
                    playerHudWindow = createPlayerHud(player, hudHeight);
                    contentWindow = createContentHud(hudHeight, line, lines);

                    options = 1;
                    option[0] = "Next";
                    createOptionHud(hudHeight, option, options);

                    // If player attack succeeds
                    if (playerSuccess >= 30) {
                        lines = 1;
                        switch(bossSelection) {
                            case 1:
                                line[0] = "You try and guess, and succeed! You hurt the ghost's pride";
                                break;
                            case 2:
                                line[0] = "You say a resounding NO! Hurting their feelings";
                                break;
                            case 3:
                                line[0] = "Jeff's character tries to attack!";
                                break;
                            case 4:
                                line[0] = "You encounter a difficult question!";
                                break;
                            case 5:
                                line[0] = "You encounter a difficult question!";
                                break;
                        }
                        boss.health = player.damage;
                        enemyHudWindow = createEnemyHud(boss, hudHeight);
                        contentWindow = createContentHud(hudHeight, line, lines);
                    } else {
                        lines = 1;
                        switch(bossSelection) {
                            case 1:
                                line[0] = "You try and guess anyway but guessed the wrong answer!";
                                break;
                            case 2:
                                line[0] = "You try to say no but are overpowered by their number";
                                break;
                            case 3:
                                line[0] = "Jeff's character tries to attack!";
                                break;
                            case 4:
                                line[0] = "You encounter a difficult question!";
                                break;
                            case 5:
                                line[0] = "You encounter a difficult question!";
                                break;
                        }
                        contentWindow = createContentHud(hudHeight, line, lines);
                    }

                    options = 1;
                    option[0] = "Next";
                    createOptionHud(hudHeight, option, options);
                }

                // If player chose to evade
                else if (optionWindow.choice == 1) {
                    // If player evade succeeds
                    if (playerSuccess >= 30) {
                        lines = 1;
                        switch(bossSelection) {
                            case 1:
                                line[0] = "You manage to ignore the math question!";
                                break;
                            case 2:
                                line[0] = "You manage to ignore their desperate pleas";
                                break;
                            case 3:
                                line[0] = "Jeff's character tries to attack!";
                                break;
                            case 4:
                                line[0] = "You encounter a difficult question!";
                                break;
                            case 5:
                                line[0] = "You encounter a difficult question!";
                                break;
                        }
                        contentWindow = createContentHud(hudHeight, line, lines);
                    } else {
                        lines = 1;
                        switch(bossSelection) {
                            case 1:
                                line[0] = "You tried ignoring, but were unsuccessful";
                                break;
                            case 2:
                                line[0] = "You tried ignoring them, but got more annoyed instead";
                                break;
                            case 3:
                                line[0] = "Jeff's character tries to attack!";
                                break;
                            case 4:
                                line[0] = "You encounter a difficult question!";
                                break;
                            case 5:
                                line[0] = "You encounter a difficult question!";
                                break;
                        }
                        player.health -= boss.damage;
                        playerHudWindow = createEnemyHud(boss, hudHeight);
                        contentWindow = createContentHud(hudHeight, line, lines);
                    }

                    options = 1;
                    option[0] = "Next";
                    createOptionHud(hudHeight, option, options);
                }

                // If player chose to taunt
                else if (optionWindow.choice == 2) {
                    // If player taunt succeeds
                    if (playerSuccess >= 20) {
                        lines = 2;
                        switch(bossSelection) {
                            case 1:
                                line[0] = "You study in order to solve the next equation";
                                line[1] = "Increasing your knowledge by 5";
                                break;
                            case 2:
                                line[0] = "You sidestepped the crowd";
                                line[1] = "Increasing your confidence by 5";
                                break;
                            case 3:
                                line[0] = "Jeff's character tries to attack!";
                                line[1] = "";
                                break;
                            case 4:
                                line[0] = "You encounter a difficult question!";
                                line[1] = "";
                                break;
                            case 5:
                                line[0] = "You encounter a difficult question!";
                                line[1] = "";
                                break;
                        }
                        player.damage += 5;
                        contentWindow = createContentHud(hudHeight, line, lines);

                    } else {
                        lines = 1;
                        switch(bossSelection) {
                            case 1:
                                line[0] = "You tried studying but procrastinated instead";
                                break;
                            case 2:
                                line[0] = "You tried sidestepping the crowd but tripped instead";
                                break;
                            case 3:
                                line[0] = "Jeff's character tries to attack!";
                                break;
                            case 4:
                                line[0] = "You encounter a difficult question!";
                                break;
                            case 5:
                                line[0] = "You encounter a difficult question!";
                                break;
                        }
                        contentWindow = createContentHud(hudHeight, line, lines);
                    }

                    options = 1;
                    option[0] = "Next";
                    createOptionHud(hudHeight, option, options);
                }

            // If boss attack fails
            } else {
                lines = 1;
                switch(bossSelection) {
                    case 1:
                        line[0] = "It failed to confuse you!";
                        break;
                    case 2:
                        line[0] = "They fail to convince you!";
                        break;
                    case 3:
                        line[0] = "Jeff's character tries to attack!";
                        break;
                    case 4:
                        line[0] = "You encounter a difficult question!";
                        break;
                    case 5:
                        line[0] = "You encounter a difficult question!";
                        break;
                }
                contentWindow = createContentHud(hudHeight, line, lines);

                options = 1;
                option[0] = "Next";
                createOptionHud(hudHeight, option, options);

                // If player chose to attack
                if (optionWindow.choice == 0) {
                    // If player attack succeeds
                    if (playerSuccess >= 30) {
                        lines = 1;
                        switch(bossSelection) {
                            case 1:
                                line[0] = "You manage to guess the answer to his math problem! Hurting the ghost's pride";
                                break;
                            case 2:
                                line[0] = "You say a resounding NO! Hurting their feelings";
                                break;
                            case 3:
                                line[0] = "Jeff's character tries to attack!";
                                break;
                            case 4:
                                line[0] = "You encounter a difficult question!";
                                break;
                            case 5:
                                line[0] = "You encounter a difficult question!";
                                break;
                        }
                        boss.health -= player.damage;
                        enemyHudWindow = createEnemyHud(boss, hudHeight);
                        contentWindow = createContentHud(hudHeight, line, lines);
                    } else {
                        lines = 1;
                        switch(bossSelection) {
                            case 1:
                                line[0] = "You tried guessing, but failed miserably";
                                break;
                            case 2:
                                line[0] = "You try to say no but are overpowered by their number";
                                break;
                            case 3:
                                line[0] = "Jeff's character tries to attack!";
                                break;
                            case 4:
                                line[0] = "You encounter a difficult question!";
                                break;
                            case 5:
                                line[0] = "You encounter a difficult question!";
                                break;
                        }
                        contentWindow = createContentHud(hudHeight, line, lines);
                    }

                    options = 1;
                    option[0] = "Next";
                    createOptionHud(hudHeight, option, options);
                }

                // If player chose to evade
                else if (optionWindow.choice == 1) {
                    lines = 1;
                    switch(bossSelection) {
                        case 1:
                            line[0] = "You ignore the ghost's attempt at confusing you";
                            break;
                        case 2:
                            line[0] = "You manage to ignore their desperate pleas";
                            break;
                        case 3:
                            line[0] = "Jeff's character tries to attack!";
                            break;
                        case 4:
                            line[0] = "You encounter a difficult question!";
                            break;
                        case 5:
                            line[0] = "You encounter a difficult question!";
                            break;
                    }
                    contentWindow = createContentHud(hudHeight, line, lines);

                    options = 1;
                    option[0] = "Next";
                    createOptionHud(hudHeight, option, options);
                }

                // If player chose to taunt
                else if (optionWindow.choice == 2) {
                    // If player taunt succeeds
                    if (playerSuccess >= 20) {
                        lines = 2;
                        switch(bossSelection) {
                            case 1:
                                line[0] = "You study in order to solve the next equation";
                                line[1] = "Increasing your knowledge by 5";
                                break;
                            case 2:
                                line[0] = "You sidestepped the crowd";
                                line[1] = "Increasing your confidence by 5";
                                break;
                            case 3:
                                line[0] = "Jeff's character tries to attack!";
                                line[1] = "";
                                break;
                            case 4:
                                line[0] = "You encounter a difficult question!";
                                line[1] = "";
                                break;
                            case 5:
                                line[0] = "You encounter a difficult question!";
                                line[1] = "";
                                break;
                        }
                        player.damage += 5;
                        contentWindow = createContentHud(hudHeight, line, lines);

                    } else {
                        lines = 1;
                        switch(bossSelection) {
                            case 1:
                                line[0] = "You tried to study, but procrastinated instead";
                                break;
                            case 2:
                                line[0] = "You tried sidestepping but tripped instead";
                                break;
                            case 3:
                                line[0] = "Jeff's character tries to attack!";
                                break;
                            case 4:
                                line[0] = "You encounter a difficult question!";
                                break;
                            case 5:
                                line[0] = "You encounter a difficult question!";
                                break;
                        }
                        contentWindow = createContentHud(hudHeight, line, lines);
                    }

                    options = 1;
                    option[0] = "Next";
                    createOptionHud(hudHeight, option, options);
                }
            }
        }

        // If boss evades
        if (boss.move == 1) {
            lines = 1;
            switch(bossSelection) {
                case 1:
                    line[0] = "The ghost tries to disappear";
                    break;
                case 2:
                    line[0] = "All of them start talking at once";
                    break;
                case 3:
                    line[0] = "Jeff's character tries to attack!";
                    break;
                case 4:
                    line[0] = "You encounter a difficult question!";
                    break;
                case 5:
                    line[0] = "You encounter a difficult question!";
                    break;
            }
            contentWindow = createContentHud(hudHeight, line, lines);

            options = 1;
            option[0] = "Next";
            createOptionHud(hudHeight, option, options);

            // If evade succeeds
            if (bossSuccess >= boss.skill) {
                // If player chose to attack
                if (optionWindow.choice == 0) {
                    lines = 1;
                    switch(bossSelection) {
                        case 1:
                            line[0] = "You try to guess but you can't see him!";
                            break;
                        case 2:
                            line[0] = "They can't hear a word you're saying";
                            break;
                        case 3:
                            line[0] = "Jeff's character tries to attack!";
                            break;
                        case 4:
                            line[0] = "You encounter a difficult question!";
                            break;
                        case 5:
                            line[0] = "You encounter a difficult question!";
                            break;
                    }
                    contentWindow = createContentHud(hudHeight, line, lines);

                    options = 1;
                    option[0] = "Next";
                    createOptionHud(hudHeight, option, options);
                }

                // If player chose to evade
                else if (optionWindow.choice == 1) {
                    lines = 1;
                    switch(bossSelection) {
                        case 1:
                            line[0] = "You ignored his disappearing act";
                            break;
                        case 2:
                            line[0] = "You manage to ignore their presence";
                            break;
                        case 3:
                            line[0] = "Jeff's character tries to attack!";
                            break;
                        case 4:
                            line[0] = "You encounter a difficult question!";
                            break;
                        case 5:
                            line[0] = "You encounter a difficult question!";
                            break;
                    }
                    contentWindow = createContentHud(hudHeight, line, lines);

                    options = 1;
                    option[0] = "Next";
                    createOptionHud(hudHeight, option, options);
                }

                // If player chose to taunt
                else if (optionWindow.choice == 2) {
                    // If player taunt succeeds
                    if (playerSuccess >= 20) {
                        lines = 2;
                        switch(bossSelection) {
                            case 1:
                                line[0] = "You study for his next attack";
                                line[1] = "Increasing your knowledge by 5";
                                break;
                            case 2:
                                line[0] = "You sidestepped the crowd";
                                line[1] = "Increasing your confidence by 5";
                                break;
                            case 3:
                                line[0] = "Jeff's character tries to attack!";
                                line[1] = "";
                                break;
                            case 4:
                                line[0] = "You encounter a difficult question!";
                                line[1] = "";
                                break;
                            case 5:
                                line[0] = "You encounter a difficult question!";
                                line[1] = "";
                                break;
                        }
                        player.damage += 5;
                        contentWindow = createContentHud(hudHeight, line, lines);

                    } else {
                        lines = 1;
                        switch(bossSelection) {
                            case 1:
                                line[0] = "You tried studying but got bored";
                                break;
                            case 2:
                                line[0] = "You tried sidestepping but bumped into one of them instead";
                                break;
                            case 3:
                                line[0] = "Jeff's character tries to attack!";
                                break;
                            case 4:
                                line[0] = "You encounter a difficult question!";
                                break;
                            case 5:
                                line[0] = "You encounter a difficult question!";
                                break;
                        }
                        player.health -= boss.damage;
                        playerHudWindow = createEnemyHud(boss, hudHeight);
                        contentWindow = createContentHud(hudHeight, line, lines);
                    }

                    options = 1;
                    option[0] = "Next";
                    createOptionHud(hudHeight, option, options);
                }

            // If boss evade fails
            } else {
                // If player chose to attack
                if (optionWindow.choice == 0) {
                    // If player attack succeeds
                    if (playerSuccess >= 30) {
                        lines = 1;
                        switch(bossSelection) {
                            case 1:
                                line[0] = "You still manage to guess his problem!";
                                break;
                            case 2:
                                line[0] = "You shout a loud NO into the crowd! Shutting them up for a while";
                                break;
                            case 3:
                                line[0] = "Jeff's character tries to attack!";
                                break;
                            case 4:
                                line[0] = "You encounter a difficult question!";
                                break;
                            case 5:
                                line[0] = "You encounter a difficult question!";
                                break;
                        }
                        boss.health -= player.damage;
                        enemyHudWindow = createEnemyHud(boss, hudHeight);
                        contentWindow = createContentHud(hudHeight, line, lines);
                    } else {
                        lines = 1;
                        switch(bossSelection) {
                            case 1:
                                line[0] = "You try to guess but can't see it!";
                                break;
                            case 2:
                                line[0] = "The sound of your NO gets drowned by all of their voices";
                                break;
                            case 3:
                                line[0] = "Jeff's character tries to attack!";
                                break;
                            case 4:
                                line[0] = "You encounter a difficult question!";
                                break;
                            case 5:
                                line[0] = "You encounter a difficult question!";
                                break;
                        }
                        contentWindow = createContentHud(hudHeight, line, lines);
                    }

                    options = 1;
                    option[0] = "Next";
                    createOptionHud(hudHeight, option, options);
                }

                // If player chose to evade
                else if (optionWindow.choice == 1) {
                    lines = 1;
                    switch(bossSelection) {
                        case 1:
                            line[0] = "You ignore his disappearing act";
                            break;
                        case 2:
                            line[0] = "You manage to ignore their presence entirely";
                            break;
                        case 3:
                            line[0] = "Jeff's character tries to attack!";
                            break;
                        case 4:
                            line[0] = "You encounter a difficult question!";
                            break;
                        case 5:
                            line[0] = "You encounter a difficult question!";
                            break;
                    }
                    contentWindow = createContentHud(hudHeight, line, lines);

                    options = 1;
                    option[0] = "Next";
                    createOptionHud(hudHeight, option, options);
                }

                // If player chose to taunt
                else if (optionWindow.choice == 2) {
                    // If player taunt succeeds
                    if (playerSuccess >= 20) {
                        lines = 2;
                        switch(bossSelection) {
                            case 1:
                                line[0] = "You study for its next attack";
                                line[1] = "Increasing your knowledge by 5";
                                break;
                            case 2:
                                line[0] = "You sidestepped the crowd";
                                line[1] = "Increasing your confidence by 5";
                                break;
                            case 3:
                                line[0] = "Jeff's character tries to attack!";
                                line[1] = "";
                                break;
                            case 4:
                                line[0] = "You encounter a difficult question!";
                                line[1] = "";
                                break;
                            case 5:
                                line[0] = "You encounter a difficult question!";
                                line[1] = "";
                                break;
                        }
                        player.damage += 5;
                        contentWindow = createContentHud(hudHeight, line, lines);

                    } else {
                        lines = 1;
                        switch(bossSelection) {
                            case 1:
                                line[0] = "You try to study but got bored immediately";
                                break;
                            case 2:
                                line[0] = "You tried sidestepping the crowd but bumped into one of them instead";
                                break;
                            case 3:
                                line[0] = "Jeff's character tries to attack!";
                                break;
                            case 4:
                                line[0] = "You encounter a difficult question!";
                                break;
                            case 5:
                                line[0] = "You encounter a difficult question!";
                                break;
                        }
                        contentWindow = createContentHud(hudHeight, line, lines);
                    }

                    options = 1;
                    option[0] = "Next";
                    createOptionHud(hudHeight, option, options);
                }
            }
        }

        // If boss taunts
        if (boss.move == 2) {
            lines = 1;
            switch(bossSelection) {
                case 1:
                    line[0] = "The ghost taunts you with a 5.00";
                    break;
                case 2:
                    line[0] = "They try and discourage you from the CMSC Club!";
                    break;
                case 3:
                    line[0] = "Jeff's character tries to attack!";
                    break;
                case 4:
                    line[0] = "You encounter a difficult question!";
                    break;
                case 5:
                    line[0] = "You encounter a difficult question!";
                    break;
            }
            contentWindow = createContentHud(hudHeight, line, lines);

            options = 1;
            option[0] = "Next";
            createOptionHud(hudHeight, option, options);

            // If taunt succeeds
            if (bossSuccess >= boss.skill) {
                lines = 2;
                switch(bossSelection) {
                    case 1:
                        line[0] = "Your anxiety kicks in and makes you think about your grades";
                        line[1] = "Decreasing your knowledge by 5";
                        break;
                    case 2:
                        line[0] = "You're starting to have doubts about joining the CMSC Club";
                        line[1] = "Decreasing your confidence by 5";
                        break;
                    case 3:
                        line[0] = "Jeff's character tries to attack!";
                        line[1] ="";
                        break;
                    case 4:
                        line[0] = "You encounter a difficult question!";
                        line[1] ="";
                        break;
                    case 5:
                        line[0] = "You encounter a difficult question!";
                        line[1] ="";
                        break;
                }
                boss.damage += 5;
                contentWindow = createContentHud(hudHeight, line, lines);

                options = 1;
                option[0] = "Next";
                createOptionHud(hudHeight, option, options);

                // If player chose to attack
                if (optionWindow.choice == 0) {
                    // If player attack succeeds
                    if (playerSuccess >= 30) {
                        lines = 1;
                        switch(bossSelection) {
                            case 1:
                                line[0] = "You still manage to guess the answer!";
                                break;
                            case 2:
                                line[0] = "You say a resounding NO! Hurting their feelings";
                                break;
                            case 3:
                                line[0] = "Jeff's character tries to attack!";
                                break;
                            case 4:
                                line[0] = "You encounter a difficult question!";
                                break;
                            case 5:
                                line[0] = "You encounter a difficult question!";
                                break;
                        }
                        boss.health -= player.damage;
                        enemyHudWindow = createEnemyHud(boss, hudHeight);
                        contentWindow = createContentHud(hudHeight, line, lines);
                    } else {
                        lines = 1;
                        switch(bossSelection) {
                            case 1:
                                line[0] = "You fail to guess the answer";
                                break;
                            case 2:
                                line[0] = "You can't hear yourself over the sound of their pleas";
                                break;
                            case 3:
                                line[0] = "Jeff's character tries to attack!";
                                break;
                            case 4:
                                line[0] = "You encounter a difficult question!";
                                break;
                            case 5:
                                line[0] = "You encounter a difficult question!";
                                break;
                        }
                        contentWindow = createContentHud(hudHeight, line, lines);
                    }

                    options = 1;
                    option[0] = "Next";
                    createOptionHud(hudHeight, option, options);
                }

                // If player chose to evade
                else if (optionWindow.choice == 1) {
                    lines = 1;
                    switch(bossSelection) {
                        case 1:
                            line[0] = "You ignore your anxiety";
                            break;
                        case 2:
                            line[0] = "You ignore their desperate pleas";
                            break;
                        case 3:
                            line[0] = "Jeff's character tries to attack!";
                            break;
                        case 4:
                            line[0] = "You encounter a difficult question!";
                            break;
                        case 5:
                            line[0] = "You encounter a difficult question!";
                            break;
                    }
                    contentWindow = createContentHud(hudHeight, line, lines);

                    options = 1;
                    option[0] = "Next";
                    createOptionHud(hudHeight, option, options);
                }

                // If player chose to taunt
                else if (optionWindow.choice == 2) {
                    // If player taunt succeeds
                    if (playerSuccess >= 20) {
                        lines = 2;
                        switch(bossSelection) {
                            case 1:
                                line[0] = "You study even harder!";
                                line[1] = "Increasing your knowledge by 10";
                                break;
                            case 2:
                                line[0] = "You sidestepped the crowd";
                                line[1] = "Increasing your confidence by 5";
                                break;
                            case 3:
                                line[0] = "Jeff's character tries to attack!";
                                line[1] = "";
                                break;
                            case 4:
                                line[0] = "You encounter a difficult question!";
                                line[1] = "";
                                break;
                            case 5:
                                line[0] = "You encounter a difficult question!";
                                line[1] = "";
                                break;
                        }
                        player.damage += 10;
                        contentWindow = createContentHud(hudHeight, line, lines);

                    } else {
                        lines = 1;
                        line[0] = "You tried to study but gave up halfway";
                        contentWindow = createContentHud(hudHeight, line, lines);
                    }

                    options = 1;
                    option[0] = "Next";
                    createOptionHud(hudHeight, option, options);
                }

                // If boss taunt fails
            } else {
                lines = 1;
                switch(bossSelection) {
                    case 1:
                        line[0] = "You are unaffected by its taunt";
                        break;
                    case 2:
                        line[0] = "Your love for CMSC Club stays unphased";
                        break;
                    case 3:
                        line[0] = "Jeff's character tries to attack!";
                        break;
                    case 4:
                        line[0] = "You encounter a difficult question!";
                        break;
                    case 5:
                        line[0] = "You encounter a difficult question!";
                        break;
                }
                contentWindow = createContentHud(hudHeight, line, lines);

                options = 1;
                option[0] = "Next";
                createOptionHud(hudHeight, option, options);

                // If player chose to attack
                if (optionWindow.choice == 0) {
                    // If player attack succeeds
                    if (playerSuccess >= 30) {
                        lines = 1;
                        switch(bossSelection) {
                            case 1:
                                line[0] = "You manage to guess a correct answer! Hurting the ghost's pride";
                                break;
                            case 2:
                                line[0] = "You say a resounding NO! Hurting their feelings";
                                break;
                            case 3:
                                line[0] = "Jeff's character tries to attack!";
                                break;
                            case 4:
                                line[0] = "You encounter a difficult question!";
                                break;
                            case 5:
                                line[0] = "You encounter a difficult question!";
                                break;
                        }
                        boss.health -= player.damage;
                        enemyHudWindow = createEnemyHud(boss, hudHeight);
                        contentWindow = createContentHud(hudHeight, line, lines);
                    } else {
                        lines = 1;
                        switch(bossSelection) {
                            case 1:
                                line[0] = "Your guess was incorrect";
                                break;
                            case 2:
                                line[0] = "You tried to say no but stuttered instead";
                                break;
                            case 3:
                                line[0] = "Jeff's character tries to attack!";
                                break;
                            case 4:
                                line[0] = "You encounter a difficult question!";
                                break;
                            case 5:
                                line[0] = "You encounter a difficult question!";
                                break;
                        }
                        contentWindow = createContentHud(hudHeight, line, lines);
                    }

                    options = 1;
                    option[0] = "Next";
                    createOptionHud(hudHeight, option, options);
                }

                // If player chose to evade
                else if (optionWindow.choice == 1) {
                    lines = 1;
                    switch(bossSelection) {
                        case 1:
                            line[0] = "You manage to ignore the ghost";
                            break;
                        case 2:
                            line[0] = "You ignore all their desperate pleas";
                            break;
                        case 3:
                            line[0] = "Jeff's character tries to attack!";
                            break;
                        case 4:
                            line[0] = "You encounter a difficult question!";
                            break;
                        case 5:
                            line[0] = "You encounter a difficult question!";
                            break;
                    }
                    contentWindow = createContentHud(hudHeight, line, lines);

                    options = 1;
                    option[0] = "Next";
                    createOptionHud(hudHeight, option, options);
                }

                // If player chose to taunt
                else if (optionWindow.choice == 2) {
                    // If player taunt succeeds
                    if (playerSuccess >= 20) {
                        lines = 2;
                        switch(bossSelection) {
                            case 1:
                                line[0] = "You study and study and study";
                                line[1] = "Increasing your knowledge by 5";
                                break;
                            case 2:
                                line[0] = "You sidestepped the crowd";
                                line[1] = "Increasing your confidence by 5";
                                break;
                            case 3:
                                line[0] = "Jeff's character tries to attack!";
                                line[1] = "";
                                break;
                            case 4:
                                line[0] = "You encounter a difficult question!";
                                line[1] = "";
                                break;
                            case 5:
                                line[0] = "You encounter a difficult question!";
                                line[1] = "";
                                break;
                        }
                        player.damage += 5;
                        contentWindow = createContentHud(hudHeight, line, lines);

                    } else {
                        lines = 1;
                        switch(bossSelection) {
                            case 1:
                                line[0] = "You thought of studying, but never did";
                                break;
                            case 2:
                                line[0] = "You tried to sidestep but tripped instead";
                                break;
                            case 3:
                                line[0] = "Jeff's character tries to attack!";
                                break;
                            case 4:
                                line[0] = "You encounter a difficult question!";
                                break;
                            case 5:
                                line[0] = "You encounter a difficult question!";
                                break;
                        }
                        contentWindow = createContentHud(hudHeight, line, lines);
                    }

                    options = 1;
                    option[0] = "Next";
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