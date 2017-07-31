/*

 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "dominion.h"
#include "dominion_helpers.h"

#define TEST_MAX 1000

int checkSmithyCard(int cp, struct gameState *g, int oldHand, int oldDeck){
	int sizeDiff;

/* For Debugging
	printf("state handsize: %d\n", g->handCount[cp]);
	printf("state decksize: %d\n", g->deckCount[cp]);
	printf("state discardsize: %d\n", g->discardCount[cp]);

	printf("old handsize: %d\n", oldHand);
	printf("old decksize: %d\n", oldDeck);
	printf("old discard: %d\n", oldDiscard);
*/

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


/*
	printf("\n-----Checking size of hand-----\n");
	printf("Size of hand before smithy() call: %d\n", oldHand);
	printf("Size of hand after smithy() call: %d\n", g->handCount[cp]);
	if(g->handCount[cp] <= oldHand)
	{
		printf("Error: Before should be < after\n");
		assert(g->handCount[cp] <= oldHand);
	}

	printf("\n-----Checking size of deck-----\n");
	printf("Size of deck before smithy() call: %d\n", oldDeck);
	printf("Size of deck after smithy() call: %d\n", g->deckCount[cp]);
	sizeDiff = g->deckCount[cp] - oldDeck;
	if(sizeDiff > 3 || sizeDiff < 3)
	{
		printf("Error: size of deck before should be 3 less than size of deck after\n");
		assert(sizeDiff > 3 || sizeDiff < 3);
	}
*/
}

int playSmithyCard(int currentPlayer, int handPos, struct gameState *state){
	int i;

    //+3 Cards
    for (i = 0; i < 3; i++)
	{
	  drawCard(currentPlayer, state);
	}
			
    //discard card from hand
    discardCard(handPos, currentPlayer, state, 0);

    return 0;
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

		g.handCount[currentPlayer] = rand() % MAX_HAND;
		g.deckCount[currentPlayer] = rand() % MAX_DECK;

		handCountCheck = g.handCount[currentPlayer];
		deckCountCheck = g.deckCount[currentPlayer];

/*For Debugging
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
			printf("\nNot enough cards to draw\n");
			shuffle(currentPlayer, &g);
		}
		else
		{
			playSmithyCard(currentPlayer, handPos, &g);
			//cardEffect(smithy, 1, 1, 1, &g, handPos, &bonus);
			checkSmithyCard(currentPlayer, &g, handCountCheck, deckCountCheck);
		}
	}

	return 0;
}