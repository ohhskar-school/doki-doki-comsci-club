#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
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
    player.health = 100;
    player.maxHealth = 100;

    //Selecting Boss Attributes
    switch (bossSelection) {
        case 1:
            player.damage = 20;
            boss.damage = 10;
            boss.health = 100;
            boss.maxHealth = 100;
            boss.skill = 30;
            boss.name = "Math Ghost";
            break;

        case 2:
            player.damage = 20;
            boss.damage = 10;
            boss.health = 100;
            boss.maxHealth = 100;
            boss.skill = 30;
            boss.name = "Club Recruiter Horde";
            break;
        case 3:
            player.damage = _battleInfo.interestPoints[0] * 0.85;
            boss.damage = 40;
            boss.health = 1000;
            boss.maxHealth = 1000;
            boss.skill = 5;
            boss.name = "Jeff's TECKEN Character";
            break;
        case 4:
            player.damage = _battleInfo.interestPoints[1] * 0.85;
            boss.damage = 10;
            boss.health = 100;
            boss.maxHealth = 100;
            boss.skill = 30;
            boss.name = "CMSC 11 Assignment";
            break;
        case 5:
            player.damage = _battleInfo.interestPoints[1] * 0.85;
            boss.damage = 10;
            boss.health = 100;
            boss.maxHealth = 100;
            boss.skill = 20;
            boss.name = "Mr. K's Pop Quiz";
            break;
        case 6:
            player.damage = _battleInfo.interestPoints[1] * 0.85;
            boss.damage = 10;
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

    // Creating Windows
    int hudHeight = 5;
    WINDOW *enemyHudWindow;
    WINDOW *playerHudWindow;
    WINDOW *contentWindow;
    optionReturn optionWindow;

    if (bossSelection == 6) {
        int lines = 1;
        char *line[lines];
        line[0] = "You approach Mr. K";

        int options = 1;
        char *option[options];
        option[0] = "Next";

        enemyHudWindow = createEnemyHud(boss, hudHeight);
        contentWindow = createContentHud(hudHeight, line, lines);
        playerHudWindow = createPlayerHud(player, hudHeight);
        optionWindow = createOptionHud(hudHeight, option, options);

        line[0] = "What do you want to do?";
        contentWindow = createContentHud(hudHeight, line, lines);

        options = 3;
        option[0] = "Ask Why";
        option[1] = "Ask Why";
        option[2] = "Ask Why";
        createOptionHud(hudHeight, option, options);

        line[0] = "Mr. K: Me and Jeff are actually together";
        contentWindow = createContentHud(hudHeight, line, lines);

        options = 1;
        option[0] = "Next";
        createOptionHud(hudHeight, option, options);

        line[0] = "It's a critical hit!";
        player.health = 0;
        playerHudWindow = createPlayerHud(player, hudHeight);
        contentWindow = createContentHud(hudHeight, line, lines);

        option[0] = "Next";
        createOptionHud(hudHeight, option, options);

        line[0] = "What do you want to do?";
        contentWindow = createContentHud(hudHeight, line, lines);

        option[0] = "Accept";
        createOptionHud(hudHeight, option, options);
    }

    //Main Battle Loop;
    while (boss.health > 0 && player.health > 0) {
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

        switch (bossSelection) {
            case 1:
                option[0] = "Guess";
                option[1] = "Ignore";
                option[2] = "Study";
                break;
            case 2:
                option[0] = "Say NO";
                option[1] = "Ignore";
                option[2] = "Plead";
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
        }

        enemyHudWindow = createEnemyHud(boss, hudHeight);
        contentWindow = createContentHud(hudHeight, line, lines);
        playerHudWindow = createPlayerHud(player, hudHeight);
        optionWindow = createOptionHud(hudHeight, option, options);

        // If boss attacks
        if (boss.move == 0) {
            lines = 1;
            switch (bossSelection) {
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
                    switch (bossSelection) {
                        case 1:
                            line[0] = "You get confused! Hurting your brain in the process";
                            break;
                        case 2:
                            line[0] = "They try to swarm you! Hurting you in the process";
                            break;
                        case 3:
                            line[0] = "He lands a hit!";
                            break;
                        case 4:
                            line[0] = "You're stunned!";
                            break;
                        case 5:
                            line[0] = "You're stunned!";
                            break;
                    }
                    if (player.health >= boss.damage) {
                        player.health -= boss.damage;
                    } else {
                        player.health = 0;
                    }
                    playerHudWindow = createPlayerHud(player, hudHeight);
                    contentWindow = createContentHud(hudHeight, line, lines);

                    options = 1;
                    option[0] = "Next";
                    createOptionHud(hudHeight, option, options);

                    // If player attack succeeds
                    if (playerSuccess >= 30) {
                        lines = 1;
                        switch (bossSelection) {
                            case 1:
                                line[0] = "You try and guess, and succeed! You hurt the ghost's pride";
                                break;
                            case 2:
                                line[0] = "You say a resounding NO! Hurting their feelings";
                                break;
                            case 3:
                                line[0] = "You furiously button mash and manage to land a hit yourself!";
                                break;
                            case 4:
                                line[0] = "You manage to solve it anyway!";
                                break;
                            case 5:
                                line[0] = "You manage to solve it anyway!";
                                break;
                        }
                        if (boss.health >= player.damage) {
                            boss.health -= player.damage;
                        } else {
                            boss.health = 0;
                        }
                        enemyHudWindow = createEnemyHud(boss, hudHeight);
                        contentWindow = createContentHud(hudHeight, line, lines);
                    } else {
                        lines = 1;
                        switch (bossSelection) {
                            case 1:
                                line[0] = "You try and guess anyway but guessed the wrong answer!";
                                break;
                            case 2:
                                line[0] = "You try to say no but are overpowered by their number";
                                break;
                            case 3:
                                line[0] = "Your furious button mashing wasn't able to hit him at all";
                                break;
                            case 4:
                                line[0] = "Your attempt at solving it is unsuccessful";
                                break;
                            case 5:
                                line[0] = "Your attempt at solving it is unsuccessful";
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
                        switch (bossSelection) {
                            case 1:
                                line[0] = "You manage to ignore the math question!";
                                break;
                            case 2:
                                line[0] = "You manage to ignore their desperate pleas";
                                break;
                            case 3:
                                line[0] = "You manage to jump away from his attack!";
                                break;
                            case 4:
                                line[0] = "You manage to skip it! Saving yourself from disappointment";
                                break;
                            case 5:
                                line[0] = "You manage to skip it! Saving yourself from disappointment";
                                break;
                        }
                        contentWindow = createContentHud(hudHeight, line, lines);
                    } else {
                        lines = 1;
                        switch (bossSelection) {
                            case 1:
                                line[0] = "You tried ignoring, but were unsuccessful";
                                break;
                            case 2:
                                line[0] = "You tried ignoring them, but got more annoyed instead";
                                break;
                            case 3:
                                line[0] = "You tried to get away but ran into his attack instead";
                                break;
                            case 4:
                                line[0] = "You tried to skip the question but it keeps bothering you";
                                break;
                            case 5:
                                line[0] = "You tried to skip the question but it keeps bothering you";
                                break;
                        }
                        if (player.health >= boss.damage) {
                            player.health -= boss.damage;
                        } else {
                            player.health = 0;
                        }
                        playerHudWindow = createEnemyHud(boss, hudHeight);
                        contentWindow = createContentHud(hudHeight, line, lines);
                    }

                    options = 1;
                    option[0] = "Next";
                    createOptionHud(hudHeight, option, options);
                }

                // If player chose to taunt
                else if (optionWindow.choice == 2) {
                    lines = 1;
                    switch (bossSelection) {
                        case 1:
                            line[0] = "You get confused! Hurting your brain in the process";
                            break;
                        case 2:
                            line[0] = "They try to swarm you! Hurting you in the process";
                            break;
                        case 3:
                            line[0] = "He lands a hit!";
                            break;
                        case 4:
                            line[0] = "You're stunned!";
                            break;
                        case 5:
                            line[0] = "You're stunned!";
                            break;
                    }
                    if (player.health >= boss.damage) {
                        player.health -= boss.damage;
                    } else {
                        player.health = 0;
                    }
                    playerHudWindow = createPlayerHud(player, hudHeight);
                    contentWindow = createContentHud(hudHeight, line, lines);

                    options = 1;
                    option[0] = "Next";
                    createOptionHud(hudHeight, option, options);

                    // If player taunt succeeds
                    if (playerSuccess >= 20) {
                        lines = 3;
                        switch (bossSelection) {
                            case 1:
                                line[0] = "You study in order to solve the next equation";
                                line[1] = "";
                                line[2] = "Increasing your knowledge by 5";
                                break;
                            case 2:
                                lines = 4;
                                line[0] = "You start yelling:";
                                line[1] = "\"Everyone! I have an announcement to make, stop bullying!\"";
                                line[2] = "";
                                line[3] = "Your ability to convince people has increased by 5";
                                break;
                            case 3:
                                line[0] = "You talk trash to Jeff!";
                                line[1] = "";
                                line[2] = "Increasing your skill by 5";
                                break;
                            case 4:
                                line[0] = "You go on Google and do some research on your topic";
                                line[1] = "";
                                line[2] = "Increasing your knowledge by 5";
                                break;
                            case 5:
                                line[0] = "You pray to God, hoping that you could answer the next question";
                                line[1] = "";
                                line[2] = "Restoring faith in yourself by 5";
                                break;
                        }
                        player.damage += 5;
                        contentWindow = createContentHud(hudHeight, line, lines);

                    } else {
                        lines = 1;
                        switch (bossSelection) {
                            case 1:
                                line[0] = "You tried studying but procrastinated instead";
                                break;
                            case 2:
                                line[0] = "You tried pleading but got interrupted by one of them instead";
                                break;
                            case 3:
                                line[0] = "You tried to talk trash but Jeff is amused at your attempt";
                                break;
                            case 4:
                                line[0] = "You tried to pray but broke down instead";
                                break;
                            case 5:
                                line[0] = "You tried to pray but broke down instead";
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
                switch (bossSelection) {
                    case 1:
                        line[0] = "It failed to confuse you!";
                        break;
                    case 2:
                        line[0] = "They fail to convince you!";
                        break;
                    case 3:
                        line[0] = "He missed!";
                        break;
                    case 4:
                        line[0] = "You read the question and it turns out it isn't that hard";
                        break;
                    case 5:
                        line[0] = "You read the question and it turns out it isn't that hard";
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
                        switch (bossSelection) {
                            case 1:
                                line[0] = "You manage to guess the answer to his math problem! Hurting the ghost's pride";
                                break;
                            case 2:
                                line[0] = "You say a resounding NO! Hurting their feelings";
                                break;
                            case 3:
                                line[0] = "You button mash furiously and manage to land a hit!";
                                break;
                            case 4:
                                line[0] = "You successfully answer the question!";
                                break;
                            case 5:
                                line[0] = "You successfully answer the question!";
                                break;
                        }
                        if (boss.health >= player.damage) {
                            boss.health -= player.damage;
                        } else {
                            boss.health = 0;
                        }
                        enemyHudWindow = createEnemyHud(boss, hudHeight);
                        contentWindow = createContentHud(hudHeight, line, lines);
                    } else {
                        lines = 1;
                        switch (bossSelection) {
                            case 1:
                                line[0] = "You tried guessing, but failed miserably";
                                break;
                            case 2:
                                line[0] = "You try to say no but are overpowered by their number";
                                break;
                            case 3:
                                line[0] = "Your button mashing gets you nowhere";
                                break;
                            case 4:
                                line[0] = "You write something on your paper but you aren't sure if it's right";
                                break;
                            case 5:
                                line[0] = "You write something on your paper but you aren't sure if it's right";
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
                    switch (bossSelection) {
                        case 1:
                            line[0] = "You ignore the ghost's attempt at confusing you";
                            break;
                        case 2:
                            line[0] = "You manage to ignore their desperate pleas";
                            break;
                        case 3:
                            line[0] = "You manage to get away from him";
                            break;
                        case 4:
                            line[0] = "You manage to skip the question!";
                            break;
                        case 5:
                            line[0] = "You manage to skip the question!";
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
                        lines = 3;
                        switch (bossSelection) {
                            case 1:
                                line[0] = "You study in order to solve the next equation";
                                line[1] = "";
                                line[2] = "Increasing your knowledge by 5";
                                break;
                            case 2:
                                lines = 4;
                                line[0] = "You start yelling:";
                                line[1] = "\"Everyone! I have an announcement to make, stop bullying!\"";
                                line[2] = "";
                                line[3] = "Your ability to convince people has increased by 5";
                                break;
                            case 3:
                                line[0] = "You talk trash to Jeff!";
                                line[1] = "";
                                line[2] = "Increasing your skill by 5";
                                break;
                            case 4:
                                line[0] = "You pray to God that you could answer the next question";
                                line[1] = "";
                                line[2] = "Increasing your faith in yourself by 5";
                                break;
                            case 5:
                                line[0] = "You pray to God that you could answer the next question";
                                line[1] = "";
                                line[2] = "Increasing your faith in yourself by 5";
                                break;
                        }
                        player.damage += 5;
                        contentWindow = createContentHud(hudHeight, line, lines);

                    } else {
                        lines = 1;
                        switch (bossSelection) {
                            case 1:
                                line[0] = "You tried to study, but procrastinated instead";
                                break;
                            case 2:
                                line[0] = "You tried sidestepping but tripped instead";
                                break;
                            case 3:
                                line[0] = "You tried to talk trash but stuttered instead";
                                break;
                            case 4:
                                line[0] = "You try to pray but broke down instead";
                                break;
                            case 5:
                                line[0] = "You try to pray but broke down instead";
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
            switch (bossSelection) {
                case 1:
                    line[0] = "The ghost tries to disappear";
                    break;
                case 2:
                    line[0] = "All of them start talking at once";
                    break;
                case 3:
                    line[0] = "Jeff's character tries to roll away";
                    break;
                case 4:
                    line[0] = "You notice that you haven't been following instructions";
                    break;
                case 5:
                    line[0] = "You notice that you haven't been following instructions";
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
                    switch (bossSelection) {
                        case 1:
                            line[0] = "You try to guess but you can't see him!";
                            break;
                        case 2:
                            line[0] = "They can't hear a word you're saying";
                            break;
                        case 3:
                            line[0] = "He manages to get away from your character!";
                            break;
                        case 4:
                            line[0] = "You start contemplating on all your life decisions that led to this point";
                            break;
                        case 5:
                            line[0] = "You start contemplating on all your life decisions that led to this point";
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
                    switch (bossSelection) {
                        case 1:
                            line[0] = "You ignored his disappearing act";
                            break;
                        case 2:
                            line[0] = "You manage to ignore their presence";
                            break;
                        case 3:
                            line[0] = "You get away as well in case of an attack";
                            break;
                        case 4:
                            line[0] = "You skip it and tell yourself that you're gonna deal with it later!";
                            break;
                        case 5:
                            line[0] = "You skip it and tell yourself that you're gonna deal with it later!";
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
                        lines = 3;
                        switch (bossSelection) {
                            case 1:
                                line[0] = "You study for his next attack";
                                line[1] = "";
                                line[2] = "Increasing your knowledge by 5";
                                break;
                            case 2:
                                lines = 4;
                                line[0] = "You start yelling:";
                                line[1] = "\"Everyone! I have an announcement to make, stop bullying!\"";
                                line[2] = "";
                                line[3] = "Your ability to convince people has increased by 5";
                                break;
                            case 3:
                                line[0] = "You talk trash to Jeff!";
                                line[1] = "";
                                line[2] = "Increasing your skill by 5";
                                break;
                            case 4:
                                line[0] = "You recite a little prayer";
                                line[1] = "";
                                line[2] = "Restoring faith in yourself by 5";
                                break;
                            case 5:
                                line[0] = "You recite a little prayer";
                                line[1] = "";
                                line[2] = "Restoring faith in yourself by 5";
                                break;
                        }
                        player.damage += 5;
                        contentWindow = createContentHud(hudHeight, line, lines);

                    } else {
                        lines = 1;
                        switch (bossSelection) {
                            case 1:
                                line[0] = "You tried studying but got bored";
                                break;
                            case 2:
                                line[0] = "You tried to plead but forgot what to say";
                                break;
                            case 3:
                                line[0] = "You tried to talk trash but your insults were too soft!";
                                break;
                            case 4:
                                line[0] = "You tried praying but have an existential crisis instead";
                                break;
                            case 5:
                                line[0] = "You tried praying but have an existential crisis instead";
                                break;
                        }
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
                        switch (bossSelection) {
                            case 1:
                                line[0] = "You still manage to guess his problem!";
                                break;
                            case 2:
                                line[0] = "You shout a loud NO into the crowd! Shutting them up for a while";
                                break;
                            case 3:
                                line[0] = "You button mash and manage to get one in!";
                                break;
                            case 4:
                                line[0] = "You don't let it discourage you and immediately start rewriting your answers";
                                break;
                            case 5:
                                line[0] = "You don't let it discourage you and immediately start rewriting your answers";
                                break;
                        }
                        if (boss.health >= player.damage) {
                            boss.health -= player.damage;
                        } else {
                            boss.health = 0;
                        }
                        enemyHudWindow = createEnemyHud(boss, hudHeight);
                        contentWindow = createContentHud(hudHeight, line, lines);
                    } else {
                        lines = 1;
                        switch (bossSelection) {
                            case 1:
                                line[0] = "You try to guess but can't see it!";
                                break;
                            case 2:
                                line[0] = "The sound of your NO gets drowned by all of their voices";
                                break;
                            case 3:
                                line[0] = "Your button mashing is a lost cause";
                                break;
                            case 4:
                                line[0] = "You start to contemplate on all your life decisions that led to this point";
                                break;
                            case 5:
                                line[0] = "You start to contemplate on all your life decisions that led to this point";
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
                    switch (bossSelection) {
                        case 1:
                            line[0] = "You ignore his disappearing act";
                            break;
                        case 2:
                            line[0] = "You manage to ignore their presence entirely";
                            break;
                        case 3:
                            line[0] = "You jump away in anticipation of an attack";
                            break;
                        case 4:
                            line[0] = "You skip and hope that you could answer it later";
                            break;
                        case 5:
                            line[0] = "You skip and hope that you could answer it later";
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
                        lines = 3;
                        switch (bossSelection) {
                            case 1:
                                line[0] = "You study for its next attack";
                                line[1] = "";
                                line[2] = "Increasing your knowledge by 5";
                                break;
                            case 2:
                                lines = 4;
                                line[0] = "You start yelling:";
                                line[1] = "\"Everyone! I have an announcement to make, stop bullying!\"";
                                line[2] = "";
                                line[3] = "Your ability to convince people has increased by 5";
                                break;
                            case 3:
                                line[0] = "You talk trash to Jeff";
                                line[1] = "";
                                line[2] = "Increasing your skill by 5";
                                break;
                            case 4:
                                line[0] = "You start praying, hoping for a miracle";
                                line[1] = "";
                                line[2] = "Restoring faith in yourself by 5";
                                break;
                            case 5:
                                line[0] = "You start praying, hoping for a miracle";
                                line[1] = "";
                                line[2] = "Restoring faith in yourself by 5";
                                break;
                        }
                        player.damage += 5;
                        contentWindow = createContentHud(hudHeight, line, lines);

                    } else {
                        lines = 1;
                        switch (bossSelection) {
                            case 1:
                                line[0] = "You try to study but get bored immediately";
                                break;
                            case 2:
                                line[0] = "You tried to plead but forgot what to say";
                                break;
                            case 3:
                                line[0] = "You trash talk horribly, causing Jeff to laugh at you";
                                break;
                            case 4:
                                line[0] = "You start praying but fell asleep halfway";
                                break;
                            case 5:
                                line[0] = "You start praying but fell asleep halfway";
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
            switch (bossSelection) {
                case 1:
                    line[0] = "The ghost taunts you with a 5.00";
                    break;
                case 2:
                    line[0] = "They try and discourage you from the CMSC Club!";
                    break;
                case 3:
                    line[0] = "Jeff starts talking trash";
                    break;
                case 4:
                    line[0] = "You read a question for a topic you didn't study for";
                    break;
                case 5:
                    line[0] = "You read a question for a topic you didn't study for";
                    break;
            }
            contentWindow = createContentHud(hudHeight, line, lines);

            options = 1;
            option[0] = "Next";
            createOptionHud(hudHeight, option, options);

            // If taunt succeeds
            if (bossSuccess >= boss.skill) {
                lines = 3;
                switch (bossSelection) {
                    case 1:
                        line[0] = "Your anxiety kicks in and makes you think about your grades";
                        line[1] = "";
                        line[2] = "Decreasing your knowledge by 5";
                        break;
                    case 2:
                        lines = 3;
                        line[0] = "You start to doubt your loyalty for CMSC Club";
                        line[1] = "";
                        line[2] = "Decreasing your ability to convince by 5";
                        break;
                    case 3:
                        line[0] = "His words hurt your feelings";
                        line[1] = "";
                        line[2] = "Decreasing your skill by 5";
                        break;
                    case 4:
                        line[0] = "You get discouraged and start to lose hope";
                        line[1] = "";
                        line[2] = "Losing faith in yourself by 5";
                        break;
                    case 5:
                        line[0] = "You get discouraged and start to lose hope";
                        line[1] = "";
                        line[2] = "Losing faith in yourself by 5";
                        break;
                }
                if (player.damage > 10) {
                    player.damage -= 5;
                } else {
                    player.damage = 10;
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
                        switch (bossSelection) {
                            case 1:
                                line[0] = "You still manage to guess the answer!";
                                break;
                            case 2:
                                line[0] = "You still manage to say a resounding NO! Hurting their feelings";
                                break;
                            case 3:
                                line[0] = "You button mash as hard as you can and manage to land some hits!";
                                break;
                            case 4:
                                line[0] = "You manage to get a few answers in!";
                                break;
                            case 5:
                                line[0] = "You manage to get a few answers in!";
                                break;
                        }
                        if (boss.health >= player.damage) {
                            boss.health -= player.damage;
                        } else {
                            boss.health = 0;
                        }
                        enemyHudWindow = createEnemyHud(boss, hudHeight);
                        contentWindow = createContentHud(hudHeight, line, lines);
                    } else {
                        lines = 1;
                        switch (bossSelection) {
                            case 1:
                                line[0] = "You fail to guess the answer";
                                break;
                            case 2:
                                line[0] = "You can't hear yourself over the sound of their pleas";
                                break;
                            case 3:
                                line[0] = "Your button mashing was unsuccessful";
                                break;
                            case 4:
                                line[0] = "You tried answering but ended up guessing instead";
                                break;
                            case 5:
                                line[0] = "You tried answering but ended up guessing instead";
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
                    switch (bossSelection) {
                        case 1:
                            line[0] = "You ignore your anxiety";
                            break;
                        case 2:
                            line[0] = "You ignore their desperate pleas";
                            break;
                        case 3:
                            line[0] = "You roll away from Jeff's character";
                            break;
                        case 4:
                            line[0] = "You skip the question in hopes of answering it later";
                            break;
                        case 5:
                            line[0] = "You skip the question in hopes of answering it later";
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
                        lines = 3;
                        switch (bossSelection) {
                            case 1:
                                line[0] = "You study even harder!";
                                line[1] = "";
                                line[2] = "Increasing your knowledge by 10";
                                break;
                            case 2:
                                lines = 4;
                                line[0] = "You start yelling:";
                                line[1] = "\"Everyone! I have an announcement to make, stop bullying!\"";
                                line[2] = "";
                                line[3] = "Your ability to convince people has increased by 5";
                                break;
                            case 3:
                                line[0] = "You insult Jeff's mom";
                                line[1] = "";
                                line[2] = "Increasing your skill by 10";
                                break;
                            case 4:
                                line[0] = "You pray a heartfelt prayer";
                                line[1] = "";
                                line[2] = "Restoring faith in yourself by 10";
                                break;
                            case 5:
                                line[0] = "You pray a heartfelt prayer";
                                line[1] = "";
                                line[2] = "Restoring faith in yourself by 10";
                                break;
                        }
                        player.damage += 10;
                        contentWindow = createContentHud(hudHeight, line, lines);

                    } else {
                        lines = 1;
                        switch (bossSelection) {
                            case 1:
                                line[0] = "You tried studying but gave up halfway";
                                break;
                            case 2:
                                line[0] = "You tried to plead but got interrupted by one of them";
                                break;
                            case 3:
                                line[0] = "You couldn't keep a straight face while insulting him, causing Jeff to laugh";
                                break;
                            case 4:
                                line[0] = "You tried to pray but slept halfway instead";
                                break;
                            case 5:
                                line[0] = "You tried to pray but slept halfway instead";
                                break;
                        }
                        contentWindow = createContentHud(hudHeight, line, lines);
                    }

                    options = 1;
                    option[0] = "Next";
                    createOptionHud(hudHeight, option, options);
                }

                // If boss taunt fails
            } else {
                lines = 1;
                switch (bossSelection) {
                    case 1:
                        line[0] = "You are unaffected by its taunt";
                        break;
                    case 2:
                        line[0] = "Your love for CMSC Club stays unphased";
                        break;
                    case 3:
                        line[0] = "His trash talk wasn't good enough to affect you";
                        break;
                    case 4:
                        line[0] = "You don't let it discourage you!";
                        break;
                    case 5:
                        line[0] = "You don't let it discourage you!";
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
                        switch (bossSelection) {
                            case 1:
                                line[0] = "You manage to guess a correct answer! Hurting the ghost's pride";
                                break;
                            case 2:
                                line[0] = "You say a resounding NO! Hurting their feelings";
                                break;
                            case 3:
                                line[0] = "Your button mashing was a success! You hit him multiple times";
                                break;
                            case 4:
                                line[0] = "You manage to answer the difficult question!";
                                break;
                            case 5:
                                line[0] = "You manage to answer the difficult question!";
                                break;
                        }
                        if (boss.health >= player.damage) {
                            boss.health -= player.damage;
                        } else {
                            boss.health = 0;
                        }
                        enemyHudWindow = createEnemyHud(boss, hudHeight);
                        contentWindow = createContentHud(hudHeight, line, lines);
                    } else {
                        lines = 1;
                        switch (bossSelection) {
                            case 1:
                                line[0] = "Your guess was incorrect";
                                break;
                            case 2:
                                line[0] = "You tried to say no but stuttered instead";
                                break;
                            case 3:
                                line[0] = "Your button mashing gets you nowhere";
                                break;
                            case 4:
                                line[0] = "You tried to answer but ended up guessing instead";
                                break;
                            case 5:
                                line[0] = "You tried to answer but ended up guessing instead";
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
                    switch (bossSelection) {
                        case 1:
                            line[0] = "You manage to ignore the ghost";
                            break;
                        case 2:
                            line[0] = "You ignore all their desperate pleas";
                            break;
                        case 3:
                            line[0] = "You successfully roll away";
                            break;
                        case 4:
                            line[0] = "You stopped caring about your grades and skipped the question with no regard for human life";
                            break;
                        case 5:
                            line[0] = "You stopped caring about your grades and skipped the question with no regard for human life";
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
                        lines = 3;
                        switch (bossSelection) {
                            case 1:
                                line[0] = "You study and study and study";
                                line[1] = "";
                                line[2] = "Increasing your knowledge by 5";
                                break;
                            case 2:
                                lines = 4;
                                line[0] = "You start yelling:";
                                line[1] = "\"Everyone! I have an announcement to make, stop bullying!\"";
                                line[2] = "";
                                line[3] = "Your ability to convince people has increased by 5";
                                break;
                            case 3:
                                line[0] = "You tell Jeff that he sucks!";
                                line[1] = "";
                                line[2] = "Increasing your skill by 5";
                                break;
                            case 4:
                                line[0] = "You start reciting all the prayers you know";
                                line[1] = "";
                                line[2] = "Restoring faith in yourself by 5";
                                break;
                            case 5:
                                line[0] = "You start reciting all the prayers you know";
                                line[1] = "";
                                line[2] = "Restoring faith in yourself by 5";
                                break;
                        }
                        player.damage += 5;
                        contentWindow = createContentHud(hudHeight, line, lines);

                    } else {
                        lines = 1;
                        switch (bossSelection) {
                            case 1:
                                line[0] = "You thought of studying, but never did";
                                break;
                            case 2:
                                line[0] = "You tried to plead but got interrupted by one of them";
                                break;
                            case 3:
                                line[0] = "You fail to insult Jeff";
                                break;
                            case 4:
                                line[0] = "You start praying but forgot what to say halfway";
                                break;
                            case 5:
                                line[0] = "You start praying but forgot what to say halfway";
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