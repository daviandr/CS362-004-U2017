/*

 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "dominion.h"
#include "dominion_helpers.h"

#define TEST_MAX 1000
#define MAX_ACTIONS 10

int checkVillageCard(int currentPlayer, struct gameState *g, int oldHand, int oldDeck, int oldActions){
	int sizeDiff;

/* For Debugging
	printf("\nIn check village card function\n");
	printf("state handsize: %d\n", g->handCount[cp]);
	printf("state decksize: %d\n", g->deckCount[cp]);
	printf("state actions: %d\n", g->numActions);

	printf("old handsize: %d\n", oldHand);
	printf("old decksize: %d\n", oldDeck);
	printf("old actions: %d\n", numberActions);
*/

//	printf("\n-----Entering Check Phase-----\n");

	//first, check hand size. New hand should be +1 than old hand
	sizeDiff = g->handCount[currentPlayer] - oldHand;
	if(sizeDiff == 0)
	{
		printf("TEST PASSED: Hand count correct\n");
	}
	else
	{
		printf("TEST FAILED\n");
		printf("	Old hand count: %d\n", oldHand);
		printf("	New hand count: %d\n", g->handCount[currentPlayer]);
		printf("	Should be %d cards in hand\n", oldHand + 1);
	}
	//assert(sizeDiff == 0);
	
	//second, check deck size. New deck should be 1 less than old
	sizeDiff = oldDeck - g->deckCount[currentPlayer];
	if(sizeDiff == 1)
	{
		printf("TEST PASSED: Deck count correct\n");
	}
	else
	{
		printf("TEST FAILED:\n");
		printf("	Old deck count: %d\n", oldDeck);
		printf("	New deck count: %d\n", g->deckCount[currentPlayer]);
		printf("	Should be %d cards in deck\n", oldDeck - 3);
	}
	//assert(sizeDiff == 1);
	
	//third, check number of actions New actions should be +2 than old actions
	sizeDiff = g->numActions - oldActions;
	if(sizeDiff == 2)
	{
		printf("TEST PASSED: Correct number of actions\n");
	}
	else
	{
		printf("TEST FAILED\n");
		printf("	Old action count: %d\n", oldActions);
		printf("	New action count: %d\n", g->numActions);
		printf("	Should be %d actions\n", oldActions + 2);
	}
	//assert(sizeDiff == 2);
/*
	printf("\n-----Entering Test-----\n");
	//First, new handsize(handsize in struct g) should be 2 > than oldHand.
	sizeDiff = g->handCount[cp] - oldHand;
	printf("After Smithy Card Hand Count: %d\n", g->handCount[cp]);
	printf("Old Hand Count: %d\n", oldHand);
	printf("Size Difference: %d\n\n", sizeDiff);
	assert(sizeDiff == 2);
	//Second, After Smithy Card decksize(decksize in struct g) should be 3 < than oldDeck.
	sizeDiff = oldDeck - g->deckCount[cp];
	printf("After Smithy Card Deck Count: %d\n", g->deckCount[cp]);
	printf("Old Deck Count: %d\n", oldDeck);
	printf("Size Difference: %d\n\n", sizeDiff);
	assert(sizeDiff == 3);
*/
}

int main(){
	int i;
	int bonus;
	int handPos;
	int gameSeed;
	int numPlayers;
	int currentPlayer;
	int handCountCheck;
	int deckCountCheck;
	int numberActions = 1;
	int discardCountCheck;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

	struct gameState g;

	srand(time(NULL));

	for(i = 0; i < TEST_MAX; i++)
	{
		printf("\n-*-*-*-*-TEST NUMBER (%d)-*-*-*-*-\n", i + 1);

		gameSeed = rand();		//generate a random see to initialize new game
		//printf("\nRandom Seed: %d\	n", gameSeed);
		numPlayers = (rand() % (3 - 1) + 1);	//pick random number of players, between 0 - MAX_PLAYERS
		bonus = 0;		//for cardEffect() function
		handPos = rand() % 4; 	//generte random handPos in standard sized hand
		currentPlayer = (rand() % (3 - 1) + 1);	//pick a random player, based on the number of players from above

/*For Debugging
		printf("Gameseed: %d\n", gameSeed);
		printf("Number Players: %d\n", numPlayers);
		printf("Hand Position: %d\n", handPos);
		printf("Current Player: %d\n", currentPlayer);
*/

		initializeGame(numPlayers, k, gameSeed, &g);

		g.handCount[currentPlayer] = rand() % (5 - 1) + 1;
		g.deckCount[currentPlayer] = rand() % MAX_DECK;
		g.numActions = 1;

		handCountCheck = g.handCount[currentPlayer];
		deckCountCheck = g.deckCount[currentPlayer];

/* For Debugging
		printf("\n----Parameters for Test----\n");
		printf("Number of Players: %d\n", numPlayers);
		printf("Hand Position: %d\n", handPos);
		printf("Current Player; %d\n", currentPlayer);
		printf("Hand Count: %d\n", handCountCheck);
		printf("Deck Count: %d\n", deckCountCheck);
		printf("Number of Actions: %d\n", numberActions);
*/

/*For Debugging
		printf("old handcount: %d\n", handCountCheck);
		printf("old deckcount: %d\n", deckCountCheck);
*/
		villageEffect(&g, handPos);
		checkVillageCard(currentPlayer, &g, handCountCheck, deckCountCheck, numberActions);
	}

	return 0;
}







