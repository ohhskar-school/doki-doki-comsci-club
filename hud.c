#include <ncurses.h>
#include <math.h>
#include <unistd.h>
#include <string.h>
#include "gameInfo.h"
#include <stdlib.h>

gameInfo computeHearts(gameInfo incomingInfo){
  for(int i = 0; i < 3; i++)
  {
    incomingInfo.hearts[i] = floor(incomingInfo.interestPoints[i]/100);
  }
  return incomingInfo;
}

void initializeNcurses(){
  initscr();                        //Initialize ncurses
  box(stdscr, 0, 0);
  cbreak();                         //Enable Line Buffering
  noecho();                         //Disable Echoing
  curs_set(0);                      //Disable Cursor
  keypad(stdscr, TRUE); //Enable using the arrow key for options
}

void initializeColors(){
  //Setting Color Pairs
  start_color();
  init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(2, COLOR_YELLOW, COLOR_BLACK);
}

void fullScreenCentered(const char **line, int lineSize){
  clear();

  //Get Terminal Size
  int row,col;
  getmaxyx(stdscr,row,col);

  //Prints line
  attron(COLOR_PAIR(2));
  for(int i = 0; i < lineSize; i++){
    mvprintw(((row/2)-floor(lineSize/2))+i, (col-strlen(line[i]))/2, "%s", line[i]);
  }
  attroff(COLOR_PAIR(2));
  
  refresh();
  sleep(2); 
}

void splashScreen(){
  int lineSize = 7;
  const char *line[lineSize];
  line[0]="  ___   ___  _  _____   ___   ___  _  _____ ";
  line[1]=" |   \\ / _ \\| |/ /_ _| |   \\ / _ \\| |/ /_ _|";
  line[2]=" | |) | (_) | ' < | |  | |) | (_) | ' < | | ";
  line[3]=" |___/ \\___/|_|\\_\\___| |___/_\\___/|_|\\_\\___|";
  line[4]="  / __|  \\/  / __|/ __|  / __| | | | | | _ )";
  line[5]=" | (__| |\\/| \\__ \\ (__  | (__| |_| |_| | _ \\";
  line[6]="  \\___|_|  |_|___/\\___|  \\___|____\\___/|___/";

  fullScreenCentered(line,lineSize);
}

void presentsScreen(){
  int lineSize = 8;
  const char *line[lineSize];
  line[0]="    ___ ___ __  __  ___ _____ ___     ";
  line[1]="   | _ \\ __|  \\/  |/ _ \\_   _| __|    ";
  line[2]="   |   / _|| |\\/| | (_) || | | _|     ";
  line[3]="   |_|_\\___|_| _|_|\\___/_|_|_|___|    ";
  line[4]="  / __/ _ \\| \\| |_   _| _ \\/ _ \\| |   ";
  line[5]="  | (_| (_) | .` | | | |   / (_) | |__  ";
  line[6]="  \\___\\___/|_|\\_| |_| |_|_\\\\___/|____|";
  line[7]="PRESENTS";

  fullScreenCentered(line,lineSize);
}

// void thankYouScreen(){
//   int lineSize = 7;
//   const char *line[lineSize];
//   line[0]="    _____  _  _    _    _  _  _  __ __   __ ___   _   _      ";
//   line[1]="   |_   _|| || |  /_\  | \| || |/ / \ \ / // _ \ | | | |     ";
//   line[2]="     | |  | __ | / _ \ | .` || ' <   \ V /| (_) || |_| |     ";
//   line[3]="  ___|_|__|_||_|/_/_\_\|_|\_||_|\_\_  |_| _\___/  \___/__  _ ";
//   line[4]=" | __|/ _ \ | _ \ | _ \| |     /_\\ \ / /|_ _|| \| | / __|| |";
//   line[5]=" | _|| (_) ||   / |  _/| |__  / _ \\ V /  | | | .` || (_ ||_|";
//   line[6]=" |_|  \___/ |_|_\ |_|  |____|/_/ \_\|_|  |___||_|\_| \___|(_)";

//   fullScreenCentered(line,lineSize);
// }

WINDOW *createHUD(int hudHeight, gameInfo incomingInfo){
  //Get Terminal Size
  int row,col;
  getmaxyx(stdscr,row,col);
  
  //Calculate Hearts for the HUD
  incomingInfo = computeHearts(incomingInfo);

  //Create HUD Windows
  WINDOW *hudWindow = newwin(hudHeight,col,0,0);
  box(hudWindow,0,0);
  
  //Creates the content for the HUD
  //Prints the Main Texts
  mvwprintw(hudWindow, 1,2, "Oscar Valles | Hearts: A: ");

  //Creates the Hearts for each person with colors
  wattron(hudWindow, COLOR_PAIR(1));
  for(int i = 0; i < incomingInfo.hearts[0]; i++){
    wprintw(hudWindow, "*");
  }
  wattroff(hudWindow, COLOR_PAIR(1));

  wprintw(hudWindow, " B: ");

  wattron(hudWindow, COLOR_PAIR(1));
  for(int i = 0; i < incomingInfo.hearts[1]; i++){
    wprintw(hudWindow, "*");
  }
  wattroff(hudWindow, COLOR_PAIR(1));

  wprintw(hudWindow, " C: ");
  
  wattron(hudWindow, COLOR_PAIR(1));
  for(int i = 0; i < incomingInfo.hearts[2]; i++){
    wprintw(hudWindow, "*");
  }
  wattroff(hudWindow, COLOR_PAIR(1));

  wrefresh(hudWindow);
  
  return hudWindow;
}

WINDOW *createContentScreen(int contentHeight, int starty, const char **line, int lines){  
  //Get Terminal Size
  int row,col;
  getmaxyx(stdscr,row,col);

  WINDOW *contentWindow = newwin(contentHeight,col,starty,0);
  int contentRow = 1, counter = 0;
  while (counter < lines){
    if (!(strcmp(line[counter], ""))){
      mvwprintw(contentWindow, contentRow+1, 2, "Press ENTER to continue");
      wrefresh(contentWindow);
      getch();
      wmove(contentWindow, contentRow+1, 0);
      wclrtoeol(contentWindow);
      contentRow = 1;
    } else {
      if (contentRow == 1){
        wclear(contentWindow);
      }
      mvwprintw(contentWindow, contentRow, 2, "%s", line[counter]);
      contentRow++;
    }
    counter++;
  }
  wrefresh(contentWindow);

  return contentWindow;
}


void printMenu(WINDOW *optionWindow, int selection, const char **option, int options){
  
  int x = 2, y = 3;	
  for(int i = 0; i < options; i++){
    if(selection == i + 1){	
      wattron(optionWindow, A_REVERSE); 
      mvwprintw(optionWindow, y, x, " %s ", option[i]);
      wattroff(optionWindow, A_REVERSE);
    }	else {
      mvwprintw(optionWindow, y, x, " %s ", option[i]);
    }
    y++;
  }
  wrefresh(optionWindow);
}

optionReturn createOptions(int optionHeight, int starty, const char **option, int options){
  //Initializing Variables
  optionReturn returnValues;
  returnValues.choice = 0;
  int selection = 1;
  int c;

  //Get Terminal Size
  int row,col;
  getmaxyx(stdscr,row,col);

  returnValues.optionWindow = newwin(optionHeight,col,starty,0);
  keypad(returnValues.optionWindow, TRUE);
  mvwprintw(returnValues.optionWindow,1,2,"press the ARROW KEYS to move and ENTER to confirm your choice");
  wrefresh(returnValues.optionWindow);

  printMenu(returnValues.optionWindow, selection, option, options);
  while(1){
  c = wgetch(returnValues.optionWindow);
    switch(c){
      case KEY_UP:
        if(selection == 1){
          selection = options;
        }
        else{
          --selection;
        }
        break;
      case KEY_DOWN:
        if(selection == options){
          selection = 1;
        }
        else{
          ++selection;
        }
        break;
      case 10:
        returnValues.choice = selection;
        break;
      default:
        break;
    }
    printMenu(returnValues.optionWindow, selection, option, options);
    if(returnValues.choice != 0)	/* User did a choice come out of the infinite loop */
      break;
  }

  return returnValues;
}

//Creates A Screen Per Event
int createGameScreen(const char **line, int lines, const char **option, int options, gameInfo incomingInfo){
  clear();
  refresh();

  int row,col;
  getmaxyx(stdscr,row,col);

  //Set Height of the Different Windows
  int hudHeight = 3;
  int contentHeight = lines + 1;
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
