#include "gameInfo.h"
#include "gameEvents.h"
#include <stdio.h>

//Switches between different events and quests depending on the given number
struct gameInfo eventSwitcher(struct gameInfo _eventInfo){
  switch (_eventInfo.nextEvent)
  {
    case 0:
      _eventInfo = mainMenu(_eventInfo);
      break;
    case 10:
      _eventInfo = startGame(_eventInfo);
      break;
    case 20:
      _eventInfo = firstOne(_eventInfo);
      break;
    case 21: 
      _eventInfo = branchOne(_eventInfo);
    case 22: 
      _eventInfo = branchTwo(_eventInfo);
    case 23: 
      _eventInfo = branchThree(_eventInfo);
    case 24: 
      _eventInfo = firstTwo(_eventInfo);
    case 25:
      _eventInfo = branchFour(_eventInfo);
    case 26:
      _eventInfo = branchFive(_eventInfo);
    case 27:
      _eventInfo = firstThree(_eventInfo);
    default:
      _eventInfo.errorCode = 1;
      break;
  }
  return _eventInfo;
}