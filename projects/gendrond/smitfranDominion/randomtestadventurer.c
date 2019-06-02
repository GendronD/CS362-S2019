/*
 * Devin Gendron
 * Assignment 4 - Random Testing
 * Due: May 19th, 2019
 * onid: gendrond
 * email: gendrond@oregonstate.edu
 * 
 * Random Test Adventurer
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include <time.h>

int main()
{
    // Prepare Dominion State
    srand(time(0));
    int seed = 1000;
    int numPlayer = 2;
    int maxBonus = 10;
    int z;
    int drawntreasure;
    int temphand;
    int cardDrawn;
    int p, r, handCount;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int k[10] = {adventurer, council_room, outpost, ambassador, mine, remodel, smithy, village, baron, great_hall};
    struct gameState state;
    initializeGame(numPlayer, k, seed, &state);

    int m = 0;
    for (m = 0; m < 100; m++)
    {
        // Test Statement
        printf("Testing Adventurer Card...%d\n", m);
        printf("+===================================+\n");

        // Set Random Deck Size
        int sizeOfDeck = rand() % MAX_DECK + 1;

        // Set Hand Size
        int sizeOfHand = rand() % MAX_DECK + 1;
        if (sizeOfHand > sizeOfDeck)
        {
            sizeOfHand = sizeOfHand - sizeOfDeck;
        }

        // Set Randomized Selections in State
        state.deckCount[0] = sizeOfDeck - sizeOfHand;
        state.handCount[0] = sizeOfHand;

        // Random Hand Position
        handpos = rand() % sizeOfHand + 1;

        // Select Card Choice if an Option
        while (choice1 == 0 && choice2 == 0 && choice3 == 0)
        {
            // Choice1
            choice1 = rand() % 2;
            // Choice2
            if (choice1 == 0)
            {
                choice2 = rand() % 2;
            }
            // Choice3
            if (choice1 == 0 && choice2 == 0)
            {
                choice3 = rand() % 2;
            }
        }

        // Set Bonus
        bonus = rand() % 50;

        // Set Game State to Test
        struct gameState testG;
        memcpy(&testG, &state, sizeof(struct gameState));

        // NOTE: cardEffect Function Not Called Due To Segmentation Fault Purposefully Added as Bug
        //cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);
        //adventurerCase(adventurer, &testG, 1, z, drawntreasure, temphand, cardDrawn);

        // Test Deck Drawing
        printf("Testing For Deck.\n");
        if (testG.deckCount[testG.whoseTurn] == state.deckCount[state.whoseTurn])
        {
            printf("TEST FAILED - Card Not Drawn from Deck.\n");
        }
        else if (testG.deckCount[testG.whoseTurn] == state.deckCount[state.whoseTurn])
        {
            printf("TEST PASSED - Card Correctly Drawn from Deck.\n");
        }

        // Set Game State to Test2
        struct gameState testG2;
        memcpy(&testG2, &state, sizeof(struct gameState));

        // NOTE: cardEffect Function Not Called Due To Segmentation Fault Purposefully Added as Bug
        //cardEffect(adventurer, choice1, choice2, choice3, &testG2, handpos, &bonus);
        //adventurerCase(adventurer, &testG2, 1, z, drawntreasure, temphand, cardDrawn);

        // Test That Proper Card in Hand From Deck
        printf("Testing For Proper Hand.\n");
        if (testG2.hand[testG2.whoseTurn][testG2.handCount[testG2.whoseTurn]] == state.hand[state.whoseTurn][state.handCount[state.whoseTurn]])
        {
            printf("TEST FAILED - Card Not Drawn from Deck.\n");
        }
        else if (testG2.hand[testG2.whoseTurn][testG2.handCount[testG2.whoseTurn]] == state.hand[state.whoseTurn][state.handCount[state.whoseTurn]])
        {
            printf("TEST PASSED - Card Correctly Put in Hand.\n");
        }

        // Prepare State For New Card Draw Test
        //struct gameState testG2;
        memcpy(&testG2, &state, sizeof(struct gameState));
        // NOTE: cardEffect Function Not Called Due To Segmentation Fault Purposefully Added as Bug
        //cardEffect(adventurer, choice1, choice2, choice3, &testG2, handpos, &bonus);
        //adventurerCase(adventurer, &testG2, 1, z, drawntreasure, temphand, cardDrawn);

        // Test If Treasure Was Properly Drawn
        printf("Testing For Deck.\n");
        if (testG2.hand[testG2.whoseTurn][testG2.handCount[testG2.whoseTurn]] - 1 == copper && state.hand[state.whoseTurn][state.handCount[state.whoseTurn]] - 1 == copper || testG2.hand[testG2.whoseTurn][testG2.handCount[testG2.whoseTurn]] - 1 == silver && state.hand[state.whoseTurn][state.handCount[state.whoseTurn]] - 1 == silver || testG2.hand[testG2.whoseTurn][testG2.handCount[testG2.whoseTurn]] - 1 == gold && state.hand[state.whoseTurn][state.handCount[state.whoseTurn]] - 1 == gold && testG2.hand[testG2.whoseTurn][testG2.handCount[testG2.whoseTurn]] - 2 == copper && state.hand[state.whoseTurn][state.handCount[state.whoseTurn]] - 2 == copper || testG2.hand[testG2.whoseTurn][testG2.handCount[testG2.whoseTurn]] - 2 == silver && state.hand[state.whoseTurn][state.handCount[state.whoseTurn]] - 2 == silver || testG2.hand[testG2.whoseTurn][testG2.handCount[testG2.whoseTurn]] - 2 == gold && state.hand[state.whoseTurn][state.handCount[state.whoseTurn]] - 2 == gold)
        {
            printf("TEST PASSED - TWO TREASURE CARDS DRAWN.\n");
        }
        else if (testG2.hand[testG2.whoseTurn][testG2.handCount[testG2.whoseTurn]] - 1 != copper && state.hand[state.whoseTurn][state.handCount[state.whoseTurn]] - 1 != copper || testG2.hand[testG2.whoseTurn][testG2.handCount[testG2.whoseTurn]] - 1 != silver && state.hand[state.whoseTurn][state.handCount[state.whoseTurn]] - 1 != silver || testG2.hand[testG2.whoseTurn][testG2.handCount[testG2.whoseTurn]] - 1 != gold && state.hand[state.whoseTurn][state.handCount[state.whoseTurn]] - 1 != gold && testG2.hand[testG2.whoseTurn][testG2.handCount[testG2.whoseTurn]] - 2 != copper && state.hand[state.whoseTurn][state.handCount[state.whoseTurn]] - 2 != copper || testG2.hand[testG2.whoseTurn][testG2.handCount[testG2.whoseTurn]] - 2 != silver && state.hand[state.whoseTurn][state.handCount[state.whoseTurn]] - 2 != silver || testG2.hand[testG2.whoseTurn][testG2.handCount[testG2.whoseTurn]] - 2 != gold && state.hand[state.whoseTurn][state.handCount[state.whoseTurn]] - 2 != gold)
        {
            printf("TEST FAILED - MISSING TWO NEW TREASURE CARDS FROM HAND.\n");
        }

        // Test That The Temporary Hand Has Been Emptied
        if (testG2.discardCount[testG2.whoseTurn] == state.discardCount[state.whoseTurn])
        {
            printf("TEST PASSED - CARDS SUCCESSFULLY DISCARDED.\n");
        }
        else
        {
            printf("TEST FAILED - CARDS UNSUCCESSFULLY DISCARDED.\n");
        }
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
