#ifndef GAMEINFO_H
#define GAMEINFO_H
#include <ncurses.h>

typedef struct {
    int end, nextEvent, errorCode;
    int interestPoints[3];
    int hearts[3];
} gameInfo;

typedef struct {
    int choice;
    WINDOW* optionWindow;
} optionReturn;

typedef struct {
    int damage;
    int health;
    int maxHealth;
    int move;
    int skill;
    char* name;
} bossStruct;

typedef struct {
    int damage;
    int health;
    int maxHealth;
} playerStruct;

#endif