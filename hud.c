#include <math.h>
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "gameInfo.h"

gameInfo computeHearts(gameInfo incomingInfo) {
    //Computes the heart by dividing each interestPoints by 100
    for (int i = 0; i < 3; i++) {
        incomingInfo.hearts[i] = floor(incomingInfo.interestPoints[i] / 100);
    }
    return incomingInfo;
}

void initializeNcurses() {
    initscr();             //Initialize ncurses
    cbreak();              //Enable Line Buffering
    noecho();              //Disable Echoing
    curs_set(0);           //Disable Cursor
    keypad(stdscr, TRUE);  //Enable using the arrow key for options
}

void initializeColors() {
    //Setting Color Pairs
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
}

void fullScreenCentered(const char **line, int lineSize) {
    clear();

    //Get Terminal Size
    int row, col;
    getmaxyx(stdscr, row, col);

    //Prints line
    //row / 2 - floor(lineSize / 2) calculates the gap needed at the top of the splashscreen before it starts printing
    //(col - strlen(line[i])) / 2 calculates whre the line should start printing so that it will be centered

    attron(COLOR_PAIR(2));
    for (int i = 0; i < lineSize; i++) {
        mvprintw(((row / 2) - floor(lineSize / 2)) + i, (col - strlen(line[i])) / 2, "%s", line[i]);
    }
    attroff(COLOR_PAIR(2));

    refresh();
    sleep(3);
}

void splashScreen() {
    int lineSize = 7;
    const char *line[lineSize];
    line[0] = "  ___   ___  _  _____   ___   ___  _  _____ ";
    line[1] = " |   \\ / _ \\| |/ /_ _| |   \\ / _ \\| |/ /_ _|";
    line[2] = " | |) | (_) | ' < | |  | |) | (_) | ' < | | ";
    line[3] = " |___/ \\___/|_|\\_\\___| |___/_\\___/|_|\\_\\___|";
    line[4] = "  / __|  \\/  / __|/ __|  / __| | | | | | _ )";
    line[5] = " | (__| |\\/| \\__ \\ (__  | (__| |_| |_| | _ \\";
    line[6] = "  \\___|_|  |_|___/\\___|  \\___|____\\___/|___/";

    fullScreenCentered(line, lineSize);
}

void presentsScreen() {
    int lineSize = 8;
    const char *line[lineSize];
    line[0] = "    ___ ___ __  __  ___ _____ ___     ";
    line[1] = "   | _ \\ __|  \\/  |/ _ \\_   _| __|    ";
    line[2] = "   |   / _|| |\\/| | (_) || | | _|     ";
    line[3] = "   |_|_\\___|_| _|_|\\___/_|_|_|___|    ";
    line[4] = "  / __/ _ \\| \\| |_   _| _ \\/ _ \\| |   ";
    line[5] = "  | (_| (_) | .` | | | |   / (_) | |__  ";
    line[6] = "  \\___\\___/|_|\\_| |_| |_|_\\\\___/|____|";
    line[7] = "PRESENTS";

    fullScreenCentered(line, lineSize);
}

void getReadyScreen() {
    int lineSize = 10;
    const char *line[lineSize];
    line[0] = "       ___ ___ _____   ___ ___   _   _____   __      ";
    line[1] = "      / __| __|_   _| | _ \\ __| /_\\ |   \\ \\ / /      ";
    line[2] = "     | (_ | _|  | |   |   / _| / _ \\| |) \\ V /       ";
    line[3] = "      \\___|___| |_|  _|_|_\\___/_/_\\_\\___/ |_|        ";
    line[4] = "           | __/ _ \\| _ \\ |_   _| || | __|           ";
    line[5] = "           | _| (_) |   /   | | | __ | _|            ";
    line[6] = "  _  _ ____|_|_\\___/|_|_\\__ |_| |_||_|___|_ _    ___ ";
    line[7] = " | \\| | __\\ \\/ /_   _| | _ ) /_\\_   _|_   _| |  | __|";
    line[8] = " | .` | _| >  <  | |   | _ \\/ _ \\| |   | | | |__| _| ";
    line[9] = " |_|\\_|___/_/\\_\\ |_|   |___/_/ \\_\\_|   |_| |____|___|";
    fullScreenCentered(line, lineSize);
}

void gameOverScreen() {
    int lineSize = 7;
    const char *line[lineSize];
    line[0] = "   ___   _   __  __ ___ ";
    line[1] = "  / __| /_\\ |  \\/  | __|";
    line[2] = " | (_ |/ _ \\| |\\/| | _| ";
    line[3] = "  \\___/_/ \\_\\_|__|_|___|";
    line[4] = "   / _ \\ \\ / / __| _ \\  ";
    line[5] = "  | (_) \\ V /| _||   /  ";
    line[6] = "   \\___/ \\_/ |___|_|_\\  ";
    fullScreenCentered(line, lineSize);
}

void endScreen() {
    int lineSize = 11;
    const char *line[lineSize];
    line[0] = "             _____ ___    ___ ___              ";
    line[1] = "            |_   _/ _ \\  | _ ) __|             ";
    line[2] = "              | || (_) | | _ \\ _|              ";
    line[3] = "   ___ ___  _ |_|_\\___/__|___/___|  _ ___ ___  ";
    line[4] = "  / __/ _ \\| \\| |_   _|_ _| \\| | | | | __|   \\ ";
    line[5] = " | (_| (_) | .` | | |  | || .` | |_| | _|| |) |";
    line[6] = "  \\___\\___/|_|\\_| |_| |___|_|\\_|\\___/|___|___/ ";
    line[7] = "";
    line[8] = "Support us on our kickstarter!";
    line[9] = "You may also support us on our github!";
    line[10] = "https://github.com/ohhskar/cmsc11-game";
    fullScreenCentered(line, lineSize);
}

void sizeScreen() {
    int lineSize = 3;
    const char *line[lineSize];
    line[0] = "This game is best played";
    line[1] = "when the terminal width";
    line[2] = "is greater than 80";
    fullScreenCentered(line, lineSize);
}

void disclaimerScreen() {
    int lineSize = 5;
    const char *line[lineSize];
    line[0] = "This is a work of fiction.";
    line[1] = "Names, characters, businesses, places, events and incidents";
    line[2] = "are either the products of the author's imagination";
    line[3] = "or used in a fictitious manner. Any resemblance to actual persons,";
    line[4] = "living or dead, or actual events is purely coincidental.";
    fullScreenCentered(line, lineSize);
}

WINDOW *createHUD(int hudHeight, gameInfo incomingInfo) {
    //Get Terminal Size
    int row, col;
    getmaxyx(stdscr, row, col);

    //Calculate Hearts for the HUD
    incomingInfo = computeHearts(incomingInfo);

    //Create HUD Windows
    WINDOW *hudWindow = newwin(hudHeight, col, 0, 0);
    box(hudWindow, 0, 0);

    //Creates the content for the HUD
    //Prints the Main Texts
    wattron(hudWindow, A_BOLD);
    mvwprintw(hudWindow, 1, 2, "Doki Doki CMSC Club | Hearts: Jeff: ");

    //Creates the Hearts for each person with colors
    //Prints Active Hearts
    int jeff;
    wattron(hudWindow, COLOR_PAIR(1));
    for (jeff = 0; jeff < incomingInfo.hearts[0]; jeff++) {
        wprintw(hudWindow, "*");
    }
    wattroff(hudWindow, COLOR_PAIR(1));

    //Prints Inactive Hearts
    wattroff(hudWindow, A_BOLD);
    for (int i = jeff; i < 5; i++) {
        wprintw(hudWindow, "*");
    }
    wattron(hudWindow, A_BOLD);

    wprintw(hudWindow, " Mr. K: ");

    //Prints Active Hearts
    int k;
    wattron(hudWindow, COLOR_PAIR(1));
    for (k = 0; k < incomingInfo.hearts[1]; k++) {
        wprintw(hudWindow, "*");
    }
    wattroff(hudWindow, COLOR_PAIR(1));

    //Prints Inactive Hearts
    wattroff(hudWindow, A_BOLD);
    for (int i = k; i < 5; i++) {
        wprintw(hudWindow, "*");
    }

    wrefresh(hudWindow);

    return hudWindow;
}

WINDOW *createContentScreen(int contentHeight, int starty, const char **line, int lines) {
    //Get Terminal Size
    int row, col;
    getmaxyx(stdscr, row, col);

    //Creates the window for the content screen
    WINDOW *contentWindow = newwin(contentHeight, col, starty, 0);

    //Sets the variables for the loop
    int contentRow = 1, counter = 0;
    int contentRowHolder = 0;
    while (counter < lines) {
        //If the line is empty, that means it is signal to start pausing the dialogue screen
        if (!(strcmp(line[counter], ""))) {
            mvwprintw(contentWindow, contentRow + 1, 0, "Press ENTER to continue");
            wrefresh(contentWindow);
            wgetch(contentWindow);                    //Waits for the user to press a key before continuing
            wmove(contentWindow, contentRow + 1, 0);  //Moves the cursor to the start of the line
            wclrtoeol(contentWindow);                 //So that wclrtoeol can start clearing the press Enter to continue line
            contentRow = 1;                           //This is so that if it will be the last line, there will be no line that states
        } else {                                      //Press enter to continue when in the options window is shown
            if (contentRow == 1) {
                wclear(contentWindow);                                     //Cleares the window if the row is already 1, which is when the window is created
            }                                                              //Or when Enter has been pressed
            mvwprintw(contentWindow, contentRow, 0, "%s", line[counter]);  //Prints the lines

            if (strlen(line[counter]) > col) {                         //If the line is longer than the width of the terminal,
                contentRowHolder = (strlen(line[counter]) / col) + 1;  //ContentRowHolder is added depending on the number of lines
            } else {                                                   //That the printed line has overflowed to.
                contentRowHolder = 1;
            }
            contentRow += contentRowHolder;
        }
        counter++;
    }
    wrefresh(contentWindow);

    return contentWindow;
}

optionReturn createOptions(int optionHeight, int starty, const char **option, int options) {
    //Initializing Variables
    optionReturn returnValues;
    returnValues.choice = 0;
    int choice;

    //Get Terminal Size
    int row, col;
    getmaxyx(stdscr, row, col);

    returnValues.optionWindow = newwin(optionHeight, col, starty, 0);
    keypad(returnValues.optionWindow, TRUE);
    mvwprintw(returnValues.optionWindow, 1, 0, "press the ARROW KEYS to move and ENTER to confirm your choice");
    wrefresh(returnValues.optionWindow);

    while (1) {
        for (int i = 0; i < options; i++) {
            if (i == returnValues.choice) {
                wattron(returnValues.optionWindow, A_REVERSE);  //Enables highlighting the option if the line to be printed is the same as the selected choice
            }
            mvwprintw(returnValues.optionWindow, i + 3, 0, " %s ", option[i]);
            wattroff(returnValues.optionWindow, A_REVERSE);
        }
        choice = wgetch(returnValues.optionWindow);

        switch (choice) {
            case KEY_UP:
                if (returnValues.choice == 0) {
                    returnValues.choice = options - 1;  //If returnValues.choice is equal to 1, the value wraps around to the last
                } else {                                //of the options.
                    returnValues.choice--;
                }
                break;
            case KEY_DOWN:
                if (returnValues.choice == options - 1) {
                    returnValues.choice = 0;  //Same logic is also applied here
                } else {
                    returnValues.choice++;
                }
                break;
            default:
                break;
        }
        if (choice == 10) {
            break;
        }
    }

    keypad(returnValues.optionWindow, FALSE);
    return returnValues;
}

//Creates A Screen Per Event
int createGameScreen(const char **line, int lines, const char **option, int options, gameInfo incomingInfo) {
    clear();
    refresh();

    int row, col;
    getmaxyx(stdscr, row, col);

    //Set Height of the Different Windows
    int hudHeight = 3;
    int contentHeight = 10;
    int optionHeight = options + 7;

    //Initialize Windows
    WINDOW *hudWindow, *contentWindow;
    optionReturn optionValues;

    hudWindow = createHUD(hudHeight, incomingInfo);

    contentWindow = createContentScreen(contentHeight, hudHeight, line, lines);

    optionValues = createOptions(optionHeight, contentHeight + hudHeight, option, options);

    //Cleanup
    wclear(hudWindow);
    wclear(contentWindow);
    wclear(optionValues.optionWindow);
    delwin(hudWindow);
    delwin(contentWindow);
    delwin(optionValues.optionWindow);
    clear();

    return optionValues.choice;
}

WINDOW *createEnemyHud(bossStruct boss, int hudHeight) {
    int row, col;
    getmaxyx(stdscr, row, col);

    WINDOW *enemyHud = newwin(hudHeight, col, 0, 0);

    int nameLen = strlen(boss.name);
    wattron(enemyHud, A_BOLD);
    //Prints the boss name and the healMath Ghostth label
    mvwprintw(enemyHud, 2, 3, "%s", boss.name);
    mvwprintw(enemyHud, 2, nameLen + 4, "| HEALTH: ");

    //Calculates the remaining space. 10 is the number of characters in health + 3
    //each side which are gaps. +1 for the space between the health and the boss name.
    //Which is equal to 17
    int remainingSpace = col - (nameLen + 17);

    //Calculates the percentage of the health of the boss, which is then multiplied by
    // the remaining space. This is then implicitly converted to int.
    int healthPercentage = ((float)boss.health / (float)boss.maxHealth) * remainingSpace;

    wattron(enemyHud, COLOR_PAIR(1));
    for (int i = healthPercentage, space = 0; i > 0; i--, space++) {
        //10 is the number of characters in health, 3 is the gap at the side and 1 is the space
        //between the boss name and the health
        mvwprintw(enemyHud, 2, space + nameLen + 14, "#");
    }
    wattroff(enemyHud, COLOR_PAIR(1));
    wattroff(enemyHud, A_BOLD);

    box(enemyHud, 0, 0);
    wrefresh(enemyHud);

    return enemyHud;
}

WINDOW *createPlayerHud(playerStruct player, int hudHeight) {
    int row, col;
    getmaxyx(stdscr, row, col);

    WINDOW *playerHud = newwin(hudHeight, col / 2, row - hudHeight, 0);

    //Same logic as above
    wattron(playerHud, A_BOLD);
    mvwprintw(playerHud, 2, 3, "HEALTH: ");
    int remainingSpace = (col / 2) - 15;
    float healthPercentage = ((float)player.health / (float)player.maxHealth) * remainingSpace;

    wattron(playerHud, COLOR_PAIR(1));
    for (int i = ceil(healthPercentage), space = 0; i > 0; i--, space++) {
        mvwprintw(playerHud, 2, space + 11, "#");
    }
    wattroff(playerHud, COLOR_PAIR(1));
    wattroff(playerHud, A_BOLD);

    box(playerHud, 0, 0);
    wrefresh(playerHud);

    return playerHud;
}

optionReturn createOptionHud(int hudHeight, char **option, int options) {
    optionReturn returnInfo;
    int row, col;
    int choice;
    getmaxyx(stdscr, row, col);

    returnInfo.optionWindow = newwin(hudHeight, col / 2, row - hudHeight, col / 2);
    returnInfo.choice = 0;
    keypad(returnInfo.optionWindow, TRUE);
    box(returnInfo.optionWindow, 0, 0);
    wrefresh(returnInfo.optionWindow);

    //Same logic as createOptions but the change is in the cases of the switch.
    while (1) {
        int gap = 3;
        for (int i = 0; i < options; i++) {
            if (i == returnInfo.choice) {
                wattron(returnInfo.optionWindow, A_REVERSE);
            }
            mvwprintw(returnInfo.optionWindow, 2, gap, " %s ", option[i]);
            //Gap is calculated from the length of the string and the spaces around it. This is added
            //to the preceding gap to calculate where the option is being printed.
            gap += strlen(option[i]) + 2;
            wattroff(returnInfo.optionWindow, A_REVERSE);
        }
        choice = wgetch(returnInfo.optionWindow);

        switch (choice) {
            case KEY_LEFT:
                if (returnInfo.choice == 0) {
                    returnInfo.choice = options - 1;
                } else {
                    returnInfo.choice--;
                }
                break;
            case KEY_RIGHT:
                if (returnInfo.choice == options - 1) {
                    returnInfo.choice = 0;
                } else {
                    returnInfo.choice++;
                }
                break;
            default:
                break;
        }
        if (choice == 10) {
            break;
        }
    }
    return returnInfo;
}

WINDOW *createContentHud(int hudHeight, char **line, int lines) {
    int row, col;
    getmaxyx(stdscr, row, col);

    WINDOW *contentHud = newwin(row - (hudHeight * 2), col, hudHeight, 0);
    box(contentHud, 0, 0);

    for (int i = 0; i < lines; i++) {
        mvwprintw(contentHud, i + 2, 3, "%s", line[i]);
    }

    wrefresh(contentHud);
    return contentHud;
}