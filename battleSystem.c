// #include <stdio.h>
// #include <stdlib.h>

// struct bossStruct {
//     int damage;
//     int health;
//     int move;
//     int skill;
//     char* name;
// };

// struct playerStruct {
//     int interestPoints;
//     int damage;
//     int health;
// };

// int bossBattle(int _boss) {
//     unsigned int _action;
//     int _battleOutcome, _bossSuccess, _playerSuccess;
//     struct bossStruct boss;
//     struct playerStruct player;
//     srand((unsigned)time(&t));

//     player.interestPoints = 5;
//     player.damage = player.interestPoints * 3;
//     player.health = 100;

//     switch (_boss) {
//         case 1:
//             boss.damage = 10;
//             boss.health = 30;
//             boss.skill = 50;
//             boss.name = "Maam Alota";
//             break;

//         case 2:
//             boss.damage = 10;
//             boss.health = 10;
//             boss.skill = 50;
//             boss.name = "Sir Ryan";
//             break;

//         case 3:
//             boss.damage = 10;
//             boss.health = 10;
//             boss.skill = 50;
//             boss.name = "CMSC";
//             break;

//         case 4:
//             boss.damage = 10;
//             boss.health = 10;
//             boss.skill = 50;
//             boss.name = "CMSC";
//             break;

//         case 5:
//             boss.damage = 10;
//             boss.health = 10;
//             boss.skill = 50;
//             boss.name = "CMSC";
//             break;
//     }

//     while (boss.health > 0 && player.health > 0) {
//         // Asks the player for input
//         do {
//             printf("What do you want to do? \n");
//             scanf("%d", &_action);
//         } while (_action > 4 && _action == 0);

//         // Generates random boss move
//         boss.move = rand() % 3;

//         // Calculates success rate
//         _bossSuccess = rand() % 100;
//         _playerSuccess = rand() % 100;

//         // If boss tries to attack
//         if (boss.move == 0) {
//             printf("%s tries to attack you. \n", boss.name);

//             // If boss attack succeeds
//             if (_bossSuccess >= boss.skill) {
//                 if (_action == 1) {
//                     printf("It lands! You take %d damage \n", boss.damage);
//                     player.health = player.health - boss.damage;

//                     // If your attack succeeds
//                     if (_playerSuccess >= 20) {
//                         printf("You strike back! Dealing %d damage", player.damage);
//                         boss.health = boss.health - player.damage;
//                     } else {
//                         printf("You strike back! But you missed. \n");
//                     }
//                 }

//                 else if (_action == 2) {
//                     // If your dodge succeeds
//                     if (_playerSuccess >= 50) {
//                         printf("You successfully dodge! \n");
//                     } else {
//                         printf("You try to dodge but the attack still lands. \n");
//                         player.health = player.health - boss.damage;
//                     }
//                 }

//                 else if (_action == 3) {
//                     printf("%s hits you! You take %d damage \n", boss.name, boss.damage);
//                     player.health = player.health - boss.damage;
//                     printf("Despite the attack, you manage to taunt the enemy! \n");
//                     printf("Your attack power increased! \n");
//                     player.damage = player.damage + 5;
//                 }

//                 else if (_action == 4) {
//                     // If you successfully flee
//                     if (_playerSuccess >= 50) {
//                         printf("You run away, but deep down you know that this isn't the last time you'll face each other \n");
//                     } else {
//                         printf("You try to flee but somehow can't! \n");
//                     }
//                 }

//             }

//             // If boss attack fails
//             else {
//                 printf("%s 's attack misses!\n", boss.name);

//                 if (_action == 1) {
//                     // If your attack succeeds
//                     if (_playerSuccess >= 20) {
//                         printf("You take the opportunity and you strike! Dealing %d damage \n", player.damage);
//                         boss.health = boss.health - player.damage;
//                     } else {
//                         printf("You try to take the opportunity but miss your attack. \n");
//                     }
//                 }

//                 else if (_action == 2) {
//                     printf("You dodge anyway! \n");
//                 }

//                 else if (_action == 3) {
//                     printf("You taunt at them for the missed attack. Increasing your attack power! \n");
//                     player.damage = player.damage + 5;
//                 }

//                 else if (_action == 4) {
//                     if (_playerSuccess >= 50) {
//                         printf("You run away, but deep down you know that this isn't the last time you'll face each other \n");
//                     } else {
//                         printf("You try to flee but somehow can't! \n");
//                     }
//                 }
//             }
//         }

//         // If boss tries to evade
//         else if (boss.move == 1) {
//             // If evade succeeds
//             if (_bossSuccess >= boss.skill) {
//                 if (_action == 1) {
//                     printf("You missed! \n  ");
//                 }

//                 else if (_action == 2) {
//                     printf("Both of you try to get away from each other \n");
//                 }

//                 else if (_action == 3) {
//                     printf("You taunt your opponent. Increasing your attack power! \n");
//                     player.damage = player.damage + 5;
//                 }

//                 else if (_action == 4) {
//                     if (_playerSuccess >= 50) {
//                         printf("You run away, but deep down you know that this isn't the last time you'll face each other \n");
//                     } else {
//                         printf("You try to flee but somehow can't! \n");
//                     }
//                 }
//             }

//             // If evade fails
//             else {
//                 if (_action == 1) {
//                     printf("%s tries to evade but stumbles instead! \n", boss.name);

//                     // If your attack succeeds
//                     if (_playerSuccess >= 20) {
//                         printf("You take the opportunity and you strike! Dealing %d damage \n", player.damage);
//                         boss.health = boss.health - player.damage;
//                     } else {
//                         printf("You try to take the opportunity but miss your attack. \n");
//                     }
//                 }

//                 else if (_action == 2) {
//                     printf("Both of you try to get away from each other \n");
//                 }

//                 else if (_action == 3) {
//                     printf("%s tries to evade but stumbles instead! \n", boss.name);
//                     printf("You laugh at his misfortune. Increasing your attack power! \n");
//                     player.damage = player.damage + 5;
//                 }

//                 else if (_action == 4) {
//                     if (_playerSuccess >= 50) {
//                         printf("You run away, but deep down you know that this isn't the last time you'll face each other \n");
//                     } else {
//                         printf("You try to flee but somehow can't! \n");
//                     }
//                 }
//             }
//         }

//         // If boss tries to taunt
//         else if (boss.move == 2) {
//             // If taunt succeeds
//             if (_bossSuccess >= boss.skill) {
//                 boss.damage = boss.damage + 5;

//                 if (_action == 1) {
//                     printf("%s taunts at you! Their attack power has increased. \n", boss.name);

//                     // If your attack succeeds
//                     if (_playerSuccess >= 20) {
//                         printf("You take the opportunity and you strike! Dealing %d damage \n", player.damage);
//                         boss.health = boss.health - player.damage;
//                     } else {
//                         printf("You try to take the opportunity but miss your attack. \n");
//                     }
//                 }

//                 else if (_action == 2) {
//                     printf("You successfully dodge. \n");
//                 }

//                 else if (_action == 3) {
//                     printf("Both of you taunt each other! Increasing both of your attack powers. \n");
//                     player.damage = player.damage + 5;
//                 }

//                 else if (_action == 4) {
//                     // If you successfully flee
//                     if (_playerSuccess >= 50) {
//                         printf("You run away, but deep down you know that this isn't the last time you'll face each other \n");
//                     } else {
//                         printf("You try to flee but somehow can't! \n");
//                     }
//                 }
//             }

//             // If taunt fails
//             else {
//                 if (_action == 1) {
//                     printf("%s tries to taunt! But chokes on spit while doing so. \n", boss.name);

//                     // If your attack succeeds
//                     if (_playerSuccess >= 20) {
//                         printf("You take the opportunity and you strike! Dealing %d damage \n", player.damage);
//                         boss.health = boss.health - player.damage;
//                     } else {
//                         printf("You try to take the opportunity but miss your attack. \n");
//                     }
//                 }

//                 else if (_action == 2) {
//                     printf("You successfully dodge! \n");
//                 }

//                 else if (_action == 3) {
//                     printf("%s tries to taunt! But chokes on spit while doing so. \n", boss.name);
//                     printf("You laugh at the mishap! By doing so, you manage to increase your attack power. \n");
//                     player.damage = player.damage + 5;
//                 }

//                 else if (_action == 4) {
//                     // If you successfully flee
//                     if (_playerSuccess >= 50) {
//                         printf("You run away, but deep down you know that this isn't the last time you'll face each other \n");
//                     } else {
//                         printf("You try to flee but somehow can't! \n");
//                     }
//                 }
//             }
//         }

//         // If boss dies
//         if (boss.health <= 0) {
//             printf("You come out triumphant! \n");
//             _battleOutcome = 1;
//         }
//         // If player dies
//         else if (player.health <= 0) {
//             printf("You have fallen unconscious. Your Doki Doki adventure ends here. \n");
//             _battleOutcome = 0;
//         }
//     }
// }

// int battle() {
//     bossBattle(1);
// }