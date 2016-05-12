#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

#include "staticlib.h"
#include "my_alloc.h"
typedef struct UnaryOps UnaryOps;
int unaryPlus (int);
int unaryMinus (int);
bool not (bool);
int complement (int);
	int main(int argc, char *argv[]){
		assertTrue(unaryPlus(2) == 2);
		assertTrue(unaryPlus((-2)) == (-2));
		assertTrue(unaryMinus(2) == (-2));
		assertTrue(unaryMinus((-2)) == 2);
		assertTrue(true);
		assertTrue((!false));
		assertTrue(not(true) == false);
		assertTrue(not(false) == true);
		assertTrue(complement((-5)) == 4);


		collect();
		return 0;
	}
	int unaryPlus (int i){
			int joy;
			joy=(i);
			collect();
			return joy;

	}
	int unaryMinus (int i){
			int joy;
			joy=(-i);
			collect();
			return joy;

	}
	bool not (bool b){
			bool joy;
			joy=(!b);
			collect();
			return joy;

	}
	int complement (int i){
			int joy;
			joy=(~i);
			collect();
			return joy;

	}
