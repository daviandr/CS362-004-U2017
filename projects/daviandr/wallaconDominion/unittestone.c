/******************************************************
* CS362 Assignment 3
* Chung-Chih Shih
* Unit Test 1
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

	printf("Unit test 1: \n");
	gState->supplyCount[great_hall] = 3;
	assertion(supplyCount(great_hall, gState) == 3, "Testing supplyCount");

	gState->supplyCount[gold] = 3;
	assertion(supplyCount(gold, gState) == 3, "Testing supplyCount");
	
	printf("End of unit test 1\n");
	return 0;
}