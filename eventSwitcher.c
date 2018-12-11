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
        case 100:
            _branchInfo = dayOne(_branchInfo);
            break;
        case 101:
            _branchInfo = dayOneCont(_branchInfo);
            break;
        case 102:
            _branchInfo = dayOneContTwo(_branchInfo);
            break;
        case 103:
            _branchInfo = dayTwo(_branchInfo);
            break;
        /*case 104:
            _branchInfo = dayTwoCont(_branchInfo);
           break;*/
        case 201:
            _branchInfo = onePathOne(_branchInfo);
            break;
        case 202:
            _branchInfo = onePathTwo(_branchInfo);
            break;
        case 203:
            _branchInfo = onePathThree(_branchInfo);
            break;
        case 204:
            _branchInfo = onePathFour(_branchInfo);
            break;
        case 205:
            _branchInfo = onePathFive(_branchInfo);
            break;
        case 206:
            _branchInfo = clubPathOne(_branchInfo);
            break;
        case 207:
            _branchInfo = clubPathTwo(_branchInfo);
            break;
        case 208:
            _branchInfo = clubPathThree(_branchInfo);
            break;
        case 500:
            _branchInfo = clubOne(_branchInfo);
            break;
        case 501:
            _branchInfo = clubOneCont(_branchInfo);
            break;
        case 502:
            _branchInfo = clubOneContTwo(_branchInfo);
            break;
        case 503:
            _branchInfo = clubOneContThree(_branchInfo);
            break;
        case 504:
            _branchInfo = clubOneContFour(_branchInfo);
            break;
        case 505:
            _branchInfo = clubOneContFive(_branchInfo);
            break;
        case 100000:
            break;
        default:
            _branchInfo.errorCode = 1;
            break;
    }

    return _branchInfo;
}