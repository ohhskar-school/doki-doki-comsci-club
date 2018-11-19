#include <stdlib.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <math.h>
#include<string.h>
#include "gameInfo.h"

struct winsize getSize(){
  struct winsize windowSize;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &windowSize);
  return windowSize;
}

void printCentered(int x, char * content){
  for(int i = 0; i < floor((x - strlen(content))/2) ; i++)
    {
      printf(" ");
    }
    printf("%s\n", content);
}

void printLine(){
  struct winsize windowSize = getSize();
  for(int i = 0; i < windowSize.ws_col; i++)
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
  printf("| Name: Oscar | Hearts: A: ");
  printHearts(_mainInfo.heartsA);
  printf("B: ");
  printHearts(_mainInfo.heartsB);
  printf("C: ");
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

void splashScreen(){
  struct winsize windowSize = getSize();
  int lines = 3;
  int y = windowSize.ws_row;
  int x = windowSize.ws_col;
  char line1[]="Welcome";
  char line2[]="to the";
  char line3[]="King of the Iron Fist Tournament";

  system("clear");
  for(int i = 0; i < floor((y/2)) - 1; i++)
  {HAHA 
    printf("\n");
  }
  printCentered(x,line1);
  printCentered(x,line2);
  printCentered(x,line3);
  sleep(3);
}