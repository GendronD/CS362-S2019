/*
 * Devin Gendron
 * Assignment 3 - Unit Tests
 * Due: May 5th, 2019
 * onid: gendrond
 * email: gendrond@oregonstate.edu
 * 
 * Card Test 4
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"

int main()
{
    int seed = 1000;
    int numPlayer = 2;
    int maxBonus = 10;
    int p, r, handCount;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int k[10] = {adventurer, council_room, outpost, ambassador, mine, remodel, smithy, village, baron, great_hall};
    struct gameState state;
    initializeGame(numPlayer, k, seed, &state);

    //test 
    printf("Testing Outpost Card.\n");
    printf("+===================================+\n"); 
    struct gameState testG;
    memcpy(&testG, &state, sizeof(struct gameState));

    int initialOutpost = testG.outpostPlayed;
    int initialHandCount = testG.handCount[testG.whoseTurn];

    printf("Number of Outpost Before: %d.\n", initialOutpost);

    cardEffect(outpost, choice1, choice2, choice3, &testG, handpos, &bonus);

    printf("Number of Outpost After: %d.\n", testG.outpostPlayed);

    if (initialOutpost < testG.outpostPlayed)
    {
        printf("TEST PASSED - Outpost Number Not Increased.\n");
    }
    else
    {
        printf("TEST FAILED - Outpost Number Not Increased.\n");
    }

    if(initialHandCount > testG.handCount[testG.whoseTurn])
    {
        printf("TEST PASSED - Card Properly Discarded.\n");
    }
    else 
    {
        printf("TEST FAILED - Card Not Discarded.\n");
    }

    printf("+===================================+\n"); 
    printf("\n");
    printf("TESTS ON OUTPOST CARD COMPLETED.\n");

    return 0;
}

/*
// Outpost card - mistake added to outpostPlayed from ++ to --
int outpostCard(int handPos, int currentPlayer, struct gameState *state)
{
  //set outpost flag
  //state->outpostPlayed++; //correct
  //****************************************************************************
  state->outpostPlayed--; // bug
  //****************************************************************************
  //discard card
  discardCard(handPos, currentPlayer, state, 0);
  return 0;
}
*/
