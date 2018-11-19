#include <stdio.h>
#include <string.h>
#include "hud.h"

int b1e1(){
  printf("You are in branch 1 event 1\n");

  //Setting Options
  char options[2][50];
  int numberOptions = 2;
  strcpy(options[0], "Option 1");
  strcpy(options[1], "Option 2");

  //Prints the options
  printMenu(options, numberOptions);

  int option;
  scanf("Please enter your choice: %i", &option);

  int nextRoom = 999;
  return nextRoom;
}