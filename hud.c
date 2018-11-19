#include <stdlib.h>

void printLine(){
  for(int i = 0; i < 80; i++)
  {
    printf("=");
  }
  printf("\n");
} 

void printHUD(int * hearts){
  system("clear");
  printLine();
  printf("| Name: Oscar | Hearts: ");
  for(int i = 0; i < 3; i++)
  {
    if (i == 0){
      printf("A: ");
    } else if (i == 1){
      printf("B: ");
    } else if (i == 2){
      printf("C: ");
    }
    for(int j = 0; j < hearts[i]; j++)
    {
      printf("*");
    }
    printf(" ");
  }
  printf("|\n");
  printLine();
}

int printMenu(char options[][50]){
  printf("\nYou have the following options:\n");
  for(int i = 0; i < sizeof(options); i++)
  {
    printf("[%d] %s\n", i+1, options[i]);
  }
  printLine();
}