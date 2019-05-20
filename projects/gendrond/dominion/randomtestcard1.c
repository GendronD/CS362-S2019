/*
 * Devin Gendron
 * Assignment 4 - Random Testing
 * Due: May 19th, 2019
 * onid: gendrond
 * email: gendrond@oregonstate.edu
 * 
 * Random Card Test 1
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include <time.h>

int main()
{
    // Prepare Game State For Random Tests
    char *cardNames[] = {"curse", "estate", "duchy", "province", "copper", "sivler",
                         "gold", "adventurer", "council_room", "feast", "gardens",
                         "mine", "remodel", "smithy", "village", "baron", "great_hall",
                         "minion", "steward", "tribute", "ambassador", "cutpurse", "embargo",
                         "outposts", "salvager", "sea_hag", "treasure_map"};
    int seed = 1000;
    int numPlayer = 2;
    int maxBonus = 10;
    int p, r, handCount;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int k[10] = {adventurer, council_room, outpost, ambassador, mine, remodel, smithy, village, baron, great_hall};
    struct gameState state;
    initializeGame(numPlayer, k, seed, &state);

    int g = 0;
    for (g = 0; g < 100; g++)
    {
        // Test Statement
        printf("Testing Smithy Card...\n");
        printf("+===================================+\n");

        // Set Bonus
        bonus = rand() % 50;

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

        // Select Card Choice if an Option (Randomized)
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

        struct gameState testG;
        memcpy(&testG, &state, sizeof(struct gameState));
        int initialHandCount = testG.handCount[testG.whoseTurn];
        int initialActionCount = testG.numActions;
        int victoryEstate = testG.supplyCount[estate];
        int victoryDuchy = testG.supplyCount[duchy];
        int victoryProvince = testG.supplyCount[province];
        //int initialKingdom = testG.supplyCount;

        cardEffect(smithy, choice1, choice2, choice3, &testG, handpos, &bonus);

        printf("+===================================+\n");
        // Test Card Amounts (+3 and then discard 1 - should be +2 in hand)
        if (initialHandCount + 2 == testG.handCount[testG.whoseTurn])
        {
            printf("TEST PASSED - 3 Cards Properly Added and 1 removed from Proper Player.\n");
        }
        else
        {
            printf("TEST FAILED - Cards Not Properly Added.\n");
        }

        // Test Victory Cards
        if (victoryEstate == testG.supplyCount[estate] && victoryDuchy == testG.supplyCount[duchy] && victoryProvince == testG.supplyCount[province])
        {
            printf("TEST PASSED - Victory Cards Not Effected.\n");
        }
        else
        {
            printf("TEST FAILED - Victory Cards Effected.\n");
        }

        // Test Kingdom Cards
        int i = 0;
        int j = 0;
        for (i = adventurer; i <= treasure_map; i++) //loop all cards
        {
            for (j = 0; j < 10; j++) //loop chosen cards
            {
                if (k[j] == i)
                {
                    if (testG.supplyCount[i] == state.supplyCount[i])
                    {
                        printf("%s PASSED.\n", cardNames[i]);
                    }
                    else
                    {
                        printf("%s FAILED.\n", cardNames[i]);
                    }
                }
                else //card is not in the set choosen for the game
                {
                    state.supplyCount[i] = -1;
                }
            }
        }
    }

    printf("+===================================+\n");
    printf("\n");
    printf("TESTS ON SMITHY CARD COMPLETED.\n");

    return 0;
}

/*
// Smithy - mistakes must be added
int smithyCard(int i, int currentPlayer, struct gameState *state, int handPos)
{
  //+3 Cards
  //****************************************************************************
  //for (i = 0; i < 3; i++) // correct
  for (i = 0; i <= 3; i++) // bug
  //****************************************************************************
  {
    drawCard(currentPlayer, state);
  }
  //discard card from hand
  discardCard(handPos, currentPlayer, state, 0);
  return 0;
}
*/