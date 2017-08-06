/******************************************************
* CS362 Assignment 3
* Chung-Chih Shih
* Unit Test 2
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

	printf("Unit test 2: \n");
	assertion(isGameOver(gState) == 0, "Testing isGameOver");

	printf("End of unit test 2\n");
	return 0;
}