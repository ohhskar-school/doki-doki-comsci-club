#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "gameInfo.h"
#include "gameEvents.h"
#include "hud.h"

//Computes for the number of hearts based on the current interestPoints
struct gameInfo computeHearts(struct gameInfo _mainInfo){
  _mainInfo.heartsA = floor(_mainInfo.iPA/100);
  _mainInfo.heartsB = floor(_mainInfo.iPB/100);
  _mainInfo.heartsC = floor(_mainInfo.iPC/100);

  return _mainInfo;
}

//Switches between different events and quests depending on the given number
struct gameInfo eventSwitcher(struct gameInfo _eventInfo){
  switch (_eventInfo.nextEvent)
  {
    case 1:
      _eventInfo = b1e1(_eventInfo);
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
  eventInfo = _mainInfo;
  eventInfo.end = 0;
  eventInfo.errorCode = 0;
  eventInfo.nextEvent = _mainInfo.nextEvent;

  //Main Event loop
  while (eventInfo.end == 0 && eventInfo.errorCode == 0){
    eventInfo = _mainInfo;
    computeHearts(_mainInfo);
    printHUD(_mainInfo);
    eventInfo = eventSwitcher(eventInfo);

    _mainInfo.iPA = eventInfo.iPA;
    _mainInfo.iPB = eventInfo.iPB;
    _mainInfo.iPC = eventInfo.iPC;
  }

  //End the game if next event = 999
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
