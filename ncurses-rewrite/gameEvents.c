#include <stdio.h>
#include <string.h>
#include "gameInfo.h"
#include "hud.h"


gameInfo mainMenu(gameInfo _eventInfo){
  int lines = 1;
  const char *line[lines];
  line[0] = "Main Menu";

  //Setting Options
  int options = 3;
  const char *option[options];
  option[0]="Start Game";
  option[1]="Exit Game";
  option[2]="Debug";

  createGameScreen(line, lines, option, options, _eventInfo);

  return _eventInfo;
}