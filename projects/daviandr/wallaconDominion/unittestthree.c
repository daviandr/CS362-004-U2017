/******************************************************
* CS362 Assignment 3
* Chung-Chih Shih
* Unit Test 3
* "Using as placeholder to complete assignment 5 to check group code. Code not written" - Andrew Davis
******************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int assertion(int trueVal, char* response){
	//if true
	if(trueVal) printf("PASS: %s\n", response);
	else printf("FAIL: %s\n", response);
	return 0;
}


int main(){

	struct gameState* gState = newGame();
	int* myKingdomCards = kingdomCards(gardens, mine, village, baron, adventurer, smithy, council_room, steward, great_hall, feast);
	initializeGame(2, myKingdomCards, 10, gState);

	printf("Unit test 3: \n");
	
	gState->handCount[0] = 6;
	gState->discardCount[0] = 0;
	gState->deckCount[0] = 0;
	gState->hand[0][0] = curse;
	gState->hand[0][1] = estate;
	gState->hand[0][2] = duchy;
	gState->hand[0][3] = province;
	gState->hand[0][4] = great_hall;
	gState->hand[0][5] = gardens;
	gState->discard[0][0] = village;
	gState->discard[0][1] = village;
	gState->discard[0][2] = village;
	gState->discard[0][3] = village;
	gState->discard[0][4] = village;
	gState->discard[0][5] = village;
	gState->deck[0][0] = village;
	gState->deck[0][1] = village;
	gState->deck[0][2] = village;
	gState->deck[0][3] = village;
	gState->deck[0][4] = village;
	gState->deck[0][5] = village;

	assertion(scoreFor(0, gState) == 10, "Testing scoreFor - hand");



	gState->handCount[0] = 0;
	gState->discardCount[0] = 6;
	gState->deckCount[0] = 0;
	gState->hand[0][0] = village;
	gState->hand[0][1] = village;
	gState->hand[0][2] = village;
	gState->hand[0][3] = village;
	gState->hand[0][4] = village;
	gState->hand[0][5] = village;
	gState->discard[0][0] = curse;
	gState->discard[0][1] = estate;
	gState->discard[0][2] = duchy;
	gState->discard[0][3] = province;
	gState->discard[0][4] = great_hall;
	gState->discard[0][5] = gardens;
	gState->deck[0][0] = village;
	gState->deck[0][1] = village;
	gState->deck[0][2] = village;
	gState->deck[0][3] = village;
	gState->deck[0][4] = village;
	gState->deck[0][5] = village;

	assertion(scoreFor(0, gState) == 10, "Testing scoreFor - discard");


	gState->handCount[0] = 0;
	gState->discardCount[0] = 0;
	gState->deckCount[0] = 6;
	gState->hand[0][0] = village;
	gState->hand[0][1] = village;
	gState->hand[0][2] = village;
	gState->hand[0][3] = village;
	gState->hand[0][4] = village;
	gState->hand[0][5] = village;
	gState->discard[0][0] = village;
	gState->discard[0][1] = village;
	gState->discard[0][2] = village;
	gState->discard[0][3] = village;
	gState->discard[0][4] = village;
	gState->discard[0][5] = village;
	gState->deck[0][0] = curse;
	gState->deck[0][1] = estate;
	gState->deck[0][2] = duchy;
	gState->deck[0][3] = province;
	gState->deck[0][4] = great_hall;
	gState->deck[0][5] = gardens;

	printf("%d\n", scoreFor(0, gState));
	assertion(scoreFor(0, gState) == 10, "Testing scoreFor - deck");

	printf("End of unit test 3\n");
	return 0;
}