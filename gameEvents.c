#include <stdio.h>
#include <string.h>
#include "gameInfo.h"
#include "hud.h"

gameInfo mainMenu(gameInfo _eventInfo){
  printf("\nMain Menu\n");

  //Setting Options
  char options[3][50];
  int numberOptions = 3;
  strcpy(options[0], "Start Game");
  strcpy(options[1], "Exit Game");
  strcpy(options[2], "Debug");

  //Prints the options
  printMenu(options, numberOptions);
#include "hud.h"
  
  //Scans for the choice
  int optionLoopEnd = 0;
  int option = 0;
  while (optionLoopEnd == 0){

    printf("\nPlease enter your choice:\n> ");
    scanf("%i", &option);

    if (option == 1){
      _eventInfo.nextEvent = 20; // startGame
      _eventInfo.end = 1;
      optionLoopEnd = 1;
    }
    else if (option == 2){
      _eventInfo.nextEvent = 100000; // exitGame
      _eventInfo.end = 1;
      optionLoopEnd = 1;
    }
    else if (option == 3){
      _eventInfo.nextEvent = 11;
      _eventInfo.end = 1;
      optionLoopEnd = 1;
    }
    else {
      option = 0;
      printError();
      printHUD(_eventInfo);
      printMenu(options, numberOptions);
    }
  }

  return _eventInfo;
}

gameInfo debug(gameInfo _eventInfo){
  int eventCode = 0;
  printf("\nDebug Menu\n");
  printf("Please enter an event code to move to that event: ");
  scanf("%i", &eventCode);

  _eventInfo.nextEvent = eventCode;
  _eventInfo.end = 1;

  return _eventInfo;
}

// gameInfo talkMenu(gameInfo _eventInfo){
//   printf("\nWho do you want to talk to?\n");
//   //Setting Options
//   char options[3][50];
//   int numberOptions = 3;
//   strcpy(options[0], "A");
//   strcpy(options[1], "B");
//   strcpy(options[2], "C");

//   //Prints the options
//   printMenu(options, numberOptions);

//   //Scans for the choiceu
//   int optionLoopEnd = 0;
//   int option = 0;
//   while (optionLoopEnd == 0){

//     printf("\nPlease enter your choice:\n> ");
//     scanf("%i", &option);

//     if (option == 1){
//       _eventInfo.nextEvent = 11; // talkWithA
//       _eventInfo.end = 1;
//       optionLoopEnd = 1;
//     }
//     else if (option == 2){
//       _eventInfo.nextEvent = 12; // talkWithB
//       _eventInfo.end = 1;
//       optionLoopEnd = 1;
//     }
//     else if (option == 2){
//       _eventInfo.nextEvent = 13; // talkWithC
//       _eventInfo.end = 1;
//       optionLoopEnd = 1;
//     }
//     else {
//       option = 0;
//       printError();
//       printHUD(_eventInfo);
//       printMenu(options, numberOptions);
//     }
//   }

//   return _eventInfo;
// }
// */

//First day
gameInfo firstOne(gameInfo _eventInfo){
  printf("\nWelcome to P University, the premier university of P country.\n");
  printf("\nIt's your first day as a BS Computer Science major and oh no! You're running late!\n");
  continuePrompt(_eventInfo);
  printf("\nQuick! Get into your classroom. You rush in and sit in a random seat near the back.\n");
  printf("\nYou look around you, everyone's already here.\n");
  continuePrompt(_eventInfo);
  printf("\nIn your hurry, you didn't notice you sat beside a girl.\n");
  printf("\n'Wow, she's pretty', you think to yourself.\n");
  continuePrompt(_eventInfo);
  printf("\nYou notice that she's sitting a little uncomfortably,\nlike she doesn't want to be seen...\n");
  printf("\n'Maybe she's a little shy...'");
  continuePrompt(_eventInfo);
  printf("\nThe door bursts open again and a young man - probably still in his early twenties - trudges in\n");
  printf("\nHis hair is unkempt and sticking up at weird places,\nlike he just rolled out of bed right before coming in.\n");
  continuePrompt(_eventInfo);
  printf("\n'Is this supposed to be our teacher?'\n");
  printf("\nTeacher: Yes, I am in fact your teacher, children... Unfortunately.");
  continuePrompt(_eventInfo);
  printf("\n'Did I say that out loud?'\n");
  printf("\nTeacher: No, you did not.\n");
  continuePrompt(_eventInfo);
  printf("\n'DOES THIS DUDE READ MINDS?'");
  printf("\nTeacher: And I also do not read minds. I just know that's what you're all thinking.\n");
  continuePrompt(_eventInfo);
  printf("\nTeacher I don't really care what you all think though. I'm just here to do my job.\n");
  printf("\nTeacher: My name is Mr. K. Don't ask. Just call me Mr. K.\n");
  continuePrompt(_eventInfo);
  printf("\nMr. K: I'll be your adviser and your Computer Science teacher for this semester.\n");
  printf("\nMr. K: I like a lot of things. I dislike a lot more things.\nNow I think that's enough about me.\n");
  continuePrompt(_eventInfo);
  printf("\nMr.K: Introduce yourselves. Lets start at the back.\n");
  printf("\nHe scans the room with his droopmainMenu dull black eyes and comes to rest on the girl beside you.\n");
  continuePrompt(_eventInfo);
  printf("\nMr. K: Let's start with you. The girl at the back.\n");
  printf("\nAll eyes in the class turn to her. She pales and hesitates. She looks absolutely terrified.\n");
  continuePrompt(_eventInfo);
  printf("\nMaybe you should say something. What do you want to say?\n");

  //Setting Options
  char options[3][50];
  int numberOptions = 3;
  strcpy(options[0], "'Pssst. Don't be scared. You can do it!'");
  strcpy(options[1], "......");
  strcpy(options[2], "'Hey, hurry up.'");
  //Prints the options
  printMenu(options, numberOptions);
  
  //Scans for the choice
  int optionLoopEnd = 0;
  int option = 0;
  while (optionLoopEnd == 0){

    printf("\nPlease enter your choice:\n> ");
    scanf("%i", &option);

    if (option == 1){
      _eventInfo.nextEvent = 21; // branchOne
      _eventInfo.end = 1;
      _eventInfo.iPA += 25;
      optionLoopEnd = 1;
    }
    else if (option == 2){
      _eventInfo.nextEvent = 22; // branchTwo
      _eventInfo.end = 1;
      _eventInfo.iPA = 0;
      optionLoopEnd = 1;
    }
    else if (option == 3){
      _eventInfo.nextEvent = 23; // branchThree
      _eventInfo.end = 1;
      _eventInfo.iPA -= 10;
      optionLoopEnd = 1;
    }
    else {
      option = 0;
      printError();
      printHUD(_eventInfo);
      printMenu(options, numberOptions);
    }
  }

  return _eventInfo;
}

//Result of option 1 in dayFirst
gameInfo branchOne(gameInfo _eventInfo){
  printf("\nThe girl is startled and jumps up in her seat.\n");
  printf("\nThere is determination in her eyes as she opens her mouth to speak\n");

  printf("\nGirl: Good morning, everyone! My name is Chi-chi Santiago.\nPlease call me Chi-chi! Thank you!\n");
  printf("\nThe girl, Chi-chi, sits down hurriedly with color in her cheeks.\n");

  printf("\nShe looks at you from under her lashes and flashes you a small smile.\n");
  printf("\nChi-Chi: Thank you.\n");

  printf("\nShe looks really pretty when she smiles.\n");
  printf("\nMr. K: Thank you, Chi-chi.\n");

  //Setting Options
  char options[1][50];
  int numberOptions = 1;
  strcpy(options[0], "Next");

  //Prints the options
  printMenu(options, numberOptions);

  //Scans for the choiceu
  int optionLoopEnd = 0;
  int option = 0;
  while (optionLoopEnd == 0){

    printf("\nPress Next to begin\n> ");
    scanf("%i", &option);

    if (option == 1){
      _eventInfo.nextEvent = 24; // firstTwo
      _eventInfo.end = 1;
      optionLoopEnd = 1;
    }
    else {
      option = 0;
      printError();
      printHUD(_eventInfo);
      printMenu(options, numberOptions);
    }
  }

  return _eventInfo;

}

//Result of option 2 in dayFirst
gameInfo branchTwo(gameInfo _eventInfo){
  printf("\nThe girl slowly gets up from her seat and plays with her hair absentmindedly.\n");
  printf("\nGirl: Umm... My.. name is.. Chi-chi Santiago. It'snicetomeetyou!\n");

  printf("\nWith that, she falls back into her seat\nand dips her head, hiding behind her hair.\n");
  printf("\n'Wow she's really shy..'\n");

  printf("\nMr. K: Oookay, thank you, uh, Chi-chi.\n");

  //Setting Options
  char options[1][50];
  int numberOptions = 1;
  strcpy(options[0], "Next");

  //Prints the options
  printMenu(options, numberOptions);

  //Scans for the choiceu
  int optionLoopEnd = 0;
  int option = 0;
  while (optionLoopEnd == 0){

    printf("\nPress Next\n> ");
    scanf("%i", &option);

    if (option == 1){
      _eventInfo.nextEvent = 24; // firstTwo
      _eventInfo.end = 1;
      optionLoopEnd = 1;
    }
    else {
      option = 0;
      printError();
      printHUD(_eventInfo);
      printMenu(options, numberOptions);
    }
  }

  return _eventInfo;
}

//Result of option 3 in dayFirstu
gameInfo branchThree(gameInfo _eventInfo){
  printf("\nShe looks even more scared and jumps in her seat all started.\n");
  printf("\nGirl: Ah! Um, I'm sorry! M-my name is Chi-chi.. Chi-chi Santiago!\nIt's nice to meet you all!\n");

  printf("\nShe sits and hides behind her hair. She looks slightly red.\n");
  printf("\nShe looks incredibly embarassed.\n");

  printf("\nMr. K: Okay, thank you, Chi-chi.\n");

  //Setting Options
  char options[1][50];
  int numberOptions = 1;
  strcpy(options[0], "Next");

  //Prints the options
  printMenu(options, numberOptions);

  //Scans for the choiceu
  int optionLoopEnd = 0;
  int option = 0;
  while (optionLoopEnd == 0){

    printf("\nPress Next\n> ");
    scanf("%i", &option);

    if (option == 1){
      _eventInfo.nextEvent = 21; // firstTwo
      _eventInfo.end = 1;
      optionLoopEnd = 1;
    }
    else {
      option = 0;
      printError();
      printHUD(_eventInfo);
      printMenu(options, numberOptions);
    }
  }

  return _eventInfo;
}

//First Day part 2
gameInfo firstTwo(gameInfo _eventInfo){
  printf("\nMr. K: Okay onto the next person.\n");
  printf("\nHe looks at you as expectantly as his lazy eyes could. You begin to stand.\n");

  printf("\nKnock! Knock!\n");
  printf("\nThe door opens and reveals a handsome dark haired boy. He looks at Mr. K with a scowl.\n");

  printf("\nBoy: Yo, Mr. K,  got a minute? It's about the CMSC Club.\n");
  printf("\nMr. K: Good of you to barge in, Jeff. We're kind of in the middle of something.\n");

  printf("\nMr. K: By the way, everyone, this trespasser is Jeff Papadopolis, the CMSC Club president.\n");
  printf("\nJeff: Yeah, my name's Jeff and this bum is the CMSC Club Adviser.\n");

  printf("\nMr. K sighs defeatedly and mumbles to himself.\nMr. K: So rude so early in the morning...\n");
  printf("\nJeff looks around and notices you're the only one standing.\n");

  printf("\nJeff chuckles.\n");
  printf("\nJeff: What's this dumbface doing?\n");

  printf("\nMr. K: We were in the middle of introductions when you barged in...\n");
  printf("\nJeff: Then by all means, go ahead, dumbface.\n");

  printf("\nWow, he's rude. What do you want to do?\n");

  //Setting Options
  char options[2][50];
  int numberOptions = 2;
  strcpy(options[0], "Introduce yourself nicely.");
  strcpy(options[1], "'Be rude back");
  //Prints the options
  printMenu(options, numberOptions);
  
  //Scans for the choice
  int optionLoopEnd = 0;
  int option = 0;
  while (optionLoopEnd == 0){

    printf("\nPlease enter your choice:\n> ");
    scanf("%i", &option);

    if (option == 1){
      _eventInfo.nextEvent = 25; // branchFour
      _eventInfo.end = 1;
      _eventInfo.iPB -= 10;
      _eventInfo.iPC += 25;
      optionLoopEnd = 1;
    }
    else if (option == 2){
      _eventInfo.nextEvent = 26; // branchFive
      _eventInfo.end = 1;
      _eventInfo.iPB += 25;
      _eventInfo.iPC -= 10;
      optionLoopEnd = 1;
    }
    else {
      option = 0;
      printError();
      printHUD(_eventInfo);
      printMenu(options, numberOptions);
    }
  }

  return _eventInfo;
}

//Result of option 1 for dayFirst_Two
// gameInfo branchFour(gameInfo _eventInfo){
//   printf("\nYou introduce yourself - your name and age - normally.\n");
//   printf("\nJeff looks slightly disappointed you didn't rise to his taunts.\n");

//   printf("\nMr. K looks relieved.\n");
//   printf("\nYou sit back down, satisfied.\n");

//   continuePrompt(_eventInfo);
//   _eventInfo.nextEvent = 27;
//   _eventInfo.end = 0;
//   return _eventInfo;
// }

gameInfo branchFour(gameInfo _eventInfo){
  printf("\nYou introduce yourself - your name and age - normally.\n");
  printf("\nJeff looks slightly disappointed you didn't rise to his taunts.\n");
  continuePrompt(_eventInfo);
  printf("\nMr. K looks relieved.\n");
  printf("\nYou sit back down, satisfied.\n");

//Setting Options
  char options[1][50];
  int numberOptions = 1;
  strcpy(options[0], "Next");

  //Prints the options
  printMenu(options, numberOptions);

  //Scans for the choiceu
  int optionLoopEnd = 0;
  int option = 0;
  while (optionLoopEnd == 0){

    printf("\nPress Next\n> ");
    scanf("%i", &option);

    if (option == 1){
      _eventInfo.nextEvent = 27; // firstThree
      _eventInfo.end = 1;
      optionLoopEnd = 1;
    }
    else {
      option = 0;
      printError();
      printHUD(_eventInfo);
      printMenu(options, numberOptions);
    }
  }

  return _eventInfo;
}

//Result of option 2 for dayFirst_Two
gameInfo branchFive(gameInfo _eventInfo){
  printf("\nJeff bursts out laughing. The whole class stirs in their seats.\n");
  printf("\nChi-chi besides you squeaks. Was that a laugh?\n");

  printf("\nMr. K sighs in defeat yet again. He looks like he would rather be at home right now.\n");
  printf("\nJeff: I like your spunk, dumbface.\n");

  printf("\nFor some reason, the grin on his face is more menacing than endearing.\n");
  printf("\nYou sit back down.\n");

//Setting Options
  char options[1][50];
  int numberOptions = 1;
  strcpy(options[0], "Next");

  //Prints the options
  printMenu(options, numberOptions);

  //Scans for the choiceu
  int optionLoopEnd = 0;
  int option = 0;
  while (optionLoopEnd == 0){

    printf("\nPress Next\n> ");
    scanf("%i", &option);

    if (option == 1){
      _eventInfo.nextEvent = 27; // firstThree
      _eventInfo.end = 1;
      optionLoopEnd = 1;
    }
    else {
      option = 0;
      printError();
      printHUD(_eventInfo);
      printMenu(options, numberOptions);
    }
  }

  return _eventInfo;
}

//First Day part 3
gameInfo firstThree(gameInfo _eventInfo){
  printf("\nJeff turns to the rest of the class.\n");
  printf("\nJeff: Come join the CMSC club.\nIt's open to all CMSC majors and we're having a meeting later this afternoon.\n");

  printf("\nJeff: Yall better come if you want to get good at this course\nbecause trust me yall greenies need the help.\n");
  printf("\nMr. K clears his throat. He's starting to look annoyed.\n");

  printf("\nMr. K: Ooookay, thank you very much for the commercial break, Jeff.\nNow shoo, I'm teaching. See me later.\n");
  printf("\nJeff: Whatever, I'm out. Bye.\n");

  printf("\nHe leaves and Mr. K heaves a sigh of relief.\nYou've lost count of how many times he's sighed today.\n");
  printf("\nMr. K: Okay now that that public disturbance has left,\nlet's continue. Next person please.\n");

  printf("\nClass continues for the rest of the day.\nYou listen as everyone introduces themselves.\n");
  printf("\nAt some point, you notice Mr. K has not so discreetly\ntaken out a book and has begun reading.\n");

  printf("\nClass finally ends and you all stand to go.\n");
  printf("\nFirst Day: COMPLETE!");

  printf("\nNext chapter is 'The CMSC Club.'\n");

//Setting Options
  char options[1][50];
  int numberOptions = 1;
  strcpy(options[0], "Proceed");

  //Prints the options
  printMenu(options, numberOptions);

  //Scans for the choiceu
  int optionLoopEnd = 0;
  int option = 0;
  while (optionLoopEnd == 0){

    printf("\nPress Next\n> ");
    scanf("%i", &option);

    if (option == 1){
      _eventInfo.nextEvent = 28; // cmscClub
      _eventInfo.end = 1;
      optionLoopEnd = 1;
    }
    else {
      option = 0;
      printError();
      printHUD(_eventInfo);
      printMenu(options, numberOptions);
    }
  }

  return _eventInfo;
}

/* nextEvent code guides 
* 0 = Main Menu
* 10 = Start Game
* 11 = Talk with A
* 12 = Talk with B
* 13 = Talk with C
* 20 = First Day 1
* 21 = First Day Branch 1
* 22 = First Day Branch 2
* 23 = First Day Branch 3
* 24 = First Day 2
* 25 = First Day Branch 4
* 26 = First Day Branch 5
* 27 = First Day 3
* 28 = CMSC Club
* 100000 = Exit Game
*/