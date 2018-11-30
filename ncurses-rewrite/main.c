#include "gameInfo.h"
#include "eventSwitcher.h"
#include "hud.h"
#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>


/*
 * Just run make to compile the files. The makefile compiles the file with 
 * the flags -lncurses and -lm to compile with ncurses and math support.
*/

//takes care of the data between the main function and the events
gameInfo gameEngine(gameInfo _mainInfo){

  //Initialize event variables
  gameInfo branchInfo;
  branchInfo = _mainInfo;
  branchInfo.end = 0;
  branchInfo.errorCode = 0;

  /*  
  *   Loops until a branch has ended. branchInfo.end signifies that a branch 
  *   has ended and a checkpoint has been reached. A checkpoint means that
  *  a day has passed.
  */

  while (branchInfo.end == 0 && branchInfo.errorCode == 0){
    branchInfo = eventSwitcher(branchInfo);
  }
  
  _mainInfo = branchInfo; //Finalizes data from the branch
  _mainInfo.day++;

  //End the game if next day == 100000
  if(branchInfo.nextEvent == 100000){
    _mainInfo.end = 1;
  } else {
    _mainInfo.end = 0;
  }

  return _mainInfo;
}

int main()
{
  //Initializing Variables;
  gameInfo mainInfo;
  mainInfo.end = 0;
  mainInfo.errorCode = 0;
  mainInfo.nextEvent = 0;
  for(int i = 0; i < 3; i++){
    mainInfo.hearts[i] = 0;
  }
  for(int i = 0; i < 3; i++){
    mainInfo.interestPoints[i] = 200;
  }
  mainInfo.day = 1;

  //Initialize ncurses
  initializeNcurses();
  initializeColors();

  //Present Splash Screen
  presentsScreen(); 
  splashScreen();

  //Main Game Loop
  while (mainInfo.end == 0 || mainInfo.errorCode == 0){
    mainInfo = gameEngine(mainInfo);
  }

  //Cleanup
  clear();
  refresh();
  endwin();

  if (mainInfo.errorCode != 0){
    clear();
    printw("Error %i has occured!", mainInfo.errorCode);
    refresh();
    sleep(10);
  }

  return 0;
}
