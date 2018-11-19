#include <stdio.h>
#include <string.h>
#include "gameInfo.h"
#include "hud.h"

struct gameInfo b1e1(struct gameInfo _eventInfo){
  printf("You are in branch 1 event 1\n");

  //Setting Options
  char options[2][50];
  int numberOptions = 2;
  strcpy(options[0], "Option 1");
  strcpy(options[1], "Option 2");

  //Prints the options
  printMenu(options, numberOptions);

  //Scans for the choice
  int option;
  scanf("Please enter your choice: %i", &option);
  printLine();

  if (option == 1){
    _eventInfo.iPA += 100;
    _eventInfo.nextEvent = 999;
  } else {
    _eventInfo.nextEvent = 1;
  }

  return _eventInfo;
}