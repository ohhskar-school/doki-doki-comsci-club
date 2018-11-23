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
      _eventInfo = talkMenu(_eventInfo);
      break;
    default:
      _eventInfo.errorCode = 1;
      break;
  }
  return _eventInfo;
}