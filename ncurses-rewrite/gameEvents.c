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
  int options = 3;
  const char *option[options];
  option[0]="Start Game";
  option[1]="Exit Game";
  option[2]="Debug";

  createGameScreen(line, lines, option, options, _eventInfo);

  _eventInfo.nextEvent = 100000;
  return _eventInfo;
}