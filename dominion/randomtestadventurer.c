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
	int sizeDiff;

	printf("\nChecking how many treasure cards in hand after card played\n");
	printf("deck count: %d\n", g->deckCount[cp]);
	printf("Hand count: %d\n", g->handCount[cp]);
	for(n = 0; n < g->handCount[cp]; n++)
	{
		printf("N: %d\n", n);
		if(g->hand[cp][n] == 6)
		{
			newTreasureCount++;
		}
	}
	printf("num treasure after: %d\n", newTreasureCount);
/*
	sizeDiff = newTreasureCount - oldTreasureCount;
	printf("Treasure Cards After Adventurer Card: %d\n", newTreasureCount);
	printf("Treasure Cards Before: %d\n", oldTreasureCount);
	printf("Size Differenc: %d\n\n", sizeDiff);

	sizeDiff = g->handCount[cp] - oldHand;
	printf("After Adventurer Hand Count: %d\n", g->handCount[cp]);
	printf("Old Hand Count: %d\n", oldHand);
	printf("Size Difference: %d\n\n", sizeDiff);

	sizeDiff = g->deckCount[cp] - oldDeck;
	printf("After Adventurer Deck Count: %d\n", g->deckCount[cp]);
	printf("Old Deck Count: %d\n", oldDeck);
	printf("Size Difference: %d\n", sizeDiff);
*/
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
	int numTotalTreasure;
	int discardCountCheck;
	int numTreasureAfter = 0;
	int numTreasureBefore = 0;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

	struct gameState g;

	srand(time(NULL));


	for(n = 0; n < TEST_MAX; n++)
	{
		printf("\n-*-*-*-*-TEST NUMBER (%d)-*-*-*-*-\n", n + 1);

		gameSeed = rand();		//generate a random see to initialize new game
		numPlayers = rand() % 2;	//pick random number of players, between 0 - MAX_PLAYERS
		bonus = 0;		//for cardEffect() function
		handPos = rand() % 4; 	//generte random handPos in standard sized hand
		currentPlayer = rand() % 2;	//pick a random player, based on the number of players from above


		initializeGame(numPlayers, k, gameSeed, &g);

		g.handCount[currentPlayer] = (rand() % (5 - 1) + 1);
		g.deckCount[currentPlayer] = rand() % MAX_DECK;
		g.discardCount[currentPlayer] = rand() % MAX_DECK;

		handCountCheck = g.handCount[currentPlayer];
		deckCountCheck = g.deckCount[currentPlayer];
		discardCountCheck = g.discardCount[currentPlayer];
		numTotalTreasure = rand() % handCountCheck;
printf("hand size: %d\n", handCountCheck);
		/* assign arbitrary type of treasure to random number (determined above) of cards in the hand */
		for(r = 0; r < numTotalTreasure; r++)
		{
			g.hand[currentPlayer][r] = gold;	//copper == 4, silver == 5, gold == 6
		}
		printf("total treasure: %d\n", numTotalTreasure);

		//numTotalTreasure = handCountCheck;

		/*What should I be comparing? 
		  The number of treasure cards before and after
		  The number of cards in the hand before and after
		  The number of cards in the deck before and after
		 */
		for(m = 0; m < handCountCheck; m++)
		{
			printf("treasure %d: %d\n", m, g.hand[currentPlayer][m]);
			if(g.hand[currentPlayer][m] == 6)	//where 6 is == gold
			{
				numTreasureBefore++;
			}
		}
		printf("num treasure before: %d\n", numTreasureBefore);
		playAdventurer(currentPlayer, handPos, &g);
		checkAdventurerCard(currentPlayer, &g, handCountCheck, deckCountCheck, numTreasureBefore);

	}	

	return 0;
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