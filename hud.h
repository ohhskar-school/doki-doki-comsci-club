struct winsize getSize();
void printCentered(int x, char * content);
void printLine();
void printHearts(int hearts);
void printHUD(struct gameInfo _mainInfo);
void printMenu(char options[][50], int numberOptions);
void splashScreen();
struct gameInfo createCharacter(struct gameInfo _mainInfo);