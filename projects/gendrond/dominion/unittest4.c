/*
 * Devin Gendron
 * Assignment 3 - Unit Tests
 * Due: May 5th, 2019
 * onid: gendrond
 * email: gendrond@oregonstate.edu
 * 
 * Unit Test 4
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"

// Have Tests Print "TEST SUCCESSFULLY COMPLETED"
// Or Print "TEST FAILED"

int main()
{
    printf("Testing numHandCards Function...\n");
    int i = 0;
    int seed = 1000;
    int numPlayer = 2;
    int maxBonus = 10;
    int p, r, handCount;
    int bonus;
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    struct gameState handCardState;
    initializeGame(numPlayer, k, seed, &handCardState);

    printf("RUNNING TESTS ON NUMHANDCARDS FUNCTION FUNCTION\n");
    printf("\n");
    printf("Testing with Correct Data:\n");
    printf("+===================================+\n");

    for (i = 0; i < numPlayer; i++)
    {
        switch (i)
        {
        case (0):
            handCardState.whoseTurn = 1;
            handCardState.handCount[1] = 10;
            //if (handCardState.handCount[whoseTurn(&handCardState)] == 10)
            if (numHandCards(&handCardState) == 10)
            {
                printf("TEST SUCCESSFULLY COMPLETED - No Errors.\n");
                printf("Player 1 Turn with 10 cards - returned 10.\n");
            }
            else
            {
                printf("TEST FAILED.\n");
                printf("Incorrect Number of Cards returned for Player 1.\n");
            }
            break;

        case (1):
            handCardState.whoseTurn = 2;
            handCardState.handCount[2] = 13;
            //if (handCardState.handCount[whoseTurn(&handCardState)] == 13)
            if (numHandCards(&handCardState) == 13)
            {
                printf("TEST SUCCESSFULLY COMPLETED - No Errors.\n");
                printf("Player 2 Turn with 13 cards - returned 13.\n");
            }
            else
            {
                printf("TEST FAILED.\n");
                printf("Incorrect Number of Cards returned for Player 2.\n");
            }
            break;

        default:
            break;
        }
    }
    printf("+===================================+\n");
    printf("\n");
    printf("TESTS ON NUMHANDCARDS FUNCTION COMPLETED.\n");

    return 0;
}

/*
int numHandCards(struct gameState *state)
{
  return state->handCount[whoseTurn(state)];
}
*/