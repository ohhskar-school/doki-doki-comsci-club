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
  sleep(2);
  raw();                            //Enable Line Buffering
  keypad(stdscr, TRUE);             //Enable Arrow Keys for Option Selection
  noecho();                         //Disable Echoing
  curs_set(0);                      //Disable Cursor
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

//Creates A Screen Per Event
void createGameScreen(const char **line, int lines, const char **option, int options, gameInfo incomingInfo){
  clear();
  refresh();
  
  //Get Terminal Sizeinit_pair(1, COLOR_RED, COLOR_BLACK);
  int row,col;
  getmaxyx(stdscr,row,col);

  //Set Height of the Different Windows
  int hudHeight = 3;
  int contentHeight = lines + 1;
  int optionHeight = options + 2;

  //Calculate Hearts for the HUD
  incomingInfo = computeHearts(incomingInfo);

  //Create HUDWINDOW
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

  //Create Content Window
  WINDOW *contentWindow = newwin(contentHeight,col,hudHeight,0);
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
  

  //Create Option Window
  WINDOW *optionWindow = newwin(optionHeight,col,contentHeight + hudHeight,0);
  mvwprintw(optionWindow,1,2,"What would you like to do?");
  for(int i = 0; i < options; i++){
    mvwprintw(optionWindow,i+3,2,"%s", option[i]);
  }
  wrefresh(optionWindow);
  getch();

  //Cleanup
  delwin(hudWindow);
  delwin(contentWindow);
  delwin(optionWindow);
  clear();
}
