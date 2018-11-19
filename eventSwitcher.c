#include "gameInfo.h"
#include "gameEvents.h"

//Switches between different events and quests depending on the given number
struct gameInfo eventSwitcher(struct gameInfo _eventInfo){
  switch (_eventInfo.nextEvent)
  {
    case 1:
      _eventInfo = b1e1(_eventInfo);
      break;
    case 2:
      _eventInfo = b1e2(_eventInfo);
      break;
    default:
      _eventInfo.errorCode = 1;
      break;
  }
  return _eventInfo;
}