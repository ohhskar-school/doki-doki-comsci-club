#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "battleSystemRewrite.h"
#include "gameInfo.h"
#include "hud.h"

gameInfo mainMenu(gameInfo _eventInfo) {
    int lines = 6;
    const char *line[lines];
    int choice = 0;
    line[0] = "Welcome to Doki Doki CMSC Club!";
    line[1] = "Where your college love story awaits!";
    line[2] = "";
    line[3] = "Use the ARROW KEYS to move between options";
    line[4] = "Press ENTER to select!";
    line[5] = "";

    //Setting Options
    int options = 4;
    const char *option[options];
    option[0] = "Start Game";
    option[1] = "Exit Game";
    option[2] = "Debug";
    option[3] = "Fight";

    choice = createGameScreen(line, lines, option, options, _eventInfo);

    switch (choice) {
        case 0:
            _eventInfo.nextEvent = 10;
            _eventInfo.end = 0;
            break;
        case 1:
            _eventInfo.nextEvent = 100000;
            _eventInfo.end = 1;
            break;
        case 2:
            _eventInfo.nextEvent = 10;
            _eventInfo.end = 1;
        case 3: {
            int result = 0;
            result = bossBattle(0, _eventInfo);
            break;
        }
        default:
            _eventInfo.errorCode = 2;
            _eventInfo.end = 1;
    }

    return _eventInfo;
}

gameInfo dayOne(gameInfo _eventInfo) {
    int lines = 50;
    const char *line[lines];
    int choice = 0;

    line[0] = "Welcome to P University, the premier university in the country!";
    line[1] = "";
    line[2] = "It's your first day as a BS Computer Science major and oh no! You're running late!";
    line[3] = "Quick get into your classroom!";
    line[4] = "";
    line[5] = "You rush in and sit in a random seat near the back.";
    line[6] = "Everyone's already here.";
    line[7] = "";
    line[8] = "In your hurry, you didn't notice you sat beside a girl.";
    line[9] = "";
    line[10] = "'Wow, she's pretty', you think to yourself.";
    line[11] = "";
    line[12] = "You notice that she's sitting a little unconfomfortably.";
    line[13] = "Like maybe she doesn't want to be here";
    line[14] = "";
    line[15] = "'Maybe she's a little shy...'";
    line[16] = "";
    line[17] = "The door bursts open and a young man - probably still in his early twenties -";
    line[18] = "trudges in. His hair is unkempt and sticking up at weird places. Like he just rolled out of bed before coming in.";
    line[19] = "";
    line[20] = "'Is this supposed to be our teacher?'";
    line[21] = "";
    line[22] = "Teacher: Yes, I am in fact your teacher, children... Unfortunately.";
    line[23] = "";
    line[24] = "'Did I say that out loud?'";
    line[25] = "";
    line[26] = "Teacher: No, you did not.";
    line[27] = "";
    line[28] = "'DOES THIS DUDE READ MINDS?'";
    line[29] = "";
    line[30] = "Teacher: And I also do not read minds. I just know that's what you're all thinking.";
    line[31] = "I don't really care what you all think though. I'm just here to do my job.";
    line[32] = "";
    line[33] = "Teacher: My name is Mr. K. Don't ask. Just call me Mr. K.";
    line[34] = "";
    line[35] = "Mr. K: I'll be your adviser and your Computer Science teacher for this semester.";
    line[36] = "";
    line[37] = "Mr. K: I like a lot of things. I dislike a lot more things.";
    line[38] = "Now I think that's enough about me.";
    line[39] = "";
    line[40] = "Mr.K: It's time for you to introduce yourselves.";
    line[41] = "";
    line[42] = "He scans the room with his droopy dull black eyes and comes to rest on the girl beside you.";
    line[43] = "";
    line[44] = "Mr. K: Let's start with you. The girl at the back.";
    line[45] = "";
    line[46] = "All eyes in the class turn to her. She pales and hesitates. She looks absolutely terrified.";
    line[47] = "";
    line[48] = "Maybe you should say something. What do you want to say?";
    line[49] = "";

    //Setting Options
    int options = 3;
    const char *option[options];
    option[0] = "Pssst. Don't be scared. You can do it!";
    option[1] = ".......";
    option[2] = "Hey, hurry up.";

    choice = createGameScreen(line, lines, option, options, _eventInfo);

    switch (choice) {
        case 0:
            _eventInfo.nextEvent = 10;
            _eventInfo.end = 1;
            break;
        case 1:
            _eventInfo.nextEvent = 100000;
            _eventInfo.end = 1;
            break;
        case 2:
            _eventInfo.nextEvent = 10;
            _eventInfo.end = 1;
        default:
            _eventInfo.errorCode = 2;
            _eventInfo.end = 1;
    }

    return _eventInfo;
}