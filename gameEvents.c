#include <stdio.h>
#include <string.h>
#include "gameInfo.h"
#include "hud.h"


gameInfo mainMenu(gameInfo _eventInfo){
  int lines = 7;
  const char *line[lines];
  line[0] = "Line 1";
  line[1] = "Line 2";
  line[2] = "";
  line[3] = "Line 4";
  line[4] = "Line 5";
  line[5] = "Line 6";
  line[6] = "";


  //Setting Options
  int options = 5;
  const char *option[options];
  option[0]="Start Game";
  option[1]="Exit Game";
  option[2]="Debug";
  option[3]="Debug";
  option[4]="Debug";

  int choice = createGameScreen(line, lines, option, options, _eventInfo);
  
  switch(choice){
    case 1:
      _eventInfo.nextEvent = 10;
      _eventInfo.end = 1;
      break;
    case 2:
      _eventInfo.nextEvent = 100000;
      _eventInfo.end = 1;
      break;
    case 3:
    default:
      _eventInfo.errorCode = 2;
      _eventInfo.end = 1;
  }
  
  return _eventInfo;
}

gameInfo dayOne(gameInfo _eventInfo){
  int lines = 47
  const char  *line[lines];

  line[0] = "Welcome to P University, the premier university in the country!";
  line[1] = "";
  line[2] = "It's your first day as a BS Computer Science major and oh no! You're running late!";
  line[3] = "Quick get into your classroom!";
  line[4] = "";
  line[5] = "You rush in and sit in a random seat near the back.";
  line[6] = "Everyone's already here.";
  line[7] = "";
  line[6] = "In your hurry, you didn't notice you sat beside a girl.";
  line[7] = "";
  line[8] = "'Wow, she's pretty', you think to yourself.";
  line[9] = "";
  line[10] = "You notice that she's sitting a little unconfomfortably.";
  line[11] = "Like maybe she doesn't want to be here";
  line[12] = "";
  line[13] = "'Maybe she's a little shy...'";
  line[14] = "";
  line[15] = "The door bursts open and a young man - probably still in his early twenties -";
  line[16] = "trudges in. His hair is unkempt and sticking up at weird places. Like he just rolled out of bed";
  line[17] = "before coming in.";
  line[18] = "";
  line[19] = "'Is this supposed to be our teacher?'";
  line[20] = "";
  line[21] = "Teacher: Yes, I am in fact your teacher, children... Unfortunately.";
  line[22] = "";
  line[23] = "'Did I say that out loud?'";
  line[24] = "";
  line[25] = "Teacher: No, you did not.";
  line[26] = "";
  line[27] = "'DOES THIS DUDE READ MINDS?'";
  line[28] = "";
  line[29] = "Teacher: And I also do not read minds. I just know that's what you're all thinking.";
  line[30] = "\tI don't really care what you all think though. I'm just here to do my job.";
  line[31] = "";
  line[32] = "Teacher: My name is Mr. K. Don't ask. Just call me Mr. K.";
  line[33] = "";
  line[34] = "Mr. K: I'll be your adviser and your Computer Science teacher for this semester.";
  line[35] = "";
  line[36] = "Mr. K: I like a lot of things. I dislike a lot more things.";
  line[37] = "Now I think that's enough about me.";
  line[38] = "";
  line[39] = "Mr.K: It's time for you to introduce yourselves.";
  line[40] = "";
  line[41] = "He scans the room with his droopy dull black eyes and comes to rest on the girl beside you.";
  line[42] = "";
  line[43] = "Mr. K: Let's start with you. The girl at the back.";
  line[44] = "";
  line[45] = "All eyes in the class turn to her. She pales and hesitates. She looks absolutely terrified.";
  line[46] = "";
  line[47] = "Maybe you should say something. What do you want to say?";

//Setting Options
  int options = 3;
  const char *option[options];
  option[0]="Pssst. Don't be scared. You can do it!";
  option[1]=".......";
  option[2]="Hey, hurry up.";

  int choice = createGameScreen(line, lines, option, options, _eventInfo);
  
  switch(choice){
    case 1:
      _eventInfo.nextEvent = 21; //branchOne
      _eventInfo.iPA += 25
      _eventInfo.end = 1;
      break;
    case 2:
      _eventInfo.nextEvent = 22; // branchTwo
      _eventInfo.end = 1;
      break;
    case 3:
      _eventInfo.nextEvent = 23; //branchThree
      _eventInfo.iPA -= 10
      _eventInfo.end = 1;
    default:
      _eventInfo.errorCode = 2; 
      _eventInfo.end = 1;
  }
  
  return _eventInfo;
}


