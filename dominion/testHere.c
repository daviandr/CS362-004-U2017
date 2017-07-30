#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int main(){

	int a, b, c;
	a = 5;
	b = 5;
	c = 6;

	assert(a == b);
	assert(!(a <= c));
}