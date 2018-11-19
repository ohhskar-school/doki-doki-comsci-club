#include <stdio.h>
#include <math.h>
#include <string.h>

//Global Function
int interestPoints[3] = {100,100,100};
int hearts[3];

//Creates a struct to store a game info after each event
struct gameInfo {
  int end;
  int nextRoom;
  int errorCode;
};

//Computes for the number of hearts based on the current interestPoints
void computeHearts(){
  for(int i = 0; i < 3; i++){
    hearts[i] = floor(interestPoints[i] / 100);
  }
}

struct gameInfo eventSwitcher(int nextRoom, struct gameInfo _eventInfo){
  
  switch (nextRoom)
  {
    case 1:
      printf("Case %i", nextRoom);
      break;
    case 2:
      printf("Case %i", nextRoom);
      break;
    case 3:
      printf("Case %i", nextRoom);
      break;
    default:
      _eventInfo.errorCode = 1;
      break;
  }
  return _eventInfo;
}

struct gameInfo eventEngine(struct gameInfo _mainInfo){

  //Initialize event variables
  struct gameInfo eventInfo;
  eventInfo.end = 0;
  eventInfo.nextRoom = 0;
  eventInfo.errorCode = 0;

  //Main Event loop - Ends if flag to end is set or error code is present
  while (eventInfo.end == 0 && eventInfo.errorCode == 0){
    eventInfo = eventSwitcher(_mainInfo.nextRoom, eventInfo);
    computeHearts();
    printf("%i, %i, %i\n", hearts[0], hearts[1], hearts[2]);
  }

  //Set Game End if next room = 999
  if(eventInfo.nextRoom = 999){
    _mainInfo.end = 1;
  } else {
    _mainInfo.end = 0;
  }

  //Sets the mainInfo nextroom to eventinfo next room;
  _mainInfo.nextRoom = eventInfo.nextRoom;

  //Error Codes
  if (eventInfo.errorCode){
    _mainInfo.errorCode = eventInfo.errorCode;
  } else {
    _mainInfo.errorCode = 0;
  }
  return _mainInfo;
}

int main(){
  //Initialize Variables
  struct gameInfo mainInfo;
  mainInfo.end = 0;
  mainInfo.nextRoom = 0;

  //Main Game Logic
  while(mainInfo.end == 0 && mainInfo.errorCode == 0){
    mainInfo = eventEngine(mainInfo);
  }
  
  //Error Checking
  if (mainInfo.errorCode != 0){
    printf("Error %i occured.", mainInfo.errorCode);
  }

  return 0;
}

/* Things to do
* Quest System
* Love System
* Interest Gauge
* Player Creation System
* 
*/
