#include <ncurses.h>
#include <unistd.h>
#include "eventSwitcher.h"
#include "gameInfo.h"
#include "hud.h"

/*
 * Just run make to compile the files. The makefile compiles the file with 
 * the flags -lncurses and -lm to compile with ncurses and math support.
 * Tested to work on Manjaro Linux. Kernel no. 4.19.6-1-MANJARO
 * 
 * The link to our github with all of our commits can be found here:
 * https://github.com/ohhskar/cmsc11-game
 * 
 * For more info please read the README
*/

int main() {
    //Initializing Variables;
    gameInfo mainInfo;
    mainInfo.end = 0;
    mainInfo.errorCode = 0;
    mainInfo.nextEvent = 0;
    for (int i = 0; i < 3; i++) {
        mainInfo.hearts[i] = 0;
    }
    for (int i = 0; i < 3; i++) {
        mainInfo.interestPoints[i] = 50;
    }

    //Initialize ncurses
    initializeNcurses();
    initializeColors();

    //Get Terminal Size
    int row, col;
    getmaxyx(stdscr, row, col);

    if (col < 80) {
        //Presents the splashscreen showing that the width of the terminal is less
        //Than the minimum requirements of the game
        sizeScreen();
        //Cleanup
        clear();
        refresh();
        endwin();
        return 0;
    }
    //Present Splash Screen before starting the game
    splashScreen();
    //Main Game Loop
    while (mainInfo.end == 0 && mainInfo.errorCode == 0) {
        mainInfo = eventSwitcher(mainInfo);
    }

    //Cleanup
    clear();
    refresh();
    endwin();

    if (mainInfo.errorCode != 0) {
        clear();
        printw("Error %i has occured!", mainInfo.errorCode);
        refresh();
        sleep(5);
    }

    return 0;
}
