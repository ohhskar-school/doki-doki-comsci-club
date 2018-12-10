#include "eventSwitcher.h"
#include "gameEvents.h"
#include "gameInfo.h"
#include "hud.h"

//Switches between different events and quests depending on the given number
gameInfo eventSwitcher(gameInfo _branchInfo) {
    switch (_branchInfo.nextEvent) {
        case 0:
            _branchInfo = mainMenu(_branchInfo);
            break;
        case 10:
            _branchInfo = dayOne(_branchInfo);
            break;
        // case 21:
        //   _branchInfo = branchOne(_branchInfo);
        //   break;
        // case 22:
        //   _branchInfo = branchTwo(_branchInfo);
        //   break;
        // case 23:
        //   _branchInfo = branchThree(_branchInfo);
        //   break;
        case 100000:
            break;
        default:
            _branchInfo.errorCode = 1;
            break;
    }

    return _branchInfo;
}