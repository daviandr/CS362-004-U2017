/* 

 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <assert.h>

#define TEST_MAX 1//5000

int checkAdventurerCard(int cp, struct gameState *g, int oldHand, int oldDeck, int oldTreasureCount){
	int n;
	int newTreasureCount = 0;
	int treasureDifference;

	printf("entering check part of test\n");
	for(n = 0; n < g->handCount[cp]; n++)
	{
		if(g->hand[cp][n] == gold || g->hand[cp][n] == silver || g->hand[cp][n] == copper)
		{
			newTreasureCount++;
		}
	}

	treasureDifference = newTreasureCount - oldTreasureCount;

	if(treasureDifference != 2)
	{
		printf("Not enough treasure cards were drawn\n");
		printf("Number of treasure cards before Adventure card played: %d\n", oldTreasureCount);
		printf("Number of treasure cards after Adventure card played: %d\n", newTreasureCount);
	}

	return 0;
}

int main(){
	int n;
	int m;
	int r;
	int bonus;
	int handPos;
	int gameSeed;
	int deckCount;
	int numPlayers;
	int currentPlayer;
	int handCountCheck;
	int deckCountCheck;
	int numTreasureAfter = 0;
	int numTreasureBefore = 0;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

	struct gameState g;

	srand(time(NULL));


	for(n = 0; n < TEST_MAX; n++)
	{
		gameSeed = rand();		//generate a random see to initialize new game
		numPlayers = rand() % (MAX_PLAYERS - 2) + 2;	//pick random number of players, between 0 - MAX_PLAYERS
		bonus = 0;		//for cardEffect() function
		handPos = rand() % 4; 	//generte random handPos in standard sized hand
		currentPlayer = rand() % (MAX_PLAYERS - 2) + 2;	//pick a random player, based on the number of players from above
		initializeGame(numPlayers, k, gameSeed, &g);

		g.handCount[currentPlayer] = rand() % MAX_HAND;
		g.deckCount[currentPlayer] = rand() % MAX_DECK;
		g.discardCount[currentPlayer] = rand() * MAX_DECK;

		handCountCheck = g.handCount[currentPlayer];
		deckCountCheck = g.deckCount[currentPlayer];

		printf("entering loop 1\n");
		for(m = 0; m < handCountCheck; m++)
		{
			if(g.hand[currentPlayer][m] == copper || g.hand[currentPlayer][m] == silver || g.hand[currentPlayer][m] == gold)
			{
				numTreasureBefore++;
			}
		}
		printf("exiting loop 1\n");

		printf("calling cardEffect()\n");
		cardEffect(adventurer, 1, 1, 1, &g, handPos, &bonus);
		printf("executed carfEffect()\n");

		printf("adventure card played\n");
		r = checkAdventurerCard(currentPlayer, &g, handCountCheck, deckCountCheck, numTreasureBefore);

	}


	printf("Testing adventurer card\n");

}


/* -Check number of treasures in hand before and after. After, there should be two more treasures -
	for(i = 0; i < 5; i++)
	{
		printf("loop %d\n", i);
		if(hand[i] == copper || hand[i] == gold)
		{
			numTreasureBefore++;
		}
	}
	printf("numTreasureBefore: %d\n", numTreasureBefore);	

	
	hand[3] = gold;
	hand[4] = copper;

	for(i = 0; i < 5; i++)
	{
		printf("loop %d\n", i);
		if(hand[i] == copper || hand[i] == gold)
		{
			numTreasureAfter++;
		}
	}	
*/