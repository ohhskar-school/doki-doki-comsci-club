#include <stdlib.h>
#include <stdio.h>
#include "gameInfo.h"


void printLine(){
  for(int i = 0; i < 80; i++)
  {
    printf("=");
  }
  printf("\n");
}

void printHearts(int hearts){
  for(int i = 0; i < hearts; i++){
    printf("*");
  }
  printf(" ");
}

void printHUD(struct gameInfo _mainInfo){
  system("clear");
  printLine();
  printf("| Name: Oscar | Hearts: ");
  printHearts(_mainInfo.heartsA);
  printHearts(_mainInfo.heartsB);
  printHearts(_mainInfo.heartsC);
  printf("|\n");
  printLine();
}

void printMenu(char options[][50], int numberOptions){
  printf("\nYou have the following options:\n");
  for(int i = 0; i < numberOptions; i++)
  {
    printf("[%d] %s\n", i+1, options[i]);
  }
  printf("\n");
}