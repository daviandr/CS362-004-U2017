/*

 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "dominion.h"
#include "dominion_helpers.h"

#define TEST_MAX 100

int checkAdventurerCard(int cp, struct gameState *g, int oldHand, int oldDeck, int oldTreasure){
	int sizeDiff;

/* For Debugging
	printf("state handsize: %d\n", g->handCount[cp]);
	printf("state decksize: %d\n", g->deckCount[cp]);

	printf("old handsize: %d\n", oldHand);
	printf("old decksize: %d\n", oldDeck);
*/

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
/*
	printf("\n-----Checking size of hand-----\n");
	printf("Size of hand before adventurer() call: %d\n", oldHand);
	printf("Size of hand after adventurer() call: %d\n", g->handCount[cp]);
*/
	sizeDiff = g->handCount[cp] - oldHand;
	assert(sizeDiff == 2);
/*
	printf("\n-----Checking size of deck-----\n");
	printf("Size of deck before adventurer() call: %d\n", oldDeck);
	printf("Size of deck after adventurer() call: %d\n", g->deckCount[cp]);
*/
	sizeDiff = g->deckCount[cp] - oldDeck;
	assert(sizeDiff == 2);
}

int main(){
	int r;
	int i;
	int bonus;
	int handPos;
	int gameSeed;
	int numPlayers;
	int currentPlayer;
	int handCountCheck;
	int deckCountCheck;
	int discardCountCheck;
	int treasureCount = 0;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

	struct gameState g;

	srand(time(NULL));

	for(i = 0; i < TEST_MAX; i++)
	{	
		//printf("\n-*-*-*-*-TEST NUMBER (%d)-*-*-*-*-\n", i + 1);

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

		g.handCount[currentPlayer] = rand() % MAX_HAND;
		g.deckCount[currentPlayer] = rand() % MAX_DECK;

		handCountCheck = g.handCount[currentPlayer];
		deckCountCheck = g.deckCount[currentPlayer];

/* For Debugging
		printf("\n----Parameters for Test----\n");
		printf("Number of Players: %d\n", numPlayers);
		printf("Hand Position: %d\n", handPos);
		printf("Current Player; %d\n", currentPlayer);
		printf("Hand Count: %d\n", handCountCheck);
		printf("Deck Count: %d\n", deckCountCheck);
*/
/*For Debugging
		printf("old handcount: %d\n", handCountCheck);
		printf("old deckcount: %d\n", deckCountCheck);
*/
		if(deckCountCheck < 3)
		{
			//printf("\nNot enough cards to draw\n");
			shuffle(currentPlayer, &g);
		}
		else
		{
		playAdventurer(currentPlayer, handPos, &g);
			//cardEffect(smithy, 1, 1, 1, &g, handPos, &bonus);
			checkAdventurerCard(currentPlayer, &g, handCountCheck, deckCountCheck, treasureCount);
		}
	}

	return 0;
}