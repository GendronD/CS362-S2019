/*
 * Devin Gendron
 * Assignment 3 - Unit Tests
 * Due: May 5th, 2019
 * onid: gendrond
 * email: gendrond@oregonstate.edu
 * 
 * Unit Test 1
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"

int main()
{
    printf("Testing Buy Card Function...\n");

    // Initializing Game (Referenced From Sample Files Provided)
    // as well as from betterTestDrawCard.c
    // Utilization of the Dominion Base Architecture File was extremely helpful

    printf("Initializing Game Code For Tests...\n");
    struct gameState gState;
    int turnChange[] = {1, 2};                                // Player Turns
    int buyAmount[] = {0, 1, 2, 3};                           // Buy Turns
    int supplyPosLoc[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};      // Card to Choose
    int coinTestAmts[] = {0, 1, 2, 3, 4, 5, 10, 15, 20, 100}; // Coins

    printf("RUNNING TESTS ON BUY CARD FUNCTION\n");
    printf("\n");
    int i = 0;
    int j = 0;
    int k = 0;
    int m = 0;
    int supplyPassed = 0;

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 4; j++)
        {
            for (k = 0; k < 10; k++)
            {
                for (m = 0; m < 10; m++)
                {
                    gState.whoseTurn = turnChange[i];
                    gState.numBuys = buyAmount[j];
                    gState.coins = coinTestAmts[m];
                    supplyPassed = supplyPosLoc[k];
                    if (buyCard(supplyPassed, &gState) == -1)
                    {
                        printf("+===================================+\n");
                        printf("TEST SUCCESSFULLY COMPLETED.\n");
                        printf("TESTED WITH whoseTurn = %d.\n", turnChange[i]);
                        printf("TESTED WITH numBuys = %d.\n", buyAmount[j]);
                        printf("TESTED WITH coins = %d.\n", coinTestAmts[m]);
                        printf("TESTED WITH supplyPos = %d.\n", supplyPosLoc[k]);
                        printf("+===================================+\n");
                    }
                    else
                    {
                        printf("+===================================+\n");
                        printf("TEST FAILED.\n");
                        printf("TESTED WITH whoseTurn = %d.\n", turnChange[i]);
                        printf("TESTED WITH numBuys = %d.\n", buyAmount[j]);
                        printf("TESTED WITH coins = %d.\n", coinTestAmts[m]);
                        printf("TESTED WITH supplyPos = %d.\n", supplyPosLoc[k]);
                        printf("+===================================+\n");
                    }
                }
            }
        }
    }

    printf("\n");
    printf("TESTS ON BUY CARD FUNCTION COMPLETED.\n");
    return 0;
}

/*
int buyCard(int supplyPos, struct gameState *state)
{
  int who;
  if (DEBUG)
  {
    printf("Entering buyCard...\n");
  }
  // I don't know what to do about the phase thing.
  who = state->whoseTurn;
  if (state->numBuys < 1)
  {
    if (DEBUG)
      printf("You do not have any buys left\n");
    return -1;
  }
  else if (supplyCount(supplyPos, state) < 1)
  {
    if (DEBUG)
      printf("There are not any of that type of card left\n");
    return -1;
  }
  else if (state->coins < getCost(supplyPos))
  {
    if (DEBUG)
      printf("You do not have enough money to buy that. You have %d coins.\n", state->coins);
    return -1;
  }
  else
  {
    state->phase = 1;
    //state->supplyCount[supplyPos]--;
    gainCard(supplyPos, state, 0, who); //card goes in discard, this might be wrong.. (2 means goes into hand, 0 goes into discard)
    state->coins = (state->coins) - (getCost(supplyPos));
    state->numBuys--;
    if (DEBUG)
      printf("You bought card number %d for %d coins. You now have %d buys and %d coins.\n", supplyPos, getCost(supplyPos), state->numBuys, state->coins);
  }
  //state->discard[who][state->discardCount[who]] = supplyPos;
  //state->discardCount[who]++;
  return 0;
}
*/
