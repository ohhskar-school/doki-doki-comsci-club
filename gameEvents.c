#include <stdio.h>
#include <string.h>
#include "gameInfo.h"
#include "hud.h"

struct gameInfo mainMenu(struct gameInfo _eventInfo){
  printf("\nMain Menu\n");

  //Setting Options
  char options[3][50];
  int numberOptions = 3;
  strcpy(options[0], "Talk");
  strcpy(options[1], "Quest");
  strcpy(options[2], "Exit Game");
  //Prints the options
  printMenu(options, numberOptions);
  
  //Scans for the choice
  int optionLoopEnd = 0;
  int option = 0;
  while (optionLoopEnd == 0){

    printf("\nPlease enter your choice:\n> ");
    scanf("%i", &option);

    if (option == 1){
      _eventInfo.nextEvent = 10; // talkMenu
      _eventInfo.end = 1;
      optionLoopEnd = 1;
    }
    else if (option == 2){
      _eventInfo.nextEvent = 20; // questMenu
      _eventInfo.end = 1;
      optionLoopEnd = 1;
    }
    else if (option == 3){
      _eventInfo.nextEvent = 100000; // exitGame
      _eventInfo.end = 1;
      optionLoopEnd = 1;
    }
    else {
      option = 0;
      printError();
      printHUD(_eventInfo);
      printMenu(options, numberOptions);
    }
  }

  return _eventInfo;
}

struct gameInfo talkMenu(struct gameInfo _eventInfo){
  printf("\nWho do you want to talk to?\n");
  //Setting Options
  char options[3][50];
  int numberOptions = 3;
  strcpy(options[0], "A");
  strcpy(options[1], "B");
  strcpy(options[2], "C");

  //Prints the options
  printMenu(options, numberOptions);

  //Scans for the choiceu
  int optionLoopEnd = 0;
  int option = 0;
  while (optionLoopEnd == 0){

    printf("\nPlease enter your choice:\n> ");
    scanf("%i", &option);

    if (option == 1){
      _eventInfo.nextEvent = 11; // talkWithA
      _eventInfo.end = 1;
      optionLoopEnd = 1;
    }
    else if (option == 2){
      _eventInfo.nextEvent = 12; // talkWithB
      _eventInfo.end = 1;
      optionLoopEnd = 1;
    }
    else if (option == 2){
      _eventInfo.nextEvent = 13; // talkWithC
      _eventInfo.end = 1;
      optionLoopEnd = 1;
    }
    else {
      option = 0;
      printError();
      printHUD(_eventInfo);
      printMenu(options, numberOptions);
    }
  }

  return _eventInfo;
}

/* nextEvent code guides 
* 0 = Main Menu
* 10 = Talk
* 11 = Talk with A
* 12 = Talk with B
* 13 = Talk with C
* 20 = Quest Menu
* 100000 = Exit Game
*/