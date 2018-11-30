#include <stdio.h>
#include <stdlib.h>

struct bossStruct {
  int damage;
  int health;
  int move;
  char* name;
};

struct playerStruct {
  int interestPoints;
  int damage;
  int health;
};

int main(int _boss) {

  unsigned int _action;
  int _battleOutcome;
  struct bossStruct boss;
  struct playerStruct player;
  time_t t;
  srand((unsigned) time(&t));
  player.interestPoints = 5;
  player.damage = player.interestPoints * 10;
  player.health = 100;

  switch(_boss) {

    case 1:
      boss.damage = 10;
      boss.health = 10;
      boss.name = "CMSC";
      break;

    case 2:
      boss.damage = 10;
      boss.health = 10;
      boss.name = "CMSC";
      break;

    case 3:
      boss.damage = 10;
      boss.health = 10;
      boss.name = "CMSC";
      break;

    case 4:
      boss.damage = 10;
      boss.health = 10;
      boss.name = "CMSC";
      break;

    case 5:
      boss.damage = 10;
      boss.health = 10;
      boss.name = "CMSC";
      break;
  }


  while(boss.health > 0 && player.health > 0) {

    // Asks the player for input
    do{
      printf("What do you want to do? \n");
      scanf("%d", &_action);
    } while( _action > 4 && _action == 0);

    // Generates random boss move
    boss.move = rand() % 3;


    // If boss attacks
    if (boss.move == 0) {
      printf("%s tries attacking you. \n", boss.name);

      if (_action == 1) {
        player.health = player.health - boss.damage;
        printf("You attack as well! \n");
        boss.health = boss.health - player.damage;
      }

      else if (_action == 2) {
        printf("You successfully dodge! \n");
      }

      else if (_action == 3) {
        player.health = player.health - (boss.damage * 0.5);
        printf("You blocked the opponent's attack! \n");
      }

      else if (_action ==  4) {
        printf("You run away, but deep down you know that this isn't the last time you'll face each other \n");
      }
    }

    // If boss tries to evade
    else if (boss.move == 1) {

      if (_action == 1) {
        printf("You missed! \n  ");
      }

      else if (_action == 2) {
        printf("Both of you try to get away from each other \n");
      }

      else if (_action == 3) {
        printf("You block yet he tries to dodge \n");
      }

      else if (_action == 4) {
        printf("You run away, but deep down you know that this isn't the last time you'll face each other \n");
      }
    }

    // If boss tries to block
    else if (boss.move == 2) {

      if (_action == 1) {
        boss.health = boss.health - (player.damage * 0.5);
        printf("Your attack was blocked! But you were still able to do some damage. \n  ");
      }

      else if (_action == 2) {
        printf("You get away from him in hopes of an attack, but he was expecting for an attack as well so he blocks \n");
      }

      else if (_action == 3) {
        printf("Both of you were anticipating for an attack so you both block \n");
      }

      else if (_action == 4) {
        printf("You run away, but deep down you know that this isn't the last time you'll face each other \n");
      }
    }


    // If boss dies
    if (boss.health <= 0) {
      printf("You come out triumphant!");
      _battleOutcome = 1;
    }
    // If player dies
    else if (player.health <= 0) {
      printf("You have fallen unconscious. Your Doki Doki adventure ends here.");
      _battleOutcome = 0;
    }
  }

}