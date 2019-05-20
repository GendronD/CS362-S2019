/*
 * Devin Gendron
 * Assignment 4 - Random Testing
 * Due: May 19th, 2019
 * onid: gendrond
 * email: gendrond@oregonstate.edu
 * 
 * Random Card Test 2
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include <time.h>

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

    int m = 0;
    for (m = 0; m < 100; m++)
    {
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

        // Randomize Number of Actions
        int numberActions = rand() % 10 + 1;
        state.numActions = numberActions;

        //test
        printf("Testing Village Card...%d\n", m);

        struct gameState testG;
        memcpy(&testG, &state, sizeof(struct gameState));
        int initialHandCount = testG.handCount[testG.whoseTurn];
        int initialActionCount = testG.numActions;

        cardEffect(village, choice1, choice2, choice3, &testG, handpos, &bonus);

        printf("+===================================+\n");
        // Test Card Amounts (+1 and then discard - should be equal)
        if (initialHandCount == testG.handCount[testG.whoseTurn])
        {
            printf("TEST PASSED - Card Balance.\n");
        }
        else if (initialHandCount > testG.handCount[testG.whoseTurn])
        {
            printf("TEST FAILED - Card Not Discarded.\n");
        }
        else if (initialHandCount < testG.handCount[testG.whoseTurn])
        {
            printf("TEST FAILED - Card Not Properly Drawn.\n");
        }

        // Test Action Amount
        if (initialActionCount == initialActionCount + 2)
        {
            printf("TEST PASSED - Action Properly Added.\n");
        }
        else
        {
            printf("TEST Failed - Action Not Properly Added.\n");
        }
    }
    printf("+===================================+\n");
    printf("\n");
    printf("TESTS ON VILLAGE CARD COMPLETED.\n");

    return 0;
}

/*
  case village:
    //+1 Card
    drawCard(currentPlayer, state);
    //+2 Actions
    state->numActions = state->numActions + 2;
    //discard played card from hand
    discardCard(handPos, currentPlayer, state, 0);
    return 0;
*/