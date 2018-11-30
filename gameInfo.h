#ifndef GAMEINFO_H
#define GAMEINFO_H
#include <ncurses.h>

typedef struct{
  int end, nextEvent, errorCode;
  int interestPoints[3];
  int hearts[3];
  int day;
} gameInfo;

typedef struct{
  int choice;
  WINDOW *optionWindow;
} optionReturn;

#endif