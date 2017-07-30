/*

 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "dominion.h"
#include "dominion_helpers.h"

#define TEST_MAX 100

int checkSmithyCard(int cp, struct gameState *g, int oldHand, int oldDeck, int oldDiscard){
	int sizeDiff;

	printf("\n-----Checking size of hand-----\n");
	printf("Size of hand before smithy() call: %d\n", oldHand);
	printf("Size of hand after smithy() call: %d\n", g->handCount[cp]);
	if(g->handCount[cp] <= oldHand)
	{
		printf("Error: Before should be < after\n");
	}

	printf("\n-----Checking size of deck-----\n");
	printf("Size of deck before smithy() call: %d\n", oldDeck);
	printf("Size of deck after smithy() call: %d\n", g->deckCount[cp]);
	sizeDiff = g->deckCount[cp] - oldDeck;
	if(sizeDiff > 3 || sizeDiff < 3)
	{
		printf("Error: size of deck before should be 3 less than size of deck after\n");
	}





}

int main(){
	int i;
	int gameSeed;
	int numPlayers;
	int bonus;
	int handPos;
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
		numPlayers = rand() % (MAX_PLAYERS - 2) + 2;	//pick random number of players, between 0 - MAX_PLAYERS
		bonus = 0;		//for cardEffect() function
		handPos = rand() % 4; 	//generte random handPos in standard sized hand
		currentPlayer = rand() % (MAX_PLAYERS - 2) + 2;	//pick a random player, based on the number of players from above
		printf("Gameseed: %d\n", gameSeed);
		printf("Number Players: %d\n", numPlayers);
		printf("Hand Position: %d\n", handPos);
		printf("Current Player: %d\n", currentPlayer);
		initializeGame(numPlayers, k, gameSeed, &g);

		g.handCount[currentPlayer] = rand() % MAX_HAND;
		g.deckCount[currentPlayer] = rand() % MAX_DECK;
		g.discardCount[currentPlayer] = rand() * MAX_DECK;

		handCountCheck = g.handCount[currentPlayer];
		deckCountCheck = g.deckCount[currentPlayer];
		discardCountCheck = g.discardCount[currentPlayer];

		cardEffect(smithy, 1, 1, 1, &g, handPos, &bonus);
		checkSmithyCard(currentPlayer, &g, handCountCheck, deckCountCheck, discardCountCheck);
	}

	return 0;
}