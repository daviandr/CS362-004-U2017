/*

 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#define TEST_MAX 100
#define CARD_MAX 254

int checkAdventurerCard(int player, int i, struct gameState *preCard, struct gameState *postCard){
	int j;

	int preTreasure = 0;
	int postTreasure = 0;

	int differences = 0;

	int deckDifference;
	int discardDifference;
	int handDifference;
	int check;
	struct gameState preCopy;

	i++;

//Check how many treasure cards were in the hand prior to calling the adventurer card
	for(j = 0; j < preCard->handCount[player]; j++)		//iterate through the size of the player's hand
	{
		if(preCard->hand[player][j] == copper || preCard->hand[player][j] == silver || preCard->hand[player][j] == gold)
		{
			preTreasure++;			//if treasure card, increment counter variable
		}
	}

//Check how many treasure cards there are in the hand after calling the adventurer card
	for(j = 0; j < postCard->handCount[player]; j++)
	{
		if(postCard->hand[player][j] == copper || postCard->hand[player][j] == silver || postCard->hand[player][j] == gold)
		{
			postTreasure++;			//if treasure card, increment counter variable
		}
	}
	if(postTreasure == preTreasure + 2)
	{
		printf("TEST PASSED: Correct number of treasure cards drawn\n");
	}
	else
	{
		printf("TEST FAILED: Treasure cards in hand before and after card\n");
		printf("	Before Adventurer Card: %d\n", preTreasure);
		printf("	After  Adventurer Card: %d\n", postTreasure);
		printf("	Should be %d additional cards in hand\n", postTreasure - preTreasure);
	}
	//assert(postTreasure == preTreasure + 2);

//check if adventurer is still in hand
	for(j = 0; j < preCard->handCount[player]; j++)		//iterate through number of cards in hand prior to adventure card call
	{
		if(preCard->hand[player][j] != postCard->hand[player][j])
		{
			differences++;		//if the current card from pre-adventurer cards is different than the card from post-adventurer, make account of it
		}
	}
	if(differences == 0)
	{
		printf("TEST PASSED: Adventurer card still in hand\n");
	}
	else
	{
		printf("TEST FAILED: Adventurer card no longer in deck\n");
	}
	//assert(differences == 0);		//check whether the difference

	//check that non-treasure cards are discarded
	deckDifference = preCard->deckCount[player] - postCard->deckCount[player];
	discardDifference = postCard->discardCount[player] - preCard->discardCount[player];
	handDifference = postCard->handCount[player] - preCard->handCount[player];

	if(deckDifference == discardDifference + handDifference)
	{
		printf("PASSED: None treasure cards drawn are sent to discard\n");
	}
	else
	{
		printf("FAILED: Cards drawn not put in discard\n");
		printf("	Difference in deck size: %d\n", deckDifference);
		printf("	Difference in discard size: %d \n", discardDifference);
		printf("	Difference in hand size: %d\n", handDifference);
	}
}

int main(){
	int i = 0;
	int j = 0;
	int r = 0;
	int x = -99;
	int player = 0;
	struct gameState preCard;
	struct gameState postCard;

	/* Declare Seed */
	SelectStream(2);
	PutSeed(-1);

	printf("Starting test for Adventurer Card\n");

	for(i = 0; i < TEST_MAX; i++)
	{
		printf("\n-*-*-*-*-TEST NUMBER (%d)-*-*-*-*-\n", i + 1);

		for(j = 0; j < sizeof(struct gameState); j++)			//randomize the gamestate
		{
			((char*)&preCard)[i] = floor(Random() * 256);
		}

		player = floor(Random() * 2);		//randomize number of players
		preCard.deckCount[player] = floor(Random() * CARD_MAX);
		preCard.discardCount[player] = floor(Random() * CARD_MAX);
		preCard.handCount[player] = floor(Random() * CARD_MAX);
		preCard.playedCards[player] = floor(Random() * CARD_MAX);
		preCard.playedCardCount = floor(Random() * CARD_MAX);

		if(preCard.deckCount[player] == 0 && preCard.discardCount[player] == 0)
		{
			if(floor(Random() * 2) == 1)
			{
				preCard.deckCount[player] = floor(Random() * CARD_MAX) + 20;
			}
			else
			{
				preCard.discardCount[player] = floor(Random() * CARD_MAX) + 20;
			}
		}

		if(preCard.deckCount[player] > 0)
		{
			for(j = 0; j < 5; j++)
			{
				x = (int)(floor(Random() * preCard.deckCount[player]));
				preCard.deck[player][x] = (int)(floor(Random() * 3)) + 4;
			}
		}
		else
		{
			for(j = 0; j < 5; j++)
			{
				x = (int)(floor(Random() * preCard.discardCount[player]));
				preCard.discard[player][x] = (int)(floor(Random() * 3)) + 4;
			}
		}

		memcpy (&postCard, &preCard, sizeof(struct gameState));
		
		r = adventurerEffect(&postCard);
		if(r != 0)
		{
			printf("Adventurer Card failed. Did not return 0\n");
		}

		checkAdventurerCard(player, i, &preCard, &postCard);
	}

	return 0;
}