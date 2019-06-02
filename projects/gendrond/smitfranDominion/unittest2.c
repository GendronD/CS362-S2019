/*
 * Devin Gendron
 * Assignment 3 - Unit Tests
 * Due: May 5th, 2019
 * onid: gendrond
 * email: gendrond@oregonstate.edu
 * 
 * Unit Test 2
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"

int main()
{
    printf("Testing Is Game Over Function...\n");

    // Initializing Game (Referenced From Sample Files Provided)
    // as well as from betterTestDrawCard.c
    // Utilization of the Dominion Base Architecture File was extremely helpful

    printf("Initializing Game Code For Tests...\n");
    struct gameState gStateProvinceLoss;
    struct gameState gStateProvinceWin;
    struct gameState gStateSupplyGameContinue;
    struct gameState gStateSupplyGameEnd;
    struct gameState gStateSupplyAlmostEnd;
    struct gameState gStateSupplyGameAlmostEnd;

    int w = 0;
    for (w = 0; w < 25; w++)
    {
        gStateProvinceLoss.supplyCount[w] = 1;
        gStateProvinceWin.supplyCount[w] = 1;
    }

    printf("RUNNING TESTS ON IS GAME OVER FUNCTION FUNCTION\n");
    printf("\n");

    // Test where Province is == to 0
    gStateProvinceLoss.supplyCount[province] = 0;
    if (isGameOver(&gStateProvinceLoss) == 1)
    {
        printf("+===================================+\n");
        printf("TEST SUCCESSFULLY COMPLETED - Game Ended.\n");
        printf("TESTED WITH province = %d\n.", 0);
        printf("+===================================+\n");
    }
    else
    {
        printf("+===================================+\n");
        printf("TEST FAILED - Game Did Not End.\n");
        printf("TESTED WITH province = %d\n.", 0);
        printf("+===================================+\n");
    }

    // Test where Province is == to 1
    gStateProvinceWin.supplyCount[province] = 1;
    if (isGameOver(&gStateProvinceWin) == 0)
    {
        printf("+===================================+\n");
        printf("TEST SUCCESSFULLY COMPLETED - Game Continued.\n");
        printf("TESTED WITH province = %d\n.", 1);
        printf("+===================================+\n");
    }
    else
    {
        printf("+===================================+\n");
        printf("TEST FAILED - Game Did Not Continue.\n");
        printf("TESTED WITH province = %d\n.", 1);
        printf("+===================================+\n");
    }

    // Test for instance of 3 empty supply piles
    int i = 0;
    int k = 0;
    int m = 0;
    int n = 0;

    for (i = 0; i < 3; i++)
    {
        switch (i)
        {
        case 0:
            for (k = 0; k < 25; k++)
            {
                gStateSupplyGameContinue.supplyCount[k] = 1;
            }

            if (isGameOver(&gStateSupplyGameContinue) == 0)
            {
                printf("+===============================================+\n");
                printf("TEST SUCCESSFULLY COMPLETED - Game Continued.\n");
                printf("TESTED WITH no empty supplies: > %d.\n", 0);
                printf("+===============================================+\n");
            }
            else
            {
                printf("+===============================================+\n");
                printf("TEST FAILED - Game Ended.\n");
                printf("TESTED WITH no empty supplies: > %d.\n", 0);
                printf("+===============================================+\n");
            }
            break;
        case 1:
            for (m = 0; m < 25; m++)
            {
                gStateSupplyGameEnd.supplyCount[m] = 0;
            }
            if (isGameOver(&gStateSupplyGameEnd) == 1)
            {
                printf("+===============================================+\n");
                printf("TEST SUCCESSFULLY COMPLETED - Game Ended.\n");
                printf("TESTED WITH supplies = %d.\n", 0);
                printf("+===============================================+\n");
            }
            else
            {
                printf("+===============================================+\n");
                printf("TEST FAILED - Game Continued.\n");
                printf("TESTED WITH empty supplies.\n");
                printf("+===============================================+\n");
            }
            break;
        case 2:
            for (n = 0; n < 25; n++)
            {
                if (n == 5 || n == 10)
                {
                    gStateSupplyGameAlmostEnd.supplyCount[n] = 0;
                }
            }
            if (isGameOver(&gStateSupplyGameAlmostEnd) == 0)
            {
                printf("+===============================================+\n");
                printf("TEST SUCCESSFULLY COMPLETED - Game Continued.\n");
                printf("TESTED WITH no empty supplies: > %d.\n", 0);
                printf("+===============================================+\n");
            }
            else
            {
                printf("+===============================================+\n");
                printf("TEST FAILED - Game Ended.\n");
                printf("TESTED WITH some empty supplies.\n");
                printf("+===============================================+\n");
            }
            break;
        default:
            break;
        }
    }

    printf("\n");
    printf("TESTS ON IS GAME OVER FUNCTION COMPLETED.\n");
    return 0;
}

/*
int isGameOver(struct gameState *state)
{
  int i;
  int j;
  //if stack of Province cards is empty, the game ends
  if (state->supplyCount[province] == 0)
  {
    return 1;
  }
  //if three supply pile are at 0, the game ends
  j = 0;
  for (i = 0; i < 25; i++)
  {
    if (state->supplyCount[i] == 0)
    {
      j++;
    }
  }
  if (j >= 3)
  {
    return 1;
  }
  return 0;
}
*/
