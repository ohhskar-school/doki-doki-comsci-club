#include <stdio.h>
#include <stdlib.h>

struct bossStruct {
  int damage
  int health;
  char name[50];
  int moveSet[5];
}

struct playerStruct {
  int interestPoints;
  int damage;
  int health;
}

void battle(_boss) {
  int _action;
  struct bossStruct boss;
  struct playerStruct player;
  player.interestPoints = 5;
  player.damage = player.interestPoints * 10;
  player.health = 100;

  switch(_boss) {

    case 1:
      boss.damage = 10;
      boss.health = 10;
      boss.name = "CMSC";
      boss.moveSet[5] = {1, 2, 3, 1, 1};
      break;

    case 2:
      boss.damage = 10;
      boss.health = 10;
      boss.name = "CMSC";
      boss.moveSet[5] = {1, 2, 3, 1, 1};
      break;

    case 3:
      boss.damage = 10;
      boss.health = 10;
      boss.name = "CMSC";
      boss.moveSet[5] = {1, 2, 3, 1, 1};
      break;

    case 4:
      boss.damage = 10;
      boss.health = 10;
      boss.name = "CMSC";
      boss.moveSet[5] = {1, 2, 3, 1, 1};
      break;

    case 5:
      boss.damage = 10;
      boss.health = 10;
      boss.name = "CMSC";
      boss.moveSet[5] = {1, 2, 3, 1, 1};
      break;
  }


  while(boss.health > 0 && player.health > 0) {

    for (int i=0; i <= 5; i++) {

      printf("\n What do you want to do? \n");
      scanf("%d", &_action);

      if (moveSet[i] == 1) {
        printf("\n %c tries attacking you. \n", bossName);

        if (_action == 1) {
          player.playerHealth = player.playerHealth - boss.damage;
          printf("\n You attack as well! \n  ");
          boss.health = boss.health - player.playerDamage;
        }

        else if (_action == 2) {
          printf("\n You successfully dodge! \n");
        }

        else if (_action == 3) {
          player.health = player.health - (boss.damage * 0.5);
          printf("\n You blocked the opponent's attack! \n");
        }

        else if (_action ==  4) {
          printf("\n You run away, but deep down you know that this isn't the last time you'll face each other \n");
        }
      }

      else if (moveSet[i] == 2) {

        if (_action == 1) {
          printf("\n You missed! \n  ");
        }

        else if (_action == 2) {
          printf("\n Both of you try to get away from each other \n");
        }

        else if (_action == 3) {
          printf("\n You block yet he tries to dodge \n");
        }

        else if (_action == 4) {
          printf("\n You run away, but deep down you know that this isn't the last time you'll face each other \n");
        }
      }

      else if (moveSet[i] == 3) {

        if (_action == 1) {
          boss.health = boss.health - (player.damage * 0.5)
          printf("\n Your attack was blocked! But you were still able to do some damage. \n  ");
        }

        else if (_action == 2) {
          printf("\n You get away from him in hopes of an attack, but he was expecting for an attack as well so he blocks \n");
        }

        else if (_action == 3) {
          printf("\n Both of you were anticipating for an attack so you both block \n");
        }

        else if (_action == 4) {
          printf("\n You run away, but deep down you know that this isn't the last time you'll face each other \n");
        }
      }

      if (boss.health <= 0) {
        printf("You come out triumphant!")
        return true;
      }
      else if (player.health <= 0) {
        printf("You have fallen unconscious. Your Doki Doki adventure ends here.")
        return false;
      }
    }
  }

}