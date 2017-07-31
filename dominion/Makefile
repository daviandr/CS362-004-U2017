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

randomtestsmithy.o: randomtestsmithy.c dominion.o rngs.o
	gcc -o smithy randomtestsmithy.c dominion.c rngs.c -g -lm $(CFLAGS)

randomtestvillage.o: randomtestvillage.c dominion.o rngs.o
	gcc -o village randomtestvillage.c dominion.c rngs.c -g -lm $(CFLAGS)

smithy: randomtestsmithy.o dominion.o rngs.o
	gcc -o smithy randomtestsmithy.c dominion.c rngs.c -g -lm $(CFLAGS)

village: randomtestvillage.o dominion.o rngs.o
	gcc -o village randomtestvillage.c dominion.c rngs.c -g -lm $(CFLAGS)

randomtestsmithy.out: randomtestsmithy.c dominion.c rngs.c
	echo "Result for running smithy tests:" > randomtestsmithy.out
	echo "randomtestsmithy.c" >> randomtestsmithy.out
	gcc -o smithy dominion.c rngs.c randomtestsmithy.c $(CFLAGS)
	smithy >> randomtestsmithy.out
	gcov dominion.c >> randomtestsmithy.out

randomtestvillage.out: randomtestvillage.c dominion.c rngs.c
	echo "Result for running village tests:" > randometestvillage.out
	echo "randomtestvillage.c" >> randomtestvillage.out
	gcc -o village dominion.c rngs.c randomtestvillage.c $(CFLAGS)
	village >> randomtestvillage.out
	gcov dominion.c >> randomtestsmithy.out

randomtestadventurer.out: randomtestadventurer.c dominion.c rngs.c
	echo "Result for running adventurer tests:" > randomtestadventurer.out
	echo "randomtestadventurer.c" >> randomtestvillage.out
	gcc -o advent dominion.c rngs.c randomtestadventurer.c $(CFLAGS)
	advent >> randomtestadventurer.out
	gcov dominion.c >> randomtestadventurer.out

all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
