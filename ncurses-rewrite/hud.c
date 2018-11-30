#include <ncurses.h>
#include <math.h>
#include <unistd.h>
#include <string.h>
#include "gameInfo.h"

gameInfo computeHearts(gameInfo incomingInfo){
 
  for(int i = 0; i < 3; i++)
  {
    incomingInfo.hearts[i] = floor(incomingInfo.interestPoints[i]/100);
  }
  
  return incomingInfo;
}

void initializeNcurses(){
  initscr();                        //Initialize ncurses
  raw();                            //Enable Line Buffering
  keypad(stdscr, TRUE);             //Enable Arrow Keys for Option Selection
  noecho();                         //Disable Echoing
  curs_set(0);                       //Disable Cursor
}

void splashScreen(){
  clear();

  //Get Terminal Size
  int row,col;
  getmaxyx(stdscr,row,col);

  //Set Splash Screen Content
  int lines = 7;
  const char *line[lines];
  line[0]="  ___   ___  _  _____   ___   ___  _  _____ ";
  line[1]=" |   \\ / _ \\| |/ /_ _| |   \\ / _ \\| |/ /_ _|";
  line[2]=" | |) | (_) | ' < | |  | |) | (_) | ' < | | ";
  line[3]=" |___/ \\___/|_|\\_\\___| |___/_\\___/|_|\\_\\___|";
  line[4]="  / __|  \\/  / __|/ __|  / __| | | | | | _ )";
  line[5]=" | (__| |\\/| \\__ \\ (__  | (__| |_| |_| | _ \\";
  line[6]="  \\___|_|  |_|___/\\___|  \\___|____\\___/|___/";

  for(int i = 0; i < lines; i++){
    mvprintw(((row/2)-floor(lines/2))+i, (col-strlen(line[i]))/2, "%s", line[i]);
  }
  
  refresh();
  sleep(2);
}

void presentsScreen(){
  clear();

  //Get Terminal Size
  int row,col;
  getmaxyx(stdscr,row,col);

  //Set Splash Screen Content
  int lines = 8;
  const char *line[lines];
  line[0]="    ___ ___ __  __  ___ _____ ___     ";
  line[1]="   | _ \\ __|  \\/  |/ _ \\_   _| __|    ";
  line[2]="   |   / _|| |\\/| | (_) || | | _|     ";
  line[3]="   |_|_\\___|_| _|_|\\___/_|_|_|___|    ";
  line[4]="  / __/ _ \\| \\| |_   _| _ \\/ _ \\| |   ";
  line[5]=" | (_| (_) | .` | | | |   / (_) | |__ ";
  line[6]="  \\___\\___/|_|\\_| |_| |_|_\\\\___/|____|";
  line[7]="PRESENTS";

  for(int i = 0; i < lines; i++){
    mvprintw(((row/2)-floor(lines/2))+i, (col-strlen(line[i]))/2, "%s", line[i]);
  }
  
  refresh();
  sleep(2);
}
