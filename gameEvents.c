#include "battleSystem.h"
#include "gameInfo.h"
#include "hud.h"

gameInfo splashScreenEvent(gameInfo _eventInfo) {
    disclaimerScreen();
    presentsScreen();
    splashScreen();

    _eventInfo.nextEvent = 1001;  //battleOne
    return _eventInfo;
}

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
    int options = 3;
    const char *option[options];
    option[0] = "Start Game";
    option[1] = "Exit Game";
    option[2] = "Debug";

    choice = createGameScreen(line, lines, option, options, _eventInfo);

    switch (choice) {
        case 0:
            _eventInfo.nextEvent = 2;  //SplashScreen
            _eventInfo.end = 0;
            break;
        case 1:
            _eventInfo.nextEvent = 100000;  //exitGame
            _eventInfo.end = 1;
            break;
        case 2:
            _eventInfo.nextEvent = 10;
            _eventInfo.end = 1;
            break;
        default:
            _eventInfo.errorCode = 2;
            _eventInfo.end = 1;
            break;
    }

    return _eventInfo;
}

//After battleOne
gameInfo homeOne(gameInfo _eventInfo) {
    int lines = 5;
    const char *line[lines];
    int choice = 0;

    line[0] = "Bzzzt...";
    line[1] = ".......";
    line[2] = "";
    line[3] = "BZZZZZZZZZZZZZZZT";
    line[4] = "";

    //Setting Options
    int options = 1;
    const char *option[options];
    option[0] = "Wake up!";

    choice = createGameScreen(line, lines, option, options, _eventInfo);

    switch (choice) {
        case 0:
            _eventInfo.nextEvent = 302;
            _eventInfo.end = 0;
            break;
        default:
            _eventInfo.errorCode = 2;
            _eventInfo.end = 1;
            break;
    }

    return _eventInfo;
}

gameInfo homeTwo(gameInfo _eventInfo) {
    int lines = 22;
    const char *line[lines];
    int choice = 0;

    line[0] = "Me: WAAHH! Please don't give me a 5.0 in Math!!";
    line[1] = "*heavy breathing*";
    line[2] = "";
    line[3] = "Bzzzt... Bzzzt....";
    line[4] = "";
    line[5] = "I turn off my alarm and look around me.";
    line[6] = "I'm not in a battle against a math ghost.";
    line[7] = "I'm in room and it's 7AM.";
    line[8] = "";
    line[9] = "Me: What a horrible dream...";
    line[10] = "";
    line[11] = "Why do I have a feeling that I'm supposed to be somewhere..";
    line[12] = "I catch a glimpse of my alarm clock again.";
    line[13] = "It's 7AM...";
    line[14] = "";
    line[15] = "Me: Oh no! It's 7AM, I'm late for my first day!";
    line[16] = "";
    line[17] = "The next few minutes were a blur of taking a shower,";
    line[18] = "breakfast with my mom, and running outside the house.";
    line[19] = "";
    line[20] = "How should I get to school?";
    line[21] = "";

    //Setting Options
    int options = 2;
    const char *option[options];
    option[0] = "RUN";
    option[1] = "Ride a jeepney";

    choice = createGameScreen(line, lines, option, options, _eventInfo);

    switch (choice) {
        case 0:
            _eventInfo.nextEvent = 311;
            _eventInfo.interestPoints[1] += 25;  //interestPoints[1] is Mr. K
            _eventInfo.end = 0;
            break;
        case 1:
            _eventInfo.nextEvent = 312;
            _eventInfo.interestPoints[0] += 25;  //interestPoints[0] is Jeff
            _eventInfo.end = 0;
            break;
        default:
            _eventInfo.errorCode = 2;
            _eventInfo.end = 1;
            break;
    }

    return _eventInfo;
}

gameInfo homePathOne(gameInfo _eventInfo) {
    int lines = 14;
    const char *line[lines];
    int choice = 0;

    line[0] = "I think school's close enough and riding a jeepney";
    line[1] = "would just be a waste of 7 pesos so I run.";
    line[2] = "";
    line[3] = "I run with all my might, dodging pedestrians";
    line[4] = "and the occassional random bystander yelling to me,";
    line[5] = "'WHY ARE YOU RUNNING?'";
    line[6] = "";
    line[7] = "A few blocks and I see it! I'm almost there!";
    line[8] = "";
    line[9] = "I accidentally bump into a young man with unkempt hair and lazy slouch";
    line[10] = "I'm way too late to care and look back so I just keep running.";
    line[11] = "";
    line[12] = "And there it is! I'm finally here!";
    line[13] = "";

    //Setting Options
    int options = 1;
    const char *option[options];
    option[0] = "Go in!";

    choice = createGameScreen(line, lines, option, options, _eventInfo);

    switch (choice) {
        case 0:
            _eventInfo.nextEvent = 100;
            _eventInfo.end = 0;
            break;
        default:
            _eventInfo.errorCode = 2;
            _eventInfo.end = 1;
            break;
    }

    return _eventInfo;
}

gameInfo homePathTwo(gameInfo _eventInfo) {
    int lines = 18;
    const char *line[lines];
    int choice = 0;

    line[0] = "Running is way too much of a risk!";
    line[1] = "I play it safe and ride a jeepney.";
    line[2] = "";
    line[3] = "Fortunately, I get on one immediately and it";
    line[4] = "speeds away to the general direction of school.";
    line[5] = "";
    line[6] = "Unfortunately for me, I barely have any room to squeeze in.";
    line[7] = "I'm literally sitting on air.";
    line[8] = "";
    line[9] = "My legs were about to give when finally, I'm here!";
    line[10] = "I hurry to get down until a voice calls out to me.";
    line[11] = "";
    line[12] = "Conductor: Oy! Pliti nimo!";
    line[13] = "Me: Ahh!! Sorry kaayo, kuya!";
    line[14] = "";
    line[15] = "How embarrassing!!";
    line[16] = "I pay quickly and run off to the school gates.";
    line[17] = "";

    //Setting Options
    int options = 1;
    const char *option[options];
    option[0] = "I'm finally here!";

    choice = createGameScreen(line, lines, option, options, _eventInfo);

    switch (choice) {
        case 0:
            _eventInfo.nextEvent = 100;
            _eventInfo.end = 0;
            break;
        default:
            _eventInfo.errorCode = 2;
            _eventInfo.end = 1;
            break;
    }

    return _eventInfo;
}

gameInfo dayOne(gameInfo _eventInfo) {
    int lines = 52;
    const char *line[lines];
    int choice = 0;

    line[0] = "'Welcome to P University, the premier university in the country!'";
    line[1] = "That's what the huge banner greeted me when I walked into the university.";
    line[2] = "It's my first day as a BS Computer Science major and OH NO!";
    line[3] = "I'M ALREADY LATE FOR MY FIRST CLASS! Where's my classroom?!";
    line[4] = "";
    line[5] = "There it is! I rush in and sit in a random seat near the back.";
    line[6] = "Everyone's already here.";
    line[7] = "";
    line[8] = "Beside me is a girl sitting by herself.";
    line[9] = "";
    line[10] = "'Wow, she's pretty', I think to myself.";
    line[11] = "";
    line[12] = "She's sitting a little unconfomfortably.";
    line[13] = "Like maybe she doesn't want to be here";
    line[14] = "Maybe she's a little shy...";
    line[15] = "";
    line[16] = "The door bursts open and a young man - probably still in his early twenties -";
    line[17] = "trudges in. His hair is unkempt and sticking up at weird places.";
    line[18] = "Like he just rolled out of bed before coming in.";
    line[19] = "";
    line[20] = "Is this supposed to be our teacher?";
    line[21] = "";
    line[22] = "Teacher: Yes, I am in fact your teacher, children... Unfortunately.";
    line[23] = "";
    line[24] = "Did I say that out loud?";
    line[25] = "";
    line[26] = "Teacher: No, you did not.";
    line[27] = "";
    line[28] = "DOES THIS DUDE READ MINDS?";
    line[29] = "";
    line[30] = "Teacher: I also do not read minds. I just know that's what you're all thinking.";
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
    line[42] = "He scans the room with his droopy dull black eyes.";
    line[43] = "They come to rest on the girl sitting beside me.";
    line[44] = "";
    line[45] = "Mr. K: Let's start with you. The girl at the back.";
    line[46] = "";
    line[47] = "All eyes in the class turn to her.";
    line[48] = "Her eyes in turn widen. She looks absolutely terrified!";
    line[49] = "";
    line[50] = "Maybe I should say something. What do I say?";
    line[51] = "";

    //Setting Options
    int options = 3;
    const char *option[options];
    option[0] = "Pssst. Don't be scared. You can do it!";
    option[1] = ".......";
    option[2] = "Hey, hurry up.";

    choice = createGameScreen(line, lines, option, options, _eventInfo);

    switch (choice) {
        case 0:
            _eventInfo.nextEvent = 201;
            _eventInfo.end = 0;
            break;
        case 1:
            _eventInfo.nextEvent = 202;
            _eventInfo.end = 0;
            break;
        case 2:
            _eventInfo.nextEvent = 203;
            _eventInfo.end = 0;
            break;
        default:
            _eventInfo.errorCode = 2;
            _eventInfo.end = 1;
            break;
    }

    return _eventInfo;
}

gameInfo onePathOne(gameInfo _eventInfo) {
    int lines = 15;
    const char *line[lines];
    int choice = 0;

    line[0] = "The girl startles and jumps up in her seat,";
    line[1] = "as if a ghost poked her in the ribs.";
    line[2] = "";
    line[3] = "Determination flashes in her eyes as she opens her mouth to squeak.";
    line[4] = "";
    line[5] = "Girl: Good morning, everyone! My name is Chi-chi Santiago.";
    line[6] = "Please call me Chi-chi! Thank you!";
    line[7] = "";
    line[8] = "Chi-chi then sits down in a hurry with color in her cheeks.";
    line[9] = "She looks at me from under her lashes and flashes me a small grateful smile.";
    line[10] = "";
    line[11] = "Chi-Chi: Thank you.";
    line[12] = "";
    line[13] = "She looks really pretty when she smiles.";
    line[14] = "";

    //Setting Options
    int options = 2;
    const char *option[options];
    option[0] = "Smile back to her";
    option[1] = ".......";

    choice = createGameScreen(line, lines, option, options, _eventInfo);

    switch (choice) {
        case 0:
            _eventInfo.nextEvent = 101;
            _eventInfo.end = 0;
            break;
        case 1:
            _eventInfo.nextEvent = 101;
            _eventInfo.end = 0;
            break;
        default:
            _eventInfo.errorCode = 2;
            _eventInfo.end = 1;
            break;
    }

    return _eventInfo;
}

gameInfo onePathTwo(gameInfo _eventInfo) {
    int lines = 9;
    const char *line[lines];
    int choice = 0;

    line[0] = "The girl slowly gets up from her seat and speaks in a quiet voice.";
    line[1] = "";
    line[2] = "Girl: Umm... My.. name is.. Chi-chi Santiago. It'snicetomeetyou!";
    line[3] = "";
    line[4] = "With that, she falls back into her seat.";
    line[5] = "She dips her head to hide behind her hair.";
    line[6] = "";
    line[7] = "'Wow she's really shy...'";
    line[8] = "";

    //Setting Options
    int options = 2;
    const char *option[options];
    option[0] = "Ignore her.";
    option[1] = ".......";

    choice = createGameScreen(line, lines, option, options, _eventInfo);

    switch (choice) {
        case 0:
            _eventInfo.nextEvent = 101;
            _eventInfo.end = 0;
            break;
        case 1:
            _eventInfo.nextEvent = 101;
            _eventInfo.end = 0;
            break;
        default:
            _eventInfo.errorCode = 2;
            _eventInfo.end = 1;
            break;
    }

    return _eventInfo;
}

gameInfo onePathThree(gameInfo _eventInfo) {
    int lines = 9;
    const char *line[lines];
    int choice = 0;

    line[0] = "She looks even more scared and jumps in her seat all started.";
    line[1] = "";
    line[2] = "Girl: Ah! Um, I'm sorry! M-my name is Chi-chi.. Chi-chi Santiago!";
    line[3] = "It's nice to meet you all!";
    line[4] = "";
    line[5] = "She sits and hides behind her hair. She looks slightly red.";
    line[6] = "";
    line[7] = "I have a feeling I should have said something nicer...";
    line[8] = "";

    //Setting Options
    int options = 2;
    const char *option[options];
    option[0] = "'Sorry, you did good.'";
    option[1] = ".......";

    choice = createGameScreen(line, lines, option, options, _eventInfo);

    switch (choice) {
        case 0:
            _eventInfo.nextEvent = 101;
            _eventInfo.end = 0;
            break;
        case 1:
            _eventInfo.nextEvent = 101;
            _eventInfo.end = 0;
            break;
        default:
            _eventInfo.errorCode = 2;
            _eventInfo.end = 1;
            break;
    }

    return _eventInfo;
}

gameInfo dayOneCont(gameInfo _eventInfo) {
    int lines = 31;
    const char *line[lines];
    int choice = 0;

    line[0] = "Mr. K: Okay, uh, thank you, Chichi.";
    line[1] = "Onto the next person.";
    line[2] = "";
    line[3] = "He looks at me as expectantly as his lazy eyes could. I begin to stand.";
    line[4] = "";
    line[5] = "Knock! Knock!";
    line[6] = "";
    line[7] = "The door opens and reveals a handsome dark haired boy.";
    line[8] = "He looks at Mr. K with a scowl.";
    line[9] = "";
    line[10] = "Boy: Yo, Mr. K,  got a minute? It's about the CMSC Club.";
    line[11] = "";
    line[12] = "Mr. K: Good of you to barge in, Jeff. We're kind of in the middle of something.";
    line[13] = "Btw, everyone, this trespasser is Jeff Papadopolis, the CMSC Club president.";
    line[14] = "";
    line[15] = "Jeff: Yeah, my name's Jeff and this bum is the CMSC Club Adviser.";
    line[16] = "";
    line[17] = "Mr. K sighs defeatedly and mumbles to himself.";
    line[18] = "Mr. K: So rude so early in the morning...";
    line[19] = "";
    line[20] = "Jeff looks around and notices I'm the only one standing.";
    line[21] = "Jeff chuckles.";
    line[22] = "";
    line[23] = "Jeff: What's this dumbface doing?";
    line[24] = "";
    line[25] = "Mr. K: We were in the middle of introductions when you barged in...";
    line[26] = "";
    line[27] = "Jeff: Then by all means, go ahead, dumbface.";
    line[28] = "";
    line[29] = "Wow, he's rude. What do I do?";
    line[30] = "";

    //Setting Options
    int options = 2;
    const char *option[options];
    option[0] = "Introduce myself nicely.";
    option[1] = "Be rude back.";

    choice = createGameScreen(line, lines, option, options, _eventInfo);

    switch (choice) {
        case 0:
            _eventInfo.nextEvent = 204;
            _eventInfo.interestPoints[1] += 25;
            _eventInfo.end = 0;
            break;
        case 1:
            _eventInfo.nextEvent = 205;
            _eventInfo.interestPoints[0] += 25;
            _eventInfo.end = 0;
            break;
        default:
            _eventInfo.errorCode = 2;
            _eventInfo.end = 1;
            break;
    }

    return _eventInfo;
}

gameInfo onePathFour(gameInfo _eventInfo) {
    int lines = 8;
    const char *line[lines];
    int choice = 0;

    line[0] = "I introduce myself - my name and age - normally.";
    line[1] = "";
    line[2] = "Jeff looks slightly disappointed I didn't rise to his taunts.";
    line[3] = "";
    line[4] = "Mr. K looks relieved.";
    line[5] = "";
    line[6] = "I sit back down, satisfied.";
    line[7] = "";

    //Setting Options
    int options = 1;
    const char *option[options];
    option[0] = "........";

    choice = createGameScreen(line, lines, option, options, _eventInfo);

    switch (choice) {
        case 0:
            _eventInfo.nextEvent = 102;
            _eventInfo.end = 0;
            break;
        default:
            _eventInfo.errorCode = 2;
            _eventInfo.end = 1;
            break;
    }

    return _eventInfo;
}

gameInfo onePathFive(gameInfo _eventInfo) {
    int lines = 16;
    const char *line[lines];
    int choice = 0;

    line[0] = "I introduce myself - including my name, likes, and dislikes.";
    line[1] = "'I like pineapples on pizza and dislike people who barge in uninvited.'";
    line[2] = "";
    line[3] = "The whole class stirs in their seats while Jeff just bursts out laughing.";
    line[4] = "";
    line[5] = "Chi-chi squeaks beside me. Was that a laugh?";
    line[6] = "";
    line[7] = "Mr. K sighs in defeat yet again.";
    line[8] = "He looks like he would rather be at home right now.";
    line[9] = "";
    line[10] = "Jeff: I like your spunk, dumbface.";
    line[11] = "";
    line[12] = "For some reason, the grin on his face is more menacing than endearing.";
    line[13] = "";
    line[14] = "I sit back down with a smirk.";
    line[15] = "";

    //Setting Options
    int options = 1;
    const char *option[options];
    option[0] = "........";

    choice = createGameScreen(line, lines, option, options, _eventInfo);

    switch (choice) {
        case 0:
            _eventInfo.nextEvent = 102;
            _eventInfo.end = 0;
            break;
        default:
            _eventInfo.errorCode = 2;
            _eventInfo.end = 1;
            break;
    }

    return _eventInfo;
}

gameInfo dayOneContTwo(gameInfo _eventInfo) {
    int lines = 42;
    const char *line[lines];
    int choice = 0;

    line[0] = "Jeff turns to the rest of the class.";
    line[1] = "";
    line[2] = "Jeff: Come join the CMSC club. It's open to all CMSC majors.";
    line[3] = "We're having a meeting later this afternoon. Yall better come if you want to";
    line[4] = "get good at this course because trust me yall need the help.";
    line[5] = "";
    line[6] = "Mr. K clears his throat. He's starting to look annoyed.";
    line[7] = "";
    line[8] = "Mr. K: Ooookay, thank you very much for the commercial break, Jeff.";
    line[9] = "Now shoo, I'm teaching. See me later.";
    line[10] = "";
    line[11] = "Jeff: Whatever, I'm out. Bye.";
    line[12] = "";
    line[13] = "Jeff finally leaves and Mr. K heaves a sigh of relief.";
    line[14] = "I think I've lost count of how many times he's sighed today.";
    line[15] = "";
    line[16] = "Mr. K: Okay now that that public disturbance has left, let's continue.";
    line[17] = "Next person please.";
    line[18] = "";
    line[19] = "Class continues for the rest of the day.";
    line[20] = "I listen as everyone introduces themselves.";
    line[21] = "";
    line[22] = "At some point, Mr. K has not so discreetly taken out a book";
    line[23] = "and has begun reading.";
    line[24] = "";
    line[25] = "The clock is as slow as ever but yes! The day's finally over!";
    line[26] = "";
    line[27] = "The class starts to leave but then Mr. K stops us";
    line[28] = "Mr. K: Not so fast, kids! Here's your first homework for the school year!";
    line[29] = "";
    line[30] = "He distributes copies of the homework to the entire class.";
    line[31] = "As expected of a premier university, they waste no time!";
    line[32] = "Mr. K: I expect that to be passed by tomorrow.";
    line[33] = "Good bye, and welcome to PU!";
    line[34] = "";
    line[35] = "With that he walks out the door in a hurry.";
    line[36] = "The rest of the class files out after him.";
    line[37] = "";
    line[38] = "Oh wait!";
    line[39] = "That's right! It's the CMSC Club's first meeting later.";
    line[40] = "Should I go?";
    line[41] = "";

    //Setting Options
    int options = 1;
    const char *option[options];
    option[0] = "Yes";

    choice = createGameScreen(line, lines, option, options, _eventInfo);

    switch (choice) {
        case 0:
            _eventInfo.nextEvent = 500;
            _eventInfo.end = 0;
            break;
        default:
            _eventInfo.errorCode = 2;
            _eventInfo.end = 1;
            break;
    }

    return _eventInfo;
}

gameInfo clubOne(gameInfo _eventInfo) {
    int lines = 3;
    const char *line[lines];
    int choice = 0;

    line[0] = "On my way looking for the CMSC Club room,";
    line[1] = "A wild horde of club recruiters suddenly appear!";
    line[2] = "'Join our club!'";

    //Setting Options
    int options = 1;
    const char *option[options];
    option[0] = "AHHHH!!";

    choice = createGameScreen(line, lines, option, options, _eventInfo);

    switch (choice) {
        case 0:
            _eventInfo.nextEvent = 1002;
            _eventInfo.end = 0;
            break;
        default:
            _eventInfo.errorCode = 2;
            _eventInfo.end = 1;
            break;
    }

    return _eventInfo;
}

gameInfo clubOneCont(gameInfo _eventInfo) {
    int lines = 15;
    const char *line[lines];
    int choice = 0;

    line[0] = "Phew! I finally got away from all those club recruiters.";
    line[1] = "";
    line[2] = "I'm starting to feel like I'm getting a little lost here.";
    line[3] = "I rest my hand on a wall and it touches a piece of haphazardly taped bondpaper.";
    line[4] = "";
    line[5] = "'This way to the CMSC Club, losers >>>>'";
    line[6] = "Well, isn't it awfully obvious who made these..";
    line[7] = "";
    line[8] = "The signs lead me to a room in Building C";
    line[9] = "and the door is cracked wide open for visitors.";
    line[10] = "";
    line[11] = "I peek inside, and the only person there is Jeff.";
    line[12] = "He's sitting in one of the desks, doing something on his laptop.";
    line[13] = "Do I go in?";
    line[14] = "";

    //Setting Options
    int options = 3;
    const char *option[options];
    option[0] = "Sure.";
    option[1] = "Why not?";
    option[2] = "Really though, do I have a choice?";

    choice = createGameScreen(line, lines, option, options, _eventInfo);

    switch (choice) {
        case 0:
            _eventInfo.nextEvent = 502;
            _eventInfo.end = 0;
            break;
        case 1:
            _eventInfo.nextEvent = 502;
            _eventInfo.end = 0;
            break;
        case 2:
            _eventInfo.nextEvent = 502;
            _eventInfo.end = 0;
            break;
        default:
            _eventInfo.errorCode = 2;
            _eventInfo.end = 1;
            break;
    }

    return _eventInfo;
}

gameInfo clubOneContTwo(gameInfo _eventInfo) {
    int lines = 5;
    const char *line[lines];
    int choice = 0;

    line[0] = "Me: Knock, knock.";
    line[1] = "";
    line[2] = "Jeff looks up and his face immediately turns sour.";
    line[3] = "Jeff: So you actually decide to show up.";
    line[4] = "";

    //Setting Options
    int options = 2;
    const char *option[options];
    option[0] = "Why wouldn't I when you literally threatened our entire class..";
    option[1] = "I wanna learn. Thought this was the place I could do that.";

    choice = createGameScreen(line, lines, option, options, _eventInfo);

    switch (choice) {
        case 0:
            _eventInfo.nextEvent = 503;
            _eventInfo.interestPoints[0] += 25;
            _eventInfo.end = 0;
            break;
        case 1:
            _eventInfo.nextEvent = 503;
            _eventInfo.interestPoints[0] += 50;
            _eventInfo.end = 0;
            break;
        default:
            _eventInfo.errorCode = 2;
            _eventInfo.end = 1;
            break;
    }

    return _eventInfo;
}

gameInfo clubOneContThree(gameInfo _eventInfo) {
    int lines = 7;
    const char *line[lines];
    int choice = 0;

    line[0] = "Jeff hums to himself and smirks.";
    line[1] = "Jeff: Seems you're not as dumb as you look.";
    line[2] = "He turns his attention back to his laptop.";
    line[3] = "";
    line[4] = "I take this moment to look around me.";
    line[5] = "The only people in the room are me and Jeff.";
    line[6] = "";

    //Setting Options
    int options = 2;
    const char *option[options];
    option[0] = "There doesn't seem to be a lot of people..";
    option[1] = "Is this really the club? There aren't a lot of people.";

    choice = createGameScreen(line, lines, option, options, _eventInfo);

    switch (choice) {
        case 0:
            _eventInfo.nextEvent = 504;
            _eventInfo.end = 0;
            break;
        case 1:
            _eventInfo.nextEvent = 504;
            _eventInfo.end = 0;
            break;
        default:
            _eventInfo.errorCode = 2;
            _eventInfo.end = 1;
            break;
    }

    return _eventInfo;
}

gameInfo clubOneContFour(gameInfo _eventInfo) {
    int lines = 30;
    const char *line[lines];
    int choice = 0;

    line[0] = "Jeff's right eye twitches.";
    line[1] = "Jeff: Wow, thank you, Captain Obvious.";
    line[2] = "But yeah, even though we're a major club,";
    line[3] = "We've been having trouble bringing actual active members in.";
    line[4] = "";
    line[5] = "Me: *under my breath* I wonder why that is..";
    line[6] = "Jeff: What was that?";
    line[7] = "Me: Nothing. Anyway, that sucks.";
    line[8] = "";
    line[9] = "I peek at his laptop screen and -";
    line[10] = "Me: Wait, is that TECKEN?!";
    line[11] = "";
    line[12] = "Jeff: Yeah, now scram.";
    line[13] = "I ignore him.";
    line[14] = "";
    line[15] = "Me: Let's play! I have another controller..";
    line[16] = "Jeff looks at you as if you grew another head.";
    line[17] = "Jeff: What part about scram did you not understand?";
    line[18] = "Me: Hey, I'm just another TECKEN lover here...";
    line[19] = "";
    line[20] = "Jeff looks thoughtful for a moment.";
    line[21] = "Jeff: Okay, let's make a deal. If you beat me, I buy snacks";
    line[22] = "for the meeting this afternoon. Right out of my own pocket.";
    line[23] = "";
    line[24] = "Me: Sweet! Let's go!";
    line[25] = "Jeff: Ah! But if I win, you'll go on a date with me tomorrow evening.";
    line[26] = "";
    line[27] = "WHAT?";
    line[28] = "Me: What? What do you mean date-?";
    line[29] = "Jeff: Too late! Here we go~!";

    //Setting Options
    int options = 1;
    const char *option[options];
    option[0] = "Oh no!";

    choice = createGameScreen(line, lines, option, options, _eventInfo);

    switch (choice) {
        case 0:
            _eventInfo.nextEvent = 1003;
            _eventInfo.end = 0;
            break;
        default:
            _eventInfo.errorCode = 2;
            _eventInfo.end = 1;
            break;
    }

    return _eventInfo;
}

gameInfo clubOneContFive(gameInfo _eventInfo) {
    int lines = 11;
    const char *line[lines];
    int choice = 0;

    line[0] = "Me: NOOOO!";
    line[1] = "Jeff: YES!";
    line[2] = "";
    line[3] = "Jeff pumps his fist into the air and laughs.";
    line[3] = "The defeat wouldn't be as embarrassing as it is if Jeff didn't";
    line[4] = "laugh so much. Then there's also the prospect of going on a date with him...";
    line[5] = "";
    line[6] = "Jeff: Here I thought you were some TECKEN genius.";
    line[8] = "Me: I didn't say I was, I just said I loved the game.";
    line[9] = "Jeff: Whatever. You owe me a date now.";
    line[10] = "";

    //Setting Options
    int options = 2;
    const char *option[options];
    option[0] = "You were actually serious about that?";
    option[1] = "Could you give me some time to think?";
    option[2] = "Hmm, sure okay. Why not.";

    choice = createGameScreen(line, lines, option, options, _eventInfo);

    switch (choice) {
        case 0:
            _eventInfo.nextEvent = 206;
            _eventInfo.interestPoints[0] += 25;
            _eventInfo.end = 0;
            break;
        case 1:
            _eventInfo.nextEvent = 207;
            _eventInfo.interestPoints[0] += 25;
            _eventInfo.end = 0;
            break;
        case 2:
            _eventInfo.nextEvent = 208;
            _eventInfo.interestPoints[0] += 50;
            _eventInfo.end = 0;
            break;
        default:
            _eventInfo.errorCode = 2;
            _eventInfo.end = 1;
            break;
    }

    return _eventInfo;
}

gameInfo clubPathOne(gameInfo _eventInfo) {
    int lines = 6;
    const char *line[lines];
    int choice = 0;

    line[0] = "The corner of Jeff's lips quirk up in a handsome smirk.";
    line[1] = "Oof! If he looked like this all the time,";
    line[2] = "I probably wouldn't mind more than one date..";
    line[3] = "";
    line[4] = "Jeff: Why not?";
    line[5] = "";

    //Setting Options
    int options = 1;
    const char *option[options];
    option[0] = "........";

    choice = createGameScreen(line, lines, option, options, _eventInfo);

    switch (choice) {
        case 0:
            _eventInfo.nextEvent = 506;
            _eventInfo.end = 0;
            break;
        default:
            _eventInfo.errorCode = 2;
            _eventInfo.end = 1;
            break;
    }

    return _eventInfo;
}

gameInfo clubPathTwo(gameInfo _eventInfo) {
    int lines = 15;
    const char *line[lines];
    int choice = 0;

    line[0] = "Jeff regards me thoughtfully and shrugs.";
    line[1] = "Jeff: Take all the time you need. But I did win fair and square though.";
    line[2] = "";
    line[3] = "The honor card. Typical.";
    line[4] = "I shake my head and sigh. To hell with it.";
    line[5] = "";
    line[6] = "Me: Fine then. Just one date. What can it hurt?";
    line[7] = "Jeff cracks a mischievous grin and I swear I felt my heart skip a beat.";
    line[8] = "";
    line[9] = "Jeff: That didn't take much convincing.";
    line[10] = "I pull my tongue out at him.";
    line[11] = "Me: Shut up. Win gracefully.";
    line[12] = "";
    line[13] = "Jeff booms in laughter and looks at me with fond eyes.";
    line[14] = "So different from the patronizing looks he gave before.";

    //Setting Options
    int options = 1;
    const char *option[options];
    option[0] = "........";

    choice = createGameScreen(line, lines, option, options, _eventInfo);

    switch (choice) {
        case 0:
            _eventInfo.nextEvent = 506;
            _eventInfo.end = 0;
            break;
        default:
            _eventInfo.errorCode = 2;
            _eventInfo.end = 1;
            break;
    }

    return _eventInfo;
}

gameInfo clubPathThree(gameInfo _eventInfo) {
    int lines = 8;
    const char *line[lines];
    int choice = 0;

    line[0] = "Jeff laughs and I swear I thought it was the prettiest sound.";
    line[1] = "I think I must be going crazy.";
    line[2] = "";
    line[3] = "Jeff: I didn't think you'd agree that quickly.";
    line[4] = "You: I honestly didn't think I would either.";
    line[5] = "";
    line[6] = "Jeff: You saying I'm undateable?";
    line[7] = "";

    //Setting Options
    int options = 2;
    const char *option[options];
    option[0] = "That's not what I meant.";
    option[1] = "This was just a bit unexpected.";

    choice = createGameScreen(line, lines, option, options, _eventInfo);

    switch (choice) {
        case 0:
            _eventInfo.nextEvent = 2208;  //clubPathBranchOne
            _eventInfo.interestPoints[0] += 25;
            _eventInfo.end = 0;
            break;
        case 1:
            _eventInfo.nextEvent = 2208;  //clubPathBranchOne
            _eventInfo.interestPoints[0] += 25;
            _eventInfo.end = 0;
            break;
        default:
            _eventInfo.errorCode = 2;
            _eventInfo.end = 1;
            break;
    }

    return _eventInfo;
}

gameInfo clubPathBranchOne(gameInfo _eventInfo) {
    int lines = 20;
    const char *line[lines];
    int choice = 0;

    line[0] = "Me: This was all just very sudden, I mean I barely know you.";
    line[1] = "Jeff chuckles, a sweet sound.";
    line[2] = "Jeff: You got a point.";
    line[3] = "";
    line[4] = "He turns to me and sighs.";
    line[5] = "Jeff: Just think of this as two strangers getting to know each other";
    line[6] = "";
    line[7] = "He smiles and extends his hand.";
    line[8] = "I nod and take his hand in mine.";
    line[9] = "His hold is firm and surprisingly kind of warm.";
    line[10] = "Not the disgustingly sweaty warmth, but a comfortable warmth.";
    line[11] = "";
    line[12] = "It's almost like home.";
    line[13] = "";
    line[14] = "I let go quickly.";
    line[15] = "Me: Okay, Jeff, but no funny business, you hear me?";
    line[16] = "He laughs and nods.";
    line[17] = "";
    line[18] = "Jeff: Okay, whatever you say.";
    line[19] = "";

    //Setting Options
    int options = 1;
    const char *option[options];
    option[0] = "Press Enter to doubt.";

    choice = createGameScreen(line, lines, option, options, _eventInfo);

    switch (choice) {
        case 0:
            _eventInfo.nextEvent = 506;
            _eventInfo.end = 0;
            break;
        default:
            _eventInfo.errorCode = 2;
            _eventInfo.end = 1;
            break;
    }

    return _eventInfo;
}

gameInfo clubOneContSix(gameInfo _eventInfo) {
    int lines = 25;
    const char *line[lines];
    int choice = 0;

    line[0] = "At that, I'm left speechless.";
    line[1] = "He's looking at me so intensely,";
    line[2] = "my heart is beating out of my chest.";
    line[3] = "";
    line[4] = "I don't know how long we stayed liked that,";
    line[5] = "but the magic broke when voices were starting to flow in from the hallway.";
    line[6] = "";
    line[7] = "I clear my throat and stand from my seat beside him";
    line[8] = "He looks up at me and smirks that heart hammering smile again.";
    line[9] = "     ";
    line[10] = "Jeff: I'll see you at 7PM sharp.";
    line[11] = "";
    line[12] = "Right at that moment, the few other members of the CMSC Club walked in.";
    line[13] = "Jeff turned to them and started chatting as if nothing happened.";
    line[14] = "    ";
    line[15] = "I stare at him, dumbfounded, for a while.";
    line[16] = "What just happened? And what did I just get myself into?";
    line[17] = "";
    line[18] = "A familiar face walks - no, slumps through the door.";
    line[19] = "What do you know, it's the club adviser himself.";
    line[20] = "";
    line[21] = "Jeff: Look who the cat finally dragged in.";
    line[22] = "Mr. K: Dog. I love cats but I can't have one.";
    line[23] = "";
    line[24] = "At that moment, Chichi Santiago walks through the door.";

    //Setting Options
    int options = 2;
    const char *option[options];
    option[0] = "Chichi! Over here";
    option[1] = ".....";

    choice = createGameScreen(line, lines, option, options, _eventInfo);

    switch (choice) {
        case 0:
            _eventInfo.nextEvent = 507;
            _eventInfo.end = 0;
            break;
        case 1:
            _eventInfo.nextEvent = 507;
            _eventInfo.end = 0;
            break;
        default:
            _eventInfo.errorCode = 2;
            _eventInfo.end = 1;
            break;
    }

    return _eventInfo;
}

gameInfo clubOneContSeven(gameInfo _eventInfo) {
    int lines = 4;
    const char *line[lines];
    int choice = 0;

    line[0] = "Chichi walks over meekly";
    line[1] = "    ";
    line[2] = "Chichi: Oh, it's you from class! Sorry about the";
    line[3] = "\tintroduction thing. I get really shy.";

    //Setting Options
    int options = 2;
    const char *option[options];
    option[0] = "No biggie.";
    option[1] = "It's fine. I completely understand.";

    choice = createGameScreen(line, lines, option, options, _eventInfo);

    switch (choice) {
        case 0:
            _eventInfo.nextEvent = 508;
            _eventInfo.end = 0;
            break;
        case 1:
            _eventInfo.nextEvent = 508;
            _eventInfo.end = 0;
            break;
        default:
            _eventInfo.errorCode = 2;
            _eventInfo.end = 1;
            break;
    }

    return _eventInfo;
}

gameInfo clubOneContEight(gameInfo _eventInfo) {
    int lines = 27;
    const char *line[lines];
    int choice = 0;

    line[0] = "She sighs happily and clasps her hands together.";
    line[1] = "";
    line[2] = "Chichi: That's a relief! I was hoping we could be friends.";
    line[3] = "\tI want to be friends with my first college seatmate.";
    line[4] = "";
    line[5] = "She's so cute! How could I say no?";
    line[6] = "    ";
    line[7] = "Me: Of course! I'd love to be friends.";
    line[8] = "Chichi: Yey!";
    line[9] = "";
    line[10] = "Obtained a new friend! We exchange numbers.";
    line[11] = "";
    line[12] = "At the front of the room, Jeff clears his throat with Mr. K beside him.";
    line[13] = "Jeff: Okay, losers, listen u-OW!";
    line[14] = "Jeff yelps and bends to grab at his foot,";
    line[15] = "while Mr. K beside him just smiles a bit too sweetly.";
    line[16] = "    ";
    line[17] = "Mr. K: What our club president means to say is 'Welcome to the CMSC Club'!";
    line[18] = "";
    line[19] = "The 3 other people in the room and me and Chichi clap our hands";
    line[20] = "in an earnest attempt at applause.";
    line[21] = "   ";
    line[22] = "Mr. K: Thank you, thank you. ";
    line[22] = "";
    line[23] = "The club meeting goes on pretty uneventfully. They talk about plans";
    line[24] = "for the club for the school year. After that, Mr. K dismisses us.";
    line[25] = "";
    line[26] = "I head home.";

    //Setting Options
    int options = 1;
    const char *option[options];
    option[0] = "Go home";

    choice = createGameScreen(line, lines, option, options, _eventInfo);

    switch (choice) {
        case 0:
            _eventInfo.nextEvent = 1004;
            _eventInfo.end = 0;
            break;
        default:
            _eventInfo.errorCode = 2;
            _eventInfo.end = 1;
            break;
    }

    return _eventInfo;
}

gameInfo homeThree(gameInfo _eventInfo) {
    int lines = 8;
    const char *line[lines];
    int choice = 0;

    line[0] = "I get home and head straight for my room.";
    line[1] = "My mom asks if I want dinner, I tell her maybe later.";
    line[2] = "";
    line[3] = "What a loooong first day.";
    line[4] = "From the moment I woke up until now, it feels like";
    line[5] = "I've been strung along on a series of events.";
    line[6] = "";
    line[7] = "Now that I think about it, I still have an assignment to do.";

    //Setting Options
    int options = 1;
    const char *option[options];
    option[0] = "Make the assignment!";

    choice = createGameScreen(line, lines, option, options, _eventInfo);

    switch (choice) {
        case 0:
            _eventInfo.nextEvent = 1004;
            _eventInfo.end = 0;
            break;
        default:
            _eventInfo.errorCode = 2;
            _eventInfo.end = 1;
            break;
    }

    return _eventInfo;
}

gameInfo homeFour(gameInfo _eventInfo) {
    int lines = 8;
    const char *line[lines];
    int choice = 0;

    line[0] = "Ugh, finally. That was tough, as expected.";
    line[1] = "Mr. K's really not wasting any time on giving us easy stuff.";
    line[2] = "";
    line[3] = "This really is college huh...";
    line[4] = "I'm not sure if I can make it for four years.";
    line[5] = "";
    line[6] = "Ring! Ring!";
    line[7] = "It's my phone. Do I pick up?";

    //Setting Options
    int options = 2;
    const char *option[options];
    option[0] = "Pick up.";
    option[1] = "Ignore it.";

    choice = createGameScreen(line, lines, option, options, _eventInfo);

    switch (choice) {
        case 0:
            _eventInfo.nextEvent = 305;  //homeFive
            _eventInfo.end = 0;
            break;
        case 1:
            _eventInfo.nextEvent = 313;  //homePathThree
            _eventInfo.end = 0;
        default:
            _eventInfo.errorCode = 2;
            _eventInfo.end = 1;
            break;
    }

    return _eventInfo;
}

gameInfo homePathThree(gameInfo _eventInfo) {
    int lines = 5;
    const char *line[lines];
    int choice = 0;

    line[0] = "It stops ringing but rings again a few minutes later.";
    line[1] = "I really should've just picked it up the first time I was";
    line[2] = "given the choice.";
    line[3] = "      ";
    line[4] = "Pick it up?";

    //Setting Options
    int options = 2;
    const char *option[options];
    option[0] = "Yeees";
    option[1] = "Make the ringing stooop";

    choice = createGameScreen(line, lines, option, options, _eventInfo);

    switch (choice) {
        case 0:
            _eventInfo.nextEvent = 305;  //homeFive
            _eventInfo.end = 0;
            break;
        case 1:
            _eventInfo.nextEvent = 305;  //homePathThree
            _eventInfo.end = 0;
        default:
            _eventInfo.errorCode = 2;
            _eventInfo.end = 1;
            break;
    }

    return _eventInfo;
}

gameInfo homeFive(gameInfo _eventInfo) {
    int lines = 24;
    const char *line[lines];
    int choice = 0;

    line[0] = "I wonder who it is.";
    line[1] = "";
    line[2] = "Me: Hello?";
    line[3] = "Chichi: Oh! Hi! It's me!";
    line[4] = "Me: Chichi?";
    line[5] = "Chichi: Yes. I hope you don't mind that I called.";
    line[6] = "Me: No it's fine. I was starting to get lonely.. What's up?";
    line[7] = "";
    line[8] = "Chichi: You finished with the assignment?";
    line[9] = "Me: Yeah, I am... I think. You?";
    line[10] = "Chichi: I think. I'm not really sure if it's right tho.";
    line[11] = "";
    line[12] = "Chichi pauses, like she's thinking.";
    line[13] = "";
    line[14] = "Chichi: I'm not really sure if Comp Sci was right for me either haha.";
    line[15] = "Me: OOF big mood.";
    line[16] = "";
    line[17] = "Chichi and I keep talking and before we know it, it's already late.";
    line[18] = "      ";
    line[19] = "Though school is beginning to stress me out,";
    line[20] = "I'm glad I have a friend I can talk to.";
    line[21] = "";
    line[22] = "I go to sleep with thoughts of my future.";
    line[23] = "";

    //Setting Options
    int options = 1;
    const char *option[options];
    option[0] = "Continue";

    choice = createGameScreen(line, lines, option, options, _eventInfo);

    switch (choice) {
        case 0:
            _eventInfo.nextEvent = 103;  //dayTwo
            _eventInfo.end = 0;
            break;
        default:
            _eventInfo.errorCode = 2;
            _eventInfo.end = 1;
            break;
    }

    return _eventInfo;
}

gameInfo dayTwo(gameInfo _eventInfo) {
    int lines = 14;
    const char *line[lines];
    int choice = 0;

    line[0] = "It's the 2nd day of class!";
    line[1] = "After last night's talk with Chichi,";
    line[2] = "I feel a bit more lighthearted.";
    line[2] = "";
    line[3] = "I felt so nice that in a total reversal of yesterday's events, ";
    line[4] = "I actually got to school an hour early.";
    line[5] = "    ";
    line[6] = "Me: I need coffee. This is ridiculous.";
    line[7] = "";
    line[8] = "I walk over to the nearby 8/12 Convenience Store.";
    line[9] = "The store is completely devoid of customers";
    line[10] = "except for one lone slouched back facing me with a head";
    line[11] = "of unkempt hair, sitting alone at one of the tables.";
    line[12] = "    ";
    line[13] = "Is that Mr. K?";

    //Setting Options
    int options = 2;
    const char *option[options];
    option[0] = "Press Enter to doubt";
    option[1] = "Pretty sure it's him";

    choice = createGameScreen(line, lines, option, options, _eventInfo);

    switch (choice) {
        case 0:
            _eventInfo.nextEvent = 104;  //dayTwoContOne
            _eventInfo.end = 0;
            break;
        case 1:
            _eventInfo.nextEvent = 104;  //dayTwoContOne
            _eventInfo.end = 0;
            break;
        default:
            _eventInfo.errorCode = 2;
            _eventInfo.end = 1;
    }

    return _eventInfo;
}

gameInfo dayTwoContOne(gameInfo _eventInfo) {
    int lines = 9;
    const char *line[lines];
    int choice = 0;

    line[0] = "I pass by him quickly on my way to get coffee and peek.";
    line[1] = "     ";
    line[2] = "Wow, it really is him.";
    line[3] = "";
    line[4] = "I think it's probably best to avoid him so I try";
    line[5] = "hurry past him after I pay for my coffee but he";
    line[6] = "chooses that moment to look up from his book.";
    line[7] = "";
    line[8] = "Our eyes meet and I freeze. I do a smol little wave.";

    //Setting Options
    int options = 2;
    const char *option[options];
    option[0] = "Oh hi, Mr. K, didn't see you there ha-ha-ha";
    option[1] = "Mornin', Mr. K!";

    choice = createGameScreen(line, lines, option, options, _eventInfo);

    switch (choice) {
        case 0:
            _eventInfo.nextEvent = 105;  //dayTwoContTwo
            _eventInfo.interestPoints[1] += 25;
            _eventInfo.end = 0;
            break;
        case 1:
            _eventInfo.nextEvent = 105;  //dayTwoContTwo
            _eventInfo.interestPoints[1] += 25;
            _eventInfo.end = 0;
            break;
        default:
            _eventInfo.errorCode = 2;
            _eventInfo.end = 1;
    }

    return _eventInfo;
}

gameInfo dayTwoContTwo(gameInfo _eventInfo) {
    int lines = 18;
    const char *line[lines];
    int choice = 0;

    line[0] = "A vague expression of recognition passes his face.";
    line[1] = "     ";
    line[2] = "Mr. K: Oh! It's one of my students. Yo! Good morning!";
    line[3] = "";
    line[4] = "Mr. K glances at the miserable sight of the table before him.";
    line[5] = "He discreetly tries to tidy up his mess and discarded breakfast";
    line[6] = "    ";
    line[7] = "It's almost cute.";
    line[8] = "";
    line[9] = "Whoa, there self, this is your teacher. Reign in the hormones.";
    line[10] = "";
    line[11] = "I shift my feet awkwardly and smile.";
    line[12] = "     ";
    line[13] = "Me: It's okay, Mr. K. I'll.. sit somewhere else.";
    line[14] = "";
    line[15] = "He looks almost relieved but shakes his head.";
    line[16] = "    ";
    line[17] = "Mr. K: No, it's fine. Come sit.";

    //Setting Options
    int options = 2;
    const char *option[options];
    option[0] = "Okay. If you say so.";
    option[1] = "Don't mind if I do hehe";

    choice = createGameScreen(line, lines, option, options, _eventInfo);

    switch (choice) {
        case 0:
            _eventInfo.nextEvent = 106;  //dayTwoContThree
            _eventInfo.end = 0;
            break;
        case 1:
            _eventInfo.nextEvent = 106;  //dayTwoContThree
            _eventInfo.end = 0;
            break;
        default:
            _eventInfo.errorCode = 2;
            _eventInfo.end = 1;
    }

    return _eventInfo;
}

gameInfo dayTwoContThree(gameInfo _eventInfo) {
    int lines = 6;
    const char *line[lines];
    int choice = 0;

    line[0] = "I sit opposite Mr. K and begin sipping at my coffee.";
    line[1] = "He continues reading whatever book it is.";
    line[2] = "Judging from the cover, it's probably a book";
    line[3] = "of questionable material. I decide not to ask.";
    line[4] = "";
    line[5] = "We sit in relatively awkward silence before I can't take it anymore";

    //Setting Options
    int options = 2;
    const char *option[options];
    option[0] = "What are you reading?";
    option[1] = "Why the 'Mr. K'?";

    choice = createGameScreen(line, lines, option, options, _eventInfo);

    switch (choice) {
        case 0:
            _eventInfo.nextEvent = 209;  //twoPathOne
            _eventInfo.interestPoints[1] += 50;
            _eventInfo.end = 0;
            break;
        case 1:
            _eventInfo.nextEvent = 210;  //twoPathTwo
            _eventInfo.interestPoints[1] += 25;
            _eventInfo.end = 0;
            break;
        default:
            _eventInfo.errorCode = 2;
            _eventInfo.end = 1;
    }

    return _eventInfo;
}

gameInfo twoPathOne(gameInfo _eventInfo) {
    int lines = 16;
    const char *line[lines];
    int choice = 0;

    line[0] = "Mr. K's head snaps up so fast I'm worried he'd get whiplash.";
    line[1] = "Mr. K: What did you say?";
    line[2] = "     ";
    line[3] = "Me: What's that you're reading?";
    line[4] = "    I saw you reading it in class yesterday too.";
    line[5] = "";
    line[6] = "Mr. K fidgets and laughs awkwardly.";
    line[7] = "     ";
    line[8] = "Mr. K: How old are you again?";
    line[9] = "     ";
    line[10] = "Me: 19.";
    line[11] = "";
    line[12] = "Mr. K rubs his chin thoughtfully as he studies me.";
    line[13] = "    ";
    line[14] = "Mr. K: I guess, it's fine to tell you but I'd rather keep my job.";
    line[15] = "       Ask me something else.";

    //Setting Options
    int options = 1;
    const char *option[options];
    option[0] = "Why the 'Mr. K'?";

    choice = createGameScreen(line, lines, option, options, _eventInfo);

    switch (choice) {
        case 0:
            _eventInfo.nextEvent = 210;  //twoPathTwo
            _eventInfo.interestPoints[1] += 50;
            _eventInfo.end = 0;
            break;
        default:
            _eventInfo.errorCode = 2;
            _eventInfo.end = 1;
    }

    return _eventInfo;
}

gameInfo twoPathTwo(gameInfo _eventInfo) {
    int lines = 52;
    const char *line[lines];
    int choice = 0;

    line[0] = "Mr. K looks at you quizzically and raises an eyebrow.";
    line[1] = "     ";
    line[2] = "Mr. K: Excuse me?";
    line[3] = "";
    line[4] = "I panic.";
    line[5] = "     ";
    line[6] = "Me: I-I mean! I'm not looking to offend you or anything but";
    line[7] = "    like isn't it weird for a teacher to not tell his students";
    line[8] = "    his real name? Like what if you're someone dangerous? What if";
    line[9] = "    your some sort of serial killer? And we'd never know because";
    line[10] = "   we DON'T KNOW YOUR NAME.";
    line[11] = "";
    line[12] = "At that, I finally shut my mouth.";
    line[13] = "     ";
    line[14] = "Mr. K is looking at me weirdly and I'm afraid I've just ruined";
    line[15] = "my non-existent working relationship with my teacher.";
    line[16] = "";
    line[17] = "Me: I'm sorry, Mr. K. I'm just really curious.. sorry.";
    line[18] = "     ";
    line[19] = "Mr. K bursts out laughing and just shakes his head.";
    line[20] = "     ";
    line[21] = "Mr. K: It's okay. When I decided to go by just K, I already steeled";
    line[22] = "       myself for the numerous questions.";
    line[23] = "";
    line[24] = "He fiddles with the corner of a page on his book and closes it.";
    line[25] = "I just noticed but his hands look delicate yet strong. Like the hands";
    line[26] = "of an aristocrat but also very much capable of the most compexly";
    line[27] = "beautiful things.";
    line[28] = "";
    line[29] = "Mr. K: Honestly, I just wanna be mysterious.";
    line[30] = "    ";
    line[31] = "He waggles his fingers playfully at me. I gulp.";
    line[32] = "THOSE BEAUTIFUL HANDS!";
    line[33] = "";
    line[34] = "Me: Not a proper answer, Mr. K.";
    line[35] = "   ";
    line[36] = "Mr. K: But I'm your superior so you're going to have to live";
    line[37] = "       with that answer for now.";
    line[38] = "";
    line[39] = "With that, he starts to gather his things.";
    line[40] = "   ";
    line[41] = "Mr. K: I'm going to go on ahead, my inquisitive pupil.";
    line[42] = "       See you in class.";
    line[43] = "    ";
    line[44] = "With a small smile and a little salute, he turns to leave";
    line[45] = "and I watch him walk out the door.";
    line[46] = "What a weird guy.";
    line[47] = "    ";
    line[48] = "I like him.";
    line[49] = "";
    line[50] = "I finish my coffee and head to class too with";
    line[51] = "a bit more spring in my step.";

    //Setting Options
    int options = 1;
    const char *option[options];
    option[0] = "Go to class";

    choice = createGameScreen(line, lines, option, options, _eventInfo);

    switch (choice) {
        case 0:
            _eventInfo.nextEvent = 107;  //dayTwoContFour
            _eventInfo.end = 0;
            break;
        default:
            _eventInfo.errorCode = 2;
            _eventInfo.end = 1;
    }

    return _eventInfo;
}

gameInfo dayTwoContFour(gameInfo _eventInfo) {
    int lines = 16;
    const char *line[lines];
    int choice = 0;

    line[0] = "When I get to the classroom, Mr. K is already there waiting for us.";
    line[1] = "    ";
    line[2] = "He sees me enter and raises his hand from the book his reading to";
    line[3] = "greet me.";
    line[4] = "    ";
    line[5] = "Mr. K: Yo.";
    line[6] = "";
    line[7] = "He smiles a small smile and my heart skips a beat.";
    line[8] = "For some reason, despite the dark circles under his eyes";
    line[9] = "and the messy hair, he's handsome.";
    line[10] = "";
    line[11] = "Keep it together, self! He's your teacher!!";
    line[12] = "I can't help it if he's cute though.";
    line[13] = "     ";
    line[14] = "'It's fine, it's just a little crush', I convince myself.";
    line[15] = "";

    //Setting Options
    int options = 2;
    const char *option[options];
    option[0] = "Bow and say 'Good morning'";
    option[1] = "Smile and wave";

    choice = createGameScreen(line, lines, option, options, _eventInfo);

    switch (choice) {
        case 0:
            _eventInfo.nextEvent = 108;  //dayTwoContFive
            _eventInfo.interestPoints[1] += 25;
            _eventInfo.end = 0;
            break;
        case 1:
            _eventInfo.nextEvent = 108;  //dayTwoContFive
            _eventInfo.interestPoints[1] += 50;
            _eventInfo.end = 0;
            break;
        default:
            _eventInfo.errorCode = 2;
            _eventInfo.end = 1;
    }

    return _eventInfo;
}

gameInfo dayTwoContFive(gameInfo _eventInfo) {
    int lines = 24;
    const char *line[lines];
    int choice = 0;

    line[0] = "I greet him back and he turns back to his book";
    line[1] = "licking his finger before turning the page.";
    line[2] = "     ";
    line[3] = "Good sweet Lord almighty.";
    line[4] = "";
    line[5] = "I hurry to my seat before I embarrass myself.";
    line[6] = "Chichi is already sitting in her seat.";
    line[7] = "";
    line[8] = "Chichi: Good morning!";
    line[9] = "Me: Good morning, Chichi.";
    line[10] = "Chichi: You look nervous. What's wrong?";
    line[11] = "Me: It's nothing special, I think.";
    line[12] = "Chichi: Okay.";
    line[13] = "";
    line[14] = "Mr. K closes his book with a snap.";
    line[15] = "   ";
    line[16] = "Mr. K: Okay, class, pop quiz time! If you answered the";
    line[17] = "       homework I gave you. This will be relatively";
    line[18] = "       easier for you.";
    line[19] = "    ";
    line[20] = "The look on everyone's faces is just pure horror.";
    line[21] = "Mr. K, on the otherhand, is ever gleeful.";
    line[22] = "    ";
    line[23] = "Mr. K: OK! Let's start!";

    //Setting Options
    int options = 1;
    const char *option[options];
    option[0] = "Start!";

    choice = createGameScreen(line, lines, option, options, _eventInfo);

    switch (choice) {
        case 0:
            _eventInfo.nextEvent = 1005;  //battleFive
            _eventInfo.end = 0;
            break;
        default:
            _eventInfo.errorCode = 2;
            _eventInfo.end = 1;
    }

    return _eventInfo;
}

gameInfo dayTwoContSix(gameInfo _eventInfo){
    int lines = 23;
    const char *line[lines];
    int choice = 0;

    line[0] = "Mr. K: Okay, everyone pass your papers!"
    line[1] = "     ";
    line[2] = "I pass my paper to the front, hoping to God I did well.";
    line[3] = "     ";
    line[4] = "";
    line[5] = "Mr. K: Don't worry, guys. I'm sure you all did good.";
    line[6] = "     ";
    line[7] = "Curse this man. He cute but I feel so incredibly betrayed.";
    line[8] = "";
    line[9] = "Classes continue for the day until it's finally time to go.";
    line[10] = "    ";
    line[11] = "Mr. K: See you tomorrow, everyone!";
    line[12] = "    ";
    line[13] = "Everyone goes to leave. Chichi and I walk out the door together";
    line[14] = "only to be greeted by a familiar smirking face.";
    line[15] = "";
    line[16] = "Me: Jeff!";
    line[17] = "Jeff: Hello. I believe someone owes me a date.";
    line[18] = "    ";
    line[19] = "Chichi daintily covers her mouth with her hand.";
    line[20] = "    ";
    line[21] = "Chichi: Oooh a date? Wow, you guys!";
    line[19] = "Me: Yeah, Chichi, it's kind of a long story. You see..";
    line[20] = "Someone: A date?";
    line[21] = "";
    line[22] = "I look behind me to find Mr. K watching us with interest.";

    //Setting options
    int options = 1;
    const char *option[options];
    option[0] = ".......";

    choice = createGameScreen(line, lines, option, options, _eventInfo);

    switch (choice) {
        case 0:
            _eventInfo.nextEvent = 1006;  //battleFive
            _eventInfo.end = 0;
            break;
        default:
            _eventInfo.errorCode = 2;
            _eventInfo.end = 1;
    }

    return _eventInfo;
}


// ---->>> BATTLES

//Math Ghost Boss
gameInfo battleOne(gameInfo _eventInfo) {
    int result = bossBattle(1, _eventInfo);

    //Switches between success and failure events
    //Failure = 0
    //Success = 1
    switch (result) {
        case 0:
            _eventInfo.nextEvent = 1201;  //resultOne
            _eventInfo.end = 0;
            break;
        case 1:
            _eventInfo.nextEvent = 301;  //homeOne
            _eventInfo.end = 0;
            break;
        default:
            _eventInfo.errorCode = 5;
            _eventInfo.end = 1;
            break;
    }

    return _eventInfo;
}

//Horde Boss
gameInfo battleTwo(gameInfo _eventInfo) {
    int result = bossBattle(2, _eventInfo);

    //Switches between success and failure events
    //Failure = 0
    //Success = 1
    switch (result) {
        case 0:
            _eventInfo.nextEvent = 1202;  //resultTwo
            _eventInfo.interestPoints[0] += 25;
            _eventInfo.end = 0;
            break;
        case 1:
            _eventInfo.nextEvent = 501;  //clubOneContOne
            _eventInfo.interestPoints[0] += 50;
            _eventInfo.end = 0;
            break;
        default:
            _eventInfo.errorCode = 2;
            _eventInfo.end = 1;
            break;
    }

    return _eventInfo;
}

//Jeff TECKEN Boss
gameInfo battleThree(gameInfo _eventInfo) {
    int result = bossBattle(3, _eventInfo);

    //Switches between success and failure events
    //Failure = 0
    //Success = 1
    switch (result) {
        case 0:
            _eventInfo.nextEvent = 505; //clubOneContFive
            _eventInfo.interestPoints[0] += 75;
            _eventInfo.end = 0;
            break;
        default:
            _eventInfo.errorCode = 2;
            _eventInfo.end = 1;
            break;
    }

    return _eventInfo;
}

//Assignment Boss
gameInfo battleFour(gameInfo _eventInfo) {
    int result = bossBattle(4, _eventInfo);

    //Switches between success and failure events
    //Failure = 0
    //Success = 1
    switch (result) {
        case 0:
            _eventInfo.nextEvent = 1204;  //resultFour
            _eventInfo.interestPoints[1] += 50;
            _eventInfo.end = 0;
            break;
        case 1:
            _eventInfo.nextEvent = 304;  //homeFour
            _eventInfo.interestPoints[1] += 75;
            _eventInfo.end = 0;
            break;
        default:
            _eventInfo.errorCode = 2;
            _eventInfo.end = 1;
            break;
    }

    return _eventInfo;
}

//Mr. K's test
gameInfo battleFive(gameInfo _eventInfo) {
    int result = bossBattle(5, _eventInfo);

    //Switches between success and failure events
    //Failure = 0
    //Success = 1
    switch (result) {
        case 0:
            _eventInfo.nextEvent = 109;  //dayTwoContSix
            _eventInfo.interestPoints[1] -= 25;
            _eventInfo.end = 0;
            break;
        case 1:
            _eventInfo.nextEvent = 109;  //dayTwoContSix
            _eventInfo.interestPoints[1] += 50;
            _eventInfo.end = 0;
            break;
        default:
            _eventInfo.errorCode = 2;
            _eventInfo.end = 1;
            break;
    }

    return _eventInfo;
}

gameInfo battleSix(gameInfo _eventInfo){
    int result = bossBattle(6, _eventInfo);

    //Switches between success and failure events
    //Failure = 0
    //Success = 1
    switch (result) {
        case 0:
            endScreen();            // displays the To Be Continued screen
            _eventInfo.end = 1;
            break;
        default:
            _eventInfo.errorCode = 2;
            _eventInfo.end = 1;
            break;
    }

    return _eventInfo;
}


// ----->> BATTLE RESULTS

//Math Ghost Battle Failure
gameInfo resultOne(gameInfo _eventInfo) {
    int lines = 1;
    const char *line[lines];
    int choice = 0;

    line[0] = "You never woke up from your nightmare.";

    //Setting Options
    int options = 1;
    const char *option[options];
    option[0] = "Quit";

    choice = createGameScreen(line, lines, option, options, _eventInfo);

    switch (choice) {
        case 0:
            gameOverScreen();
            _eventInfo.end = 1;
            break;
        default:
            _eventInfo.errorCode = 2;
            _eventInfo.end = 1;
            break;
    }

    return _eventInfo;
}

//Horde Battle Failure
gameInfo resultTwo(gameInfo _eventInfo) {
    int lines = 3;
    const char *line[lines];
    int choice = 0;

    line[0] = "The horde has taken you away from the CMSC Club!";
    line[1] = "      ";
    line[2] = "Try again?";

    //Setting Options
    int options = 1;
    const char *option[options];
    option[0] = "Continue";

    choice = createGameScreen(line, lines, option, options, _eventInfo);

    switch (choice) {
        case 0:
            _eventInfo.end = 1002;  //back to battleTwo
            break;

        default:
            _eventInfo.errorCode = 2;
            _eventInfo.end = 1;
            break;
    }

    return _eventInfo;
}

//Assignment Battle Failure
gameInfo resultThree(gameInfo _eventInfo) {
    int lines = 4;
    const char *line[lines];
    int choice = 0;

    line[0] = "The assignment was too much for you.";
    line[1] = "You have failed Mr. K.";
    line[2] = "     ";
    line[3] = "Try again?";

    //Setting Options
    int options = 1;
    const char *option[options];
    option[0] = "Continue";

    choice = createGameScreen(line, lines, option, options, _eventInfo);

    switch (choice) {
        case 0:
            _eventInfo.end = 1004;  //back to battleFour
            break;

        default:
            _eventInfo.errorCode = 2;
            _eventInfo.end = 1;
            break;
    }

    return _eventInfo;
}
