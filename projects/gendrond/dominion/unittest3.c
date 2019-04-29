/*
 * Devin Gendron
 * Assignment 3 - Unit Tests
 * Due: May 5th, 2019
 * onid: gendrond
 * email: gendrond@oregonstate.edu
 * 
 * Unit Test 3
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
    printf("Testing getCost Function...\n");
    int cardCosts[] = {0, 2, 5, 8, 0, 3, 6, 6, 5, 4, 4, 5, 4, 4, 3, 4, 3, 5, 3, 5, 3, 4, 2, 5, 4, 4, 4};
    //int cardCostsIncorrect[] = {0, 2, 5, 8, 6, 3, 6, 6, 5, 4, 4, 5, 4, 4, 4, 4, 3, 5, 3, 5, 3, 6, 2, 5, 2, 4};
    char *cardNames[] = {"curse", "estate", "duchy", "province", "copper", "sivler",
                         "gold", "adventurer", "council_room", "feast", "gardens",
                         "mine", "remodel", "smithy", "village", "baron", "great_hall",
                         "minion", "steward", "tribute", "ambassador", "cutpurse", "embargo",
                         "outposts", "salvager", "sea_hag", "treasure_map"};

    printf("RUNNING TESTS ON IS GAME OVER FUNCTION FUNCTION\n");
    printf("\n");
    printf("Testing with Correct Data:\n");
    printf("+===================================+\n");
    int i = 0;
    int allPassed = 0;
    for (i = 0; i < 27; i++)
    {
        if (getCost(i) == cardCosts[i])
        {
            printf("Card %s Cost Passed.\n", cardNames[i]);
        }
        else
        {
            printf("Card %s Cost FAILED.\n", cardNames[i]);
            allPassed++;
        }

        if (getCost(i) == -1)
        {
            printf("Default Value Reached - FAIL.\n");
        }
    }
    if (allPassed == 0)
    {
        printf("TEST SUCCESSFULLY COMPLETED - No Errors.\n");
    }
    else
    {
        printf("TEST FAILED - Errors with card costs.\n");
        allPassed = 0;
    }
    printf("+===================================+\n");
    printf("\n");
    printf("TESTS ON GETCOST FUNCTION COMPLETED.\n");

    return 0;
}

/*printf("Testing with Correct Data:\n");
    printf("+===================================+\n");
    int m = 0;
    int allPassed = 0;
    for (m = 0; m < 26; m++)
    {
        if (getCost(m) == cardCosts[m])
        {
            printf("Card %s Cost Passed", cardNames[m]);
        }
        else
        {
            printf("Card %s Cost Passed", cardNames[i]);
            allPassed++;
        }
    }
    if (allPassed == 0)
    {
        printf("TEST SUCCESSFULLY COMPLETED - No Errors.\n");
    }
    else
    {
        printf("TEST FAILED - Errors with card costs.\n");
        allPassed = 0;
    }
    printf("+===================================+\n");
    printf("\n");*/

/*
int getCost(int cardNumber)
{
  switch (cardNumber)
  {
  case curse:
    return 0;
  case estate:
    return 2;
  case duchy:
    return 5;
  case province:
    return 8;
  case copper:
    return 0;
  case silver:
    return 3;
  case gold:
    return 6;
  case adventurer:
    return 6;
  case council_room:
    return 5;
  case feast:
    return 4;
  case gardens:
    return 4;
  case mine:
    return 5;
  case remodel:
    return 4;
  case smithy:
    return 4;
  case village:
    return 3;
  case baron:
    return 4;
  case great_hall:
    return 3;
  case minion:
    return 5;
  case steward:
    return 3;
  case tribute:
    return 5;
  case ambassador:
    return 3;
  case cutpurse:
    return 4;
  case embargo:
    return 2;
  case outpost:
    return 5;
  case salvager:
    return 4;
  case sea_hag:
    return 4;
  case treasure_map:
    return 4;
  }

  return -1;
}
*/