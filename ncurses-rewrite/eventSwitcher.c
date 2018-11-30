#include "eventSwitcher.h"
#include "gameInfo.h"

//Switches between different events and quests depending on the given number
gameInfo eventSwitcher(gameInfo _branchInfo){
  switch (_branchInfo.nextEvent)
  {
    case 0:
      _branchInfo = mainMenu(_branchInfo);
      break;
    case 100000:
      break;
    default:
      _branchInfo.errorCode = 1;
      break;
  }

  return _branchInfo;
}