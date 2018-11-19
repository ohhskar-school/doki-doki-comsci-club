#include <stdio.h>
#include <string.h>
#include "gameInfo.h"
#include "hud.h"

struct gameInfo b1e1(struct gameInfo _eventInfo){
  printf("\nYou are in branch 1 event 1\n");

  //Setting Options
  char options[2][50];
  int numberOptions = 2;
  strcpy(options[0], "End Game");
  strcpy(options[1], "Add 1 Heart to A");

  //Prints the options
  printMenu(options, numberOptions);

  //Scans for the choice
  int option = 0;
  printf("Please enter your choice:\n> ");
  scanf("%i", &option);

  if (option == 1){
    _eventInfo.iPA += 100;
    _eventInfo.nextEvent = 999;
    _eventInfo.end = 1;
  } else {
    _eventInfo.nextEvent = 2;
    _eventInfo.iPA += 100;
  }

  return _eventInfo;
}

struct gameInfo b1e2(struct gameInfo _eventInfo){
  printf("\nYou are in branch 1 event 2\n");
  //Setting Options
  char options[2][50];
  int numberOptions = 2;
  strcpy(options[0], "End");
  strcpy(options[1], "Add 1 Heart to A");

  //Prints the options
  printMenu(options, numberOptions);

  //Scans for the choice
  int option = 0;
  printf("Please enter your choice:\n> ");
  scanf("%i", &option);

  if (option == 1){
    _eventInfo.iPA += 100;
    _eventInfo.nextEvent = 999;
    _eventInfo.end = 1;
  } else {
    _eventInfo.nextEvent = 2;
    _eventInfo.iPA += 100;
  }

  return _eventInfo;
}