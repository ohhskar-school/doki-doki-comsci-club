#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//Custom Includes
#include "gameEvents.c"
#include "hud.h"

//Global Variables
int interestPoints[3] = {100,100,100};
int hearts[3];

//Creates a struct to store a game info after each event
struct gameInfo {
  int end;
  int nextEvent;
  int errorCode;
};

//Computes for the number of hearts based on the current interestPoints
void computeHearts(){
  for(int i = 0; i < 3; i++){
    hearts[i] = floor(interestPoints[i] / 100);
  }
}

//Switches between different events and quests depending on the given number
struct gameInfo eventSwitcher(struct gameInfo _eventInfo){
  switch (_eventInfo.nextEvent)
  {
    case 1:
      _eventInfo.nextEvent = b1e1();
      _eventInfo.end = 1;
      break;
    default:
      _eventInfo.errorCode = 1;
      break;
  }
  return _eventInfo;
}

struct gameInfo eventEngine(struct gameInfo _mainInfo){

  //Initialize event variables
  struct gameInfo eventInfo;
  eventInfo.end = 0;
  eventInfo.errorCode = 0;
  eventInfo.nextEvent = _mainInfo.nextEvent;

  //Main Event loop
  while (eventInfo.end == 0 && eventInfo.errorCode == 0){
    eventInfo = eventSwitcher(eventInfo);
    computeHearts();
    printHUD(hearts);
  }

  //End the game if next room = 999
  if(eventInfo.nextEvent = 999){
    _mainInfo.end = 1;
  } else {
    _mainInfo.end = 0;
  }

  // After finishing the event, sets the mainInfo nextEvent to eventinfo next room;
  _mainInfo.nextEvent = eventInfo.nextEvent;

  //Error Codes
  if (eventInfo.errorCode){
    _mainInfo.errorCode = eventInfo.errorCode;
  } else {
    _mainInfo.errorCode = 0;
  }

  return _mainInfo;
}

int main(){
  //Initialize Variables
  struct gameInfo mainInfo;
  mainInfo.end = 0;
  mainInfo.nextEvent = 1;

  //Present Splash Screen
  // splashScreen();

  //Main Game Logic
  while(mainInfo.end == 0 && mainInfo.errorCode == 0){
    mainInfo = eventEngine(mainInfo);
  }
  
  //Error Checking
  if (mainInfo.errorCode != 0){
    printf("Error %i occured.", mainInfo.errorCode);
  }

  return 0;
}
