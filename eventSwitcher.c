#include "gameInfo.h"
#include "gameEvents.h"
#include <stdio.h>

//Switches between different events and quests depending on the given number
gameInfo eventSwitcher(gameInfo _eventInfo){
  switch (_eventInfo.nextEvent)
  {
    case 0:
      _eventInfo = mainMenu(_eventInfo);
      break;
    case 20:
      _eventInfo = firstOne(_eventInfo);
      break;
    case 21: 
      _eventInfo = branchOne(_eventInfo);
      break;
    case 22: 
      _eventInfo = branchTwo(_eventInfo);
      break;
    case 23: 
      _eventInfo = branchThree(_eventInfo);
      break;
    case 24: 
      _eventInfo = firstTwo(_eventInfo);
      break;
    case 25:
      _eventInfo = branchFour(_eventInfo);
      break;
    case 26:
      _eventInfo = branchFive(_eventInfo);
      break;
    case 27:
      _eventInfo = firstThree(_eventInfo);
      break;
    default:
      _eventInfo.errorCode = 1;
      break;
  }
  return _eventInfo;
}