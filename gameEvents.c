#include <stdio.h>
#include <string.h>
#include "gameInfo.h"
#include "hud.h"


gameInfo mainMenu(gameInfo _eventInfo){
  int lines = 7;
  const char *line[lines];
  line[0] = "Line 1";
  line[1] = "Line 2";
  line[2] = "";
  line[3] = "Line 4";
  line[4] = "Line 5";
  line[5] = "Line 6";
  line[6] = "";


  //Setting Options
  int options = 5;
  const char *option[options];
  option[0]="Start Game";
  option[1]="Exit Game";
  option[2]="Debug";
  option[3]="Debug";
  option[4]="Debug";

  int choice = createGameScreen(line, lines, option, options, _eventInfo);
  
  switch(choice){
    case 1:
      _eventInfo.nextEvent = 10;
      _eventInfo.end = 1;
      break;
    case 2:
      _eventInfo.nextEvent = 100000;
      _eventInfo.end = 1;
      break;
    case 3:
    default:
      _eventInfo.errorCode = 2;
      _eventInfo.end = 1;
  }
  
  return _eventInfo;
}

gameInfo dayOne(gameInfo _eventInfo){
  int lines = 
  const char  *line[lines];

  line[0] = "Welcome to P University, the premier university in the country!"
  line[1] = "";
  line[2] = "It's your first day as a BS Computer Science major and oh no! You're running late!"
  line[3] = "Quick get into your classroom!"
}