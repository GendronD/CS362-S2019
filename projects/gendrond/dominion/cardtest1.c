/*
 * Devin Gendron
 * Assignment 3 - Unit Tests
 * Due: May 5th, 2019
 * onid: gendrond
 * email: gendrond@oregonstate.edu
 * 
 * Card Test 1
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
    printf("Testing Adventurer Card...\n");

    printf("+===================================+\n");

    //test deck drawing
    printf("Testing For Deck.\n");
    
    
    struct gameState testG;
    memcpy(&testG, &state, sizeof(struct gameState));
    //////cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);
    
    if(testG.deckCount[testG.whoseTurn] == state.deckCount[state.whoseTurn])
    {
        printf("TEST FAILED - Card Not Drawn from Deck.\n");
    } 
    else if(testG.deckCount[testG.whoseTurn] == state.deckCount[state.whoseTurn])
    {
        printf("TEST PASSED - Card Correctly Drawn from Deck.\n");
    }

    
    
    // Test that a card was correctly drawn and put in hand
    printf("Testing For Deck.\n");
    struct gameState testG2;
    
    memcpy(&testG2, &state, sizeof(struct gameState));
    
    //cardEffect(adventurer, choice1, choice2, choice3, &testG2, handpos, &bonus);
    
    if(testG2.hand[testG2.whoseTurn][testG2.handCount[testG2.whoseTurn]] == state.hand[state.whoseTurn][state.handCount[state.whoseTurn]])
    {
        printf("TEST FAILED - Card Not Drawn from Deck.\n");
    } 
    else if(testG2.hand[testG2.whoseTurn][testG2.handCount[testG2.whoseTurn]] == state.hand[state.whoseTurn][state.handCount[state.whoseTurn]])
    {
        printf("TEST PASSED - Card Correctly Put in Hand.\n");
    }

    
    // Test that if treasure was drawn, it as added
    printf("Testing For Deck.\n");
    //struct gameState testG2;
    memcpy(&testG2, &state, sizeof(struct gameState));
    /////////cardEffect(adventurer, choice1, choice2, choice3, &testG2, handpos, &bonus);

    if(testG2.hand[testG2.whoseTurn][testG2.handCount[testG2.whoseTurn]] - 1 == copper && state.hand[state.whoseTurn][state.handCount[state.whoseTurn]] - 1 == copper
    || testG2.hand[testG2.whoseTurn][testG2.handCount[testG2.whoseTurn]] - 1 == silver && state.hand[state.whoseTurn][state.handCount[state.whoseTurn]] - 1 == silver
    || testG2.hand[testG2.whoseTurn][testG2.handCount[testG2.whoseTurn]] - 1 == gold && state.hand[state.whoseTurn][state.handCount[state.whoseTurn]] - 1 == gold
    && testG2.hand[testG2.whoseTurn][testG2.handCount[testG2.whoseTurn]] - 2 == copper && state.hand[state.whoseTurn][state.handCount[state.whoseTurn]] - 2 == copper
    || testG2.hand[testG2.whoseTurn][testG2.handCount[testG2.whoseTurn]] - 2 == silver && state.hand[state.whoseTurn][state.handCount[state.whoseTurn]] - 2 == silver
    || testG2.hand[testG2.whoseTurn][testG2.handCount[testG2.whoseTurn]] - 2 == gold && state.hand[state.whoseTurn][state.handCount[state.whoseTurn]] - 2 == gold){
        printf("TEST PASSED - TWO TREASURE CARDS DRAWN.\n");
    } 
    else if(testG2.hand[testG2.whoseTurn][testG2.handCount[testG2.whoseTurn]] - 1 != copper && state.hand[state.whoseTurn][state.handCount[state.whoseTurn]] - 1 != copper
    || testG2.hand[testG2.whoseTurn][testG2.handCount[testG2.whoseTurn]] - 1 != silver && state.hand[state.whoseTurn][state.handCount[state.whoseTurn]] - 1 != silver
    || testG2.hand[testG2.whoseTurn][testG2.handCount[testG2.whoseTurn]] - 1 != gold && state.hand[state.whoseTurn][state.handCount[state.whoseTurn]] - 1 != gold
    && testG2.hand[testG2.whoseTurn][testG2.handCount[testG2.whoseTurn]] - 2 != copper && state.hand[state.whoseTurn][state.handCount[state.whoseTurn]] - 2 != copper
    || testG2.hand[testG2.whoseTurn][testG2.handCount[testG2.whoseTurn]] - 2 != silver && state.hand[state.whoseTurn][state.handCount[state.whoseTurn]] - 2 != silver
    || testG2.hand[testG2.whoseTurn][testG2.handCount[testG2.whoseTurn]] - 2 != gold && state.hand[state.whoseTurn][state.handCount[state.whoseTurn]] - 2 != gold)
    {
        printf("TEST FAILED - MISSING TWO NEW TREASURE CARDS FROM HAND.\n");
    }

    // Test that temphand is empty
    if(testG2.discardCount[testG2.whoseTurn] == state.discardCount[state.whoseTurn])
    {
        printf("TEST PASSED - CARDS SUCCESSFULLY DISCARDED.\n");
    } else
    {
        printf("TEST FAILED - CARDS UNSUCCESSFULLY DISCARDED.\n");
    }

    

    printf("+=============================================+\n");
    printf("\n");
    printf("TESTS ON ADVENTURER CARD COMPLETED.\n");



    return 0;
}

/*
// Adventurer - mistakes must be added
int adventurerCard(int drawntreasure, int currentPlayer, struct gameState *state, int cardDrawn, int temphand[], int z)
{
  while (drawntreasure < 2)
  {
    if (state->deckCount[currentPlayer] < 1)
    { //if the deck is empty we need to shuffle discard and add to deck
      shuffle(currentPlayer, state);
    }
    drawCard(currentPlayer, state);
    cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer] - 1]; //top card of hand is most recently drawn card.
    //if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold) //correct
    //****************************************************************************
    if (cardDrawn == copper && cardDrawn == silver || cardDrawn == gold) //bug
                                                                         //****************************************************************************
      drawntreasure++;
    else
    {
      temphand[z] = cardDrawn;
      state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
      z++;
    }
  }
  while (z - 1 >= 0)
  {
    state->discard[currentPlayer][state->discardCount[currentPlayer]++] = temphand[z - 1]; // discard all cards in play that have been drawn
    z = z - 1;
  }
  return 0;
}
*/