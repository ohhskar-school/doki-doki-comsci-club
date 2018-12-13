#ifndef HUD_C
#define HUD_C

void initializeNcurses();
void initializeColors();
void splashScreen();
void presentsScreen();
void getReadyScreen();
void sizeScreen();
void disclaimerScreen();
void endScreen();
void gameOverScreen();
int createGameScreen(const char **line, int lines, const char **option, int options, gameInfo incomingInfo);
WINDOW *createEnemyHud(bossStruct boss, int hudHeight);
WINDOW *createPlayerHud(playerStruct player, int hudHeight);
WINDOW *createContentHud(int hudHeight, char **line, int lines);
optionReturn createOptionHud(int hudHeight, char **option, int options);
#endif