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
  for(int i = 0; i < (floor((x - strlen(content))/2) - 1) ; i++)
    {
      printf(" ");
    }
    printf("%s\n", content);
}

void printPadding(int y, int lines){
  for(int i = 0; i < floor(((y-lines)/2)) - 1; i++){
    printf("\n");
  }
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
  for(int i = 100; i < hearts; i++){
    printf("*");
  }
  printf(" ");
}

void printHUD(gameInfo _mainInfo){
  system("clear");
  printLine();
  printf("| Hearts: A: ");
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

void printError(){
  struct winsize windowSize = getSize();
  int y = windowSize.ws_row;
  int x = windowSize.ws_col;
  int lines = 1;
  char line1[] = "You have entered an invalid option";
  system("clear");
  printPadding(y, lines);
  printCentered(x, line1);
  sleep(2);
}

void splashScreen(){
  struct winsize windowSize = getSize();
  int y = windowSize.ws_row;
  int x = windowSize.ws_col;
  int lines = 8;
  char line1[]="  ___   ___  _  _____   ___   ___  _  _____ ";
  char line2[]=" |   \\ / _ \\| |/ /_ _| |   \\ / _ \\| |/ /_ _|";
  char line3[]=" | |) | (_) | ' < | |  | |) | (_) | ' < | | ";
  char line4[]=" |___/ \\___/|_|\\_\\___| |___/_\\___/|_|\\_\\___|";
  char line5[]="  / __|  \\/  / __|/ __|  / __| | | | | | _ )";
  char line6[]=" | (__| |\\/| \\__ \\ (__  | (__| |_| |_| | _ \\";
  char line7[]="  \\___|_|  |_|___/\\___|  \\___|____\\___/|___/";

  system("clear");
  printPadding(y, lines);
  printCentered(x,line1);
  printCentered(x,line2);
  printCentered(x,line3);
  printCentered(x,line4);
  printCentered(x,line5);
  printCentered(x,line6);
  printCentered(x,line7);
  printPadding(y, lines);
  sleep(2);
}