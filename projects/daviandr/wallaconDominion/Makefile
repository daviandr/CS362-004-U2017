CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)
## HW 3 Unit Tests
unittestresults.out: unittestone.c unittesttwo.c dominion.o rngs.o
	gcc -o unittestone -g unittestone.c dominion.o rngs.o $(CFLAGS)
	./unittestone &>> unittestresults.out
	gcov -b -c dominion.c >> unittestresults.out
	gcc -o unittesttwo -g unittesttwo.c dominion.o rngs.o $(CFLAGS)
	./unittesttwo &>> unittestresults.out
	gcov -b -c dominion.c >> unittestresults.out
	gcc -o unittestthree -g unittestthree.c dominion.o rngs.o $(CFLAGS)
	./unittestthree &>> unittestresults.out
	gcov -b -c dominion.c >> unittestresults.out
	gcc -o unittestfour -g unittestfour.c dominion.o rngs.o $(CFLAGS)
	./unittestfour &>> unittestresults.out
	gcov -b -c dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out


## HW 4 Random Tests
allOuts: randomtestsmithy.out randomtestvillage.out randomtestadventurer.out

randomtestsmithy.out: randomtestsmithy.c dominion.o rngs.o
	gcc -o randomtestsmithy -g -lm randomtestsmithy.c dominion.o rngs.o $(CFLAGS)
	./randomtestsmithy &>> randomtestsmithy.out
	gcov -b -c dominion.c >> randomtestsmithy.out
	cat dominion.c.gcov >> randomtestsmithy.out

randomtestvillage.out: randomtestvillage.c dominion.o rngs.o
	gcc -o randomtestvillage -g -lm randomtestvillage.c dominion.o rngs.o $(CFLAGS)
	./randomtestvillage &>> randomtestvillage.out
	gcov -b -c dominion.c >> randomtestvillage.out
	cat dominion.c.gcov >> randomtestvillage.out

randomtestadventurer.out: randomtestadventurer.c dominion.o rngs.o
	gcc -o randomtestadventurer -g -lm randomtestadventurer.c dominion.o rngs.o $(CFLAGS)
	./randomtestadventurer &>> randomtestadventurer.out
	gcov -b -c dominion.c >> randomtestadventurer.out
	cat dominion.c.gcov >> randomtestadventurer.out


all: playdom player testDrawCard testBuyCard badTestDrawCard randomtestadventurer randomtestsmithy randomtestvillage

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe randomtestadventurer randomtestsmithy randomtestvillage
